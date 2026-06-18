//Huffman Coding
#include <iostream>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;
};

Node* createNode(char ch, int freq)
{
    Node* temp = new Node;
    temp->ch = ch;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

void printCode(Node* root, string code)
{
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL)
    {
        cout << root->ch << " : " << code << endl;
    }

    printCode(root->left, code + "0");
    printCode(root->right, code + "1");
}

int findMin(Node* arr[], int n)
{
    int min = 0;

    for(int i = 1; i < n; i++)
    {
        if(arr[i]->freq < arr[min]->freq)
        {
            min = i;
        }
    }

    return min;
}

int main()
{
    int n;

    cout << "Enter number of symbols: ";
    cin >> n;

    Node* arr[50];

    for(int i = 0; i < n; i++)
    {
        char ch;
        int freq;

        cout << "Enter symbol: ";
        cin >> ch;

        cout << "Enter frequency: ";
        cin >> freq;

        arr[i] = createNode(ch, freq);
    }

    while(n > 1)
    {
        int min1 = findMin(arr, n);
        Node* left = arr[min1];

        arr[min1] = arr[n - 1];
        n--;

        int min2 = findMin(arr, n);
        Node* right = arr[min2];

        arr[min2] = arr[n - 1];
        n--;

        Node* parent = createNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        arr[n] = parent;
        n++;
    }

    cout << "\nHuffman Codes:\n";
    printCode(arr[0], "");

    return 0;
}