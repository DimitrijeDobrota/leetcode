class Solution {
  public:
    bool uniqueOccurrences(const vector<int> &arr) {
        static int count[2001], seen[1001];
        memset(count, 0x00, sizeof(count));
        memset(seen, 0x00, sizeof(seen));
        for (const int n : arr)
            count[n + 1000]++;
        for (const int n : count) {
            if (!n) continue;
            if (seen[n]) return false;
            seen[n] = 1;
        }
        return true;
    }
};
