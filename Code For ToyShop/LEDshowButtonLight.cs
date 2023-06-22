using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using System.Text;

public class LEDshowButtonLight : MonoBehaviour
{
    public Light RedLight;
    public Light GreenLight;
    public Light BlueLight;
    public Light YellowLight;

    SerialPort portNo = new SerialPort("COM4", 9600);

    private bool responseReceived = false; // Flag to track button response

    // Start is called before the first frame update
    void Start()
    {
        // Disable all lights
        RedLight.enabled = false;
        GreenLight.enabled = false;
        BlueLight.enabled = false;
        YellowLight.enabled = false;

        portNo.Open();
        portNo.ReadTimeout = 1000; // Set the read timeout to 1 second

        StartCoroutine(SendLightPattern());
        StartCoroutine(ReceiveButtonData());
    }

    IEnumerator SendLightPattern()
    {
        while (true)
        {
            // Create an array of the lights
            Light[] lights = new Light[] { RedLight, GreenLight, BlueLight, YellowLight };

            // Select a random light index
            int randomIndex = Random.Range(0, lights.Length);

            // Turn off all lights
            foreach (Light light in lights)
            {
                light.enabled = false;
            }

            // Turn on the random light
            lights[randomIndex].enabled = true;

            // Send the light index to Arduino
            int lightIndex = randomIndex;
            try
            {
                portNo.Write(lightIndex.ToString());
                Debug.Log("Sent light index: " + lightIndex);
            }
            catch (System.Exception e)
            {
                Debug.LogWarning("Failed to send data to Arduino: " + e.Message);
            }

            // Reset flag for button response
            responseReceived = false;

            // Wait for Arduino to send the expected response
            StartCoroutine(WaitForDataResponse(lightIndex));

            // Wait until the data response is received
            while (!responseReceived)
            {
                yield return null;
            }

            yield return new WaitForSeconds(1.0f); // Pause for 1 second before next light

            yield return null; // Wait for the end of frame before proceeding to the next light
        }
    }

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
                Debug.Log("Received data from Arduino: " + receivedChar);

                if (receivedChar == '5')
                {
                    responseReceived = true;
                    yield break; // Exit the coroutine
                }
            }

            elapsedTime += Time.deltaTime;
            yield return null;
        }

        // Timeout occurred, handle the timeout condition here
        Debug.LogWarning("Data response timeout occurred");
    }

    IEnumerator ReceiveButtonData()
    {
        while (true)
        {
            if (portNo.BytesToRead > 0)
            {
                byte receivedByte = (byte)portNo.ReadByte();
                char receivedChar = Encoding.ASCII.GetChars(new byte[] { receivedByte })[0];
                Debug.Log("Received button data from Arduino: " + receivedChar);

                // Handle the received button data here
                // For example, you can control the lights based on the received button data

                // Reset flag for button response
                responseReceived = true;
            }

            yield return null;
        }
    }

    private void OnDestroy()
    {
        // Close the serial port when the script is destroyed
        if (portNo.IsOpen)
        {
            portNo.Close();
        }
    }
}
