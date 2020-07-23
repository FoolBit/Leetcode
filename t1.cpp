class Solution {
public:
    struct CNum
    {
        int val;
        int idx;
        
        CNum(){};
        CNum(int val_, int idx_):val(val_),idx(idx_){};
        
        bool operator < (const CNum& b)
        {
            return val<b.val;
        }
    };

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<CNum> num;
        
        for(int i=0; i<nums.size(); ++i)
        {
            num.push_back(CNum(nums[i], i));
        }
        
        vector<int> ans;
        sort(num.begin(), num.end());
        int l=0;
        int r=num.size()-1;
        
        while(l<r)
        {
            int s = num[l].val + num[r].val;
            if(s == target)
            {
                ans.push_back(num[l].idx);
                ans.push_back(num[r].idx);
                ++l;--r;
            }
            else if(s<target)
            {
                ++l;
            }
            else
            {
                --r;
            }
        }
        return ans;
    }
};