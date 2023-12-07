//
// Created by Khalid Khan on 12/5/23.
//

// TODO: Implement the following:
//Declare a class Graph                                                                             [X] DONE
//Adopt the adjacency list representation                                                           [X] DONE
//Represent each adjacency list as a “raw pointer”-based singly linked list                         [X] DONE
//Include and implement the big-3
//Member functions to construct a graph such as adding vertices and edges                           [X] DONE
//Implement the BFS algorithm on Slide 7
//Print out the BFS-tree from a given source vertex
//Print the shortest path from s to v by implement the recursive algorithm on Slide 10


#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <queue>
#include "graph.h"

namespace GP_GRAPH{

//    ---------------------------------------------------------------------------------
//    ------------------NODE STRUCT IMPLEMENTATION ------------------------------------
//    ---------------------------------------------------------------------------------

// Overloeaded == operator for Node Struct

    bool operator==(const Node& n1, const Node& n2){
        return n1.vertex == n2.vertex;

    }

    // Overloaded < operator for Node Struct
    bool operator<(const Node& n1, const Node& n2) {
        return n1.vertex < n2.vertex;
    }

    // Overloading Assignment Operator for Node Struct


//    ---------------------------------------------------------------------------------
//    ------------------LINKED LIST IMPLEMENTATION ------------------------------------
//    ---------------------------------------------------------------------------------

    // Default Constructor
    LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0){}


    // Destructor
    LinkedList::~LinkedList(){
        Node* temp = head;
        // Destructing all the nodes in the linked list
        while(temp != nullptr){
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // getHead Function
    // -- used to get the head of the linked list
    // --- used in the adjacency list
    Node* LinkedList::getHead(){
        return head;
    }


//    ---------------------------------------------------------------------------------
//    ------------------ SPECIAL FUNCTION ---------------------------------------------
//    ------------------  addUniqueNode -----------------------------------------------
//    ---------------------------------------------------------------------------------

    // -- used to add a node to the linked list
    // --- come handy with the adjacency list

    void LinkedList::addUniqueNode(int v){
        Node* newNode = new Node;
        newNode->vertex = v;
        // Dynamically allocate memory for the new node
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            bool found = false;
            Node* temp = head;
            while (temp != nullptr) {
                if (temp->vertex == v) {
                    found = true;
                    break;
                }
                temp = temp->next;
            }

            if (!found) {
                tail->next = newNode;
                tail = newNode;
            }
        }

        size++;
    }



    // printList Function
    // -- used to print the linked list
    // --- used in printing the adjacency list

    void LinkedList::printList(){
        Node* temp = head;
        while(temp != nullptr){
            std::cout << temp->vertex << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

//    ---------------------------------------------------------------------------------
//    ---------------------------------------------------------------------------------
//    ------------------ GRAPH CLASS IMPLEMENTATION -----------------------------------
//    ---------------------------------------------------------------------------------
//    ---------------------------------------------------------------------------------



    //Default Constructor
    Graph::Graph(){
        // empty vertices vector
        vertices = std::vector<Node>();
        // empty edges vector
        edges = std::vector<std::pair<int, int>>();
        // empty adjacency list
        adjList = std::vector<LinkedList>();

        size = 0;




    }

    // Graph Constructor
    // given = EDGES

    Graph::Graph(std::vector<std::pair<int, int>> edgeList) {

        for (std::pair<int, int> edge: edgeList) {

            Node v1;
            v1.vertex = edge.first;
            Node v2;
            v2.vertex = edge.second;

            std::pair<int, int> newEdge;
            newEdge = std::make_pair(edge.first, edge.second);
            edges.push_back(newEdge);

            vertices.push_back(v1);
            vertices.push_back(v2);

        }




        updateAdjList();

    }



    // Graph Constructor
    // given = VERTICES and EDGES
    // given as LISTS

    Graph::Graph(std::vector<int> vertexList, std::vector<std::pair<int, int>> edgeList){

        for (std::pair<int, int> edge: edgeList) {

            Node v1;
            v1.vertex = edge.first;
            Node v2;
            v2.vertex = edge.second;

            std::pair<int, int> newEdge = std::make_pair(edge.first, edge.second);
            edges.push_back(newEdge);

        }

        for( int vertex: vertexList){

            addNode(vertex);
        }




        updateAdjList();
    }


    // Copy Constructor
    Graph::Graph(const Graph& g){

        for (std::pair<int, int> edge: g.edges) {

            Node v1;
            v1.vertex = edge.first;
            Node v2;
            v2.vertex = edge.second;

            std::pair<int, int> newEdge;
            newEdge = std::make_pair(edge.first, edge.second);
            edges.push_back(newEdge);

            vertices.push_back(v1);
            vertices.push_back(v2);

        }




        updateAdjList();

        int length = vertices.size();
        color.resize(length);
        distance.resize(length);
        parent.resize(length);

        for(int i = 0; i < length; i++){
            color[i] = g.color[i];
            distance[i] = g.distance[i];
            parent[i] = g.parent[i];
        }



    };

    // Assignment Operator
    Graph& Graph::operator=(const Graph& g){

        if(this == &g){
            return *this;
        }

        for (std::pair<int, int> edge: g.edges) {

            Node v1;
            v1.vertex = edge.first;
            Node v2;
            v2.vertex = edge.second;

            std::pair<int, int> newEdge;
            newEdge = std::make_pair(edge.first, edge.second);
            edges.push_back(newEdge);

            vertices.push_back(v1);
            vertices.push_back(v2);

        }

        updateAdjList();

        int length = vertices.size();
        color.resize(length);
        distance.resize(length);
        parent.resize(length);

        for(int i = 0; i < length; i++){
            color[i] = g.color[i];
            distance[i] = g.distance[i];
            parent[i] = g.parent[i];
        }

    }

    // Getters

    int Graph::getSize(){
        return size;
    }



    //addEdge member Function

    void Graph::addEdge(int v1, int v2){
        // make a pair given two vertices
        Node v1Node;
        v1Node.vertex = v1;
        Node v2Node;
        v2Node.vertex = v2;

        std::pair<int, int> edge = std::make_pair(v1, v2);
        edges.push_back(edge);

        vertices.push_back(v1Node);
        vertices.push_back(v2Node);
        updateAdjList();
    }


    //addNode Function

    void Graph::addNode(int v){
       Node newNode;
         newNode.vertex = v;
         vertices.push_back(newNode);

        size = vertices.size();
        color.resize(size);
        distance.resize(size);
        parent.resize(size);
    }


//    ---------------------------------------------------------------------------------
//    ------------------ UPDATE ADJACENCY LIST IMPLEMENTATION -------------------------
//    ---------------------------------------------------------------------------------

//    - updates on every new edge added to the graph

    // updateing Adjacency List of a graph Object
    // - useful when adding new edges to a graph
    // -- or when creating a graph from a list of edges
    // --- serves as a function to get the adjacency list of a graph

    void Graph::updateAdjList(){
        // Clearing the adjacency list
        adjList.clear();

        // Creating a linked list for each vertex
        for(int i = 0; i < vertices.size(); i++){
            LinkedList newList;
            adjList.push_back(newList);
        }

        // Adding nodes to the adjacency list
        for(int i = 0; i < edges.size(); i++){




            adjList[edges[i].first -1 ].addUniqueNode(edges[i].second);
            adjList[edges[i].second - 1].addUniqueNode(edges[i].first);
        }

        size = vertices.size();
        color.resize(size);
        distance.resize(size);
        parent.resize(size);


    }


    // Print Adjacency List Function

    void Graph::printAdjList(){
        std::cout<< "Adjacency List: " << std::endl;
        for(int i = 0; i < adjList.size(); i++){
            std::cout << i + 1 << " : ";
            adjList[i].printList();
        }
    }


    // Destructor
    Graph::~Graph(){

    }



    // ---------------------------------------------------------------------------------
    // ------------------ BFS IMPLEMENTATION --------------------------------------------
    // ---------------------------------------------------------------------------------

    // BFS Algorithm
    // - takes a source vertex as an argument
    // -- prints the BFS tree from the source vertex

    void Graph::BFS( int s) {
        for (int i = 0; i < size; i++) {
            color[i] = Color::WHITE;
            distance[i] = 0;
            parent[i] = nullptr;
        }

        color[s - 1] = Color::GRAY;

        std::queue<Node*> eQueue;
        eQueue.push(&vertices[s - 1]);

        while (!eQueue.empty()) {
            int levelSize = eQueue.size();
            for (int i = 0; i < levelSize; i++) {
                Node* qHead = eQueue.front();
                eQueue.pop();

                // Check if qHead is nullptr
                if (qHead == nullptr) {
                    continue;
                }

                // Getting the starting of Adjacency List for the current vertex
                Node* u = adjList[qHead->vertex - 1].getHead();

                while (u != nullptr) {
                    if (color[u->vertex - 1] == Color::WHITE) {
                        color[u->vertex - 1] = Color::GRAY;
                        distance[u->vertex - 1] = distance[qHead->vertex - 1] + 1;
                        parent[u->vertex - 1] = qHead;
                        eQueue.push(u);
                    }
                    u = u->next;
                }

                color[qHead->vertex - 1] = Color::BLACK;

                // Print the vertex at the current level with setw for formatting
                std::cout << qHead->vertex;
            }

            std::cout << std::endl;
        }
    }

    // Print Shortest Path Function
    // - takes a source vertex and a destination vertex as arguments
    // -- prints the shortest path from the source vertex to the destination vertex

    void Graph::PrintShortestPath(int s, int v){
        BFS(s);

        if(v == s){
            std::cout << s << " ";
        }else if(parent[v-1] == nullptr){
            std::cout << "No Path from " << s << " to " << v << " exists" << std::endl;
        }else{
            PrintShortestPath(s, parent[v-1]->vertex);
            std::cout << v << " ";
        }
    }







}// namespace GP_GRAPH










#endif //GRAPH_H