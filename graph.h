#pragma once

#include <list>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <set>
#include <sstream>
#include <vector>
#include <string>
#include <map>

#include "edge.h"

using std::cerr;
using std::cout;
using std::endl;
using std::set;
using std::to_string;
using std::make_pair;
using std::unordered_map;
using std::string;
using std::vector;
using std::pair;
using std::map;

typedef pair<int, Vertex> intVertPair;
class Graph {
    public: 
        /**
         *  Prints out all states via BFS traversal
         */
        void BFS(Vertex v);

        /**
         *  Insert vertex into graph
         */
        void insertVertex(Vertex v);

        /**
         *  Insert edge between two states weighted by
         *  the sum of the cases between them. If a
         *  vertex doesn't exist then one is created
         */
        void insertEdge(Vertex v1, Vertex v2, int cases);

        /**
         *  Returns all vertices adjacent to a vertex
         */
        vector<Vertex> incidentVertices(Vertex v);

        /**
         *  Returns all vertices in the graph
         */
        vector<Vertex> getVertices();

        /**
         *  Returns all vertices in the graph
         */
        bool vertexExists(Vertex v) const;

        /**
         *  
         */
        map<Vertex, vector<Vertex>> shortestPaths(Vertex v1);

        /**
         *  
         */
        string landmarkPath(Vertex source, Vertex dest, Vertex landmark);

        /**
         *  Return case rate between two states
         */
        int getCasesByEdge(Vertex v1, Vertex v2);

        /**
         *  Prints all vertices, their neighbors, and edges
         */
        void printGraph();

    private:
        mutable unordered_map<Vertex, unordered_map<Vertex, Edge>> adjacency_list;
};