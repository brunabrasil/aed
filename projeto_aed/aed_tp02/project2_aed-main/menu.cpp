#include "menu.h"
#include <limits>

Menu::Menu() = default;

void Menu::printMenu() {
    unsigned short answer;
    bool error = true;

    do {
        std::cout <<
                  "-----------------------------" << std::endl <<
                  "|        Transports         |" << std::endl <<
                  "|Departure Location:     1  |" << std::endl <<
                  "|Destination Location:   2  |" << std::endl <<
                  "|Calculate trajectory:   3  |" << std::endl <<
                  "|Exit:                   0  |" << std::endl <<
                  "-----------------------------" << std::endl;
        std::cin >> answer;
        if (std::cin.eof()) {
            exit(0);
        }
        if (!std::cin.good()) {
            std::cout << "Sadly that's not an option. Please choose another one." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            continue;
        }
        switch (answer) {
            case 1:
                writeLocation(1);
                error = false;
                break;
            case 2:
                writeLocation(2);
                error = false;
                break;
            case 3:
                error = false;
                break;
            case 0:
                exit(0);
            default:
                std::cout << "Sadly that's not an option. Please choose another one." << std::endl;
        }
    } while (error);
}

void Menu::writeLocation(int choice) {
    unsigned short answer;
    bool error = true;

    do {
        std::cout << "Press 1 if location is in coordinates, 2 if it´s stops and 3 if you wish to return to menu." << std::endl;
        std::cin >> answer;

        if (!std::cin.good()) {
            std::cout << "Sadly that's not an option. Please choose another one." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            continue;
        }
        switch (answer) {
            case 1: {
                writeCoordinates(choice);
                error = false;
                break;
            }
            case 2: {
                writeStops(choice);
                error = false;
                break;
            }
            case 3: {
                error = false;
                break;
            }
            default: std::cout << "Invalid input.";
        }
    } while (error);
    printMenu();
}

void Menu::writeCoordinates(int choice) {
    double latitude, longitude;
    bool error = true;

    while (error) {
        std::cout << "Write latitude: ";
        std::cin >> latitude;
        std::cout << std::endl;
        std::cout << "Write longitude: ";
        std::cin >> longitude;
        std::cout << std::endl;

        if (!std::cin.good()) {
            std::cout << "Invalid input." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            continue;
        }
        else error = false;
    }
    if (choice == 1) {
        depCoordinates.first = latitude;
        depCoordinates.second = longitude;
    }
    else if (choice == 2) {
        desCoordinates.first = latitude;
        desCoordinates.second = longitude;
    }
}

void Menu::writeStops(int choice) {
    std::string code;
    bool error = true;

    while (error) {
        std::cout << "Write stop's code: ";
        std::cin >> code;
        std::cout << std::endl;

        if (!std::cin.good()) {
            std::cout << "Invalid input." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            continue;
        }
        else error = false;
    }
    if (choice == 1) depStop = code;
    else if (choice == 2) desStop = code;
}