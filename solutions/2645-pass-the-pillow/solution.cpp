class Solution {
public:
    int passThePillow(int n, int time) 
    {
        bool forward = true;
        int ans = 1;
        int t = time;
        while(t!=0)
        {

            if (forward) 
            {
                ans+=1;
                if (ans==n) forward = false;
            }
            else if(!forward)
            {
                ans-=1;
                if (ans==1) forward = true;
            }
            t--;
        }
        return ans;
    }
};
