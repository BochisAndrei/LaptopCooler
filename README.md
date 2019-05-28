# LaptopCooler
Java and Arduino

Arduino
Codul scris pe placuta arduino contine atat cod care sa transforme datele primite de a senzorii de temperatura si luminiozitate, avem si codul care face posibila reglarea luminiozitatii beculetelor in functie de lumina de afara.
Datele pe care le citim de la sensorul de temperatura si umiditate vor fi scrise in Serial iar apoi din acest loc vor fi luate de catre programul scris in java si apoi afisate intr o fereastra.

Java
In partea de cod scrisa in Java avem doua clase importante si anume: 
- ArduinoSerial.java
- GestiuneTemp.java

Clasa ArduinoSerial.java contine codul necesar conectarii la Serial port pentru a putea copia datele de acolo
Clasa GestiuneTemp.java realizeaza interfata in care se vor afisa datele in mod continuu cu ajutorul unui fir de executie.
