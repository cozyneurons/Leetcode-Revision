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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (!head) return NULL;
        ListNode* prev = head;
        ListNode* temp = head;
        while(temp || prev)
        {
            temp = temp->next;
            while (temp!=NULL && temp->val == prev->val)
            {
                prev->next = temp->next;
                temp = temp->next;
            }
            prev = prev->next;
        }
        return head;
    }
};
