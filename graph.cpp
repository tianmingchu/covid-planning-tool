#include "graph.h"
#include "edge.h"
#include <map>

void Graph::insertVertex(Vertex v) {
    /*vector<bool> vect(vertices_.size() + 1, false); 
    edge_matrix_.push_back(vect);
    for (unsigned i = 0; i < vertices_.size(); i++)
        edge_matrix_[i].push_back(false);
    int i = vertices_.size();
    vertices_.insert({v, i});
    vertices_vector_.push_back(v);
    */
    adjacency_list[v] = unordered_map<Vertex, Edge>();
}

void Graph::insertEdge(Vertex v1, Vertex v2, int cases) {
    /*
    int x = vertices_[v1];
    int y = vertices_[v2];
    edge_matrix_[x][y] = true;
    edge_matrix_[y][x] = true;
    */
    if(adjacency_list.find(v1)!= adjacency_list.end() 
    && adjacency_list[v1].find(v2)!= adjacency_list[v1].end())
    {
        //edge already exit
        return;
    }

    if(adjacency_list.find(v1)==adjacency_list.end())
    {
        adjacency_list[v1] = unordered_map<Vertex, Edge>();
    }
        //source vertex exists
    Edge edge (v1, v2, cases);
    adjacency_list[v1][v2] = edge;
    
    if(adjacency_list.find(v2)== adjacency_list.end()) {
        adjacency_list[v2] = unordered_map<Vertex, Edge>();
    }
    adjacency_list[v2][v1] = Edge(v1, v2, cases);
    
    
}

vector<Vertex> Graph::incidentVertices(Vertex v) {
    /*
    vector<Vertex> incidentVertices;
    for (unsigned i = 0; i < edge_matrix_.size(); i++) {
        if (edge_matrix_[i][vertices_[v]]) {
            incidentVertices.push_back(vertices_vector_[i]);
            break;
        }
    }
    return incidentVertices;
    */
    auto lookup = adjacency_list.find(v);
    
    if(lookup == adjacency_list.end())
        return vector<Vertex>();

    else
    {
        vector<Vertex> vertex_list;
        unordered_map <Vertex, Edge> & map = adjacency_list[v];
        for (auto it = map.begin(); it != map.end(); it++)
        {
            vertex_list.push_back(it->first);
        }
        return vertex_list;
    }

}

vector<Vertex> Graph::getVertices() {
    vector<Vertex> ret;

    for(auto it = adjacency_list.begin(); it != adjacency_list.end(); it++)
    {
        ret.push_back(it->first);
    }

    return ret;
}