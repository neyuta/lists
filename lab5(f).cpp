#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void topoSortUtil(int v, vector<bool>& visited, vector<vector<int>>& graph, stack<int>& st) 
{

    visited[v] = true;

    for (int i = 0; i < graph.size(); ++i) 
    {
        if (!visited[i] && graph[v][i] != 0) 
        {
            topoSortUtil(i, visited, graph, st);
        }
    }

    st.push(v);
}

vector<int> topologicalSort(vector<vector<int>>& graph) 
{
    int n = graph.size();
    vector<int> result;
    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; ++i) 
    {
        if (!visited[i]) 
        {
            topoSortUtil(i, visited, graph, st);
        }
    }

    while (!st.empty()) 
    {
        result.push_back(st.top());
        st.pop();
    }

    return result;
}

int main() 
{

    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };

   vector<int> sorted = topologicalSort(graph);

    cout << "Topological Order: ";
    for (int vertex : sorted) 
    {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
