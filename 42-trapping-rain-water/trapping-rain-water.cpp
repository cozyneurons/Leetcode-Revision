class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        vector<int> prefixMax(n,0);
        vector<int> suffixMax(n,0);
        prefixMax[0] = height[0];
        suffixMax[n-1] = height[n-1];
        for(int i = 1; i<n; i++)
        {
            prefixMax[i] = max(prefixMax[i-1],height[i]);
            suffixMax[n-i-1] = max(suffixMax[n-i],height[n-i-1]);
        }
        int ans = 0;
        for (int i = 0; i<n; i++)
        {
            if (min(prefixMax[i],suffixMax[i])>height[i]) ans += min(prefixMax[i],suffixMax[i]) - height[i];
        }
        return ans;
    }
};