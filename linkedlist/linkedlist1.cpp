ListNode* odd = head;
ListNode* oddhead = odd;

ListNode* even = head->next;
ListNode* evenhead = even;

if (head == nullptr || head->next == nullptr)
    return head;

while (even != nullptr && even->next != nullptr) {

    odd->next = even->next;
    odd = odd->next;

    even->next = odd->next;
    even = even->next;
}

odd->next = evenhead;

return oddhead;