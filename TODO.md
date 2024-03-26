
# TODO

# Notes

Utiliser [Remote XY](https://remotexy.com)

Revoir les couleurs pour les leds de la voirure
Dispositif de télémétrie ???

# Functions

## Commande

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

void printLedBar(int speed);
/*
input : speed (0 - 20) 10=0m/s
output : (voir doc)
*/

int get_command_state_button(int command_state);
/*
input : command state
output : incremented command state
States :
- Auto (0)
- Telecommand (1)
- Bluetooth (2)
*/

void print_state_LCD(int command_state);
/*
input : command state
output : pirint text on the LCD
*/

## Xbee

| Message | Code |
| --- | --- |
| Ready | c |
| Urgency | u |
| Mode auto | a |
| Mode Telecommande | t |
| Mode Bluetooth | b |
| Vitesse | value |
| Direction | **l**(eft)/**f**(orward)/**r**(ight)/ **s**(opt)|

void send_msg(char msg);
/*
input : message to send to the other Xbee
*/

char receive_msg();
/*
output : message sent by the other Xbee or "" by default
*/

## Voiture / Recepteur

#### Hardware

int get_distance();
/*
output : the distance read from the ultrason distance detector
*/

bool obtacle(int distance) ???
/*
input : distance of trigger
output : true if the obsacle in range
*/

void urgent_stop();
/*
Stop the motors and everything else
Send Urgency message via Xbee
*/

void go_forward(int speed)
/*
input : speed of the motors(0-20)
output : move
*/

void turn(int speed, int direction)
/*
input : 
    - speed : speed of the motor (0-20)
    - direction : direction of the motor left(0) or strait(1) or right(2)
output : turn the car to the direction with the appropriate speed

If the car is stopped, turn staticaly (wheel turn in opposite direction) 
*/

#### Software

void ready_setup()
/*
Do some bipboup things to tell it is working
*/

void set_led_motor_state(int speed, int direction);
/*
input : 
    - speed : speed of the motor (0-20)
    - direction : direction of the motor left(0) or strait(1) or right(2)
output : for each motor, green if speed forward, red if backward, off if 0
*/

### Manuel

bool buzz(bool buzzing, int distance, int secure_dist)
/*
input : 
    - buzzing : true if buzzer running
    - actual distance to the obstacle
    - secure_dist : distance to trigger the buzzer
output :
    - true if buzzer running
Buzz if distance to obstacle <= secure_dist
*/

### Autonome


void init_auto();
/*
 le robot émet 5 bips de 1s
*/

void driving();
/*
if !obstacle :
go_forward(20);
else :
during N seconde:
turn(20, r)
during N seconde:
turn(20, l)
during N seconde:
turn(20, l)
during N seconde:
turn(20, r)
*/

void turn_angle(int angle)
/*
Use turn function but use time to do a specific angle
*/

# Composants

Faire un code de test pour chaque composant.

## Telecommande

- potentiomètre 
- bouton
- LCD
- Coque-tel

## Telecommande + voiture
led bico
- Xbee

## Voiture

- moteurs pont en H (vitesse, avant arrière,...) 
- buzzer
- led bicouleur
- Bluetooth
- Capteur ultrason


