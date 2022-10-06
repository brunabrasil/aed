#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
#include <filesystem>
#include <map>
#include <algorithm>
#include "stop.h"
#include "line.h"
#include "menu.h"
#include "graph.h"

using std::ifstream;
using std::string;
using std::vector;

/**
 * Converts degrees to radian
 * @param degrees Degree in decimal form
 * @return Degree in radian
 */
double radians(double degrees) {
    return degrees * M_PI / 180.0;
}

/**
 * Distance between two locations
 * @param lat1 Latitude of location 1
 * @param lon1 Longitude of location 1
 * @param lat2 Latitude of location 2
 * @param lon2 Longitude of location 1
 * @return Distance between the two locations
 */
double haversine(double lat1, double lon1, double lat2, double lon2) {
    double d_lat = radians(lat2 - lat1);
    double d_lon = radians(lon2 - lon1);
    lat1 = radians(lat1);
    lat2 = radians(lat2);
    double a = pow(sin(d_lat / 2), 2)
             + pow(sin(d_lon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

/**
 * Reads line from file and pushes it to vector
 * @param vec Vector where stops are stored
 * @param filename
 */
void readLineFile(vector<string>& vec, const string& filename) {
    ifstream infile(filename);
    int num_stops;
    infile >> num_stops;
    vec.resize(num_stops);
    for (int i = 0; i < num_stops; ++i) {
        infile >> vec[i];
    }
}

/**
 * Reads file
 * @param path File's path
 * @return Map containing file's contents
 */
std::map<string, vector<vector<string>>> readLineFiles(const string& path) {
    std::map<string, vector<vector<string>>> lines_to_stops;
    for (const auto & file : std::filesystem::directory_iterator(path)) {
        std::stringstream str(file.path().stem().string());

        string temp, line;
        bool is_reverse_direction;
        std::getline(str, temp, '_');
        std::getline(str, line, '_');
        str >> is_reverse_direction;

        if (temp == "line") {
            vector<vector<string>>& vec = lines_to_stops[line];
            vec.resize(2);
            readLineFile(vec[is_reverse_direction], file.path().string());
        }
    }
    return lines_to_stops;
}

/**
 * Reads files in path
 * @tparam T Line or stop
 * @param filename Path to file
 * @return Vector with contents of file
 */
template <typename T>
vector<T> readCSV(const string& filename) {
    vector<T> content;
    ifstream infile(filename);
    if (infile.is_open()) {
        string line, cell;
        std::getline(infile, line);
        const int cells_per_row = (int) std::count(line.begin(), line.end(), ',') + 1;
        vector<string> row(cells_per_row, "");
        while (std::getline(infile, line)) {
            std::stringstream str(line);
            for (int i = 0; i < cells_per_row; ++i) {
                std::getline(str, row[i], ',');
            }
            content.emplace_back(row);
        }
    } else {
        std::cout << "Could not open the file\n";
    }
    return content;
}

/**
 * Main function
 * @return 0
 */
int main() {
    string path = "../dataset/";
    vector<Line> lines = readCSV<Line>(path + "lines.csv");
    vector<Stop> stops = readCSV<Stop>(path + "stops.csv");
    std::map<string, vector<vector<string>>> lines_to_stops = readLineFiles(path);
    Graph<double> graph(stops.size(), true);

    Menu menu;
    menu.printMenu();
    return 0;
}
