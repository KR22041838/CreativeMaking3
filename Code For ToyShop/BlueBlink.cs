// https://www.youtube.com/watch?v=__DG62kEULg 
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class BlueBlink : MonoBehaviour
{
    public Light light_;
    SerialPort portNo = new SerialPort("COM4", 9600);
    // Start is called before the first frame update
    void Start()
    {
        portNo.Open();
        portNo.ReadTimeout = 5000;
    }

    // Update is called once per frame
    void Update()
    {
        if (portNo.IsOpen)
        {
            try
            {
                blink_light(portNo.ReadByte());
            }
            catch (System.Exception)
            {
                throw;
            }

        }
    }

    void blink_light(int stat)
    {
        if (stat == 8)
        {
            light_.enabled = true;
            print(8);
        }

        else if (stat != 8)
        {
            light_.enabled = false;
            print(0);
        }
    }


}
