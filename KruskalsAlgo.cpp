// Kruskal's Algorithm
#include <iostream>
using namespace std;

int find(int parent[], int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void Union(int parent[], int i, int j) {
    int rootI = find(parent, i);
    int rootJ = find(parent, j);
    parent[rootI] = rootJ;
}

int main() {
    int v, e;

    cout << "Enter the number of vertices : ";
    cin >> v;

    cout << "Enter the number of edges : ";
    cin >> e;

    int source[e], destination[e], weight[e];

    for (int i = 0; i < e; i++) {
        cout << "Enter edge " << i + 1 << " : ";
        cin >> source[i] >> destination[i] >> weight[i];
    }

    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - 1 - i; j++) {
            if (weight[j] > weight[j + 1]) {

                int temp_w = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp_w;

                int temp_s = source[j];
                source[j] = source[j + 1];
                source[j + 1] = temp_s;

                int temp_d = destination[j];
                destination[j] = destination[j + 1];
                destination[j + 1] = temp_d;
            }
        }
    }

    int parent[v + 1];

    for (int i = 1; i <= v; i++)
        parent[i] = i;

    int mstCost = 0;
    int edgesUsed = 0;

    cout << "Edges in MST : " << endl;

    for (int i = 0; i < e && edgesUsed < v - 1; i++) {

        int root_source = find(parent, source[i]);
        int root_destination = find(parent, destination[i]);

        if (root_source != root_destination) {

            cout << source[i] << " - " << destination[i]
                 << "  Weight : " << weight[i] << endl;

            mstCost += weight[i];
            edgesUsed++;

            Union(parent, source[i], destination[i]);
        }
    }

    cout << "Total Cost : " << mstCost << endl;

    return 0;
}