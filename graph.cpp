#include "graph.hpp"
#include <iostream> // delete later
#include<bits/stdc++.h>

void prt(vector <int> tbd, vector <int> next, vector <int> explored)
{
    for (int j = 0; j < tbd.size(); j++)
            cout << tbd[j] << ' ';
        cout << " | ";
    for (int j = 0; j < next.size(); j++)
        cout << next[j] << ' ';
    cout << " | ";
    for (int j = 0; j < explored.size(); j++)
        cout << explored[j] << ' ';
    cout << endl;
}

bool is_present(int n, vector <int> v)
{
    for (int i = 0; i < v.size(); i++)
        if (n == v[i])
            return true;
    return false;
}

vector<int> *Graph::DFS(string startVertex)
{
    int index, index2, flag, a;
    vector <int> tbd;
    explored.clear();
    for (int i = 0; i < size; i++)
    {
        if (startVertex == vertices[i])
            index = i;
        tbd.push_back(i);
    }
    explored.push_back(index);
    flag = 0;
    while (flag != -1)
    {
        cin >> a;
        cout << flag << ' ';
        index2 = 0;
        while (weights[index][index2])
        {
            if (weights[index][index2] != 0 && !is_present(index2, explored))
            {
                explored.push_back(index2);
                flag++;
                index = index2;
            }
            index2++;
        }
        if (index2 == size)
        {
            index = explored[flag];
            flag--;
        }
    } 
    return &explored;
}

vector<int> *Graph::BFS(string startVertex)
{
    int index;
    vector <int> tbd;
    vector <int> next;
    explored.clear();
    for (int i = 0; i < size; i++)
    {
        if (startVertex == vertices[i])
            index = i;
        tbd.push_back(i);
    }
    next.push_back(index);
    int a;
    while (tbd.size() > 0 && next.size() > 0)
    {
        index = next[0];
        next.pop_back();
        explored.push_back(index);
        for (int i = 0; i < size; i++)
        {
            if (weights[index][i] != 0)
            {
                next.push_back(i);
            }
        }
        for (int i = 0; i < tbd.size(); i++)
        {
            if (tbd[i] == index)
            {
                tbd.erase(tbd.begin() + i);
            }
        }
        
        for (int i = 0; i < explored.size(); i++)
        {
            if (is_present(explored[i], next))
                for (int j = 0; j < next.size(); j++)
                    if (next[j] == explored[i])
                        next.erase(next.begin() + j);
        }
    }
   
    return &explored;
}

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
int Graph::NumberOfVertices()
{
    return size;
}
int Graph::NumberOfEdges()
{
    int num_e = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            
            if (weights[i][j] != 0.0)
            {
                num_e += 1;
            }
        }
    }
    cout << endl;
    return num_e;
}
int Graph::MinimumDegree()
{
    int buf = 0;
    vector<int> min_compare;
    for (int i = 0; i < size; i++)
    {
        int min = 0;
       
        for (int j = 0; j < size; j++)
        {
            
            if (weights[i][j] )
            {
                min += 1;
            }
        }
        min_compare.push_back(min);
    }
    buf = min_compare[0];
    for (int m = 1; m < min_compare.size(); m++)
    {
        if ((buf > min_compare[m]) && (min_compare[m] != 0))//!!! min_compare[m] != 0
        {
            buf = min_compare[m];
        }
    }
    return buf;
}
int Graph::MaximumDegree()
{
    int buf = 0;
    vector<int> max_compare;
    for (int i = 0; i < size; i++)
    {
        int max = 0;
       
        for (int j = 0; j < size; j++)
        {
            
            if (weights[i][j] )
            {
                max += 1;
            }
        }
        max_compare.push_back(max);
    }
    buf = max_compare[0];
    for (int m = 1; m < max_compare.size(); m++)
    {
        if ((buf < max_compare[m]) && (max_compare[m] != 0))
        {
            buf = max_compare[m];
        }
    }
    return buf;
}
float Graph::AverageDegree()
{
    float avg;
    avg = (MaximumDegree() + MinimumDegree()) / 2;
    return avg;
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

int Graph::get_index(string vertex)
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
    cout << endl;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (weights[i][j])
                cout << vertices[i] << "<--" << weights[i][j] << "-->" << vertices[j] << endl;
}
