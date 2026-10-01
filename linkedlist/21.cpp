class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        ListNode* slow = list1;
        ListNode* fast = list2;

        while (slow != nullptr && fast != nullptr) {
            if (slow->val <= fast->val) {
                temp->next = slow;
                slow = slow->next;
            } else {
                temp->next = fast;
                fast = fast->next;
            }

            temp = temp->next;
        }

        while (slow != nullptr) {
            temp->next = slow;
            slow = slow->next;
            temp = temp->next;
        }

        while (fast != nullptr) {
            temp->next = fast;
            fast = fast->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};