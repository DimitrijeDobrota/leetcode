class Solution {
public:
  vector<int> nextLargerNodes(ListNode *head) {
    if (!head) return {};

    int len = 0, i = 0;
    vector<int> res;
    stack<pair<int, int>> st;

    for (ListNode *p = head; p; p = p->next, i++) {
      res.push_back(0);
      while (!st.empty() && p->val > st.top().first) {
        res[st.top().second] = p->val;
        st.pop();
      }
      st.push({p->val, i});
    }
    return res;
  }
};
