class Solution {
public:
    bool judgeCircle(string moves) 
    {
        int vertical = 0, horizontal = 0;
        for (char c : moves)
        {
            if (c == 'U') vertical++;
            else if (c == 'D') vertical--;
            else if (c == 'R') horizontal++;
            else if (c == 'L') horizontal--;
        }
        return (vertical == 0 && horizontal == 0);
    }
};
