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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {\
        if (list1 == nullptr){
            return list2;
        }

        if (list2 == nullptr){
            return list1;
        }

        ListNode* a = list1;
        ListNode* b = list2;

        ListNode* result = new ListNode(0);
        ListNode* curr = result;

        while (a != nullptr && b != nullptr){
            // compare the two items in list1 and list2
            if (a->val < b->val){
                curr->next = a;
                curr = curr->next;
                a = a->next;
            }
            else{
                curr->next = b;
                curr = curr->next;
                b = b->next;
            }
        }

        if (a != nullptr){
            curr->next = a;
        }

        if (b != nullptr){
            curr->next = b;
        }

        return result->next;
    }
};