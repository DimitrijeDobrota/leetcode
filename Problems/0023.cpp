// Naive solution, barely passed
class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *dummy, *tmp;
        tmp = dummy = new ListNode;

        while (true) {
            int mini = INT_MAX, index = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] && lists[i]->val < mini) {
                    index = i;
                    mini = lists[i]->val;
                }
            }
            if (index == -1) break;
            ListNode *t = lists[index];
            lists[index] = lists[index]->next;
            tmp = tmp->next = t;
        }
        return dummy->next;
    }
};

// Proper solution
class Solution {
    typedef pair<int, int> pii;

  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *dummy, *tmp;
        tmp = dummy = new ListNode;

        auto cmp = [](const pii &a, const pii &b) { return a.first > b.first; };
        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < lists.size(); i++)
            if (lists[i]) pq.push({lists[i]->val, i});
        while (!pq.empty()) {
            int index = pq.top().second;
            pq.pop();
            ListNode *t = lists[index];
            lists[index] = lists[index]->next;
            if (lists[index]) pq.push({lists[index]->val, index});
            tmp = tmp->next = t;
        }
        return dummy->next;
    }
};
