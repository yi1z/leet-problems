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
    ListNode* swapPairs(ListNode* head) {
        ListNode* result = new ListNode(0);
        ListNode* curr = result;

        while (head != nullptr){
            if (head->next != nullptr){
                curr->next = new ListNode(head->next->val);
                curr = curr->next;
                curr->next = new ListNode(head->val);
                curr = curr->next;

                head = head->next->next;
            }
            else{
                curr->next = head;
                break;
            }
        }
        return result->next;
    }
};