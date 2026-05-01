class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) 
    {
        int row;
        int col;
        int toto = 0;
        for (int i = 0; i<8; i++)
        {
           for (int j = 0; j<8; j++)
           {
            if(board[i][j] == 'R')
            {
                row = i;
                col = j;
                break;
            }
           }
        }
        for (int i = row; i<8; i++)
        {
            if (board[i][col]=='B') break;
            if (board[i][col]=='p')
            {
                toto++;
                break;
            }
        }
        for (int i = row; i>=0; i--)
        {
            if (board[i][col]=='B') break;
            if (board[i][col]=='p')
            {
                toto++;
                break;
            }
        }
        for (int i = col; i<8; i++)
        {
            if (board[row][i]=='B') break;
            if (board[row][i]=='p')
            {
                toto++;
                break;
            }
        }
        for (int i = col; i>=0; i--)
        {
            if (board[row][i]=='B') break;
            if (board[row][i]=='p')
            {
                toto++;
                break;
            }
        }
        return toto;
    }
};
