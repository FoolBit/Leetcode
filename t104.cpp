class Solution {
public:
    int d;
    
    void getDepth(TreeNode* root, int dp)
    {
        if(!root)
            return ;
        d = max(d, dp);
        getDepth(root->left, dp+1);
        getDepth(root->right, dp+1);
        
    }
    
    int maxDepth(TreeNode* root) {
        d = 0;
        getDepth(root, 1);
        return d;
    }
};