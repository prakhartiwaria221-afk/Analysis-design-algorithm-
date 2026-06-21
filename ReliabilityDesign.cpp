#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;

    cout << "Enter number of components: ";
    cin >> n;

    float r[n];
    int c[n];

    cout << "\nEnter reliability of each component:\n";
    for(int i = 0; i < n; i++)
    {
        cout << "Reliability of component " << i + 1 << ": ";
        cin >> r[i];
    }

    cout << "\nEnter cost of each component:\n";
    for(int i = 0; i < n; i++)
    {
        cout << "Cost of component " << i + 1 << ": ";
        cin >> c[i];
    }

    int C;

    cout << "\nEnter total budget: ";
    cin >> C;

    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum = sum + c[i];
    }

    int extra = C - sum;

    int u[n];

    for(int i = 0; i < n; i++)
    {
        u[i] = (extra / c[i]) + 1;
    }

    float dp[100][1000];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= C; j++)
        {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= C; j++)
        {
            for(int m = 1; m <= u[i-1]; m++)
            {
                int cost = m * c[i-1];

                if(j >= cost)
                {
                    float rel = 1 - pow((1 - r[i-1]), m);

                    if(dp[i][j] < dp[i-1][j-cost] * rel)
                    {
                        dp[i][j] = dp[i-1][j-cost] * rel;
                    }
                }
            }
        }
    }

    float ans = 0;
    int bestCost = 0;

    for(int j = 0; j <= C; j++)
    {
        if(dp[n][j] > ans)
        {
            ans = dp[n][j];
            bestCost = j;
        }
    }

    cout << "\nMaximum Reliability = " << ans << endl;
    cout << "Total Cost = " << bestCost << endl;

    return 0;
}