class Solution {
public:
    double findMedianSortedArrays(vector<int > & a, vector<int >& b)
    {
        int m = a.size();
        int n = b.size();
        if (m > n) {
            return findMedianSortedArrays(b,a);
        }
        int l = 0, r = m;
        while (l <= r) {
            int i = (l + r) >> 1;
            int j = ((m + n + 1) >> 1) - i;
            if (j != 0 && i != m && b[j-1] > a[i]){ // i 需要增大
                l = i + 1;
            }
            else if (i != 0 && j != n && a[i-1] > b[j]) { // i 需要减小
                r = i - 1;
            }
            else {
                int maxLeft = 0;
                if (i == 0) { maxLeft = b[j-1]; }
                else if (j == 0) { maxLeft = a[i-1]; }
                else { maxLeft = max(a[i-1], b[j-1]); }
                if ( (m + n) % 2 == 1 ) { return maxLeft; } // 奇数的话不需要考虑右半部分

                int minRight = 0;
                if (i == m) { minRight = b[j]; }
                else if (j == n) { minRight = a[i]; }
                else { minRight = min(b[j], a[i]); }

                return (maxLeft + minRight) / 2.0; //如果是偶数的话返回结果
            }
        }
        return 0.0;
    }
};