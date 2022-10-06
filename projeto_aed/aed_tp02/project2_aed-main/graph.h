#pragma once

#include "minHeap.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;

/**
 * Graph used to store lines and stops
 * @tparam T Line or stop
 */
template <class T>
class Graph {
    struct Edge {
        int destination;                 /*!< Destination node */
        T weight;                        /*!< An integer weight */
        string line;                     /*!< Existing line */
    };

    struct Node {
        list<Edge> adjacent;             /*!< The list of outgoing edges (to adjacent nodes) */
        int distance;                    /*!< Distance between nodes */
        int predecessor;                 /*!< Predecessor for current node */
        bool hasBeenVisited;             /*!< Node has been accessed */
        string name;                     /*!< Stop name */
    };

    int numNodes;                        /*!< Graph size (vertices are numbered from 1 to n) */
    bool isDirected;                     /*!< false: undirect; true: directed */
    vector<Node> nodes;                  /*!< The list of nodes being represented */

public:

    explicit Graph(unsigned long numNodes, bool isDirected) :
        numNodes(numNodes), isDirected(isDirected), nodes(numNodes + 1) {}

    void addEdge(int src, int dest, T weight = 1);

    T dijkstraDistance(int a, int b);

    list<int> dijkstraPath(int a, int b);
};