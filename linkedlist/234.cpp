class Solution {
public:

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return true;

        // Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* second = reverse(slow);

        // Compare
        ListNode* first = head;
        ListNode* temp = second;

        while (temp != nullptr) {
            if (first->val != temp->val)
                return false;

            first = first->next;
            temp = temp->next;
        }

        return true;
    }
};