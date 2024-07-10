class Solution {
  public:
    int minOperations(const vector<string> &logs) const {
        int res = 0;

        for (const auto &log : logs) {
            if (log == "./") continue;
            if (log == "../")
                res -= res != 0;
            else
                res++;
        }

        return res;
    }
};
