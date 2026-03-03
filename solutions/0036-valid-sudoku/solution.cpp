#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for (int i = 0; i < 9; i++)
        {
            unordered_set<char> row;
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.') continue;

                if (row.find(board[i][j]) != row.end())
                    return false;

                row.insert(board[i][j]);
            }
        }
        for (int j = 0; j < 9; j++)
        {
            unordered_set<char> col;
            for (int i = 0; i < 9; i++)
            {
                if (board[i][j] == '.') continue;

                if (col.find(board[i][j]) != col.end())
                    return false;

                col.insert(board[i][j]);
            }
        }
        for (int boxRow = 0; boxRow < 3; boxRow++)
        {
            for (int boxCol = 0; boxCol < 3; boxCol++)
            {
                unordered_set<char> square;

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        char value = board[boxRow*3 + i][boxCol*3 + j];
                        if (value == '.') continue;

                        if (square.find(value) != square.end())
                            return false;

                        square.insert(value);
                    }
                }
            }
        }

        return true;
    }
};
