class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0,j = 0;
        
        while(s[i] && t[j])
        {
            if(s[i] == t[j])
                ++i;
            ++j;
        }
        if(!s[i])
            return 1;
        return 0;
    }
};