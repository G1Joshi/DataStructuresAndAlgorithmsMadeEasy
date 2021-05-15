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

int size(Node *root)
{
    int count = 0;
    if (!root)
        return count;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        count++;
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return count;
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

    cout << size(root);

    return 0;
}