class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) 
    {
        if (!head->next) return {0};
        stack<pair<int,int>> stk;
        ListNode* temp = head;
        int n = 0;
        while(temp)
        {
            n++;
            temp = temp->next;
        }
        vector<int> ans(n, 0);
        temp = head;
        int index = 0;
        stk.push({temp->val, index});
        temp = temp->next;
        while(temp)
        {
            index++;
            while(!stk.empty() && temp->val > stk.top().first)
            {
                ans[stk.top().second] = temp->val;
                stk.pop();
            }
            stk.push({temp->val, index});
            temp = temp->next;
        }
        return ans;
    }
};
