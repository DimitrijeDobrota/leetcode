class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        int mlen = 200;
        for (string &s : strs)
            mlen = min(mlen, (int)s.size());

        string res = "";
        for (int i = 0; i < mlen; i++) {
            for (int j = 1; j < strs.size(); j++)
                if (strs[j][i] != strs[0][i]) return res;
            res += strs[0][i];
        }
        return res;
    }
};
