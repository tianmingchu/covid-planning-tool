#include "../catch/catch.hpp"
#include "../graph.h"

TEST_CASE("Graph_insertVertex()") {
    Graph g;
    Vertex v = "illinois";
    g.insertVertex(v);
    REQUIRE(g.getVertices().size() == 1);
    REQUIRE(g.getVertices()[0] == "illinois");
    Vertex v1 = "wisconsin";
    Vertex v2 = "minnesota";
    Vertex v3 = "north dakota";
    g.insertVertex(v1);
    g.insertVertex(v2);
    g.insertVertex(v3);
    REQUIRE(g.getVertices().size() == 4);
    REQUIRE(g.getVertices()[0] == "minnesota");
    REQUIRE(g.getVertices()[1] == "north dakota");
    REQUIRE(g.getVertices()[2] == "wisconsin");
}

TEST_CASE("Graph_test_edges") {
    Graph g;
    Vertex v1 = "illinois";
    Vertex v2 = "wisconsin";
    g.insertVertex(v1);
    g.insertVertex(v2);
    REQUIRE(g.getVertices().size() == 2);
    REQUIRE(g.incidentVertices(v1).size() == 0);
    REQUIRE(g.incidentVertices(v2).size() == 0);
    g.insertEdge(v1, v2, 50000);
    REQUIRE(g.getCasesByEdge(v1, v2) == 50000);
    REQUIRE(g.incidentVertices(v1).size() == 1);
    REQUIRE(g.incidentVertices(v2).size() == 1);
    Vertex v3 = "minnesota";
    g.insertVertex(v3);
    REQUIRE(g.getVertices().size() == 3);
    g.insertEdge(v1, v3, 10000);
    REQUIRE(g.getCasesByEdge(v1, v3) == 10000);
    REQUIRE(g.incidentVertices(v1).size() == 2);
    REQUIRE(g.incidentVertices(v3).size() == 1);
}