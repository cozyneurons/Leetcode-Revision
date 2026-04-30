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
private:
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* prev = nullptr;
        while(head)
        {
            ListNode* front = head->next;
            head->next = prev;
            prev = head;
            head = front;
        }
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        if (!head) return head;
        head = reverseLL(head);

        ListNode* curr = head;
        while(curr && curr->next)
        {
            while (curr->next && curr->val > curr->next->val)
            {
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }


        return reverseLL(head);
    }
};
