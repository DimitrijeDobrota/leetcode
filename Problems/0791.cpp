class Solution {
  public:
    string customSortString(const string &order, string &s) {
        uint8_t index[27] = {0};
        for (int i = 0; i < order.size(); i++)
            index[order[i] & 0x1F] = i;
        sort(begin(s), end(s), [&](const char a, const char b) { return index[a & 0x1F] < index[b & 0x1F]; });
        return s;
    }
};
