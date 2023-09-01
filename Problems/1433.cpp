class Solution {
  public:
    bool checkIfCanBreak(const string &s1, const string &s2) const {
        int vec[27] = {0};

        for (int i = 0; i < s1.size(); i++) {
            vec[s1[i] & 0x1F]++;
            vec[s2[i] & 0x1F]--;
        }

        bool b1 = false, b2 = false;
        for (int i = 1, total = 0; i <= 26; i++) {
            total += vec[i];
            if (total > 0) b1 = true;
            if (total < 0) b2 = true;
            if (b1 && b2) return false;
        }
        return true;
    }
};
