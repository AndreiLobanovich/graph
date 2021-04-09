#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "graph.hpp"

using namespace std;


int main()
{
    vector <int> *tst;
    Graph *g = new Graph();
    g->AddVertex("A");
    g->AddVertex("B");
    g->AddVertex("C");
    g->AddVertex("D");
    g->AddVertex("E");
    g->AddVertex("F");
    g->AddVertex("G");
    g->AddEdge(0, 1, 10.0);
    g->AddEdge("B", "C", 10.5);
    g->AddEdge("C", "A", 11.0);
    g->AddEdge("A", "D", 20.0);
    g->AddEdge("A", "E", 10.12);
    g->AddEdge("D", "E", 1);
    g->NumberOfVertices();
    cout << "Number of edges: " << g->NumberOfEdges() << endl;
    cout << "Minimum degree: " << g->MinimumDegree() << endl;
    cout << "Maximum degree: " << g->MaximumDegree() << endl;
    cout << "Average degree: " << setprecision(2) << g->AverageDegree() << endl;
    g->Display();
    tst = g->DFS("A");
    for (int i = 0; i < tst->size(); i++)
        cout << tst[0][i]<< ' ';
    



}