
// Prim's Algorithm
#include <iostream>
using namespace std;

int n;
int cost[10][10];
int visited[10];

int main() {

    int min, a = 0, b = 0;
    int i, j;
    int num_edge = 0;
    int mincost = 0;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter Cost Matrix:\n";

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {

            cin >> cost[i][j];

            if (cost[i][j] == 0) {
                cost[i][j] = 999;
            }
        }
    }

    visited[0] = 1;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (num_edge < n - 1) {

        min = 999;

        for (i = 0; i < n; i++) {

            if (visited[i] == 1) {

                for (j = 0; j < n; j++) {

                    if (visited[j] == 0 && cost[i][j] < min) {

                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        cout << "Edge " << num_edge + 1
             << ": (" << a << " - " << b
             << ") Cost = " << min << endl;

        visited[b] = 1;
        mincost += min;
        num_edge++;
    }

    cout << "\nMinimum Cost = " << mincost;

    return 0;
}