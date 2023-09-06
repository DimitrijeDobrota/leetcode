class Solution {
  public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        int size = 0, part, extra;

        for (ListNode *tmp = head; tmp; tmp = tmp->next)
            size++;
        if (k >= size) {
            part = 1;
            extra = 0;
        } else {
            part = size / k;
            extra = size - (part * k);
        }

        vector<ListNode *> res;
        ListNode *crnt = head, *tmp;
        while (size >= part) {
            res.push_back(crnt);
            for (int i = 1; i < part; i++)
                crnt = crnt->next;
            if (extra-- > 0) crnt = crnt->next, size--;
            size -= part;
            tmp = crnt->next;
            crnt->next = nullptr;
            crnt = tmp;
        }

        while (res.size() < k)
            res.push_back(nullptr);

        return res;
    }
};
