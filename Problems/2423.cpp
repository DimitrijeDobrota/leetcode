class Solution {
    int count[27] = {};
    bool check(int crnt, int goal) {
        for (int j = 1; j <= 26; j++) {
            if (crnt == j || !count[j]) continue;
            if (goal == -1)
                goal = count[j];
            else if (count[j] != goal)
                return false;
        }
        return true;
    }

  public:
    bool equalFrequency(const string &word) {
        for (const char c : word)
            count[c & 0x1F]++;

        for (int i = 1; i <= 26; i++) {
            if (!count[i]) continue;
            const int goal = count[i] > 1 ? count[i] - 1 : -1;
            if (check(i, goal)) return true;
        }

        return false;
    }
};
