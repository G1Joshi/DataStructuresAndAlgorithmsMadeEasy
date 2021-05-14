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

void insert(Node *root, int data)
{
    Node *node = new Node(data);
    if (!root)
    {
        root = node;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->right)
            q.push(temp->right);
        else
        {
            temp->right = node;
            return;
        }
        if (temp->left)
            q.push(temp->left);
        else
        {
            temp->left = node;
            return;
        }
    }
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

    insert(root, 128);

    return 0;
}