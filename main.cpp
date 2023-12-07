#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <string>


#include "graph.h"


using namespace GP_GRAPH;

int main() {




    std::vector<std::pair<int,int>> edges = {{1,2},{1,4},{1,5},{2,3},{2,7},{3,4},{3,5},{2,6},{6,7}};
    std::vector<int> vertices = {1,2,3,4,5,6,7};

    Graph g(vertices,edges);

    g.printAdjList();

    g.BFS( 5);

    g.PrintShortestPath(1,7);




    return 0;








}
