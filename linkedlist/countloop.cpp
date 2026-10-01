class Solution {
public:
    int findLengthOfLoop(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return 0;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        // No cycle
        if (fast == nullptr || fast->next == nullptr)
            return 0;

        // Step 2: Find starting point of cycle
        slow = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 3: Count length of cycle
        int count = 1;
        fast = slow->next;

        while (fast != slow) {
            count++;
            fast = fast->next;
        }

        return count;
    }
};