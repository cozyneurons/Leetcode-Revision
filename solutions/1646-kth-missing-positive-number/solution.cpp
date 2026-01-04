class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> s(arr.begin(), arr.end());

        int num = 1;
        while (true)
        {
            if (s.find(num)==s.end())
            {
                k--;
                if (k==0)
                {
                    return num;
                    false;
                }
            }
            num++;
        }
    }
};
