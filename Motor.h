#ifndef MOTOR_H
#define MOTOR_H

#include <string>

class Motor {
private: 
    int currentspeed;
    std::string name;
    int direction;
    int ID;
public:
    Motor();
    Motor(const std::string& motorName);
    void setspeed(int speed);
    void setDirection();
    void stop();
};

class Car {
private:
    Motor frontLeft;
    Motor frontRight;
    Motor rearLeft;
    Motor rearRight;

    int x;
    int y;
    int direction;

    void updatePose(int dx, int dy, int direction);
public:
    // Default constructor:
    Car();

    //Movemonet Command
    void moveForward(int speed);
    void moveBackward(int speed);
    void turnLeft(int speed);
    void turnRight(int speed);

    // Accessors for the GUI to read the pose.
    int getX() const;
    int getY() const;
    int getDirection() const;

    // Optional accessors that the GUI may use for debug printing.
    Motor getFrontLeftMotor() const;
    Motor getFrontRightMotor() const;
    Motor getRearLeftMotor() const;
    Motor getRearRightMotor() const;

    // Stops all motors
    void stopAll();
};

#endif