#include <string>
#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;


class Graph 
{
    private:
        string          *vertices; // IDs of the vertices
        float           **weights; // Adjacenty Matrix
        int             size;
        int             max_size;
        vector <int>    explored;
    public:
        Graph();
        ~Graph();
        int             NumberOfVertices();
        int             NumberOfEdges();
        int             MinimumDegree();
        int             MaximumDegree();
        float           AverageDegree();
        uint            AddVertex(string label);  // +
        int             get_index(string vertex); // +
        void            AddEdge(string l1, string l2, float weight); // +
        void            AddEdge(uint v1, uint v2, float weight); // +
        void            Display(); // +
        vector<int>     *BFS(string startVertex);
        vector<int>     *DFS(string startVertex);

};