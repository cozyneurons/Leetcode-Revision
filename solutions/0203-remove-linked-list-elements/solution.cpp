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
    ListNode* removeElements(ListNode* head, int val) 
    {
        if (!head) return head;
        while(head && head->val==val) head = head->next;
        ListNode* temp = head;
        ListNode* prev = new ListNode(-1);
        while(temp)
        {
            ListNode* front = temp->next;
            if (temp->val==val) 
            {
                prev->next = front;
            }
            else prev = temp;
            temp = front;
        }
        return head;
    }
};
