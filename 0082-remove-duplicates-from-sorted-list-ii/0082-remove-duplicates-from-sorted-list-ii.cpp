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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* dummy = new ListNode(0,head);

        ListNode *prev=dummy, *t1=head, *t2=head->next;
        while(t2!=nullptr){
            if(t1->val == t2->val){
                t2=t2->next;
                while(t2!=nullptr && t1->val == t2->val){
                    t2=t2->next;
                }
                prev->next=t2;
                t1=t2;
                if(t2!=nullptr) t2=t2->next;
            }
            else{
                prev=t1;
                t1=t2;
                if(t2!=nullptr) t2=t2->next;

            }
        }
        return dummy->next;
        
    }
};