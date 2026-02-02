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
    ListNode* reverseList(ListNode* head) 
        {
            ListNode* prev = nullptr;
            ListNode* temp = head;
            while(temp)
            {
                ListNode* front = temp->next;
                temp->next = prev;
                prev = temp;
                temp = front;

            }
            return prev;
        }
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if (!head) return nullptr;
        head = reverseList(head);
        ListNode* node = head;
        ListNode* prev = nullptr;
        int cnt = 1;
        if (n==1)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return reverseList(head);
        }
        while(node)
        {
            if (cnt==n)
            {
                prev->next = node->next;
                delete node;
                break;
            }
            prev = node;
            node = node->next;
            cnt++;
        }
        return reverseList(head);
    }
};
