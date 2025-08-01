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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;  // If 0 or 1 node, nothing to do
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;  // Save the start of even list
        
        while (even && even->next) {
            odd->next = even->next;     // Link odd to next odd
            odd = odd->next;            // Move odd pointer
            even->next = odd->next;     // Link even to next even
            even = even->next;          // Move even pointer
        }
        
        odd->next = evenHead;  // Connect end of odd list to start of even list
        return head;
    }
};
