class Solution {
public:
    int memo(int i, int j1, int j2, vector<vector<int>> &grid, int m, int n,
                                       vector<vector<vector<int>>> &dp){
        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) return -1e9;

        if (i == m - 1) {
            if (j1 == j2)
              return grid[i][j1];
            else
              return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = INT_MIN;
          for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
              int ans;
              if (j1 == j2)
                ans = grid[i][j1] + memo(i + 1, j1 + dj1, j2 + dj2, grid, m, n, dp);
              else
                ans = grid[i][j1] + grid[i][j2] + memo(i + 1, j1 + dj1, j2 + dj2, grid, m, n, dp);
              maxi = max(maxi, ans);
            }
          }
         return dp[i][j1][j2] = maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
                
        int m=grid.size(), n=grid[0].size();
        /* MEMOIZATION
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return memo(0, 0, n - 1, grid, m, n, dp);
        */
        
   /*  TABULATION 3D     
        int dp[m][n][n];
        // base case
        for(int j1=0;j1<n;j1++){
            for(int j2=0;j2<n;j2++){
                if (j1 == j2) dp[m-1][j1][j2] = grid[m-1][j1];
                else dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }
        //. tabualtion is BOTTOM UP -> from base case to up -> from row n-1 to 0
        for(int i=m-2;i>=0;i--){
            for(int j1=0;j1<n;j1++){
                for(int j2=0;j2<n;j2++){
                    int maxi = INT_MIN;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                          int val=0;
                            
                          if (j1 == j2) val = grid[i][j1]; 
                          else val = grid[i][j1] + grid[i][j2]; 
                            
                          if(j1+dj1 >=0 && j1+dj1<n && j2+dj2 >=0 && j2+dj2<n) 
                              val += dp[i+1][j1+dj1][j2+dj2];
                          else val += -1e8;
                            
                          maxi = max(maxi, val);
                        }
                      }
                   dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][n-1];
        
    */  
        
        
        // SPACE OPTIMISED TO 2D
        // we are only using (i+1)th row so no need to store for other values of row
        
        vector<vector<int>> front(n, vector<int>(n));
        vector<vector<int>> curr(n, vector<int>(n));
        
        for(int j1=0;j1<n;j1++){
            for(int j2=0;j2<n;j2++){
                if (j1 == j2) front[j1][j2] = grid[m-1][j1];
                else front[j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }
        //. tabualtion is BOTTOM UP -> from base case to up -> from row n-1 to 0
        for(int i=m-2;i>=0;i--){
            for(int j1=0;j1<n;j1++){
                for(int j2=0;j2<n;j2++){
                    int maxi = INT_MIN;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                          int val=0;
                            
                          if (j1 == j2) val = grid[i][j1]; 
                          else val = grid[i][j1] + grid[i][j2]; 
                            
                          if(j1+dj1 >=0 && j1+dj1<n && j2+dj2 >=0 && j2+dj2<n) 
                              val += front[j1+dj1][j2+dj2];
                          else val += -1e8;
                            
                          maxi = max(maxi, val);
                        }
                      }
                   curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }
        return front[0][n-1];
    }
};

























