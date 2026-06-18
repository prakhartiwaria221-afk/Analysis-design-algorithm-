

//Heap Sort
 /* #include <iostream>
using namespace std;
void heapify (int arr[] , int n , int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if (l<n && arr[l]>arr[largest])
    largest = l;
    if (r<n && arr[r]>arr[largest])
    largest = r;
    if (largest !=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapSort (int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    heapify(arr,n,i);
    for(int i=n-1;i>=0;i--){
    swap(arr[0],arr[i]);
    heapify(arr,i,0);
}
}
void printArray (int arr[],int n)
{
    for(int i=0;i<n;++i)
    cout<<arr[i]<<" ";
    cout<<"\n";
}
int main()
{
    int arr[300];
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Before sorting:\n";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "After sorting:\n";
    printArray(arr, n);

    return 0;
}*/





// Heap sort Insertion and Deletion Method :
#include <iostream>
#include <cmath>
using namespace std;

int n;

int insertHeap(int, int, int *heap);
int deleteHeap(int n, int *heap);

int heapSort(int n, int *arr, int *heap){
    for (int i = 0; i < n; i++)
        insertHeap(i, arr[i], heap);
    for (int i = 0; i < n; i++)
        cout << deleteHeap(n - i, heap) << " ";
    return 0;
}

int main(){

    cout << "Enter size of list: ";
    cin >> n;

    int *arr = new int[n];
    int *heap = new int[n + 1];

    cout << "Enter numbers of list:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Sorting list using heapsort:\n";
    heapSort(n, arr, heap);

    

    delete[] arr;
    delete[] heap;

    return 0;
}

int insertHeap(int i, int item, int *heap){
    i++;
    int ptr = i;
    while (ptr > 1) {
        int par = floor(ptr / 2);
        if (heap[par] <= item)
            heap[ptr] = heap[par];
        else{
            heap[ptr] = item;
            return 0;
        }
        ptr = par;
    }
    heap[1] = item;
    return 0;
}

int deleteHeap(int n, int *heap){
    int item = heap[1];
    int last = heap[n];
    n--;
    int ptr = 1, left = 2, right = 3;

    while(right <= n){
        if(last >= heap[left] && last >= heap[right]){
            heap[ptr] = last;
            return item;
        }
        else if(heap[left] <= heap[right]){
            heap[ptr] = heap[right];
            ptr = right;
        }
        else{
            heap[ptr] = heap[left];
            ptr = left;
        }
        left = 2 * ptr;
        right = 2 * ptr + 1;
    }

    if(left == n){
        if(last < heap[left]){
            heap[ptr] = heap[left];
            ptr = left;
        }
    }

    heap[ptr] = last;
    return item;
}
