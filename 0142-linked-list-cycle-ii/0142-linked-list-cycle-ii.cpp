class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                fast=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return fast;
            }
            
        }
        return NULL;
    }
};