class Solution {
public:
    int per[10];
    int used[10];
    
    void init()
    {
        per[0] = 1;
        for(int i=1; i<10; ++i)
            per[i] = per[i-1]*i, used[i] = 0;
    }
    
    int getNth(int N)
    {
        for(int i=1; i<10; ++i)
        {
            if(!used[i])
            {
                --N;
                if(!N)
                {
                    used[i] = 1;
                    return i;
                }
            }
        }
        return -1;
    }
    
    string getPermutation(int n, int k) {
        init();
        string s = "";
        
        for(int i=n; i; --i)
        {
            int p = k / per[i-1];
            k = k % per[i-1];
            if(k)
                s  = s + to_string(getNth(p+1));
            else
            {
                s += to_string(getNth(p));
                break;
            }
        }
        
        if(s.size()!=n)
        {
            for(int i=n; i; --i)
            {
                if(!used[i])
                    s += to_string(i);
            }
        }
        
        return s;
    }
};