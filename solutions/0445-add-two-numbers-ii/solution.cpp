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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* lnew = reverseList(l1);
        ListNode* lnew2 = reverseList(l2);
        ListNode* Naya = new ListNode(0);
        ListNode* Naya2 = Naya;
        int carry = 0;
        while(lnew && lnew2)
        {
            int sum = lnew->val + lnew2->val + carry;
            carry = sum/10;
            Naya->next = new ListNode(sum%10);
            Naya = Naya->next;
            lnew = lnew->next;
            lnew2 = lnew2->next;
        } 
        while(lnew)
        {
            int sum = lnew->val + carry;
            carry = sum/10;
            Naya->next = new ListNode(sum%10);
            Naya = Naya->next;
            lnew = lnew->next;
        } 
        while(lnew2)
        {
            int sum = lnew2->val + carry;
            carry = sum/10;
            Naya->next = new ListNode(sum%10);
            Naya = Naya->next;
            lnew2 = lnew2->next;
        } 
        if (carry) {
            Naya->next = new ListNode(carry);
        }
        return reverseList(Naya2->next);    
    }
};
