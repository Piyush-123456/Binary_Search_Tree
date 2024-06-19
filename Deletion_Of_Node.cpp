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

Node *deleteNode(Node *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == target)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            Node *maximum = maximum_Element(root->left);
            root->data = maximum->data;
            root->left = deleteNode(root->left, maximum->data);
            return root;
        }
    }
    else if (root->data > target)
    {
        root->left = deleteNode(root->left, target);
    }
    else
    {
        root->right = deleteNode(root->right, target);
    }
    return root;
}

int main()
{
    Node *root = NULL;
    createTree(root);
    cout << "Before Deletion of node : " << endl;
    Level_Order_Traversal(root);
    cout << "After Deletion of node : " << endl;
    deleteNode(root, 80);
    Level_Order_Traversal(root);
    return 0;
}
