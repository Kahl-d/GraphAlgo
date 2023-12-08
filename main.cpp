#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <string>


#include "graph.h"
#include "unitTest.h"


using namespace GP_GRAPH;

int main() {




    std::vector<std::pair<int,int>> edges =
            {
                {1,2},{1,4},{1,5},{2,3},
                {2,7},{3,4},{3,5},{2,6},
                {6,7}
            };
    std::vector<int> vertices = {1,2,3,4,5,6,7};

    Graph g(vertices,edges);

    g.printAdjList();
    g.BFS(2);

    g.PrintShortestPath(2,7);

    std::cout <<std::endl;


    std::cout << "Unit Test: \n" ;


    std:: cout << test_NodeDefaultConstructor() << std::endl;

//Testing LinkedList
    std:: cout << test_LinkedListDefaultConstructor() << std::endl;
    std:: cout << test_LinkedListAddUniqueNode() << std::endl;



// Testing Graph
    std:: cout << test_graphDefaultConstructor() << std::endl;
    std:: cout << test_graphContructor1() << std::endl;
    std:: cout << test_graphContructor2() << std::endl;
    std:: cout << test_graphAddEdge() << std::endl;
    std:: cout << test_graphAddVertex() << std::endl;
    std:: cout << test_graphBFS() << std::endl;





    return 0;








}
