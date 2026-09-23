class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // Only one node
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is now just before the middle
        slow->next = slow->next->next;

        return head;
    }
};