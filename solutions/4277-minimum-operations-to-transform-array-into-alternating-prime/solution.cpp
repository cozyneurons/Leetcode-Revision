class Solution {
private:
    bool isPrime(int x)
    {
        if (x==1) return false;
        if (x==2) return true;
        for (int i = 2; i*i<=x; i++)
            {
                if (x%i==0)
                {
                    return false;
                }
            }
        return true;
    }
public:
    int minOperations(vector<int>& nums) 
    {
        int n = nums.size();
        int operations = 0;
        for (int i = 0; i<n; i++)
            {
                if (i%2==0)
                {
                    int haha = nums[i];
                    while (!isPrime(haha))
                        {
                            haha+=1;
                            operations+=1;
                        }
                }
                else
                {
                    int hahaha = nums[i];
                    while(isPrime(hahaha))
                        {
                            hahaha+=1;
                            operations+=1;
                        }
                }
            }
        return operations;
    }
};
