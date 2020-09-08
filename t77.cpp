class Solution {
public:
    vector<vector<int> > solution;
    vector<int > comb;
    
    void dfs(int s, int e, int k)
    {
        if(!k)
        {
            solution.push_back(comb);
            return;
        }
        for(int i=s; i<=(e-k+1); ++i)
        {
            comb.push_back(i);
            dfs(i+1, e, k-1);
            comb.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return solution;
    }
};