class Solution {
  public:
    bool canChange(const string &start, const string &target) const {
        const int n = size(start);
        int i = 0, j = 0;

        while (i < n || j < n) {
            while (i < n && start[i] == '_')
                i++;
            while (j < n && target[j] == '_')
                j++;

            if (i == n || j == n) return i == n && j == n;

            if (start[i] != target[j]) return false;
            if (start[i] == 'R' ? i > j : i < j) return false;

            i++, j++;
        }

        return true;
    }
};
