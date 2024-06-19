#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertintoBST(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }
    if (root->data > val)
    {
        root->left = insertintoBST(root->left, val);
    }
    else
    {
        root->right = insertintoBST(root->right, val);
    }
    return root;
}

void createTree(Node *&root)
{
    int val;
    cout << "Enter the value of node : " << endl;
    cin >> val;
    while (val != -1)
    {
        root = insertintoBST(root, val);
        cout << "Enter the value of Node : " << endl;
        cin >> val;
    }
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void Level_Order_Traversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        Node *frontnode = q.front();
        q.pop();
        if (frontnode == NULL)
        {
            cout << endl;
            q.push(NULL);
        }
        else
        {
            cout << frontnode->data << " ";
            if (frontnode->left != NULL)
            {
                q.push(frontnode->left);
            }
            if (frontnode->right != NULL)
            {
                q.push(frontnode->right);
            }
        }
    }
}

Node *maximum_Element(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

bool search(Node *root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == target)
    {
        return true;
    }
    if (root->data > target)
    {
        return search(root->left, target);
    }
    else
    {
        return search(root->right, target);
    }
}

int main()
{
    Node *root = NULL;
    createTree(root);
    cout << search(root, 4);

    return 0;
}
