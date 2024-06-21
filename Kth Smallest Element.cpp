class Solution {
public:
    void solve(vector<int>& order, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        solve(order, root->left);
        order.push_back(root->val);
        solve(order, root->right);
    }
    int kthSmallest(TreeNode* root, int& k) { 
        vector<int> order;
        solve(order, root);
        for(int i =0;i<order.size();i++){
            cout<<order[i]<<" ";
        }
        return order[k-1];
    }
};
