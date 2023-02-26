# Smart-home-project

This project is used to control different home accessories that every home have such as lights, TVs and AC.

It is done by ATMEGA32 microcontroller and is coded using atmel studio IDE.

For the comunication between two microcontrollers it uses SPI protocol to transmit and receive data.

First time login you will be asked to set password for admen and guest users. 

![image](https://user-images.githubusercontent.com/119271600/221420740-e708000d-34f6-4de5-9c3d-3e7d3754d463.png)

Then it will store these passwords to the EEPROM and when login for the seconed time you will be asked to enter the password.

![image](https://user-images.githubusercontent.com/119271600/221420840-741e90f4-781a-4f60-b456-a17ec9d3264d.png)

It has led indicator to show wich mode is on.

On the LED screen it will show different options for each mode which allow user to chose from.

![image](https://user-images.githubusercontent.com/119271600/221421001-21dc8477-b7d5-4ff6-a5e6-2d5e5166fa2f.png)
![image](https://user-images.githubusercontent.com/119271600/221421055-a33d3368-b4c8-4d64-9815-4cc7c600873b.png)

after number of seconeds applied in the code user will get timeout message and will exit the app.

![image](https://user-images.githubusercontent.com/119271600/221421260-23cb02c7-0756-4f68-b27d-323ad3c902b6.png)

