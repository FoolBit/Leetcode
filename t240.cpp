class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = 0;
        if(m)
            n = matrix[0].size();
        
        
        int i=0, j=n-1;
        while(1)
        {
            if(i>=m || j<0)
                return false;
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] < target)
            {
                ++i;
            }
            else
            {
                --j;
            }
        }
        
        return false;
    }
};