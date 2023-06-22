using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class PatternLightSend : MonoBehaviour
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

        StartCoroutine(SendLightPattern());
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
            int lightIndex = randomIndex; // Assuming Arduino expects values 1, 2, 3, 4
            try
            {
                portNo.Write(lightIndex.ToString());
                Debug.Log("Sent light index: " + lightIndex);
            }
            catch (System.Exception e)
            {
                Debug.LogWarning("Failed to send data to Arduino: " + e.Message);
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
