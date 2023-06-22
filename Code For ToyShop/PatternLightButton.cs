using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class PatternLightButton : MonoBehaviour
{
    public Light RedLight;
    public Light GreenLight;
    public Light BlueLight;
    public Light YellowLight;

    SerialPort portNo = new SerialPort("COM4", 9600);

    // Start is called before the first frame update
    void Start()
    {
        portNo.Open();
        portNo.ReadTimeout = 1000; // Set the read timeout to 1 second

        StartCoroutine(RandomLightPattern());
    }

    IEnumerator RandomLightPattern()
    {
        while (true)
        {
            // Read bytes from the Arduino
            try
            {
                if (portNo.BytesToRead > 0)
                {
                    int receivedByte = portNo.ReadByte();
                    Debug.Log("Arduino data: " + receivedByte);
                }
            }
            catch (System.Exception e)
            {
                Debug.LogWarning("Failed to read data from Arduino: " + e.Message);
            }

            // Create an array of the lights
            Light[] lights = new Light[] { RedLight, GreenLight, BlueLight, YellowLight };

            // Select a random light index
            int randomIndex = Random.Range(0, lights.Length);

            // Turn off all lights
            foreach (Light light in lights)
            {
                light.enabled = false;
            }

            // Turn on the randomly selected light
            lights[randomIndex].enabled = true;

            yield return new WaitForSeconds(0.5f); // Wait for 0.5 seconds

            // Turn off all lights
            foreach (Light light in lights)
            {
                light.enabled = false;
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
