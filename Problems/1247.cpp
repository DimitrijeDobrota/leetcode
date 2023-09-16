class Solution {
  public:
    int minimumSwap(const string &s1, const string &s2) {
        int count[2] = {0};
        for (int i = 0; i < s1.size(); i++)
            if (s1[i] != s2[i]) count[s1[i] & 1]++;

        if ((count[0] + count[1]) % 2) return -1;
        return (count[0] + 1) / 2 + (count[1] + 1) / 2;
    }
};
