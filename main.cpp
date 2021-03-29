#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "graph.hpp"

using namespace std;

int main()
{
    Graph *g = new Graph();
    g->AddVertex("A");
    g->AddVertex("B");
    g->AddVertex("C");
    g->AddVertex("D");
    g->AddVertex("E");
    g->AddVertex("F");
    g->AddVertex("G");
    g->AddVertex("H");
    g->AddVertex("I");
    g->AddVertex("J");
    g->AddEdge("A", "B", 10.0);
    g->AddEdge("B", "C", 10.5);
    g->AddEdge("C", "A", 11.0);
    g->AddEdge("A", "D", 20.0);
    g->AddEdge("A", "E", 10.12);
    g->AddEdge("E", "I", 1.0);
    g->AddEdge("A", "J", 2.0);
    g->Display();
}