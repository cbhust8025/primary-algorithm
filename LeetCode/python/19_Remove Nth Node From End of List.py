# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        num = 0
        node = head
        knode = head
        k1node = head
        if (head == None):
            return head
        while (node.next):
            if (num < n):
                num += 1
            if (num >= n):
                num += 1
                k1node = knode
                knode = knode.next
            node = node.next
        if(knode == head):
            return head.next
        if (num < n - 1):
            return None
        else:
            k1node.next = knode.next
            return head


    def showA(self, head):
        if(head == None):
            return None
        else:
            while(head):
                print head.val,'->',
                head = head.next
            print 'None'
s = Solution()
a = ListNode(1)
b = ListNode(2)
c = ListNode(3)
d = ListNode(4)
e = ListNode(5)
a.next = b
b.next = c
c.next = d
d.next = e
s = Solution()
s.showA(d)
ttt = s.removeNthFromEnd(d, 2)
s.showA(ttt)