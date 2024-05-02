# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # two pointers
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        temp = ListNode(0)
        # link temp to head
        # this deals with edge case
        temp.next = head

        front = temp
        back = temp

        for _ in range(n + 1):
            front = front.next

        while front is not None:
            front = front.next
            back = back.next

        back.next = back.next.next
        return temp.next
