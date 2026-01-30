class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        unordered_map<int, int> ump;
        vector<int> ans(2);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ump[grid[i][j]]++;
                if (ump[grid[i][j]] == 2)
                    ans[0] = grid[i][j]; 
            }
        }

        for (int num = 1; num <= n * n; num++) {
            if (ump.find(num) == ump.end()) {
                ans[1] = num;            
                break;
            }
        }

        return ans;
    }
};
