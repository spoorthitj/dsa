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

    ListNode* addOne(ListNode* head) {

        head = reverse(head);

        ListNode* temp = head;
        int carry = 1;

        while (temp != nullptr) {

            int x = temp->data + carry;

            temp->data = x % 10;
            carry = x / 10;

            if (carry == 0)
                break;

            if (temp->next == nullptr)
                break;

            temp = temp->next;
        }

        // Carry remains after the last digit
        if (carry) {
            ListNode* last = new ListNode(carry);
            temp->next = last;
        }

        head = reverse(head);

        return head;
    }
};