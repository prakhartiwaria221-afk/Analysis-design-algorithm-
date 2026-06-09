//Binary Search with intertive Method :
#include <iostream>
using namespace std;
int BinarySearch(int arr[],int n, int Key)
{
    int start = 0 , end = n-1 , mid ;
    while (start<=end)
    {
        mid = (start + end)/2;
        if (arr[mid]== Key)
        return mid;
        else if (arr[mid]< Key)
        start = mid+1;
        else 
        end = mid-1;
    }
    return-1;
}
int main()
{
    int arr[500];
    int n;
    cout<<"Enter the number of element in array : ";
    cin>>n;
    cout<<"Enter the Elements :";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int key;
    cout<<"Enter the key :";
    cin>>key;
    cout<<BinarySearch(arr,n,key)<<endl;
    return 0;
}

// Binary Sort Recursive Method :
/*#include <iostream>
using namespace std;

int binarySearch(int arr[], int Beg, int End, int item)
{
    if (Beg > End)
        return -1;

    int mid = (Beg + End) / 2;

    if (item == arr[mid])
        return mid;
    else if (item < arr[mid])
        return binarySearch(arr, Beg, mid - 1, item);
    else
        return binarySearch(arr, mid + 1, End, item);
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter elements of array in increasing order:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int item, loc;
    int Beg = 0, End = n - 1;

    cout << "Enter number you want to search: ";
    cin >> item;

    loc = binarySearch(arr, Beg, End, item);

    if (loc != -1)
        cout << item << " is found at location " << loc;
    else
        cout << item << " is not found in array";

    delete[] arr;
    return 0;
}*/