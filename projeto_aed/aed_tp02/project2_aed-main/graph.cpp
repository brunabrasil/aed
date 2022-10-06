#include "graph.h"
#include <limits>

// Add edge from source to destination with a certain weight
template<class T>
void Graph<T>::addEdge(int src, int dest, T weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adjacent.push_back({dest, weight});
    if (!isDirected) nodes[dest].adjacent.push_back({src, weight});
}


// ----------------------------------------------------------
// 1) Algoritmo de Dijkstra e caminhos mais curtos
// ----------------------------------------------------------

// ..............................
// a) Distância entre dois nós
template<class T>
T Graph<T>::dijkstraDistance(int a, int b) {
    MinHeap<int, int> heap(nodes.size(), -1);
    for(int i = 1; i < nodes.size(); i++){
        nodes[i].distance = numeric_limits<int>::max();
        nodes[i].hasBeenVisited = false;
        heap.insert(i, numeric_limits<int>::max());
    }
    nodes[a].distance = 0;
    nodes[a].predecessor = a;
    heap.decreaseKey(a, 0);
    while(heap.getSize() != 0){
        int u = heap.removeMin();
        nodes[u].hasBeenVisited = true;
        for(const auto& edge : nodes[u].adjacent){
            int v = edge.destination;
            if(!nodes[v].hasBeenVisited && nodes[u].distance + edge.weight < nodes[v].distance) {
                int newWeight = nodes[u].distance + edge.weight;
                nodes[v].distance = newWeight;
                nodes[v].predecessor = u;
                heap.decreaseKey(v, newWeight);
            }
        }
    }
    if (nodes[b].distance == numeric_limits<int>::max()) return -1;
    else return nodes[b].distance;
}

// ..............................
// b) Caminho mais curto entre dois nós
template<class T>
list<int>  Graph<T>::dijkstraPath(int a, int b) {
    list<int> path;
    dijkstra_distance(a, b);
    path.push_front(b);
    do {
        if(nodes[b].predecessor == b) {
            path.clear();
            break;
        }
        b = nodes[b].predecessor;
        path.push_front(b);
    } while(b != a);
    return path;
}
