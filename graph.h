//
// Created by Khalid Khan on 12/5/23.
//

// TODO: Implement the following:
//  Declare a class Graph                                                                             [X] DONE
//  Adopt the adjacency list representation                                                           [X] DONE
//  Represent each adjacency list as a “raw pointer”-based singly linked list                         [X] DONE
//  Include and implement the big-3                                                                   [X] DONE
//  Member functions to construct a graph such as adding vertices and edges                           [X] DONE
//  Implement the BFS algorithm on Slide 7                                                            [X] DONE
//  Print out the BFS-tree from a given source vertex                                                 [X] DONE
//  Print the shortest path from s to v by implement the recursive algorithm on Slide 10              [X] DONE

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

// Include Statements
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <set>

namespace GP_GRAPH{

    // enum for color
    // A node can be white, gray or black
    enum class Color{
        WHITE,
        GRAY,
        BLACK
    };

    // Node Data Structure
    struct Node{
        int vertex{-1};
        Node* next{nullptr};
    };


    // class Linked List to work with adjacency List

    class LinkedList {
    public:
        // Default Constructor
        LinkedList();

        //Destructor
        ~LinkedList();

        // member functions
        // checks for unique node when adding in the list
        void addNode(int v);

        void addUniqueNode(int v);
        void printList();

        // Getters
        Node* getHead();
        int getSize();

    private:
        Node* head;
        Node* tail;
        int size;
    };

    // Class Graph
    class Graph {
    public:

        // Graph Constructors
        //Deafult Constructor
        Graph();

        //Constructor given edges
        Graph(std::vector<std::pair<int, int>> edges);

        //Construcotr given vertices and edges
        Graph(std::vector<int> vertexList, std::vector<std::pair<int, int>> edgeList);

        // Copy Constructor
        Graph(const Graph& g);

        // Assignment Operator
        Graph& operator=(const Graph& g);

        // Destructor
        ~Graph();

        // Internal Graph Member Functions

        void addEdge(int v1, int v2);
        void addNode(int v);

        // Helper Functions
        // Automatically updates the adjacency list once a new edge is added
        // or a new vertex is added
        void updateAdjList();


         // Getters
         void printAdjList();
            int getSize();

            int getParentID(int i);


         // Algorithms
         // BFS

        void BFS( int s);
        void printBFS(int s);
        void PrintShortestPath( int s, int v);


    private:
        std::vector<Node> vertices;
        std::vector<std::pair<int, int>> edges;

        // Adjacency List
        // Using a linked list helps easy insertion and deletion
        // also helps with destroying because Linked List has a destructor
        std::vector<LinkedList> adjList;

        std::vector<Color> color;
        std::vector<int> distance;
        std::vector<Node*> parent;

        int size;

    };

}

#endif //GRAPH_GRAPH_H
