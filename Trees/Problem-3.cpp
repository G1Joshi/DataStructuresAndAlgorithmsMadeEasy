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

int search(Node *root, int key)
{
    if (root)
    {
        if (root->data == key)
            return 1;
        return search(root->left, key) || search(root->right, key);
    }
    return 0;
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

    cout << search(root, 32);

    return 0;
}