class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* temp = head;
        int n = 1;

        // Find tail and length
        while (temp->next != nullptr) {
            temp = temp->next;
            n++;
        }

        // Reduce k
        k = k % n;
        if (k == 0)
            return head;

        // Make circular
        temp->next = head;

        // Find new tail
        int r = n - k;
        ListNode* temp1 = head;

        for (int i = 1; i < r; i++) {
            temp1 = temp1->next;
        }

        // New head
        ListNode* result = temp1->next;

        // Break circle
        temp1->next = nullptr;

        return result;
    }
};