class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n!=0){
            if(n&1) ans++;
            n/=2;
            cout<<n<<endl;
        }
        return ans;
    }
};