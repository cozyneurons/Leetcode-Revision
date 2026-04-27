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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        if (!head) return head;

        unordered_map<int,int> mpp;
        for(int i = 0; i<nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        ListNode* prev = new ListNode(-1);
        prev->next = head;
        ListNode* curr = head;
        int value;
        while(curr)
        {
            value = curr->val;
            if(mpp.find(value)!=mpp.end())
            {
                prev->next = curr->next;
                curr = curr->next;
            }
            else break;
        }
        head = prev->next;
        prev = head;
        cout<<curr->val;
        curr = curr->next;
        while(curr)
        {
            value = curr->val;
            if (mpp.find(value)!=mpp.end())
            {
                prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                prev = prev->next;
                curr = curr->next;
            }
            
        }
        return head;
    }
};
