#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int data = 0)
    {
        this->data = data;
        left = right = NULL;
    }
};

int findMax(Node *root)
{
    if (!root)
        return 0;
    static int mx = INT_MIN;
    mx = max(mx, root->data);
    findMax(root->left);
    findMax(root->right);
    return mx;
}

int main()
{
    Node *root = new Node(8);
    root->left = new Node(2);
    root->right = new Node(32);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(16);
    root->right->right = new Node(64);

    cout << findMax(root);

    return 0;
}