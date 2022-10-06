#pragma once

#include <iostream>

/**
 * Menu of program
 */
class Menu {
    std::pair<double, double> depCoordinates, desCoordinates;       /*!< Coordinates of departure and destination location, respectively */
    std::string depStop, desStop;                                   /*!< Name of stop's departure and destination */
public:
    /**
     * Constructor of class
     */
    Menu();
    /**
     * Displays menu
     */
    void printMenu();
    /**
     * Receives input of location
     * @param choice Whether the user inputs destination or departure location
     */
    void writeLocation(int choice);
    /**
     * Receives input of location's coordinates
     * @param choice Whether the user inputs destination or departure location
     */
    void writeCoordinates(int choice);
    /**
     * Receives input of location's stops
     * @param choice Whether the user inputs destination or departure location
     */
    void writeStops(int choice);
};