/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int getLength(ListNode* head) 
    {
        int length = 0;
        while (head != nullptr) 
        {
            length++;
            head = head->next;
        }
        return length;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        ListNode *t1 = headA;
        ListNode *t2 = headB;
        if (lenA > lenB) 
        {
            int d = lenA - lenB;
            while (d--) 
            {
                t1 = t1->next;
            }
        } 
        else 
        {
            int d = lenB - lenA;
            while (d--) 
            {
                t2 = t2->next;
            }
        }
        while (t1 != nullptr && t2 != nullptr)
        {
            if (t1 == t2) return t1;
            t1 = t1->next;
            t2 = t2->next;
        }
        return nullptr;
    }
};
