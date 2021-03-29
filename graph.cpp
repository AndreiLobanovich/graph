#include "graph.hpp"

Graph::Graph()
{
    vertices = NULL;
    weights = NULL;
    size = 0;
    max_size = 0;
}

Graph::~Graph()
{
    free(vertices);
    free(weights);
}

uint Graph::AddVertex(string label)
{
    if (size == max_size)
    {
        max_size += 10;
        vertices = (string*) realloc(vertices, max_size * sizeof(string));
        weights = (float**) realloc(weights, max_size * sizeof(float*));
        for (int i = 0; i < max_size; i++)
            weights[i] = (float*) realloc(weights[i], max_size * sizeof(float));
    }
    if (vertices && weights)
    {
        for (int i = max_size - 10; i < max_size; i++)
            for (int j = max_size - 10; j < max_size; j++)
                weights[i][j] = 0;
        vertices[size] = label;
        size++;
        return 1;
    }
    else
        return 0;
}

uint Graph::get_index(string vertex)
{
    for (int i = 0; i < size; i++)
    {
        if (vertices[i] == vertex)
            return i;
    }
    return -1;
}

void Graph::AddEdge(string l1, string l2, float weight)
{
    if (get_index(l1) == -1)
        AddVertex(l1);
    if (get_index(l2) == -1)
        AddVertex(l2);
    weights[get_index(l1)][get_index(l2)] = weight;
    weights[get_index(l2)][get_index(l1)] = weight;
}

void Graph::AddEdge(uint v1, uint v2, float weight)
{
    if (v1 < size && v2 < size)
    {
        weights[v1][v2] = weight;
        weights[v2][v1] = weight;
    }
}

void Graph::Display()
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (weights[i][j])
                cout << vertices[i] << "<--" << weights[i][j] << "-->" << vertices[j] << endl;
}
