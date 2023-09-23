class Solution {
  public:
    bool canConstruct(const string &s, int k) {
        if (s.size() < k) return false;

        int count[27] = {0};
        for (const char c : s)
            count[c & 0x1F]++;

        int singles = 0;
        for (int i = 1; i <= 26; i++)
            singles += count[i] & 1;
        return singles <= k;
    }
};

class Solution {
  public:
    bool canConstruct(const string &s, int k) {
        if (s.size() < k) return false;

        bitset<27> bs;
        for (const char c : s)
            bs.flip(c & 0x1F);
        return bs.count() <= k;
    }
};
