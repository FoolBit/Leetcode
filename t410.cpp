class Solution {
public:
    vector<long long> sum;
    
    int init(vector<int>& nums)
    {
        int maxVal = nums[0];
        sum = vector<long long>(nums.size()+1, 0);
        
        for(int i=1; i<=nums.size(); ++i)
        {
            sum[i] = sum[i-1] + nums[i-1];
            if(nums[i-1] > maxVal)
                maxVal = nums[i-1];
        }
        return maxVal;
    }
    
    bool divide(long long maxVal, int maxPart)
    {
        int l = 0;
        int cnt = 0;
        for(int r = 1; r<sum.size(); ++r)
        {
            if(sum[r]-sum[l]<=maxVal)
                continue;
            ++cnt;
            l = r-1;
        }
        
        return cnt<maxPart;
    }
    
    int splitArray(vector<int>& nums, int m) {
        long long l = init(nums);
        long long r = *sum.rbegin();
        
        int ans = 0;
        while(l<=r)
        {
            long long mid = (l+r) >> 1;
            if(divide(mid, m))
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        
        return ans;
    }
};