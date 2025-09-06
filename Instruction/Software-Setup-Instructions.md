## Software Setup and Uploading Code

1. **Install Arduino IDE:**  
   Download and install the Arduino IDE from [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software) for your operating system.

2. **Connect Arduino to Computer:**  
   Use a USB cable to connect your Arduino Uno board to the computer.

3. **Open Arduino Code:**  
   Launch the Arduino IDE and open the `code.ino` file 

4. **Select Board and Port:**  
   - Go to `Tools > Board` and select **Arduino Uno**.  
   - Go to `Tools > Port` and select the COM port corresponding to your Arduino board.

5. **Compile the Code:**  
   Click the **Verify** button (checkmark icon) in the IDE toolbar to compile the code and check for errors.

6. **Upload Code to Arduino:**  
   Click the **Upload** button (right arrow icon) to upload the code to your Arduino Uno. Wait for the **“Done uploading”** message.

7. **Open Serial Monitor (Optional):**  
   Open the Serial Monitor via `Tools > Serial Monitor` to view sensor readings or debugging output.  
   Set baud rate to **9600** to match `Serial.begin(9600);` in your code.

---

After upload is complete, disconnect the USB cable and power your robot via the motor driver’s external power source for autonomous operation.
