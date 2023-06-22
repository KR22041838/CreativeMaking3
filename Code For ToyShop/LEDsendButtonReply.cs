using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class LEDsendButtonReply : MonoBehaviour
{
    public Light RedLight;
    public Light GreenLight;
    public Light BlueLight;
    public Light YellowLight;

    SerialPort portNo = new SerialPort("COM4", 9600);

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

        StartCoroutine(RandomLightPattern());
    }

    IEnumerator RandomLightPattern()
    {
        while (true)
        {
            // Create an array of the lights
            Light[] lights = new Light[] { RedLight, GreenLight, BlueLight, YellowLight };

            // Select a random light index
            int randomIndex = Random.Range(0, lights.Length);

            // Flash the light at the random index
            lights[randomIndex].enabled = true;

            // Set the duration of the flash
            float flashDuration = 0.5f;

            // Flash the light on and off for the specified duration
            float elapsedTime = 0f;
            while (elapsedTime < flashDuration)
            {
                // Toggle the light state
                lights[randomIndex].enabled = !lights[randomIndex].enabled;

                yield return new WaitForSeconds(0.1f); // Adjust the duration of each flash cycle

                elapsedTime += 0.1f;
            }

            // Turn off the light
            lights[randomIndex].enabled = false;

            // Wait for the corresponding Arduino data
            int receivedByte = - 1;
            while (receivedByte == 1)
            {
                try
                {
                    if (portNo.BytesToRead > 0)
                    {
                        receivedByte = portNo.ReadByte();
                        Debug.Log("Arduino data: " + receivedByte);
                    }
                }
                catch (System.Exception e)
                {
                    Debug.LogWarning("Failed to read data from Arduino: " + e.Message);
                }
                yield return null;
            }

            // Map the received byte to the corresponding light index
            int lightIndex = receivedByte - 1; // Assuming the Arduino sends values 1, 2, 3, 4
            if (lightIndex >= 0 && lightIndex < 4)
            {
                // Turn off all lights
                foreach (Light light in lights)
                {
                    light.enabled = false;
                }

                // Turn on the corresponding light
                lights[lightIndex].enabled = true;
            }

            yield return new WaitForSeconds(0.5f); // Wait for 0.5 seconds
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
