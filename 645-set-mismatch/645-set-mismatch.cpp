class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        for(int i:nums){
            if(nums[abs(i)-1] < 0) ans.push_back(abs(i));
            nums[abs(i)-1] = -abs(nums[abs(i)-1]);
        }
        for(int i=0;i<nums.size();i++) if(nums[i]>0) ans.push_back(i+1);
        return ans;
    }
};