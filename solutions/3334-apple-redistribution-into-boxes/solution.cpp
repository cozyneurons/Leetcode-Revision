class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) 
    {
        int m = capacity.size();
        int sum = 0;
        sort(capacity.begin(),capacity.end());
        for (int x : apple) sum += x;
        int count = 0;
        for (int i = m-1; i>=0; i--)
        {
            if (sum>capacity[i]) sum-= capacity[i];
            else sum = 0;
            count++;
            if (sum==0) break;
        }
        return count;
    }
};
