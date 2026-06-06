class Solution {
public:
    bool consecutiveSetBits(int n) 
    {
        if (n==0) return false;
        
        string binary = "";
        
        while(n>0)
            {
                binary += (n%2) + '0';
                n/=2;
            }
        int count = 0;
        int sz = binary.size();
        for (int i = 0; i<sz-1; i++)
            {
                if (binary[i]=='1' && binary[i+1]=='1') count++;
            }
        if (count == 1) return true;
        return false;
    }
};
