class Solution {
public:
    queue<vector<int>> q;
    void dfs(vector<vector<int>> &grid, int i, int j){
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() ||  grid[i][j]==0 || grid[i][j]==2){
            return;
        }
        q.push({i, j, 0});
        cout<<q.size()<<endl;
        grid[i][j]=2;
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) {
                    dfs(grid, i, j);
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        
        int x[4]={-1, 0, 1, 0};
        int y[4]={0, -1, 0, 1};
        int ans;
        bool got=false;
      //   cout<<q.size();
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            int i=t[0], j=t[1], lvl=t[2];
            // cout<<i<<" "<<j<<" ";
            for(int k=0;k<4;k++){
                int ni=i+x[k], nj=j+y[k];
                // cout<<ni<<" "<<nj;
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]!=2){
                   //  cout<<grid[ni][nj]<<" "<<lvl+1<<endl;
                    if(grid[ni][nj]==1){
                        ans=lvl;
                        got=true;
                        break;
                    } 
                    grid[ni][nj]=2;
                    q.push({ni, nj, lvl+1});
                } 
            }
            if(got) break;
        }
        return ans;
    }
};