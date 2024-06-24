class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution{
    public:
    Node* insertintoBST(Node*&root, int& succ, int val){
        if(root==NULL){
            return new Node(val);
        }
        if(root->data > val){
            succ = root->data;
            root->left = insertintoBST(root->left, succ, val);
        }
        else{
            root->right = insertintoBST(root->right, succ, val);
        }
        return root;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int>ans(n,-1);
        Node* root = NULL;
        for(int i = n-1;i>=0;i--){
            int succ = -1;
            root = insertintoBST(root, succ, arr[i]);
            ans[i] = succ;
        }
        return ans;
    }
};
