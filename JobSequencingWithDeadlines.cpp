//Job Sequencing with Deadlines 
#include <iostream>
#include <algorithm>

using namespace std;

struct Job
{
    int id;
    int profit;
    int deadline;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

int main()
{
    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[n];

    for(int i = 0; i < n; i++)
    {
        cout << "Enter profit and deadline for job " << i + 1 << ": ";
        cin >> jobs[i].profit >> jobs[i].deadline;
        jobs[i].id = i + 1;
    }

    sort(jobs, jobs + n, compare);

    int maxDeadline = 0;

    for(int i = 0; i < n; i++)
    {
        if(jobs[i].deadline > maxDeadline)
        {
            maxDeadline = jobs[i].deadline;
        }
    }

    int slot[maxDeadline + 1];

    for(int i = 0; i <= maxDeadline; i++)
    {
        slot[i] = -1;
    }

    int totalProfit = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = jobs[i].deadline; j >= 1; j--)
        {
            if(slot[j] == -1)
            {
                slot[j] = i;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "\nSelected Jobs:\n";

    for(int i = 1; i <= maxDeadline; i++)
    {
        if(slot[i] != -1)
        {
            cout << "Job " << jobs[slot[i]].id << " ";
        }
    }

    cout << "\nTotal Profit = " << totalProfit;

    return 0;
}