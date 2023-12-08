#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <string>


#include "graph.h"
#include "unitTest.h"


using namespace GP_GRAPH;

int main() {


    // INPUTS HERE
    //

    // Graph 1
    // SET VERTICES

    std::vector<int> vertices = {1,2,3,4,5,6,7};

    // SET EDGES
    std::vector<std::pair<int,int>> edges =
            {
                {1,2},{1,3},{2,4},{2,5},
                {3,6},{6,7}
            };

    // Make Graph
    Graph g(vertices,edges);

    // Print Adjacency List
    g.printAdjList();

    // BFS
    g.BFS(1);
    g.printBFSTree(1);



    // Print Shortest Path a and b)

    std::cout << "Shortest Path: " << std::endl;
    g.PrintShortestPath(1,7);



//// Calling Units Tests
//
//
//    std::cout <<std::endl;
//    std::cout << "Unit Test: \n" ;
//
//
//    std:: cout << test_NodeDefaultConstructor() << std::endl;
//
////Testing LinkedList
//    std:: cout << test_LinkedListDefaultConstructor() << std::endl;
//    std:: cout << test_LinkedListAddUniqueNode() << std::endl;
//
//
//
//// Testing Graph
//    std:: cout << test_graphDefaultConstructor() << std::endl;
//    std:: cout << test_graphContructor1() << std::endl;
//    std:: cout << test_graphContructor2() << std::endl;
//    std:: cout << test_graphAddEdge() << std::endl;
//    std:: cout << test_graphAddVertex() << std::endl;
//    std:: cout << test_graphBFS() << std::endl;





    return 0;








}
