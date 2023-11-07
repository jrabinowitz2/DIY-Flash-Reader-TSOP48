![image](https://github.com/jrabinowitz2/DIY-Flash-Reader-TSOP48/assets/45504513/9bbfecae-b9a5-441f-8d88-04f3fbc97b43)
![image](https://github.com/jrabinowitz2/DIY-Flash-Reader-TSOP48/assets/45504513/73bd5f18-bec6-435f-bb2b-f92faf62ff98)
![image](https://github.com/jrabinowitz2/DIY-Flash-Reader-TSOP48/assets/45504513/5a9d5cb3-5f0f-4439-9689-29323294faea)

# DIY Flash Reader: TSOP48
Instructions for building a homemade flash chip reader/programmer for TSOP48 packages. Chip-off connection via socket with attached breakout; arduino-based microcontroller uses bit-banging to read from or program chip via Serial Peripheral Interface (SPI).

## Hardware
* Arduino-compatible microcontroller
* TSOP48 Socket + DIP Breakout
* Jumpers/wires
* Breadboard (optional)

## Software
* **RDID.ino**: reads out manufacturer ID code
* Other commands/manufacturers can be quickly implemented with slight modification...

## Setup
### Hardware Setup


Pin layout:
![image](https://github.com/jrabinowitz2/DIY-Flash-Reader-TSOP48/assets/45504513/79d98425-9af2-4ab9-83a5-2653793c91ef)
![image](https://github.com/jrabinowitz2/DIY-Flash-Reader-TSOP48/assets/45504513/ad339071-690b-4dc9-8571-3cf14e9daf66)

Signals used:
![image](https://github.com/jrabinowitz2/DIY-Flash-Reader-TSOP48/assets/45504513/f7f10bfd-91df-4d26-8b79-2fb79e3c6784)

### Uploading code via Arduino
1. Connect microcontroller via USB, configure in Arduino
2. Paste code for desired command (RDID, etc.)
3. Verify & Upload when ready

### Running commands
Once uploaded, the code can be run using either:
* Arduino's built-in Serial Monitor (good for quick test)
* Other serial comm. utilities: screen, minicom, PuTTY, etc. (*note: project has not been tested on Windows*)
<img src="https://github.com/jrabinowitz2/DIY-Flash-Reader-SOIC16/blob/main/img/soic16_running.png" >


NOTE: Before attempting chip-on commuincation...
* **ensure proper connection** between all physical components
