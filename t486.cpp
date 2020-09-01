class Solution {
public:
    
    int dp[22][22];
    int sum[22];
    
    void init(vector<int>& nums)
    {
        sum[0] = 0;
        dp[0][0] = nums[0];
        for(int i=1; i<nums.size(); ++i)
        {
            sum[i] = sum[i-1] + nums[i-1];
            dp[i][i] = nums[i];
        }
        sum[nums.size()] = sum[nums.size()-1] + nums[nums.size()-1];
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size() % 2 == 0)
            return 1;
        
        init(nums);
        
        for(int j=1; j<nums.size(); ++j)
        {
            for(int i=0; i<nums.size()-j; ++i)
            {
                int sum_seg = sum[i+j+1] - sum[i];
                dp[i][i+j] = max(sum_seg-dp[i+1][i+j], sum_seg-dp[i][i+j-1]);
            }
        }
        
        int first = dp[0][nums.size()-1];
        int second = sum[nums.size()] - first;
        
        return first>=second;
    }
};