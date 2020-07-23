/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<vector<vector<TreeNode*> > > dp;
    
    vector<TreeNode*> generateTrees(int l, int r)
    {
        if(l > r)
            return {NULL};
        
        if(dp[l][r].size())
            return dp[l][r];
        
        vector<TreeNode*> heades;
        
        for(int i=l; i<=r; ++i)
        {
            for(auto lt: generateTrees(l, i-1))
            {
                for(auto rt: generateTrees(i+1, r))
                {
                    heades.push_back(new TreeNode(i, lt, rt));
                }
            }
        }
        
        return dp[l][r] = heades;
    }
    
    
    vector<TreeNode*> generateTrees(int n)
    {
        dp.resize(n+1,vector<vector<TreeNode*>>(n+1));
        if(n == 0)
            return {};
        return generateTrees(1,n);
    }
};