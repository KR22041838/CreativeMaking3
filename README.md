# CreativeMaking3


For this project I have explored the incorporation of a physical memory game using flashing LEDs, with a Game environment and alternative controller.
I started the project with an Arduino based memory game where the LEDs flashed in an order and you have to press the correct corresponding buttons. I then met difficalties trying to incorporate it into unity. I decided write my own arduino/unity programs to slowly build up to making the memory game.

# First Iteration
The first iteration worked by Unity reading the arduino serial to listen for which colour LED is flashing and to flash the corresponding light in Unity as it goes through the random sequence. 

# Second Iteration 
For the second iteration I felt the use of Unity to mirror the light pattern was a bit futile as you could play the physical arduino game and didn’t need to look at the screen to play it. 

A lecturer then suggested I recreate the memory game in unity and use the arduino as the controller to select the correct button/led when prompted. I found the arduino code complicated to transfer into unity so I started from the basics and set up a random light sequence to be sent from unity to the arduino LED’s. At this point I hadn't decided whether to ditch the LED’s as they are useful for debugging and can be incorporated into the controller. 

# Third Iteration
In the third iteration I incorporated the arduino buttons pressed status into the Unity code.  I had issues with sending the button serial data to unity as I had kept the original circuit of each LED and Button set connected the same pin. And you cannot receive data and send data simultaneously. Once I separated the buttons and LED’s the code worked and if a light would turn on in unity it will send data to the Arduino and wait to see if the corresponding button has been pressed for the sequence continues. The Unity code waits for a button to be pressed but it does not seem to acknowledge if it is the right button or not and just continues with the light sequence regardless of if it is correct. I also struggled to get the code to   repeat the sequence like in the original memory game after the button has been pressed. The game has turned more into a chase the light game. 

One thing that really helped my arduino code interact smoothly with Unity was to change from ‘switch case’ statements activated by serial data from unity and containing instructions for both the LED input and button output. To be separated into ‘if else’ statements for LED’s as a group and same with the buttons. This prevented a lot of crashing of the unity engine. 

# Fourth Iteration
For the forth iteration I still hadn't managed to get unity to distinguish between a button push and the correct button push. I also struggled to get the code to repeat the sequence like in the original memory game after the button has been pressed. The game has turned more into a chase the light game. It does however flash a looser sequence when you time out. 

### I wanted the unity the unity scene to look like a dilapidated toy shop that sits in relative darkness, with only the LED’s flashing the memory sequence. And then, only when you press the buttons the unity Lights turn on and you see a glimpse of the slightly creepy looking toy shop.

# Alternative Controller 
To make an alternative controller I used a rubix cube as it fits in the theme of a toy shop along with a Capacitive Touch Sensor and copper tape. I originally wanted the user to have to rotate the cube to align the required colours to match the light colour of unity. However, I ran out of time and it needed a lot of time to work out moving parts and wires, and there is no way of knowing if a line of the right colour has been matched up before the capacitive touch sends the ‘button press’ data.

# In Conclusion 
To conclude, I am happy with the progression of the project even thought the outcome of a memory game was not met, and it is more of a chase the light game. Though this could be changed into a speed game as the time-out function works to end the game if you do not press the buttons fast enough.

I found scripting in Unity hard as I was not familiar with C# and used ChatGTP to help at times, however the code would crash a lot when trying to run in game mode without any errors popping up so it was hard to troubleshoot other than reverting to the last useable code. To improve the code in future I would create a game manager script to call on the different elements needed as I think part of the reason for all the crashing is putting all the code in one script. I would like to have spent more time making the toyshop look good as I wanted to make some creepy teddies in Blender but ran out of time and used prefabs. I’m not overly happy with the rubix cube controller, but I really like the possibilities of a kinetic controller and would like to explore this. Having to form certain colour formations on the rubix cube to press a ‘button’ would add an extra layer of skill and difficulty to a simple memory or time limited game. 
