class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for (const auto& ticket : tickets) graph[ticket[0]].push(ticket[1]);
        vector<string> route;
        stack<string> dfsStack;
        dfsStack.push("JFK");

        while (!dfsStack.empty()) 
        {
            string curr = dfsStack.top();
            if (graph.find(curr) != graph.end() && !graph[curr].empty()) 
            {
                dfsStack.push(graph[curr].top());
                graph[curr].pop();
            } 
            else 
            {
                route.push_back(curr);
                dfsStack.pop();
            }
        }
        reverse(route.begin(), route.end());
        return route;
    }
};
