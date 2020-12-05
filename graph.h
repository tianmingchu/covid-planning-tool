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

class Graph {
    public: 
        void insertVertex(Vertex v);
        //void removeVertex(Vertex v);
        void insertEdge(Vertex v1, Vertex v2, int cases);
        //void removeEdge(Vertex v1, Vertex v2);
        vector<Vertex> incidentVertices(Vertex v);
        vector<Vertex> getVertices();
    private:
        /*
        vector<vector<bool>> edge_matrix_;
        map<Vertex, int> vertices_;
        vector<Vertex> vertices_vector_;*/

        mutable unordered_map<Vertex, unordered_map<Vertex, Edge>> adjacency_list;
};