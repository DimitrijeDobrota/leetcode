class Solution {
  public:
    int numJewelsInStones(const string &jewels, const string &stones) const {
        static const auto convert = [](char c) { return isupper(c) ? c - 'A' : c - 'a' + 26; };

        static int seen[52];
        int res = 0;

        memset(seen, 0x00, sizeof(seen));
        for (const char c : jewels)
            seen[convert(c)] = true;
        for (const char c : stones)
            res += seen[convert(c)];

        return res;
    }
};
