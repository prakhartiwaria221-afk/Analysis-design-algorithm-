//Optimal Merge Patterns
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int weight;
    Node* left;
    Node* right;
};

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->weight > b->weight;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    priority_queue<Node*, vector<Node*>, compare> pq;

    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        Node* temp = new Node();
        temp->weight = w;
        temp->left = NULL;
        temp->right = NULL;
        pq.push(temp);
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* parent = new Node();
        parent->weight = left->weight + right->weight;
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    Node* root = pq.top();

    cout << "Root weight (total cost): " << root->weight << endl;

    return 0;
}