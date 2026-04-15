/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

public:
    int pairSum(ListNode* head) 
    {
        stack<int> stk;
        ListNode* curr = head;

        while(curr)
        {
            stk.push(curr->val);
            curr = curr->next;
        }
        int N = stk.size();
        curr = head;
        int result = 0;
        for (int i = 1; i<=N/2; i++)
        {
            result = max (result, curr->val + stk.top());
            stk.pop();
            curr = curr->next;
        }
        return result;
    }
};
