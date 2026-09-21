class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        // Dummy node to build the answer
        ListNode* answer = new ListNode(0);
        ListNode* temp = answer;

        int carry = 0;

        while (temp1 != nullptr || temp2 != nullptr || carry != 0) {

            int x = 0;

            if (temp1 != nullptr)
                x += temp1->val;

            if (temp2 != nullptr)
                x += temp2->val;

            x += carry;

            // Current digit
            int digit = x % 10;

            // Carry for next digit
            carry = x / 10;

            // Add digit to answer
            temp->next = new ListNode(digit);
            temp = temp->next;

            // Move input pointers
            if (temp1 != nullptr)
                temp1 = temp1->next;

            if (temp2 != nullptr)
                temp2 = temp2->next;
        }

        return answer->next;
    }
};