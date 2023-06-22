using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class PatternLight : MonoBehaviour
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
        portNo.ReadTimeout = 5000; 

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

            // Turn off all lights
            foreach (Light light in lights)
            {
                light.enabled = false;
            }

            // Turn on the randomly selected light
            lights[randomIndex].enabled = true;

            yield return new WaitForSeconds(0.5f); // Wait for one second

            // Turn off all lights
            foreach (Light light in lights)
            {
                light.enabled = false;
            }

            yield return new WaitForSeconds(0.5f); // Wait for one second
        }
    }
} 
