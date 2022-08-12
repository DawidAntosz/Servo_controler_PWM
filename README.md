# Servo controler PWM

Project of 6 channel PWM generator on Atmega328P-PU with 2x16 lcd which displays the number of ports used and specific value.<br />
The remaining ports PC0, PC1, PC2, PC3 according to the possibilities for general use, example connection of two joysticks.<br />
Powering the servos from an external source.

#### Value setting:
- manual (2 buttons) 
- I2C communication

#### Optionality:

- selection of ports 1-6 for PWM signal generation
- value set in degrees 0°-180° of servo rotation

#### Schematic:
<p align="center">
  <img src="https://user-images.githubusercontent.com/64035334/184445404-4d4c22af-b061-4279-89d7-b70cb9a22796.png" />
</p>

#### PCB from KiCad 6.0

<p align="center">
  <img src="https://user-images.githubusercontent.com/64035334/184446491-74c9fd44-4221-442b-9973-27dbd792c26c.png" width="450" /> <img src="https://user-images.githubusercontent.com/64035334/184446645-12c16e73-7fcf-4c7b-87cc-a8c451541f7a.png" width="500" />
  
  <img src="https://user-images.githubusercontent.com/64035334/184446754-b61995f1-f479-4f09-9cec-50737c38f749.png" height = "350" /> <img src="https://user-images.githubusercontent.com/64035334/184446885-974ce7b1-abd6-4d39-b52b-0d7b5ee99c7f.png" height = "350" />
</p>



#### Atmega328P-PU outputs:
<p align="center">
  <img src="https://user-images.githubusercontent.com/64035334/177892341-275cee10-aec5-4f1f-b29a-1f927f3bb094.png" height = "400" />
</p>


# Timers using in project - description from datasheet:

TIMER0 for PWM 
![image](https://user-images.githubusercontent.com/64035334/184011073-686e2480-1d23-48f0-9f22-e35dc4fab74c.png)
![image](https://user-images.githubusercontent.com/64035334/184011144-39d04c72-28b3-4e31-8d42-9c2e494c5824.png)
![image](https://user-images.githubusercontent.com/64035334/184011186-76fc60bd-8f44-46b1-ac80-24520565a301.png)
![image](https://user-images.githubusercontent.com/64035334/184011284-5fa0c075-d014-43e8-90b1-37f020e4ade8.png)
![image](https://user-images.githubusercontent.com/64035334/184011308-5664a95b-c749-45b1-bfe5-58f45bf51946.png)
![image](https://user-images.githubusercontent.com/64035334/184011377-b1f3e2c4-1ab7-4729-aa15-8548d417869a.png)
![image](https://user-images.githubusercontent.com/64035334/184011434-dd7b3d0e-a89a-4eb5-b463-d5079c856c26.png)
![image](https://user-images.githubusercontent.com/64035334/184011558-3afac3b0-57bf-44bf-8987-872f5c186e04.png)




 





















