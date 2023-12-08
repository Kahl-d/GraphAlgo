//
// Created by Khalid Khan on 12/7/23.
//

#ifndef GRAPH_UNITTEST_H
#define GRAPH_UNITTEST_H

#include <iostream>
#include "graph.h"

using namespace GP_GRAPH;

bool test_graphDefaultConstructor() 
{
    Graph g;

    return true == (g.getSize() == 0);
}

#endif //GRAPH_UNITTEST_H
