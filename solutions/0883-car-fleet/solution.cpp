class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        int n = position.size();
        if(n == 1) return 1;
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) v.push_back({position[i], speed[i]});

        sort(v.begin(), v.end());
        stack<double> time_stack;
        for(int i = n - 1; i >= 0; i--)
        {
            double time = (double)(target - v[i].first) / v[i].second;

            if(time_stack.empty() || time > time_stack.top())
                time_stack.push(time);
        }
        return time_stack.size();
    }
};
