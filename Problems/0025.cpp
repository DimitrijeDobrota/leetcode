class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    stack<ListNode *> st;
    ListNode *tmp, *dummy, *next;

    tmp = dummy = new ListNode(-1, nullptr);
    for (ListNode *p = head; p; p = next) {
      next = p->next;
      st.push(p);
      if (st.size() == k) {
        while (!st.empty()) {
          tmp = tmp->next = st.top();
          st.pop();
        }
        tmp->next = next;
      }
    }
    return dummy->next;
  }
};
