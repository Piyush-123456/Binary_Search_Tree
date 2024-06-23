class Solution
{
public:
    void inorder(Node* root, Node*&prev){
        if(root==NULL){
            return;
        }
        inorder(root->left, prev);
        prev->left= NULL;
        prev->right = root;
        prev = root;
        inorder(root->right, prev);
    }
    
    Node *flattenBST(Node *root)
    {
        Node* dummy = new Node(-1);
        Node* prev = dummy;
        inorder(root, prev);
        prev->right = prev->left = NULL;
        root = dummy->right;
        return root;
    }
};
