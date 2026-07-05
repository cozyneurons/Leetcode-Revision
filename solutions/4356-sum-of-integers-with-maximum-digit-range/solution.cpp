class Solution {
public:
    int maxDigitRange(vector<int>& nums) 
    {
        int maxRange = -1;
        int ans = 0;
        for (int x : nums)
            {
                int l = 9;
                int h = 0;
                if (x==0)
                {
                    h = 0;
                    l = 0;
                }
                while(x>0)
                    {
                        int d = x%10;
                        l = min (l,d);
                        h = max(h,d);
                        x/=10;
                        
                    }
                maxRange = max(maxRange,h-l);
            }
        for (int x : nums)
            {
                int h = 0;
                int l = 9;
                int num = x;
                if (num==0)
                {
                    h = 0;
                    l = 0;
                }
                while(x>0)
                    {
                        int d = x%10;
                        l = min (l,d);
                        h = max (h,d);
                        x/=10;
                    }
                if (h-l==maxRange) ans += num;
            }
        return ans;
    }
};
