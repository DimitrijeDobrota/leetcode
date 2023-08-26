class Solution {
    ListNode *head = nullptr;
    int size = 0;

  public:
    Solution(ListNode *head) : head(head) {
        for (ListNode *p = head; p; p = p->next)
            size++;
    }

    int getRandom() {
        int elem = rand() % size;
        ListNode *p = head;
        while (elem--)
            p = p->next;
        return p->val;
    }
};
