class Solution {
public:
    vector<int>drow={1,0,-1,0};
    vector<int>dcol={0,1,0,-1};
    bool isvalid(int r,int c,int m,int n)
    {
        if(r<0 || c<0 || r>=m || c>=n) return false;
        return true;
    }
    void solve(vector<vector<char>>& grid, int r,int c,int m,int n)
    {
        grid[r][c]='2';
        int i;
        for(i=0;i<4;i++)
        {
            int newrow=r+drow[i];
            int newcol=c+dcol[i];
            if(isvalid(newrow,newcol,m,n) && grid[newrow][newcol]!='2'
            && grid[newrow][newcol]=='1')
            {
                solve(grid,newrow,newcol,m,n);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int i,j;
        int c=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    solve(grid,i,j,m,n);
                    c=c+1;
                }
            }
        }
        return c;

    }
};
