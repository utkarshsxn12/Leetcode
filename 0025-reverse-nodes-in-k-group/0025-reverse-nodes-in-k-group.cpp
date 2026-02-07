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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || !head) return head;

        ListNode* end = head;
        for (int i = 0; i < k; i++) {
            if (!end) return head;
            end = end->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head->next = reverseKGroup(end, k);
        return prev;
    }
};
