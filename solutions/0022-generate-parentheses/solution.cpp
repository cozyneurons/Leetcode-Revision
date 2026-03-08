class Solution {
private:
    void backtrack(vector<string> &v,string &st, int open, int close, int n)
        {
            if (open==n && close==n)
            {
                v.push_back(st);
            }
            if (open<n)
            {
                st.push_back('(');
                backtrack(v,st,open+1,close,n);
                st.pop_back();
            }
            if (close<open)
            {
                st.push_back(')');
                backtrack(v,st,open,close+1,n);
                st.pop_back();
            }
        }
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> v;
        if (n==1)
        {
            v.push_back("()");
            return v;
        }
        // 1 open 1 close * 3 times
        // 2 open 2 close 1 open 1 close
        // 3 open 3 close
        // no. of close = no. of open before
        string st = "";
        backtrack(v,st,0,0,n);
        return v;
    }
};
