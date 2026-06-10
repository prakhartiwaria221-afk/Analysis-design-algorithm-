// FloydWarshallAlgo
#include <iostream>
#include <vector>
using namespace std;

#define INF 999

int minimum(int a, int b)
{
    if (a <= b)
        return a;
    else
        return b;
}

int main()
{
    int v;
    cout << "Enter no of vertices: ";
    cin >> v;

    int a[v][v],cost[v][v];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << "Enter the cost between vertex "
                 << i + 1 << " and " << j + 1 << ": ";
            cin >> cost[i][j];

            if (cost[i][j] == 0 && i != j)
                a[i][j] = INF;
            else
                a[i][j] = cost[i][j];
        }
    }

    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                a[i][j] = minimum(a[i][j], a[i][k]+a[k][j]);
            }
        }
    }

    cout << "Shortest Path Matrix:\n";

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}