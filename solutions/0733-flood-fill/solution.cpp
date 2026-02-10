class Solution {
private:
    void dfs (int sr, int sc,vector<vector<int>>& image,vector<vector<int>>& ans,int inicolor, int color)
    {
        ans[sr][sc]=color;
        int n = image.size();
        int m = image[0].size();
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,-1,0,1};
        for (int i = 0; i<4; i++)
        {
            int newrow = sr + dr[i];
            int newcol = sc + dc[i];
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m &&
            image[newrow][newcol]==inicolor && ans[newrow][newcol] != color)
            {
                dfs (newrow,newcol,image,ans,inicolor,color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int inicolor = image[sr][sc];
        if(inicolor == color) return image;
        vector<vector<int>> ans = image;
        dfs (sr,sc,image,ans,inicolor,color);
        return ans;
    }
};
