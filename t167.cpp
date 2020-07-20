class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int l,r;
        l = 0;
        r = numbers.size()-1;

        while(l<r)
        {
            int s = numbers[l]+numbers[r];
            if(s == target)
            {
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
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