// GreedyKnapsack Method:
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of objects: ";
    cin >> n;

    float p[50], w[50], x[50], ratio[50];

    cout << "Enter profits:\n";
    for(int i=0;i<n;i++)
        cin >> p[i];

    cout << "Enter weights:\n";
    for(int i=0;i<n;i++)
        cin >> w[i];

    float m;
    cout << "Enter capacity: ";
    cin >> m;

    for(int i=0;i<n;i++)
        ratio[i] = p[i] / w[i];

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ratio[i] < ratio[j])
            {
                swap(ratio[i], ratio[j]);
                swap(p[i], p[j]);
                swap(w[i], w[j]);
            }
        }
    }

    for(int i=0;i<n;i++)
        x[i] = 0.0;

    float u = m;

    for(int i=0;i<n;i++)
    {
        if(w[i] > u)
            break;

        x[i] = 1.0;
        u = u - w[i];
    }

    if(u > 0)
        x[n-1] = u / w[n-1];

    float profit = 0;

    for(int i=0;i<n;i++)
        profit += x[i] * p[i];

    cout << "Selected fractions:\n";
    for(int i=0;i<n;i++)
        cout << x[i] << " ";

    cout << "\nMaximum profit: " << profit;

    return 0;
}