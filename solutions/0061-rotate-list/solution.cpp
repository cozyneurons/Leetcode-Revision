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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head || !head->next) return head;
        ListNode* temporary = head;
        long long n = 0;
        while(temporary)
        {
            temporary = temporary->next;
            n++;
        }
        k = k%n;
        while (k)
        {
            ListNode* temp = head;
            ListNode* prev = nullptr;
            while(temp->next)
            {
                prev = temp;
                temp = temp->next;
            }
            temp->next = head;
            head = temp;
            prev->next = NULL;
            k--;
        }
        return head;
    }
};
