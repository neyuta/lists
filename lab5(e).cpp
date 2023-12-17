#include <iostream>
#include <queue>

using namespace std;


void DFS(int** graph, bool* visited, int vertex, int num_vertices, vector<int>& result_dfs) 
{
    result_dfs.push_back(vertex);
    visited[vertex] = true;

    for (int i = 0; i < num_vertices; i++) 
    {
        if (graph[vertex][i] == 1 && !visited[i]) 
        {
            DFS(graph, visited, i, num_vertices, result_dfs);
        }
    }
}

void BFS(int** graph, bool* visited, int vertex, int num_vertices, vector<int>& result_bfs) 
{
    queue<int> q;
    q.push(vertex);
    visited[vertex] = true;

    while (!q.empty()) 
    {
        int current = q.front();
        q.pop();
        result_bfs.push_back(current);

        for (int i = 0; i < num_vertices; i++) 
        {
            if (graph[current][i] == 1 && !visited[i]) 
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() 
{
    int num_vertices;
    cout << "Enter the number of vertices of the graph: ";
    cin >> num_vertices;

    int** graph = new int* [num_vertices];
    for (int i = 0; i < num_vertices; i++) 
    {
        graph[i] = new int[num_vertices];
    }

    cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < num_vertices; i++) 
    {
        for (int j = 0; j < num_vertices; j++) 
        {
            cin >> graph[i][j];
        }
    }

    bool* visited = new bool[num_vertices];
    for (int i = 0; i < num_vertices; i++) 
    {
        visited[i] = false;
    }

    int start_vertex;
    cout << "Enter the vertex to start the crawl from: ";
    cin >> start_vertex;

    vector<int> result_dfs;
    vector<int> result_bfs;

    DFS(graph, visited, start_vertex, num_vertices, result_dfs);
    BFS(graph, visited, start_vertex, num_vertices, result_bfs);

    cout << "Traversing the graph in depth: ";
    for (int i = 0; i < result_dfs.size(); i++) 
    {
        cout << result_dfs[i] << " ";
    }
    cout << endl;

    cout << "Traversing the graph in width: ";
    for (int i = 0; i < result_bfs.size(); i++) 
    {
        cout << result_bfs[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < num_vertices; i++) 
    {
        delete[] graph[i];
    }
    delete[] graph;
    delete[] visited;

    return 0;
}
