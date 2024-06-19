#include <iostream>
#include <queue>
#include <vector>
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

Node *createBST_FromInorder(vector<int> inorder, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = new Node(inorder[mid]);
    root->left = createBST_FromInorder(inorder, start, mid - 1);
    root->right = createBST_FromInorder(inorder, mid + 1, end);
    return root;
}

int main()
{
    Node *root = NULL;
    vector<int> inorder = {10, 20, 30, 40, 50, 60, 70};
    Node *temp = createBST_FromInorder(inorder, 0, inorder.size() - 1);
    Level_Order_Traversal(temp);
    return 0;
}
