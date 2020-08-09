class Solution {
public:
    void dfs(string s, string cur, vector<string>& ans, int cnt)
    {
        if(cnt == 4 && s.size() == 0)
        {
            cur.pop_back();
            ans.push_back(cur);
            return ;
        }
        if(cnt == 4 && s.size())
            return ;
        int len = s.size();
        for(int i = 1; i<=3 && i<=len; i++)
        {
            string ss = s.substr(0,i);
            int num = stoi(ss);
            if(to_string(num).size() != ss.size())
                return ;
            if(num<=255 && num>=0)
            {
                string temp = cur;
                cur += (ss + '.');
                dfs(s.substr(i),cur,ans,cnt+1);
                cur = temp;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        dfs(s,"",ans,0);
        return ans;
    }
};