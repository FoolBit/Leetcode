class Solution {
public:
    vector<string> chess;
    vector<vector<string> > solutions;
    vector<bool> rows;
    int N;
    
    void init(int n)
    {
        for(int i=0; i<n; ++i)
        {
            chess.push_back(string(n, '.'));
        }
        solutions = vector<vector<string> >();
        N = n;
        
        rows = vector<bool>(N, true);
    }
    
    bool judge(int x, int y)
    {
        int nx = x-1, ny = y-1;
        while(nx>=0 && ny>=0)
        {
            if(chess[nx][ny] == 'Q')
                return false;
            nx -= 1;
            ny -= 1;
        }
        
        nx = x+1;
        ny = y-1;
        while(nx<N && ny>=0)
        {
            if(chess[nx][ny] == 'Q')
                return false;
            nx += 1;
            ny -= 1;
        }
        
        return true;
    }
    
    void dfs(int y)
    {
        if(y == N)
        {
            solutions.push_back(chess);
            return;
        }
            
        for(int x=0; x<N; ++x)
        {
            if(rows[x] && judge(x, y))
            {
                rows[x] = 0;
                chess[x][y] = 'Q';
                dfs(y+1);
                chess[x][y] = '.';
                rows[x] = 1;
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        init(n);
        dfs(0);
        
        return solutions;
    }
};