class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> ans = {-1,-1};
        int low = 0;
        int high = nums.size()-1;
        int n =nums.size();
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if (nums[mid]==target)
            {  
                if (nums[mid] == target)
                {
                    int left = mid;
                    int right = mid;
                    while (left - 1 >= 0 && nums[left - 1] == target) left--;
                    while (right + 1 < n && nums[right + 1] == target) right++;
                    ans[0] = left;
                    ans[1] = right;
                    return ans;
                }
            }
            else if (nums[mid]<target) low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }
};
