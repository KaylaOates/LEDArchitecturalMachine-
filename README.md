# LED Architectural Machine
Turn on LEDs in an LED matrix based on what four ultrasonic sensors detect

### Tutorials: 

https://create.arduino.cc/projecthub/Mukhin/led-architectural-machin-bb67ba?ref=tag&ref_id=ultrasonic&offset=46 
https://www.hackster.io/Mukhin/led-architectural-machin-bb67ba  

### Parts:
- Arduino Uno 
- Ultra-Sonic sensor (x4) 

### LEDS: 

(TUTORIAL) RGB LED matrix: https://www.newark.com/adafruit/1487/led-module-type-board-led/dp/26Y8459?COM=ref_hackster OR https://www.adafruit.com/product/1487 

DIY Kit: https://www.instructables.com/Large-8x8-LED-Matrix-Display/ 

Complete DIY: https://docs.arduino.cc/built-in-examples/display/RowColumnScanning 
- 84 LEDS: https://www.amazon.com/Novelty-Place-Transparent-Electronics-Components/dp/B01AKPKC84/ref=sr_1_3?keywords=white%2Bled%2Bdiode&qid=1655488553&sprefix=white%2Bled%2Bdiode%2Caps%2C131&sr=8-3&th=1  
- Circuit board: https://www.amazon.com/AiTrip-Perfboard-Breadboard-Prototyping-Electronic/dp/B07XYL451Y/ref=sr_1_6?crid=3VNF39A292QSC&keywords=circuit%2Bboard&qid=1654725180&sprefix=circuit%2Bboard%2Caps%2C103&sr=8-6&th=1   
- Helpful tutorial on how to solder: https://beuniquecreateunique.blogspot.com/2018/04/how-to-make-8x8-led-matrix.html

### Steps: 
1. Order all the parts
2. Prototype (Ultra sonic sensor document challenge 2 & 3)
   https://giphy.com/gifs/U6SfzJQzJPcGhpMHqy?utm_source=iframe&utm_medium=embed&utm_campaign=Embeds&utm_term=https%3A%2F%2Fcreate.arduino.cc%2F 
3. Wire ultra-sonic sensor together using the diagrams below
4. Solder the LED Matrix

### How it works: 
To control a matrix, you connect both its rows and columns to your microcontroller. The columns are connected to the LEDs cathodes (see Figure 1), so a column needs to be LOW for any of the LEDs in that column to turn on. The rows are connected to the LEDs anodes, so the row needs to be HIGH for an individual LED to turn on. If the row and the column are both high or both low, no voltage flows through the LED and it doesn't turn on. 

#### How to solder: 
follow the link below for a step-by-step tutorial on creating the above schematic as they follow a very similar schematic that we are using (as seen in the pic below) 

### Multiplexing:  
- What is multiplexing: https://www.instructables.com/Multiplexing-with-Arduino-and-the-74HC595/  
- Tutorial for wiring and coding with our 8x8 matrix: http://www.learnerswings.com/2014/08/simple-arduino-program-to-turn-on-all.html  
