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
