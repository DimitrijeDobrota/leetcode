class Solution {
    bool seen[21] = {0};
    vector<int> res = vector(39, 0);

    bool rec(const int n, int crnt) {
        while (crnt < size(res) && res[crnt])
            crnt++;
        if (crnt == size(res)) return true;

        for (int i = n; i > 1; i--) {
            if (seen[i] || crnt + i >= size(res) || res[crnt + i]) continue;
            res[crnt + i] = res[crnt] = i;
            seen[i] = true;
            if (rec(n, crnt + 1)) return true;
            seen[i] = false;
            res[crnt + i] = 0;
        }

        if (!seen[1]) {
            res[crnt] = 1;
            seen[1] = true;
            if (rec(n, crnt + 1)) return true;
            seen[1] = false;
        }
        res[crnt] = 0;

        return false;
    }

  public:
    vector<int> constructDistancedSequence(const int n) {
        res.resize(2 * n - 1);
        rec(n, 0);
        return res;
    }
};
