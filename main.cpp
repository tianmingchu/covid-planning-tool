#include "graph.h"
int main() {
    Graph g;
    Vertex v1 = "illinois";
    Vertex v2 = "wisconsin";
    Vertex v3 = "minnesota";
    Vertex v4 = "north dakota";
    g.insertVertex(v1);
    g.insertVertex(v2);
    g.insertVertex(v3);
    g.insertVertex(v4);
    g.insertEdge(v1, v2, 50);
    g.insertEdge(v2, v3, 50);
    g.insertEdge(v3, v4, 50);
    g.shortestPath(v1);
}