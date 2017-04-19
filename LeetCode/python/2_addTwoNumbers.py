# Definition for singly-linked list.
import string
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def show(self, a):
        while(a):
            print a.val,
            a = a.next

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        num_1 = ''
        while (l1):
            num_1 += str(l1.val)
            l1 = l1.next
        list_1 = list(num_1)
        list_1.reverse()
        num1 = int(''.join(list_1))
        num_2 = ''
        while(l2):
            num_2 += str(l2.val)
            l2 = l2.next
        list_2 = list(num_2)
        list_2.reverse()
        num2 = int(''.join(list_2))
        res = num1 + num2
        num3 = list(str(res))
        num3.reverse()
        l3 = ListNode(0)
        temp = l3
        for i in range(len(num3)):
            t = ListNode(int(num3[i]))
            temp.next = t
            temp = temp.next
        return l3.next


so = Solution()

L = ListNode(0)
t= ListNode(2)
m = ListNode(3)
a = ListNode(1)

n = ListNode(6)
k = ListNode(4)
b = ListNode(3)

b.next = k
k.next = n
a.next = t
t.next =m
L.show(a)
print '\n'
L.show(b)
print '\n'
L.show(so.addTwoNumbers(a,b))
