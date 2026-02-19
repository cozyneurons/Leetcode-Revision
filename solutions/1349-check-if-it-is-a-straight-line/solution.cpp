class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        int n = coordinates.size();
        int del_y = coordinates[1][1] - coordinates[0][1];
        int del_x = coordinates[1][0] - coordinates[0][0];
        for (int i = 2; i<n; i++)
        {
            int del_y_i = coordinates[i][1] - coordinates[0][1];
            int del_x_i = coordinates[i][0] - coordinates[0][0]; 
            if ((del_y * del_x_i) != (del_x * del_y_i)) return false;
        }
        return true;
    }
};
