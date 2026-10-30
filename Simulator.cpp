#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <cmath>

#include "Motor.h"

// Size of the "map" shown in the console.
static const int MAP_WIDTH  = 21;
static const int MAP_HEIGHT = 21;

// Convert world coordinates (x, y) to map indices.
// We assume the world origin (0,0) is at the center of the map.
void worldToMap(double x, double y, int& outRow, int& outCol)
{
    int centerRow = MAP_HEIGHT / 2;
    int centerCol = MAP_WIDTH / 2;

    // y grows "up", rows grow "down", so row decreases when y increases.
    outRow = centerRow - static_cast<int>(std::round(y));
    outCol = centerCol + static_cast<int>(std::round(x));
}

// Draw a simple ASCII map with the car at its current position.
void drawMap(const Car& car) {
    int carRow = 0;
    int carCol = 0;
    worldToMap(car.getX(), car.getY(), carRow, carCol);

    // Clear screen (simple portable trick).
    std::cout << "\x1B[2J\x1B[H";

    std::cout << "Mecanum Car Visualizer\n";
    std::cout << "----------------------\n";
    std::cout << "Pose: (x = " << car.getX()
              << ", y = " << car.getY();
    Motor fl = car.getFrontLeftMotor();
    Motor fr = car.getFrontRightMotor();
    Motor rl = car.getRearLeftMotor();
    Motor rr = car.getRearRightMotor();

    std::cout << "\nMap Legend: C = car, . = empty\n\n";

    for (int row = 0; row < MAP_HEIGHT; ++row) {
        for (int col = 0; col < MAP_WIDTH; ++col) {
            if (row == carRow && col == carCol) {
                std::cout << 'C';
            } else {
                std::cout << '.';
            }
        }
        std::cout << "\n";
    }

    std::cout << "\n";
}

void interactiveMode()
{
    Car car;

    char cmd = ' ';
    double value = 0.0;

    while (true) {
        drawMap(car);
        std::cout << "Commands:\n";
        std::cout << "  w d  : move forward   by d units\n";
        std::cout << "  s d  : move backward  by d units\n";
        std::cout << "  a d  : turn left    by d units\n";
        std::cout << "  d d  : turn right   by d units\n";
        std::cout << "  x    : stop all motors\n";
        std::cout << "  z    : quit\n\n";

        std::cout << "Enter command: ";
        std::cin >> cmd;

        if (!std::cin) {
            return;
        }

        if (cmd == 'z') {
            break;
        }

        if (cmd == 'x') {
            car.stopAll();
            continue;
        }

        std::cout << "Enter value: ";
        std::cin >> value;
        if (!std::cin) {
            return;
        }

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

int main()
{
    std::cout << "=== Mecanum Car GUI / Visualizer ===\n\n";
    std::cout << " Run demo path\n";

    Car car;
    interactiveMode();
    std::cout << "Demo finished.\n";
    

    std::cout << "Exiting visualizer.\n";
    return 0;
}