class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast n positions ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both together
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete the node
        slow->next = slow->next->next;

        return dummy->next;
    }
};