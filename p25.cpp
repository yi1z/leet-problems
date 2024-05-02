/**
 * Definition for singly-linked list->
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
        if (head == nullptr){
            return head;
        }
        
        if (k == 1){
            return head;
        }
        
        ListNode* new_head = new ListNode(0, head);
        ListNode* prev_tail = new_head;
        ListNode* tail = new_head;

        while (true){
            // check if there are enough nodes
            ListNode* temp = head;
            for (int i = 0; i < k; i ++){
                if (temp == nullptr){
                    return new_head->next;
                }
                temp = temp->next;
            }

            // reverse the current partition
            for (int i = 0; i < k - 1; i ++){
                tail = head->next;
                head->next = tail->next;
                tail->next = prev_tail->next;
                prev_tail->next = tail;
            }

            // move to the next partition
            prev_tail = head;
            head = head->next;
            if (head == nullptr){
                return new_head->next;
            }
            tail = head->next;
        }
    }
};