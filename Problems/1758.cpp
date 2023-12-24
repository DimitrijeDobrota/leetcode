class Solution {
  public:
    int minOperations(const string &s) const {
        int num = 0, crnt = 1;
        for (const char c : s) {
            if ((c & 0xF) != crnt) num++;
            crnt = !crnt;
        }
        return min(num, (int)size(s) - num);
    }
};
