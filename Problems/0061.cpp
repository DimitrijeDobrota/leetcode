class Solution {
    int len(ListNode *head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }

  public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return nullptr;

        k %= len(head);
        ListNode *p, *t;
        t = p = head;
        for (; p->next; p = p->next) {
            if (k)
                k--;
            else
                t = t->next;
        }
        p->next = head;
        head = t->next;
        t->next = nullptr;
        return head;
    }
};
