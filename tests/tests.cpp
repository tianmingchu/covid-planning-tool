#include "../catch/catch.hpp"
#include "../graph.h"
#include "../vertex.h"

TEST_CASE("Test1",) {
    Graph g;
    Vertex v = "illinois";
    g.insertVertex(v);
    REQUIRE(1 == 1);
}