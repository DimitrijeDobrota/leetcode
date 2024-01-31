class Solution {
  public:
    bool checkStrings(const string &s1, const string &s2) const {
        int count1[27] = {0}, count2[27] = {0};

        for (int i = 0; i < size(s1); i += 2) {
            count1[s1[i] & 0x1F]++;
            count1[s2[i] & 0x1F]--;
            count2[s1[i + 1] & 0x1F]++;
            count2[s2[i + 1] & 0x1F]--;
        }

        for (int i = 1; i <= 26; i++) {
            if (count1[i] || count2[i]) return false;
        }

        return true;
    }
};
