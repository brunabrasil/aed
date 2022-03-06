// AED 2021/2022 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [09/01/2022]

#include "graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}


// ----------------------------------------------------------
// Exercicio 3: Algoritmo de Prim
// ----------------------------------------------------------
// TODO
int Graph::prim(int r) {
    MinHeap<int, int> h(nodes.size(), -1);
    for (int i = 1; i <=n; ++i) {
        nodes[i].distance=99999;
        nodes[i].parent=0;
        h.insert(i,nodes[i].distance);
    }
    nodes[r].distance=0;
    h.decreaseKey(r,0);
    while(h.getSize()!=0){
        int u = h.removeMin();
        for(auto v: nodes[u].adj){
            int n = v.dest;
            if(h.hasKey(n) && v.weight < nodes[n].distance){
                nodes[n].parent=u;
                nodes[n].distance=v.weight;
            }
            h.decreaseKey(n,v.weight);
        }
    }
    int ret = 0;
    for(auto x: nodes){
        ret+=x.distance;
    }
    return ret;
}


// ----------------------------------------------------------
// Exercicio 5: Algoritmo de Kruskal
// ----------------------------------------------------------
// TODO
int Graph::kruskal() {
    return 0;
}
