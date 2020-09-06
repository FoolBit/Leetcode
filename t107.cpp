class Solution {
public:
    deque<TreeNode*> q1, q2;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ans;
        vector<int> layer;
        TreeNode* p;
        
        q1.push_back(root);
        
        while(1)
        {
            p = q1.front();
            q1.pop_front();
            if(p)
            {
                layer.push_back(p->val);
                q2.push_back(p->left);
                q2.push_back(p->right);
            }
            
            if(q1.empty())
            {
                if(layer.empty())
                    break;
                ans.push_back(layer);
                q1 = q2;
                q2 = deque<TreeNode*>();
                layer = vector<int>();
            }
        }
        
        return vector<vector<int> >(ans.rbegin(), ans.rend());
    }
};