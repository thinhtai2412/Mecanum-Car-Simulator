#include "Motor.h"
#include <cmath>

Motor::Motor()
    : name("unnamed"), currentspeed(0), ID(0), direction(0)
{
    // Nothing else to do.
}

Motor::Motor(const std::string& motorName)
    : name(motorName), currentspeed(0), ID(0), direction(0)
{
   // Nothing else to do.
}

void Motor::setspeed(int newSpeedPercent)
{
    // TODO:
    // 1) Clamp newSpeedPercent to the range [-100, 100] using if/else.
    // 2) Store the clamped value in speedPercent.

    // Example style (you should complete it):
    if (newSpeedPercent > 100) {
        currentspeed = 100;
    } else if (newSpeedPercent < -100) {
        currentspeed = -100;
    } else {
        currentspeed = newSpeedPercent;
    }
}

Car::Car()
    : frontLeft("front-left"),
    frontRight("front-right"),
    rearLeft("rear-left"),
    rearRight("rear-right"),
    x(0), y(0), direction(0)
{
    // Constructor body can be empty once the member-initialization list is complete.
}

void Car::updatePose(int dx, int dy, int direction) 
{
    x += dx;
    y += dy;
    direction += 1;
}

void Car::moveForward(int speed){
    frontLeft.setspeed(50);
    frontRight.setspeed(50);
    rearLeft.setspeed(50);
    rearRight.setspeed(50);
}

void Car::moveBackward(int speed){
    frontLeft.setspeed(-50);
    frontRight.setspeed(-50);
    rearLeft.setspeed(-50);
    rearRight.setspeed(-50);
}

void Car::turnLeft(int speed){
    frontLeft.setspeed(50);
    frontRight.setspeed(0);
    rearLeft.setspeed(50);
    rearRight.setspeed(0);
}

void Car::turnRight(int speed){
    frontLeft.setspeed(0);
    frontRight.setspeed(50);
    rearLeft.setspeed(0);
    rearRight.setspeed(50);
}

int Car::getX() const {
    return x;
}

int Car::getY() const {
    return y;
}

int Car::getDirection() const {
    return direction;
}

void Car::stopAll() {
    frontLeft.setspeed(0);
    frontRight.setspeed(0);
    rearLeft.setspeed(0);
    rearRight.setspeed(0);
}