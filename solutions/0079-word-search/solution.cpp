class Solution {
private:
    bool dfs(int row, int col, vector<vector<char>>& board, string word, int wordidx)
    {
        int m = board.size();
        int n = board[0].size();
        if (wordidx == word.size()) return true;
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != word[wordidx]) return false;
        char temp = board[row][col];
        board[row][col] = '#';
        int roww[4] = {0,1,0,-1};
        int coll[4] = {1,0,-1,0};
        for (int k = 0; k < 4; k++)
        {
            int newrow = row + roww[k];
            int newcol = col + coll[k];

            if (dfs(newrow, newcol, board, word, wordidx + 1)) return true;
        }
        board[row][col] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dfs(i, j, board, word, 0))
                    return true;
            }
        }
        return false;
    }
};
