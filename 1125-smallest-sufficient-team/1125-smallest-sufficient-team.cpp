typedef long long int ll;
class Solution {
public:
    int countSetBits(ll mask){
        int c=0;
        for(int i=0;i<61;i++){
            if((mask>>i) & 1){
                c++;
            }
        }
        return c;
    }
    
    ll solve(int mask, int index, int n, vector<int> &pmask, vector<vector<ll>> &dp){
        if(mask == (1<<n)-1) return 0;
        if(index == pmask.size()) return dp[index][mask] = (1l<<61)-1;
        
        if(dp[index][mask] != -1) return dp[index][mask];
        
        ll incl = 1l<<index | solve(mask|pmask[index], index+1, n, pmask, dp);
        ll excl = solve(mask, index+1, n, pmask, dp);
        
        return dp[index][mask] = countSetBits(incl) < countSetBits(excl) ? incl : excl;
    }
    
    vector<int> smallestSufficientTeam(vector<string>& skills, vector<vector<string>>& people) {
        
        unordered_map<string, int> m;
        int n=skills.size();
        for(int i=0;i<n;i++){
            m[skills[i]] = i;
        }
        vector<int> pmask(people.size(),0);
        for(int i=0;i<people.size();i++){
            for(auto &skill : people[i]){
                pmask[i] = pmask[i] | (1<<m[skill]);
            }
        }
    
        vector<vector<ll>> dp(61, vector<ll> (1<<17, -1));
        
        ll ansmask = solve(0, 0, n, pmask, dp);
        
        vector<int> ans;
        for(int i=0;i<61;i++){
            if((ansmask>>i) & 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};