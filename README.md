# LaptopCooler
Java and Arduino

# Arduino
The arduino code is fetching data from the temperature and light sensors. 
The intensity of the lights on the laptop cooler project are changing if the outside light is dimming.
The data from the humidity and temperature sensors will be written into the Serial and then they will be read and displayed into the java interface.

# Java
In the java part we have two major classes:
- ArduinoSerial.java
- GestiuneTemp.java

ArduinoSerial.java contains the code necessary for the connection to the Serial port and to copy the data from there.
GestiuneTemp.java contains the interface that will display the data with a thread.
