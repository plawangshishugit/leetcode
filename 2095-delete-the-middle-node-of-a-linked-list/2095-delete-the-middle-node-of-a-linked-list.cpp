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
    ListNode* deleteMiddle(ListNode* head) {
        // Only one node, delete it
        if (head == nullptr || head->next == nullptr) {
            return nullptr;  
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            //prev will have node before slow since we want to delete slow
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        //delete slow
        prev->next = slow->next;
        delete slow;

        return head;
    }
};
