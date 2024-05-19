/*
 * name: elian iluk
    * id: 214787483
    * email: elian10119@gmail.com
 */

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"


using namespace std;
#include <sstream>
TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.printGraph() == "[0 2 1]\n[2 0 3]\n[1 3 0]\n");
    ariel::Graph g4=g3+g1;
    CHECK(g4.printGraph() == "[0 3 1]\n[3 0 4]\n[1 4 0]\n");
    ariel::Graph g5=g4+g2;
    CHECK(g5.printGraph() == "[0 4 2]\n[4 0 6]\n[2 6 0]\n");
}

TEST_CASE("Test graph dedction")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 - g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, -1},
        {0, 0, -1},
        {-1, -1, 0}};
    CHECK(g3.printGraph() == "[0 0 -1]\n[0 0 -1]\n[-1 -1 0]\n");
    ariel::Graph g4=g3-g1;
    CHECK(g4.printGraph() == "[0 -1 -1]\n[-1 0 -2]\n[-1 -2 0]\n");
    ariel::Graph g5=g4-g2;
    CHECK(g5.printGraph() == "[0 -2 -2]\n[-2 0 -4]\n[-2 -4 0]\n");
    // ariel::Graph g6;
    // vector<vector<int>> graph2 = {
    //     {0, 1, 0, 0, 1},
    //     {1, 0, 1, 0, 0},
    //     {0, 1, 0, 1, 0},
    //     {0, 0, 1, 0, 1},
    //     {1, 0, 0, 1, 0}};
    // g6.loadGraph(graph2);
    // ariel::Graph g7=g6-g1;
    // CHECK(g7.printGraph() == "[0 0 0 0 1]\n[0 0 0 0 0]\n[0 0 0 1 0]\n[0 0 1 0 1]\n[1 0 0 1 0]\n");
    //std::cout<<g7.printGraph();
}

TEST_CASE("Test graph multiplication by number")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    g1 *= 2;
    CHECK(g1.printGraph() == "[0 2 0]\n[2 0 2]\n[0 2 0]\n");
    g2 *= 3;
    CHECK(g2.printGraph() == "[0 3 3]\n[3 0 6]\n[3 6 0]\n");
    g1 *= 0;
    CHECK(g1.printGraph() == "[0 0 0]\n[0 0 0]\n[0 0 0]\n");
}

TEST_CASE("Test graph division by number")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    g1 /= 2;
    CHECK(g1.printGraph() == "[0 0 0]\n[0 0 0]\n[0 0 0]\n");
    g2 /= 3;
    CHECK(g2.printGraph() == "[0 0 0]\n[0 0 0]\n[0 0 0]\n");
    g2.loadGraph(weightedGraph);
    g2 /= 2;
    CHECK(g2.printGraph() == "[0 0 0]\n[0 0 1]\n[0 1 0]\n");
    // g1/=0;
    // CHECK(g1.printGraph() == "[0 0 0]\n[0 0 0]\n[0 0 0]\n");
}

TEST_CASE("Test graph addition and store it in g1")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    g1 += g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g1.printGraph() == "[0 2 1]\n[2 0 3]\n[1 3 0]\n");
}

TEST_CASE("Test graph subtraction and store it in g1")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    g1 -= g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, -1},
        {0, 0, -1},
        {-1, -1, 0}};
    CHECK(g1.printGraph() == "[0 0 -1]\n[0 0 -1]\n[-1 -1 0]\n");
}

TEST_CASE("Test graph unary plus")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = +g1;
    CHECK(g3.printGraph() == "[0 1 0]\n[1 0 1]\n[0 1 0]\n");
    ariel::Graph g4 = +g2;
    CHECK(g4.printGraph() == "[0 1 1]\n[1 0 2]\n[1 2 0]\n");
}

TEST_CASE("Test graph unary minus")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = -g1;
    CHECK(g3.printGraph() == "[0 -1 0]\n[-1 0 -1]\n[0 -1 0]\n");
    ariel::Graph g4 = -g2;
    CHECK(g4.printGraph() == "[0 -1 -1]\n[-1 0 -2]\n[-1 -2 0]\n");
}

TEST_CASE("Test graph comparison")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    CHECK((g1 > g2) == false);
    CHECK((g1 < g2) == true);
    CHECK((g1 == g2) == false);
    CHECK((g1 != g2) == true);
    CHECK((g1 >= g2) == false);
    CHECK((g1 <= g2) == true);

    ariel::Graph g3;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g3.loadGraph(graph2);
    CHECK((g1 > g3) == false);
    CHECK((g1 < g3) == true);
    CHECK((g1 == g3) == false);
    CHECK((g1 != g3) == true);
    CHECK((g1 >= g3) == false);
    CHECK((g1 <= g3) == true);
}

TEST_CASE("Test graph increment and decrement")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ++g1;
    CHECK(g1.printGraph() == "[0 2 0]\n[2 0 2]\n[0 2 0]\n");
    --g2;
    CHECK(g2.printGraph() == "[0 0 0]\n[0 0 1]\n[0 1 0]\n");
    g1++;
    CHECK(g1.printGraph() == "[0 3 0]\n[3 0 3]\n[0 3 0]\n");
    g2--;
    CHECK(g2.printGraph() == "[0 0 0]\n[0 0 0]\n[0 0 0]\n");
}


TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    CHECK(g4.printGraph() == "[0 0 2]\n[1 0 1]\n[1 0 0]\n");
}


TEST_CASE("print graph")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    std::stringstream ss;
    ss << g1;
    CHECK(ss.str() == "0 1 0 \n1 0 1 \n0 1 0 \n");
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}

