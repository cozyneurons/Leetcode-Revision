class Solution {
public:
    int hammingDistance(int x, int y) 
    {
        int val = x ^ y;
        int count = 0;
        
        while (val) {
            count += (val & 1);
            val >>= 1;
        }
        return count;
    }
};
