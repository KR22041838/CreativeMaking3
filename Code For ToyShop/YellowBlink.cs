// https://www.youtube.com/watch?v=__DG62kEULg 
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class YellowBlink : MonoBehaviour
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
        if (stat == 2)
        {
            light_.enabled = true;
            print(2);
        }

        else if (stat != 2)
        {
            light_.enabled = false;
            print(0);
        }
    }


}
