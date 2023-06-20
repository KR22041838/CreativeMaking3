/* Code adapted from:
https://www.youtube.com/watch?v=_RzhCQx3PUc&t=189se
https://www.youtube.com/watch?v=5ElKFY3N1zs
and aided by ChatGTP to expland code function. 
*/


using System.Collections; 
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports; //Allows connection to serial port COM
using System.Text;
using System;
using Random = UnityEngine.Random;

public class FirstSix : MonoBehaviour
{
    public Light RedLight;  // Reference to the red light object in Unity
    public Light GreenLight;  // Reference to the green light object in Unity
    public Light BlueLight;  // Reference to the blue light object in Unity
    public Light YellowLight;  // Reference to the yellow light object in Unity
    public Light[] lights;  // Array to store references to all lights

    SerialPort portNo = new SerialPort("COM4", 9600);  // Serial port configuration

    private bool responseReceived = false; // Flag to track button response

    void Start()
    {
        // Disable all lights at the beginning
        RedLight.enabled = false;
        GreenLight.enabled = false;
        BlueLight.enabled = false;
        YellowLight.enabled = false;

        // Assign the lights array
        lights = new Light[] { RedLight, GreenLight, BlueLight, YellowLight };

        portNo.Open();  // Open the serial port connection
        portNo.ReadTimeout = 1000; // Set the read timeout to 1 second

        StartCoroutine(SendLightPattern());  // Start coroutine to send light patterns
        StartCoroutine(ReceiveButtonData());  // Start coroutine to receive button data
    }

    // Coroutine to send light patterns to Arduino
    IEnumerator SendLightPattern()
    {
        List<int> lightSequence = new List<int>() { 1, 2, 0, 3, 1, 2 }; // Define the light sequence

        int currentStep = 0; //current step initalised to 0

        while (true)
        {
            int lightIndex = lightSequence[currentStep];

            // Turn off all lights
            foreach (Light light in lights)
            {
                light.enabled = false;
            }

            // Turn on the light at the current step
            lights[lightIndex].enabled = true;

            // Send the light index to Arduino
            int arduinoIndex = lightIndex + 1; // Map to numbers 1, 2, 3, 4
            try
            {
                portNo.Write(arduinoIndex.ToString());  // Send the light index as a string
                Debug.Log("Sent light index: " + arduinoIndex);
            }
            catch (System.Exception e)
            {
                Debug.LogWarning("Failed to send data to Arduino: " + e.Message);
            }

            // Reset flag for button response
            responseReceived = false;

            // Wait for Arduino to send the expected response
            StartCoroutine(WaitForDataResponse(arduinoIndex));

            // Wait until the data response is received
            while (!responseReceived)
            {
                yield return null;
            }

            // Flash the light for 1 second
            float flashDuration = 1.0f;
            float elapsedTime = 0.0f;
            while (elapsedTime < flashDuration)
            {
                // Toggle the light state every half second
                lights[lightIndex].enabled = !lights[lightIndex].enabled;

                yield return new WaitForSeconds(0.5f);

                elapsedTime += 0.5f;
            }

            // Move to the next step in the sequence
            currentStep++;
            if (currentStep >= lightSequence.Count)
            {
                currentStep = 0; // Go back to the beginning of the sequence
            }

            yield return null; // Wait for the end of frame before proceeding to the next light
        }
    }


    // Coroutine to wait for data response from Arduino
    IEnumerator WaitForDataResponse(int expectedData)
    {
        float elapsedTime = 0f;
        float timeoutDuration = 15f; // Timeout duration in seconds

        while (elapsedTime < timeoutDuration)
        {
            if (portNo.BytesToRead > 0)
            {
                byte receivedByte = (byte)portNo.ReadByte();
                char receivedChar = Encoding.ASCII.GetChars(new byte[] { receivedByte })[0];
                Debug.Log("Received data from Arduino: " + receivedChar.ToString());

                // Check if the received character is within the expected range
                if (receivedChar >= '1' && receivedChar <= '4')
                {
                    responseReceived = true;
                }
            }

            elapsedTime += Time.deltaTime;
            yield return null;
        }

        // Timeout occurred, timeout condition 
        Debug.LogWarning("Data response timeout occurred");
        StopGame();
    }

    // Coroutine to receive button data from Arduino
    IEnumerator ReceiveButtonData()
    {
        while (true)
        {
            if (portNo.BytesToRead > 0)
            {
                byte receivedByte = (byte)portNo.ReadByte();
                char receivedChar = Encoding.ASCII.GetChars(new byte[] { receivedByte })[0];
                Debug.Log("Received button data from Arduino: " + receivedChar.ToString());

                // Check if the received light index matches the incoming data
                int lightIndex = -1;
                for (int i = 0; i < lights.Length; i++)
                {
                    if (lights[i].enabled)
                    {
                        lightIndex = i;
                        break;
                    }
                }

                // Check if the received character matches the expected light index
                if (lightIndex != -1 && lightIndex + '1' != receivedChar)
                {
                    // Wrong character received, stop the game
                    StopGame();
                    // Or set a flag to indicate game over
                    // gameOver = true;
                }
                else
                {
                    // Reset flag for button response
                    responseReceived = true;
                }
            }

            yield return null;
        }
    }


    // Coroutine to stop the game and flash lights
    IEnumerator StopGameCoroutine()
    {
        // Flash all lights for a certain duration
        float flashDuration = 2.0f;
        float elapsedTime = 0.0f;

        while (elapsedTime < flashDuration)
        {
            // Toggle the state of all lights
            foreach (Light light in lights)
            {
                light.enabled = !light.enabled;
            }

            // Wait for a short duration
            yield return new WaitForSeconds(0.5f);

            elapsedTime += 0.5f;
        }

        // Reset the lights to their initial state
        foreach (Light light in lights)
        {
            light.enabled = false;
        }
    }

    // Function to stop the game and start the coroutine to flash lights
    void StopGame()
    {
        StartCoroutine(StopGameCoroutine());
    }

    // Called when the script is destroyed
    private void OnDestroy()
    {
        // Close the serial port when the script is destroyed
        if (portNo.IsOpen)
        {
            portNo.Close();
        }
    }

}

