# Servo controler PWM

Project of 6 channel PWM generator on Atmega328P-PU with 2x16 lcd which displays the number of ports used and specific value.<br />
The remaining ports PC0, PC1, PC2, PC3 according to the possibilities for general use.<br />
Powering the servos from an external source.

#### Value setting:
- manual (2 buttons) 
- I2C communication

#### Optionality:

- selection of ports 1-6 for PWM signal generation
- value set in degrees 0°-180° of servo rotation

#### Schematic:
<p align="center">
  <img src="https://user-images.githubusercontent.com/64035334/177417897-1b7af1aa-1d3f-49db-90b7-9aefa702d41d.png" />
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/64035334/177894077-cd582a37-9ee8-4597-9e0c-e75ae41a1d94.png" width="450" /> <img src="https://user-images.githubusercontent.com/64035334/177894122-c322c7e2-0176-44ed-9996-5d8b9e2f199e.png" width="500" />
  
  <img src="https://user-images.githubusercontent.com/64035334/177892812-44e56187-1419-47c4-b371-4797ef9cb6cb.png" height = "400" />
  
</p>

#### Atmega328P-PU outputs:
<p align="center">
  <img src="https://user-images.githubusercontent.com/64035334/177892341-275cee10-aec5-4f1f-b29a-1f927f3bb094.png" height = "400" />
</p>


##PROGRAM description:

TIMER0 for PWM 

![image](https://user-images.githubusercontent.com/64035334/183487624-d66d5a1e-d2da-453b-8ec5-904da820342c.png)
 





















