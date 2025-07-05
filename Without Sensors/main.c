#include <kipr/wombat.h>

void wait(int time);
void forward(int speed, double distance);
void back(int speed, double distance);
void left(int speed, double distance);
void right(int speed, double distance);
void turnLeft(double distance);
void turnRight(double distance);
void fryDropOpen();
void fryDropClose();
void potatoArmUp();
void potatoArmRest();
void potatoArmGrab();
void potatoClawOpen();
void potatoClawClose();
void pompomClawOpen();
void pompomClawClose();

int topLeft = 0;
int topRight = 1;
int bottomLeft = 2;
int bottomRight = 3;

int fryDrop = 0;
int potatoArm = 1;
int potatoClaw = 2;
int pompomClaw = 3;

int main() {
    wait_for_light(2);
    shut_down_in(119);
    
    enable_servos();  

    fryDropClose();
    potatoArmRest();
    potatoClawOpen();
    pompomClawOpen();

    wait(11000);
        
    left(1000, 20);
    forward(1000, 15);
    left(1000, 5);
    forward(1000, 10);
    right(1000, 10);
    forward(1000, 10);
    left(1000, 5);
    forward(1000, 10);
    left(1000, 5);
    forward(1000, 10);
    right(1000, 10);
    forward(1000, 10);
    left(1000, 5);
    forward(1000, 20);
    pompomClawClose();
    wait(250);
    forward(1000, 25);
    wait(250);
    back(1000, 1);
    right(1000, 15);
    wait(250);
    back(2000, 7);
    wait(250);
    left(1000, 15);
    turnRight(20);
    wait(250);
    pompomClawOpen();
    wait(250);
    forward(1000, 13);
    back(1000, 10);
    left(1000, 10);
    turnRight(2);
    back(1000, 1);
    wait(250);
    potatoArmGrab();
    wait(250);
    potatoClawClose();
    wait(250);
    potatoArmUp();
    wait(250);
    turnRight(40);
    back(1000, 10);
    wait(500);
    potatoClawOpen();
    wait(5000);
    forward(1000, 10);
    left(1000, 20);
    back(1000, 7);
    fryDropOpen();
    left(2000, 75);
    
    return 0;
}

void wait(int time) {
    ao();
    msleep(time);
}

void forward(int speed, double distance) {
    mav(topLeft, speed);
    mav(topRight, -speed);
    mav(bottomLeft, -speed);
    mav(bottomRight, speed);
    msleep(distance/0.00675);
}

void back(int speed, double distance) {
    mav(topLeft, -speed);
    mav(topRight, speed);
    mav(bottomLeft, speed);
    mav(bottomRight, -speed);
    msleep(distance/0.00675);
}

void left(int speed, double distance) {
    mav(topLeft, -speed);
    mav(topRight, -speed);
    mav(bottomLeft, -speed);
    mav(bottomRight, -speed);
    msleep(distance/0.00675);
}

void right(int speed, double distance) {
    mav(topLeft, speed);
    mav(topRight, speed);
    mav(bottomLeft, speed);
    mav(bottomRight, speed);
    msleep(distance/0.00675);
}

void turnLeft(double distance) {
    mav(topLeft, -750);
    mav(topRight, -750);
    mav(bottomLeft, 750);
    mav(bottomRight, 750);
    msleep(distance/0.00675);
}

void turnRight(double distance) {
    mav(topLeft, 750);
    mav(topRight, 750);
    mav(bottomLeft, -750);
    mav(bottomRight, -750);
    msleep(distance/0.00675);
}

void fryDropOpen() {
    set_servo_position(fryDrop, 700);
}

void fryDropClose() {
    set_servo_position(fryDrop, 1600);
}

void potatoArmUp() {
	for(int i = 0; i < 725; i++) {
    	set_servo_position(potatoArm, 200 + i);
        msleep(3);
    }
}

void potatoArmRest() {
    set_servo_position(potatoArm, 2047);
}

void potatoArmGrab() {
    for(int i = 0; i < 1877; i++) {
    	set_servo_position(potatoArm, 2047 - i);
        msleep(3);
    }
}
        
void potatoClawOpen() {
    set_servo_position(potatoClaw, 1800);
}

void potatoClawClose() {
    for(int i = 0; i < 1600; i++) {
    	set_servo_position(potatoClaw, 1800 - i);
        msleep(3);
    }
}

void pompomClawOpen() {
    set_servo_position(pompomClaw, 600);
}

void pompomClawClose() {
    set_servo_position(pompomClaw, 250);
}
