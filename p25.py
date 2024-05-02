# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if (head is None):
            return head
        if (k == 1):
            return head
        
        new_head = ListNode(0, head)
        prev_tail = new_head
        tail = new_head

        while True:
            # check if there are enough nodes
            temp = head
            for _ in range(k):
                if temp is None:
                    return new_head.next
                temp = temp.next

            # reverse the current partition
            for _ in range(k - 1):
                tail = head.next
                head.next = tail.next
                tail.next = prev_tail.next
                prev_tail.next = tail

            # move to the next partition
            prev_tail = head
            head = head.next
            if head is None:
                return new_head.next
            tail = head.next

