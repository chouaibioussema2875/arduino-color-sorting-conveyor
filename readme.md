This Arduino program controls an automatic color-sorting system using a conveyor, a color sensor, an infrared object detector, a servo motor, LEDs, and an LCD screen.

The system starts by moving a stepper motor, which acts like a conveyor belt. When an object reaches the detection point, the IR sensor detects it and the conveyor pauses. Then, the TCS3200 color sensor reads the object’s color by measuring the red, green, and blue values.

After reading the color, the Arduino compares the values to decide whether the object is red, green, or blue. Based on the detected color, a servo motor arm moves to a specific angle to push or sort the object into the correct bin:

Red object → Bin A
Green object → Bin B
Blue object → Bin C

The LCD screen displays the current system status, such as "System Ready", "ROUGE -> Bac A", "VERT -> Bac B", or "BLEU -> Bac C". After sorting the object, the servo returns to its neutral position and the system waits for the next object.
