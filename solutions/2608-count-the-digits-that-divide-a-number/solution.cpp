class Solution {
public:
    int countDigits(int num) {
        int n = num;
        long long count = 0;
        while(num>0) {
            int val = num%10;
            num = num/10;
            if(n%val == 0) {
                count++;
            }
        }
        return count;
    }
};
