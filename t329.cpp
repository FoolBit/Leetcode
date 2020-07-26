class Solution {
public:
    struct Node
    {
        int x,y;
        int h;
        Node(){};
        Node(int x_, int y_, int h_):x(x_),y(y_),h(h_){};
        bool operator < (const Node& a)
        {
            return h > a.h;
        }
    };
    
    vector<Node> seq;
    vector<vector<int> > dp;
    int m,n;
    
    void init(vector<vector<int>>& matrix)
    {
        m = matrix.size();
        n = matrix[0].size();
        
        dp = vector<vector<int> >(m, vector<int>(n,0));
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                seq.push_back(Node(i,j,matrix[i][j]));
            }
        }
        
        sort(seq.begin(), seq.end());
    }
    
    int runDP(vector<vector<int>>& matrix)
    {
        Node tmp;
        int x,y,h;
        int ans = 0;
        int len = seq.size();
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        
        for(int i=0; i<len; ++i)
        {
            tmp = seq[i];
            x = tmp.x; y = tmp.y; h = tmp.h;
            
            for(int j=0; j<4; ++j)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                if(matrix[nx][ny] > h)
                    dp[x][y] = max(dp[x][y], dp[nx][ny]);
            }
            ++dp[x][y];
            if(ans < dp[x][y])
                ans = dp[x][y];
        }
        
        return ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return 0;
        
        init(matrix);
        return runDP(matrix);
        
    }
};