//Quick Sort
 #include <iostream>
using namespace std;
int Partition(int arr[],int s,int e)
{
    int pivot=arr[e];
    int pIndex = s;
    for(int i=s;i<e;i++)
    {
        if(arr[i]<pivot)
        {
            int temp=arr[i];
            arr[i]=arr[pIndex];
            arr[pIndex]=temp;
            pIndex++;
        }
    }
    int temp=arr[e];
    arr[e]=arr[pIndex];
    arr[pIndex]=temp;
    return pIndex;
}
void QuickSort(int arr[],int s,int e)
{
    if(s<e)
    {
        int p =Partition(arr,s,e);
        QuickSort(arr,s,(p-1));
        QuickSort(arr,(p+1),e);
    }
}
int main()
{
    int size=0;
    cout<<"Enter size of array :"<<endl;
    cin>>size;
    int myarray[size];
    cout<<"Enter integers in any order :"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>myarray[i];
    }
    cout<<"Before Sorting"<<endl;
    for (int i = 0; i < size; i++)
    {
    cout<<myarray[i]<<" ";
    }
    cout<<endl;
    cout<<"After Sorting"<<endl;
for(int i= 0;i<size;i++)
{
    cout<<myarray[i]<<" ";
}
    return 0;
}


/* #include <iostream>
using namespace std;

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int quick(int arr[], int beg, int end){
    int left = beg, right = end;
    int loc = beg;

    do{
        while(arr[loc] < arr[right] && loc != right)
            right--;

        if(loc == right)
            return loc;

        if(arr[loc] > arr[right]){
            swap(&arr[loc], &arr[right]);
            loc = right;
        }

        while(arr[loc] >= arr[left] && loc != left)
            left++;

        if(loc == left)
            return loc;

        if(arr[loc] < arr[left]){
            swap(&arr[loc], &arr[left]);
            loc = left;
        }

    } while(left < right);

    return loc;
}

void quicksort(int arr[], int size){
    int top = -1;
    int lower[size];
    int upper[size];

    if(size > 1){
        top++;
        lower[top] = 0;
        upper[top] = size - 1;
    }

    while(top >= 0){
        int beg = lower[top];
        int end = upper[top];
        int loc = quick(arr, beg, end);
        top--;

        if(beg < loc - 1){
            top++;
            lower[top] = beg;
            upper[top] = loc - 1;
        }

        if(end > loc + 1){
            top++;
            lower[top] = loc + 1;
            upper[top] = end;
        }
    }
}

int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];  

    cout << "Enter elements in array:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    quicksort(arr, n);

    cout << "List after sorting:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << "  ";

    return 0;
}*/