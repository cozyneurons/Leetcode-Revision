class Solution {
public:
    string rearrangeString(string s, char x, char y) 
    {
        string arranged = "";
        int x_count = 0;
        int y_count = 0;
        for (char c : s)
            {
                if (c==x) x_count++;
                else if (c==y) y_count++;
                else arranged += c;
            }
        return string(y_count,y) + arranged + string(x_count,x);  
    }
};
