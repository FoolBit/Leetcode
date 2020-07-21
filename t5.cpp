class Solution {
public:
    int dp[1002][1002];
    int len;
    
    void init()
    {
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<len; ++i)
            dp[i][i] = 1;
    }
    
    string longestPalindrome(string s) {
        len = s.size();
        init();
        
        int maxLen = 1;
        string ans = s.substr(0,1);
        
        for(int d=1; d<len; ++d)
        {
            bool flag = 1;
            for(int i=0; i<len-d; ++i)
            {
                if(s[i]!=s[i+d])
                    continue;
                
                if(dp[i+1][i+d-1] ||
                   d == 1)
                {
                    dp[i][i+d] = 1;
                    if(flag)
                    {
                        flag = 0;
                        maxLen = d+1;
                        ans = s.substr(i, maxLen);
                    }
                }
            }
        }
        
        
        return ans;
    }
};