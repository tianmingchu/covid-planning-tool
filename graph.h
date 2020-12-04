#pragma once

#include <vector>
#include <string>
#include <utility>
#include <map>

using std::string;
using std::vector;
using std::pair;
using std::map;

class Graph {
    public: 
        void insertVertex(Vertex v);
        //void removeVertex(Vertex v);
        void insertEdge(Vertex v1, Vertex v2);
        //void removeEdge(Vertex v1, Vertex v2);
        vector<Vertex> incidentVertices(Vertex v);
        bool areAdjacent(Vertex v1, Vertex v2);
    private:
        class Vertex {
            public: 
                Vertex(string name, int cases);
                double getName();
                int getCases();
            private:
                string name_;
                int cases_;
        };
        /*
        class Edge {
            public:
                Edge(Vertex v1, Vertex v2);
                pair<Vertex, Vertex> getVertices();
            private:
                pair<Vertex, Vertex> vertices_;
        };
        */
        vector<vector<bool>> edge_matrix_;
        map<Vertex, int> vertices_;
        vector<Vertex> vertices_vector_;
};