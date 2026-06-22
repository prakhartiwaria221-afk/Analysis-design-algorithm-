// Single Source Shortest Path (Dijkstra's Algorithm)
#include <iostream>
using namespace std;

int main()
{
    int n, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    int cost[100][100];
    int dist[100];
    bool visited[100];

    cout << "Enter adjacency matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];

            if(cost[i][j] == 0 && i != j)
            {
                cost[i][j] = 9999;
            }
        }
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    for(int i = 0; i < n; i++)
    {
        dist[i] = cost[start][i];
        visited[i] = false;
    }

    dist[start] = 0;
    visited[start] = true;

    for(int count = 1; count < n; count++)
    {
        int min = 9999;
        int u;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        for(int w = 0; w < n; w++)
        {
            if(!visited[w] && dist[u] + cost[u][w] < dist[w])
            {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }

    cout << "\nShortest distances:\n";

    for(int i = 0; i < n; i++)
    {
        cout << "From " << start << " to " << i << " = " << dist[i] << endl;
    }

    return 0;
}