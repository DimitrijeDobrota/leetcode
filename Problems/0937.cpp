class Solution {
  public:
    vector<string> reorderLogFiles(const vector<string> &logs) const {
        const int n = size(logs);

        typedef tuple<bool, int, string, string> record;
        vector<record> vec(n);

        for (int i = 0; i < n; i++) {
            bool letter = false, space = false;
            int idx = 0;
            for (int j = 0; j < size(logs[i]); j++) {
                if (logs[i][j] == ' ')
                    space = true;
                else if (!space)
                    idx = j;
                else {
                    letter = isalpha(logs[i][j]);
                    break;
                }
            }
            vec[i] = {!letter, letter ? 0 : i, logs[i].substr(idx + 2), logs[i].substr(0, idx + 1)};
        }

        sort(begin(vec), end(vec));
        vector<string> res(n);
        for (int i = 0; i < n; i++)
            res[i] = get<3>(vec[i]) + " " + get<2>(vec[i]);
        return res;
    }
};
