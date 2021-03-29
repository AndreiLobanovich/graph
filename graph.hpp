#include <string>
#include <iostream>

using namespace std;


class Graph 
{
    private:
        string          *vertices; // IDs of the vertices
        float           **weights; // Adjacenty Matrix
        int             size;
        int             max_size;
    public:
        Graph();
        ~Graph();

        uint            AddVertex(string label);  // +
        uint            get_index(string vertex); // +
        void            AddEdge(string l1, string l2, float weight); // +
        void            AddEdge(uint v1, uint v2, float weight); // +
        void            Display(); // +
};