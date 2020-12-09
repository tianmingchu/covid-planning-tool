#include "graph.h"
#include "readFromFile.cpp"

int main() {
    
    Graph g = createGraph("united_states_covid19_cases_and_deaths_by_state.csv"); // create weighted graph based on data
    g.BFS("Illinois"); // prints BFS traversal of graph
    g.printGraph(); // prints all vertices, neighbors, & edges
    
    
    //nayonika's stuff
    /*
    Graph g;
    Vertex v1 = "illinois";
    Vertex v2 = "wisconsin";
    Vertex v3 = "minnesota";
    Vertex v4 = "north dakota";
    Vertex v5 = "south dakota";
    g.insertVertex(v1);
    g.insertVertex(v2);
    g.insertVertex(v3);
    g.insertVertex(v4);
    g.insertVertex(v5);
    g.insertEdge(v1, v2, 300);
    g.insertEdge(v2, v3, 200);
    g.insertEdge(v3, v4, 50);
    g.insertEdge(v4, v5, 50);
    g.insertEdge(v2, v5, 400);
    g.insertEdge(v1, v5, 100);
    std::cout << g.landmarkPath(v1, v5, v3) << std::endl;
    */
}