class Solution {
private:
    void compute(vector<int>& temperatures, stack<int>& stk, vector<int>& ans)
    {
        int i = 1;
        int n = ans.size();
        while(i < n)
        {
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()])
            {
                int prev = stk.top();
                stk.pop();
                ans[prev] = i - prev;
            }
            stk.push(i);
            i++;
        }
    }
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size();
        vector<int> ans(n,0);
        if(n == 1) return ans;
        stack<int> stk;
        stk.push(0);
        compute(temperatures, stk, ans);
        return ans;
    }
};
