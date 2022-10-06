#pragma once

#include <string>
#include <utility>
#include <vector>

/**
 * Bus line
 */
class Line {
public:
    /**
     * Class constructor
     * @param code Code of the line
     * @param name Name of the line
     */
    Line(std::string code, std::string name) : code(std::move(code)), name(std::move(name)) {}

    /**
     * Class constructor
     * @param vec Vector containing all lines and respective name and code
     */
    explicit Line(std::vector<std::string> vec) : Line(vec[0], vec[1]) {}

    /**
     * Getter for line's code
     * @return code
     */
    [[nodiscard]] const std::string &getCode() const {
        return code;
    }

    /**
     * Getter for name's code
     * @return name
     */
    [[nodiscard]] const std::string &getName() const {
        return name;
    }

    /**
     * Overloaded operator ==
     * @param rhs Line to be compared to
     * @return Boolean dependant on whether lines are the same or not
     */
    bool operator==(const Line &rhs) const {
        return code == rhs.code;
    }

private:
    std::string code;           /*!< Line's code */
    std::string name;           /*!< Line's name */

};