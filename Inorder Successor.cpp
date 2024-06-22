class Solution{
  public:
    
    void inorder(Node*root, vector<Node*>&order){
        if(root==NULL){
            return;
        }
        inorder(root->left, order);
        order.push_back(root);
        inorder(root->right, order);
    }
    Node * inOrderSuccessor(Node *root, Node *x)
    {
         vector<Node*> order;
        inorder(root, order); 

        Node* ans = NULL;
        for (int i = 0; i < order.size(); i++) {
            if (x->data == order[i]->data && i + 1 < order.size()) {
                ans = order[i + 1];
                break;
            }
        }
        return ans;
    }
};
