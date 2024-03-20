# TODO

# Notes

Utiliser [Remote XY](https://remotexy.com)

# Functions

## Commande

int get_command_state_button(command_state);
/*
input : command state
output : incremented command state
States :
- Auto
- Manuel
- Bluetooth
*/

void print_state_LCD(command_state);
/*
input : command state
output : pirint text on the LCD
*/

void printLedBar(speed);
/*
input : speed (0 - 20) 10=0m/s
output : (voir doc)
*/

int getSpeed();
/*
output : speed (0-20)
from potentiomètre
*/

int getDirection()
/*
output : left(0) or strait(1) or right(2)
use the 2 buttons
*/



## Xbee

| Message | Code |
| --- | --- |
| Mode auto | a |
| Mode Teleocommande | t |
| Mode Bluetooth | b |
| Vitesse | value |
| Direction | **l**(eft)/**f**(orward)/**r**(ight) |

void send_msg(string msg);
/*
input : message to send to the other Xbee
*/

string receive_msg();
/*
output : message sent by the other Xbee or "" by default
*/

## Voiture



int get_distance();
/*
output : the distance read from the ultrason distance detector
*/

void set_led_motor_state(int speed, int direction);
/*
input : 
    - speed : speed of the motor (0-20)
    - direction : direction of the motor left(0) or strait(1) or right(2)
output : for each motor, green if speed forward, red if backward, off if 0
*/

void urgent_stop();
/*
Stop the motors
*/


### Autonome



### Manuel


### Bluetooth

