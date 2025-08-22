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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        // Step 1: Find the length of the list
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        // Step 2: Connect tail to head to make it circular
        tail->next = head;
        // Step 3: Calculate the actual rotations needed
        k = k % length;
        int stepsToNewHead = length - k;
        // Step 4: Move to the new head
        ListNode* newTail = tail;
        while (stepsToNewHead--) {
            newTail = newTail->next;
        }
        // Step 5: Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};