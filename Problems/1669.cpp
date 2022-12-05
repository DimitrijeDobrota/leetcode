class Solution {
public:
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    ListNode *ap, *bp;
    a--;
    for (ap = list1; a; a--, b--) ap = ap->next;
    for (bp = ap; b; b--) bp = bp->next;
    ap->next = list2;
    while (ap->next) ap = ap->next;
    ap->next = bp->next;
    return list1;
  }
};
