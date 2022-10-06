#pragma once

#include <string>
#include <utility>
#include <vector>

/**
 * Bus stop
 */
class Stop {
public:
    /**
     * Constructor of class
     * @param code Stop's code
     * @param name Stop's name
     * @param zone Stop's zone
     * @param latitude Stop's latitude
     * @param longitude Stop's longitude
     */
    Stop(std::string  code, std::string  name, std::string  zone, double latitude, double longitude)
            : code(std::move(code)), name(std::move(name)), zone(std::move(zone)), latitude(latitude), longitude(longitude) {}

    /**
    * Class constructor
    * @param vec Vector containing stop's data
    */
    explicit Stop(std::vector<std::string> vec)
            : Stop(vec[0], vec[1], vec[2], std::stod(vec[3]), std::stod(vec[4])) {}

    /**
    * Getter for stop's code
    * @return stop's code
    */
    [[nodiscard]] const std::string &getCode() const {
        return code;
    }

    /**
    * Getter for stop's name
    * @return stop's name
    */
    [[nodiscard]] const std::string &getName() const {
        return name;
    }

    /**
    * Getter for stop's zone
    * @return stop's zone
    */
    [[nodiscard]] const std::string &getZone() const {
        return zone;
    }

    /**
    * Getter for stop's latitude
    * @return stop's latitude
    */
    [[nodiscard]] double getLatitude() const {
        return latitude;
    }

    /**
    * Getter for stop's longitude
    * @return stop's longitude
    */
    [[nodiscard]] double getLongitude() const {
        return longitude;
    }

    /**
     * Overloaded operator ==
     * @param rhs Second stop
     * @return true if stops are the same, false otherwise
     */
    bool operator==(const Stop &rhs) const {
        return code == rhs.code;
    }

private:
    std::string code;       /*!< Stop's code */
    std::string name;       /*!< Stop's name */
    std::string zone;       /*!< Stop's zone */
    double latitude;        /*!< Stop's latitude */
    double longitude;       /*!< Stop's longitude */
};
