#include "graph.h"
#include "readFromFile.cpp"

int main() {
    Graph g = createGraph("united_states_covid19_cases_and_deaths_by_state.csv"); // create weighted graph based on data
    g.BFS("Illinois"); // prints BFS traversal of graph
    g.printGraph(); // prints all vertices, neighbors, & edges
}