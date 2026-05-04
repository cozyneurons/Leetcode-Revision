class Solution {
public:
    string winningPlayer(int x, int y) 
    {
        int par = min(x,y/4);
        if (par%2==1) return "Alice";
        return "Bob";
    }
};
