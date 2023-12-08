//
// Created by Khalid Khan on 12/7/23.
//

#ifndef GRAPH_UNITTEST_H
#define GRAPH_UNITTEST_H

#include <iostream>
#include "graph.h"

using namespace GP_GRAPH;

// Forward Declarations of Unit Tests


// Testing struct Node
bool test_NodeDefaultConstructor();

//Testing LinkedList
bool test_LinkedListDefaultConstructor();
bool test_LinkedListAddUniqueNode();


// Testing Graph
bool test_graphDefaultConstructor();
bool test_graphContructor1();
bool test_graphContructor2();
bool test_graphAddEdge();
bool test_graphAddVertex();
bool test_graphBFS();





// Unit Test for Node

inline
bool test_NodeDefaultConstructor() {
    Node n;

    return true == (n.vertex == -1 && n.next == nullptr);
}
// Unit Test for LinkedList
bool test_LinkedListDefaultConstructor() {
    LinkedList l;

    return true == (l.getHead() == nullptr);
}


bool test_LinkedListAddUniqueNode(){
    LinkedList l;

    l.addUniqueNode(1);
    l.addUniqueNode(1);
    l.addUniqueNode(2);
    l.addUniqueNode(3);
    l.addUniqueNode(4);
    l.addUniqueNode(4);
    l.addUniqueNode(5);
    l.addUniqueNode(5);
    l.addUniqueNode(6);
    l.addUniqueNode(7);
    l.addUniqueNode(7);


    return true == (l.getSize() == 7);

}

// Unit Test for Graphs

bool test_graphDefaultConstructor() {
    Graph g;

    return true == (g.getSize() == 0);


}
// Unit Test for Graphs constructor with vertices and edges
bool test_graphContructor1() {
    std::vector<std::pair<int,int>> edges =
            {
                {1,2},{1,4},{1,5},
                {2,3},{2,7},{3,4},
                {3,5},{2,6},{6,7}
            };
    std::vector<int> vertices = {1,2,3,4,5,6,7};

    Graph g(vertices,edges);

    return true == (g.getSize() == 7);
}


// Unit Test for Graphs constructor with edges
bool test_graphContructor2() {
    std::vector<std::pair<int,int>> edges =
            {
                 {1,2},{1,4},{1,5},
                 {2,3},{2,7},{3,4},
                 {3,5},{2,6},{6,7}
            };

    Graph g(edges);

    return true == (g.getSize() == 7);
}


// Unit Test for Graphs addEdge
bool test_graphAddEdge() {
    std::vector<std::pair<int,int>> edges =
            {
                {1,2},{1,4},{1,5},
                {2,3},{2,7},{3,4},
                {3,5},{2,6},{6,7}
            };
    std::vector<int> vertices = {1,2,3,4,5,6,7};

    Graph g(vertices,edges);

    g.addEdge(1,3);

    return true == (g.getSize() == 7);
}


// Unit Test for Graphs addVertex
bool test_graphAddVertex() {
    std::vector<std::pair<int,int>> edges =
            {
                {1,2},{1,4},{1,5},
                {2,3},{2,7},{3,4},
                {3,5},{2,6},{6,7}
            };
    std::vector<int> vertices = {1,2,3,4,5,6,7};

    Graph g(vertices,edges);

    g.addNode(8);
    g.addNode(8);

    return true == (g.getSize() == 8);
}


// Unit Test for Graphs BFS
bool test_getParentID(){
    std::vector<std::pair<int,int>> edges =
            {
                {1,2},{1,4},{1,5},
                {2,3},{2,7},{3,4},
                {3,5},{2,6},{6,7}
            };
    std::vector<int> vertices = {1,2,3,4,5,6,7};

    Graph g(vertices,edges);

    g.BFS(2);

    return true == (g.getParentID(7 - 1) == 2);
}


// Unit Test for Graphs BFS
bool test_graphBFS() {
    std::vector<std::pair<int,int>> edges =
            {
                {1,2},{1,4},{1,5},
                {2,3},{2,7},{3,4},
                {3,5},{2,6},{6,7}
            };
    std::vector<int> vertices = {1,2,3,4,5,6,7};

    Graph g(vertices,edges);

    g.BFS(2);

    return true == (g.getParentID(7 - 1) == 2);
}













#endif //GRAPH_UNITTEST_H
