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

void levelOrderReverse(Node *root)
{
    queue<Node *> q;
    stack<Node *> s;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->right)
            q.push(temp->right);
        if (temp->left)
            q.push(temp->left);
        s.push(temp);
    }
    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        cout << temp->data << " ";
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

    levelOrderReverse(root);

    return 0;
}