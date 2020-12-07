#pragma once

#include <string>

using std::string;

typedef string Vertex;

class Edge {
    public:
        Edge();
        Edge(Vertex s, Vertex d, int cases);
        Vertex getSource() const;
        Vertex getDestination() const;
        int getCases() const;
    private:
        Vertex source_;
        Vertex destination_;
        int cases_;
};