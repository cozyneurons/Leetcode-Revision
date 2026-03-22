class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) 
    {
        unordered_set<int> us;
        us.reserve(nums1.size());
        us.insert(nums1.begin(), nums1.end());  

        unordered_set<int> us1;
        us1.reserve(nums2.size());
        us1.insert(nums2.begin(), nums2.end());  

        unordered_set<int> us2;
        us2.reserve(nums3.size());
        us2.insert(nums3.begin(), nums3.end());  

        unordered_set<int> us4;

        vector<int> ans;

        for (int x : nums1)
        {
            if (us4.find(x) == us4.end() &&
                ((us.count(x) && us1.count(x)) || 
                 (us1.count(x) && us2.count(x)) || 
                 (us2.count(x) && us.count(x))))
            {
                ans.push_back(x);
                us4.insert(x);
            }
        }

        for (int x : nums2)
        {
            if (us4.find(x) == us4.end() &&
                ((us.count(x) && us1.count(x)) || 
                 (us1.count(x) && us2.count(x)) || 
                 (us2.count(x) && us.count(x))))
            {
                ans.push_back(x);
                us4.insert(x);
            }
        }

        for (int x : nums3)
        {
            if (us4.find(x) == us4.end() &&
                ((us.count(x) && us1.count(x)) || 
                 (us1.count(x) && us2.count(x)) || 
                 (us2.count(x) && us.count(x))))
            {
                ans.push_back(x);
                us4.insert(x);
            }
        }

        return ans;
    }
};
