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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* front = temp;
        ListNode* back = temp;

        for (int _ = 0; _ < n; _ ++){
            front = front->next;
        }

        while (front->next != nullptr){
            front = front->next;
            back = back->next;
        }

        back->next = back->next->next;

        return temp->next;
    }
};