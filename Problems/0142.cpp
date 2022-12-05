class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (!head) return nullptr;

    ListNode *slow, *fast;
    fast = slow = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        fast = head;
        while (fast != slow) {
          fast = fast->next;
          slow = slow->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};
