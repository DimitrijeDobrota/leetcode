class Solution {
  int gcd(int a, int b) {
    if (!a) return b;
    if (!b) return a;
    return gcd(b, a % b);
  }

public:
  ListNode *insertGreatestCommonDivisors(ListNode *head) {
    ListNode *crnt = head, *next = head->next;
    while (next) {
      crnt->next = new ListNode(gcd(crnt->val, next->val), next);
      crnt = next;
      next = next->next;
    }
    return head;
  }
};
