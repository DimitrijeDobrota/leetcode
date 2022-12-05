class Solution {
public:
  string addStrings(string num1, string num2) {
    if (num1 == "0" && num2 == "0") return "0";

    string res = "";
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    int add = 0;
    while (i >= 0 || j >= 0 || add) {
      if (i >= 0) add += num1[i--] - '0';
      if (j >= 0) add += num2[j--] - '0';
      res += to_string(add % 10);
      add /= 10;
    }

    reverse(res.begin(), res.end());
    return res;
  }

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (!l1 || !l2) return nullptr;

    string s1 = "", s2 = "";

    for (ListNode *p = l1; p; p = p->next) s1 += '0' + p->val;

    for (ListNode *p = l2; p; p = p->next) s2 += '0' + p->val;

    string s = addStrings(s1, s2);
    ListNode *h, *t;
    t = h = new ListNode();
    for (char c : s) t = t->next = new ListNode(c - '0');

    return h->next;
  }
};
