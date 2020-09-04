class Solution {
public:
    vector<string> ans;
    
    void dfs(TreeNode* root, string path)
    {
        if(!root)
            return;
        path += to_string(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(path);
            return;
        }
        path += "->";
        
        dfs(root->left, path);
        dfs(root->right, path);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};