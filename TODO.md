# TODO

# Notes

Utiliser [Remote XY](https://remotexy.com)

Revoir les couleurs pour les leds de la voirure

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
| Mode Telecommande | t |
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

#### Hardware

int get_distance();
/*
output : the distance read from the ultrason distance detector
*/

bool obtacle(distance)
/*
input : distance of trigger
output : true if the obsacle in range
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

void go_forward(speed)
/*
input : speed of the motors
output : move
*/

void turn(speed, direction)
/*
input : 
    - speed : speed of the motor (0-20)
    - direction : direction of the motor left(0) or strait(1) or right(2)
output : turn the car to the direction with the appropriate speed

If the car is stopped, turn staticaly (wheel turn in opposite direction) 
*/

#### Software

void bipbip

### Autonome

void do_BIP();
/*
 le robot émet 5 bips de 1s
*/

void driving();
/*
if !obstacle :
go_forward(20);
else :
    pendant 1s :
        turn(20, r)


*/

### Manuel

