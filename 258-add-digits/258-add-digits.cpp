class Solution {
public:
    int addDigits(int num) {
        while(num/10 != 0){
            int t=num, sum=0;
            while(t!=0){
                sum+=t%10;
                t=t/10;
            }
            num=sum;
        }
        return num;
    }
};