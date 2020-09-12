class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sol;
        if(!root)
            return {};
        queue<TreeNode*> q, nexyLayer;
        TreeNode* p;
        double sum = root->val;
        q.push(root);
        
        while(q.size())
        {
            sol.push_back(sum / q.size());
            sum = 0;
            
            while(q.size())
            {
                p = q.front();q.pop();
                if(p->left)
                {
                    sum += p->left->val;
                    nexyLayer.push(p->left);
                }
                if(p->right)
                {
                    sum += p->right->val;
                    nexyLayer.push(p->right);
                }
            }
            
            q = nexyLayer;
            nexyLayer = queue<TreeNode*>();
            
        }
        return sol;
    }
};