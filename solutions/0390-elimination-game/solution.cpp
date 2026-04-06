class Solution {
public:
    int lastRemaining(int n) 
    {
        int start= 1;
        int step = 1;
        if (n==1) return 1;
        if(n%2!=0) n--;
        int remaining= n;
        bool forward= true;
        while(remaining!=1)
            {
                if (remaining%2!=0) remaining --;
                for(int i = 0; i<remaining-1; i++)
                    {
                        if (forward) start+=step;
                        else start-=step;
                    }
                forward= !forward;
                step*=2;
                remaining/=2;
            }
        return start;
    }
};
