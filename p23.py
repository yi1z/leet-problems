# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def toList(self, linkedlist):
        result = []
        curr = linkedlist

        while curr is not None:
            result.append(curr.val)
            curr = curr.next

        return result

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        temp = []
        
        for lst in lists:
            temp.extend(self.toList(lst))

        temp = sorted(temp)
        
        # convert to linked list
        result = ListNode(0)
        head = result
        for i in temp:
            result.next = ListNode(i)
            result = result.next

        return head.next