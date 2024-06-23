class Solution{
  public:
    void solve(Node* root, unordered_map<int, bool>& visited, bool&ans){
        if(root==0){
            return;
        }
        visited[root->data] = true;
        if(root->left==NULL && root->right==NULL){
            int xp1 = root->data+1;
            int xm1 = root->data-1==0 ? root->data: root->data-1;
            if(visited.find(xp1)!=visited.end() && visited.find(xm1)!=visited.end()){
                ans = true;
                return;
            }
        }
        solve(root->left, visited, ans);
        solve(root->right, visited, ans);
    }
    bool isDeadEnd(Node *root)
    {
        bool ans = false;
        unordered_map<int,bool> visited;
        solve(root, visited, ans);
        return ans;
        //Your code here
    }
};
