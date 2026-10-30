#include <iostream>
#include "Motor.h"

int main() {
    Car car;

    char cmd = ' ';
    double value = 0.0;

    while (true) {
        std::cout << "Commands:\n";
        std::cout << "  w d  : move forward   by d units\n";
        std::cout << "  s d  : move backward  by d units\n";
        std::cout << "  a d  : turn left    by d units\n";
        std::cout << "  d d  : turn right   by d units\n";
        std::cout << "  x    : stop all motors\n";
        std::cout << "  z    : quit\n\n";

        std::cout << "Enter command: ";
        std::cin >> cmd;

        if (cmd == 'z') {
            break;
        }

        if (cmd == 'x') {
            car.stopAll();
            continue;
        }

        std::cout << "Enter value: ";
        std::cin >> value;

        switch (cmd) {
        case 'w':
            car.moveForward(value);
            break;
        case 's':
            car.moveBackward(value);
            break;
        case 'a':
            car.turnLeft(value);
            break;
        case 'd':
            car.turnRight(value);
            break;
        default:
            std::cout << "Unknown command.\n";
            break;
        }
    }
}