class Solution {
public:
    int minOperations(vector<int>& arr) 
    {
        int n = arr.size();
        int count = 0;
        deque<int> dq;
        for (int i = 0; i<n; i++)
        {
            while(!dq.empty() && i > dq.front()+2)
            {
                dq.pop_front();
            }
            if ((arr[i] + dq.size())%2==0)
            {
                if (i==n-2 || i==n-1) return -1;
                dq.push_back(i);
                count++;
            }
        }
        return count;
    }
};
