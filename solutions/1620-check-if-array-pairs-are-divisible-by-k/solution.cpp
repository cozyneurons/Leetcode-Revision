class Solution {
public:
    bool canArrange(vector<int>& arr, int k) 
    {
        unordered_map<int,int> mpp;

        for (int num : arr)
        {
            int rem = ((num % k) + k) % k;
            int need = (k - rem) % k;
            if (mpp[need] > 0)
            {
                mpp[need]--;
            }
            else
            {
                mpp[rem]++;
            }
        }
        for (auto &it : mpp)
        {
            if (it.second != 0) return false;
        }
        return true;
    }
};
