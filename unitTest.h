//
// Created by Khalid Khan on 12/7/23.
//

#ifndef GRAPH_UNITTEST_H
#define GRAPH_UNITTEST_H

#include <iostream>
#include "graph.h"

using namespace GP_GRAPH;

inline
// Unit Test for LinkedList
bool test_LinkedListDefaultConstructor() {
    LinkedList l;

    return true == (l.getHead() == nullptr);
}


// Unit Test for Graphs

bool test_graphDefaultConstructor() {
    Graph g;

    return true == (g.getSize() == 0);


}
// Unit Test for Graphs constructor with vertices and edges
bool test_graphContructor1() {
    std::vector<std::pair<int,int>> edges = {{1,2},{1,4},{1,5},{2,3},{2,7},{3,4},{3,5},{2,6},{6,7}};
    std::vector<int> vertices = {1,2,3,4,5,6,7};

    Graph g(vertices,edges);

    return true == (g.getSize() == 7);
}


// Unit Test for Graphs constructor with edges
bool test_graphContructor2() {
    std::vector<std::pair<int,int>> edges = {{1,2},{1,4},{1,5},{2,3},{2,7},{3,4},{3,5},{2,6},{6,7}};

    Graph g(edges);

    return true == (g.getSize() == 7);
}


// Unit Test for Graphs addEdge
bool test_graphAddEdge() {
    std::vector<std::pair<int,int>> edges = {{1,2},{1,4},{1,5},{2,3},{2,7},{3,4},{3,5},{2,6},{6,7}};
    std::vector<int> vertices = {1,2,3,4,5,6,7};

    Graph g(vertices,edges);

    g.addEdge(1,3);

    return true == (g.getSize() == 7);
}


// Unit Test for Graphs addVertex
bool test_graphAddVertex() {
    std::vector<std::pair<int,int>> edges = {{1,2},{1,4},{1,5},{2,3},{2,7},{3,4},{3,5},{2,6},{6,7}};
    std::vector<int> vertices = {1,2,3,4,5,6,7};

    Graph g(vertices,edges);

    g.addNode(8);
    g.addNode(8);

    return true == (g.getSize() == 8);
}


// Unit Test for Graphs BFS
bool test_getParentID(){
    std::vector<std::pair<int,int>> edges = {{1,2},{1,4},{1,5},{2,3},{2,7},{3,4},{3,5},{2,6},{6,7}};
    std::vector<int> vertices = {1,2,3,4,5,6,7};

    Graph g(vertices,edges);

    g.BFS(2);

    return true == (g.getParentID(7 - 1) == 2);
}


// Unit Test for Graphs BFS
bool test_graphBFS() {
    std::vector<std::pair<int,int>> edges = {{1,2},{1,4},{1,5},{2,3},{2,7},{3,4},{3,5},{2,6},{6,7}};
    std::vector<int> vertices = {1,2,3,4,5,6,7};

    Graph g(vertices,edges);

    g.BFS(2);

    return true == (g.getParentID(7 - 1) == 2);
}











#endif //GRAPH_UNITTEST_H
