// MerageSort 
#include <iostream>
using namespace std;

void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int size = high - low + 1;
    int* b = new int[size];  

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= mid)
        b[k++] = a[i++];

    while (j <= high)
        b[k++] = a[j++];

    for (int i = 0; i < size; i++)
        a[low + i] = b[i];

    delete[] b;  
}

void mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* a = new int[n];  

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    mergesort(a, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    delete[] a;  
    return 0;
}