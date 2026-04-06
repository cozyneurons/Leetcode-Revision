class Solution {
public:
    int numberOfChild(int n, int k) 
    {
        bool forward = true;
        int ans = 0;
        int t = k;
        while(t!=0)
        {

            if (forward) 
            {
                ans+=1;
                if (ans==n-1) forward = false;
            }
            else if(!forward)
            {
                ans-=1;
                if (ans==0) forward = true;
            }
            t--;
        }
        return ans;
    }
};
