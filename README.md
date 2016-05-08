# How-to-create-and-burn-Arduino-Bootloader-for-Atmega32
This project shows how to create and burn Arduino Bootloader for Atmega32. More details as below:

#Build arduino bootloader for Atmega32
- This bootloader was cloned from arduino bootloader of atmega8.
- It was compiled in Atmel Studio with 16MHz and FLASH segment = 0x3c00 (Boot Reset Address - It was depended on setting of hfuse bits to configure bootload loader size)
            
          ---------------------------------------------------
          | hfuse bits  |  Boot size  | Boot Reset Address  |
          ---------------------------------------------------
          | 11          |  256 words  | 0x3F00              |
          ---------------------------------------------------
          | 10          |  512 words  | 0x3E00              |
          ---------------------------------------------------
          | 01          |  1024 words | 0x3C00              |
          ---------------------------------------------------
          | 00          |  2048 words | 0x3800              |
          ---------------------------------------------------
          
#Configure Arduino IDE 
- Modify \hardware\arduino\avr\boards.txt so that The ardunio IDE recognizes target board corresonding to Atmega32: 
- Please pay attention: 
  + Baudrate: was equal to the baudrate in the bootloader program. 
  + lfuse = 0xFF: Select clock source with external oscillator 16MHz
  + hfuse = 0xDA: Enable Serial programming with boot loader size = 1024 words. The boot loader size was corresponding to FLASH segment which was configured in Atmel Studio when compiling bootloader project. 
  + file=atmega32\Bootloader.hex: This file was compiled above and placed in hardware\arduino\avr\bootloaders\atmega32\. It was used to burn bootloader for Atmega32.

#How to burn ardunio bootloader for Atmega32
- Use Arduino Uno R3 as ISP programer to burn bootloader: 
  + In Arduino IDE, select target board to rduino Uno R3
  + Compile and upload ArduinoISP Sketch to Arduino Uno R3. This Sketch was got from example of arduino-1.6.8
- Making physical connections between the Arduino board and the target MCU (Atmega32) as below: 

                  The Arduino board   The target MCU (Atmega32)                 
        RESET-----10------------------PB4(SS)
        PIN_MOSI--11------------------PB5                        
        PIN_MISO--12------------------PB6
        PIN_SCK---13------------------PB7
        
- Finally, burn bootloader for Atmega32
  + In Arduino IDE, switch target board to Atmega32
  + Set programmer to "Arduino as ISP"
  + In Tools > Burn booloader
        
After burning bootloader successfully, you can program for Atmega32 with Serial programming. 

