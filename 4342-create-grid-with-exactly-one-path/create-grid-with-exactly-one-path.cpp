class Solution {
public:
    vector<string> createGrid(int m, int n) 
    {
        vector<string>g(m, string(n,'#'));
        // for(int j=0; j<n; j++)
        // {
        //     g[0][j]='.';
        // }
        // for(int i=0; i<m; i++)
        // {
        //     g[i][n-1]='.';
        // }
        int r=0,c=0;
        g[r][c]= '.';

        while(r<m-1 || c<n-1)
        {
            if(c+1<n && (r==m-1 || (r+c)%2==0)) c++;
            else r++;
            g[r][c]= '.';
        }
        return g;
    }
};