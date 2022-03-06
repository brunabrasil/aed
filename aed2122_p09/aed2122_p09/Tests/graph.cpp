// AED 2021/2022 - Aula Pratica 09
// Pedro Ribeiro (DCC/FCUP) [03/01/2022]

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

// Depth-First Search: example implementation
int Graph::dfs(int v) {
    cout << v << " "; // show node order
    int count = 1;
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            count += dfs(w);
    }
    return count;
}

// Depth-First Search: example implementation
void Graph::bfs(int v) {
    for (int v=1; v<=n; v++) nodes[v].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        cout << u << " "; // show node order
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
}

// ----------------------------------------------------------
// Exercicio 1: Introdução a uma classe simplificada de grafos
// ----------------------------------------------------------

// ..............................
// a) Contando diferentes somas de pares
// TODO

int Graph::outDegree(int v) {
    if(v<1 || v>n){
        return -1;
    }
    else return nodes[v].adj.size();
}

// ----------------------------------------------------------
// Exercicio 2: Componentes conexos
// ----------------------------------------------------------

// ..............................
// a) Contando componentes conexos
// TODO

int Graph::connectedComponents() {
    int count = 0;
    for(int i =1; i<=n;i++){
        if(!nodes[i].visited){
            count++;
            dfs(i);
        }
    }
    return count;
}

// ..............................
// b) Componente gigante
// TODO
int Graph::giantComponent() {
    int m = 0;
    for(int i =1 ; i<=n; i++){
        if(!nodes[i].visited){
            m = max(m, dfs(i));
        }
    }
    return m;
}


// ----------------------------------------------------------
// Exercicio 3: Ordenacao topologica
// ----------------------------------------------------------
// TODO

void Graph::dfsTopo(int v, list<int>& order) {
    nodes[v].visited = true;
    for(auto e: nodes[v].adj){
        int w = e.dest;
        if(!nodes[w].visited)
            dfsTopo(w, order);
    }
    order.push_front(v);
}

list<int> Graph::topologicalSorting() {
    list<int> order;
    for(int i =1; i<=n;i++)
        nodes[i].visited=false;
    for(int i =1; i<=n;i++){
        if(!nodes[i].visited)
            dfsTopo(i, order);
    }
    return order;
}

// ----------------------------------------------------------
// Exercicio 4: Distancias em grafos nao pesados
// ----------------------------------------------------------

// ..............................
// a) Distancia entre dois nos
// TODO

int Graph::distance(int a, int b) {
    if(a==b) return 0;
    for(int i=1; i<=n; i++){
        nodes[i].distance=-1;
    }
    bfsDist(a);
    return nodes[b].distance;

}
void Graph::bfsDist(int v){
    nodes[v].distance=0;
    for (int i = 1; i <= n; ++i) {
        nodes[i].visited = false;
    }
    queue<int> q; //unvisited nodes
    q.push(v);
    nodes[v].visited= true;
    while (!q.empty()){ //enquanto ainda ha nodes nao visitados
        int u = q.front();
        q.pop();
        cout<<u<<" "; //só para visualizar
        for(auto e: nodes[u].adj){
            int w=e.dest;
            if(!nodes[w].visited){
                q.push(w);
                nodes[w].visited = true;
                nodes[w].distance=nodes[u].distance+1;
            }
        }
    }
}
// ..............................
// b) Diametro
// TODO

int Graph::diameter() {
    if(connectedComponents()>1)
        return -1;
    else{
        bfsDist(1);
        int m = 0;
        for (int i = 1; i <=n ; ++i) {
            m=max(nodes[i].distance,m);
        }
        return m;
    }

}
// ----------------------------------------------------------
// Exercicio 5: To or not be… a DAG!
// ----------------------------------------------------------
// TODO
bool Graph::hasCycle() {
    for (int i = 1; i <= n; ++i) {
        nodes[i].color = "white";
    }
    cycleDfs(1);
}

bool Graph::cycleDfs(int v){
    nodes[v].color="gray";
    for (auto e: nodes[v].adj) {
        int w=e.dest;
        if(nodes[w].color=="gray") return true;
        else if(nodes[w].color=="white")
            return cycleDfs(w);
    }
    nodes[v].color="black";
    return false;
}
