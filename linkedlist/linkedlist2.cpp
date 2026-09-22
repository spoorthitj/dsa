class Solution {
public:
    ListNode* sortList(ListNode* &head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* zeroDummy = new ListNode(-1);
        ListNode* oneDummy = new ListNode(-1);
        ListNode* twoDummy = new ListNode(-1);

        ListNode* zero = zeroDummy;
        ListNode* one = oneDummy;
        ListNode* two = twoDummy;

        ListNode* temp = head;

        while (temp != nullptr) {

            if (temp->data == 0) {
                zero->next = temp;
                zero = zero->next;
            }
            else if (temp->data == 1) {
                one->next = temp;
                one = one->next;
            }
            else {
                two->next = temp;
                two = two->next;
            }

            temp = temp->next;
        }

        // Connect the three lists
        zero->next = oneDummy->next;
        one->next = twoDummy->next;
        two->next = nullptr;

        return zeroDummy->next;
    }
};