class Solution {
  public:
    int minimumCardPickup(const vector<int> &cards) const {
        static int pos[1000001];
        int res = INT_MAX;

        memset(pos, 0xFF, sizeof(pos));
        for (int i = 0; i < size(cards); i++) {
            if (pos[cards[i]] != -1) res = min(res, i - pos[cards[i]]);
            pos[cards[i]] = i;
        }

        return res != INT_MAX ? res + 1 : -1;
    }
};
