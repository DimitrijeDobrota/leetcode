class Solution {
  public:
    bool doesAliceWin(const string &s) const {
        for (const char c : s) {
            if (c == 'a') return true;
            if (c == 'e') return true;
            if (c == 'i') return true;
            if (c == 'o') return true;
            if (c == 'u') return true;
        }

        return false;
    }
};
