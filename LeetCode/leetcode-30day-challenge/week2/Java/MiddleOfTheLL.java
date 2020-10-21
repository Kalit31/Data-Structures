/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode(int x) { val = x; } }
 */

//Type: LinkedLists, Pointers

//Approach: Maintain a slowPtr and a fastPtr. 
//          The slowPtr moves 1 index in a step, while fastPtr moves 2 indices.
//          So, when the fastPtr would have reached the end of the linkedlist,
//          the slowPtr would be at the middle of the linkedlist.
//Complexity: O(N) time and O(1) space

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode slowPtr = head;
        ListNode fastPtr = head;
        while (fastPtr != null && fastPtr.next != null) {
            fastPtr = fastPtr.next.next;
            slowPtr = slowPtr.next;
        }
        return slowPtr;
    }
}