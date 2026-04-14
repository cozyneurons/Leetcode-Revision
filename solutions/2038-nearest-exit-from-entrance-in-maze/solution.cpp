class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        int m = maze.size();
        int n = maze[0].size();

        int entryRow = entrance[0];
        int entryCol = entrance[1];

        queue<pair<int,pair<int,int>>> q;
        q.push({1,{entryRow,entryCol}});
        maze[entryRow][entryCol] = '+';

        int neighRow[4] = {-1,0,1,0};
        int neighCol[4] = {0,1,0,-1};

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int level = it.first;
            int row = it.second.first;
            int col = it.second.second;
            for (int i = 0; i<4; i++)
            {
                int newRow = row + neighRow[i];
                int newCol = col + neighCol[i];    
                if ((newRow < m && newRow>=0 && newCol < n && newCol>=0) && maze[newRow][newCol]!='+')
                {
                    if (newRow == m - 1 || newRow==0 || newCol==n - 1|| newCol==0) return level;
                    q.push({level+1,{newRow,newCol}});
                    maze[newRow][newCol] = '+';
                }
            }

        }
        return -1;
    }
};
