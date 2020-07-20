class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt[257];
        memset(cnt, 0, sizeof(cnt));
        int len = s.size();
        int maxLen = 0;
        
        
        int l=0,r=0;
        
        for(; r<len; ++r)
        {
            ++cnt[s[r]];
            if(cnt[s[r]]>1)
            {
                maxLen = maxLen>(r-l)?(maxLen):(r-l);
            
                while(s[r]!=s[l])
                {
                    --cnt[s[l]];
                    ++l;
                }
                ++l;
                --cnt[s[r]];
            }
        }
        maxLen = maxLen>(r-l)?(maxLen):(r-l);
        
        return maxLen;
    }
};