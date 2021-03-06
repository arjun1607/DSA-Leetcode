class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int len=1, ans=0;
        vector<int> count(n,1), dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<=i-1;j++){
                if(nums[j]<nums[i] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }else if(nums[j]<nums[i] && dp[j]+1==dp[i]){
                    count[i]+=count[j];
                }
            }
            len=max(len, dp[i]);
        }
        for(int i=0;i<n;i++){
            if(len==dp[i]) ans+=count[i];
        }
        return ans;
    }
};