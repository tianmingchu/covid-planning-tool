#include "graph.h"
#include "edge.h"
#include <map>
#include <queue>

void Graph::BFS(Vertex v) {
    unordered_map<Vertex, bool> visited;
    vector<Vertex> vertices = this->getVertices();
    for (auto i = vertices.begin(); i != vertices.end(); ++i) {  // keep track of vertices visited
        visited.insert(pair<Vertex, bool>(*i, false));
    }

    std::list<Vertex> queue;
    visited[v] = true;
    queue.push_back(v);
    cout << endl;
    while (!queue.empty()) {
        v = queue.front();
        cout << v << endl;
        queue.pop_front();
        unordered_map<Vertex, Edge> adjacentVertices = adjacency_list[v];
        for (auto i = adjacentVertices.begin(); i != adjacentVertices.end(); ++i) {
            if (!visited[i->first]) {   // add all unvisited adjacent vertices to queue
                visited[i->first] = true;
                queue.push_back(i->first);
            }
        }
    }
    cout << endl;
}

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

int Graph::getCasesByEdge(Vertex v1, Vertex v2) {
    return adjacency_list[v1][v2].getCases();
}

/*vector<vector<Vertex>>*/void Graph::shortestPath(Vertex v1) {
    
    std::map<Vertex,int> d;
    std::map<Vertex, Vertex> p;
    for (Vertex v : getVertices()) {
        d[v] = INT_MAX;
        p[v] = "NONE";
    }
    d[v1] = 0;
    std::priority_queue<iPair> q;
    q.push({0, v1});
    Graph t;

    while (!q.empty()) {
        Vertex v = q.top().second;
        q.pop();

        for (Vertex v2 : incidentVertices(v)) {
            int cases = getCasesByEdge(v, v2);

            if (d[v2] > d[v] + cases) {
                d[v2] = d[v] + cases;
                p[v2] = v;
                q.push({(-1 * d[v2]), v2});
            }
        }
    }
    std::cout<<"hiiiiii"<<std::endl;
    for (Vertex v : getVertices()) 
        std::cout<<"Vertex: "<<v<<"   Distance from source: "<<d[v]<<"   Previous vertex: "<<p[v]<<std::endl;
}

void Graph::printGraph() {
    cout << endl;
    for (auto i = adjacency_list.begin(); i != adjacency_list.end(); ++i) {
        cout << i->first << endl;
        for (auto it = i->second.begin(); it != i->second.end(); ++it) {
            std::stringstream ss;
            ss << it->first;
            string vertexColumn = "        => " + ss.str();
            vertexColumn += " ";
            cout << std::left << std::setw(30) << vertexColumn;
            cout << std::left << "case rate per 100k: " << it->second.getCases() << endl;
        }
        cout << endl;
    }
}