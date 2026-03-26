class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        int n = fruits.size();
        int left = 0;
        int right = 0;
        unordered_map <int,int> mpp;
        int maxfruits = 0;
        while(right < n)
        {
            mpp[fruits[right]]++;
            while(mpp.size()>2)
            {
                mpp[fruits[left]]--;
                if (mpp[fruits[left]]==0) mpp.erase(fruits[left]);
                left++;
            }
            maxfruits = max (maxfruits,right-left+1);
            right++;
        }

        return maxfruits;
    }
};
// 1,1,2,2,3
// basket -
// 1,1
// 1,2

