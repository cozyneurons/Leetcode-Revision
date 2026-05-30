class Solution {
public:
    int ans = 0;
    void solve(int col, vector<string>& board, int n)
    {
        if (col==n)
        {
            ans++;
            return;
        }
        for (int row = 0; row<n; row++)
        {
            if (issafe(row,col,board,n))
            {
                board[row][col] = 'Q';
                solve(col+1,board,n);
                board[row][col] = '.';
            }
        }
    }
    bool issafe(int row, int col, vector<string>& board, int n)
    {
        int duprow = row;
        int dupcol = col;
        // wahi row check kar
        while(dupcol>=0)
        {
            if (board[row][dupcol]=='Q') return false;
            dupcol--;
        }
        duprow = row;
        dupcol = col;
        //upar wale diagonal ko cxhek kar
        while(duprow>=0 && dupcol>=0)
        {
            if (board[duprow][dupcol]=='Q') return false;
            duprow--;
            dupcol--;
        }
        duprow = row;
        dupcol = col;
        //niche wale diagonal ko cxhek kar
        while(duprow<n && dupcol>=0)
        {
            if (board[duprow][dupcol]=='Q') return false;
            duprow++;
            dupcol--;
        }
        return true;
    }
    int totalNQueens(int n) 
    {
        vector<string> board(n, string(n, '.'));
        solve(0,board,n);
        return ans;
    }
};
