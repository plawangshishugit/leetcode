/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */



class Solution {
public:
    // void deleteNode(ListNode* node) {
    //     ListNode *temp = node -> next;
    //     node -> val = node -> next ->val;
    //     node -> next = node -> next -> next;
    //     delete temp;    
    //     }
    void deleteNode(ListNode* node) {
    auto nN = node->next;
    *node = *nN;
    delete nN;
}
};

//for this type of problem in which you dont have access to the head then 
//there is a smart move that you take the node which you have to delete 
// and you copy the whole data of next node to the node and 
//instead of deleting the node you delete the next node of the given node \U0001f601