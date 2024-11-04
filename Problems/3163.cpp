class Solution {
  public:
    string compressedString(const string &word) const {
        const int n = size(word);
        string res;

        for (int i = 0; i < n;) {
            const char c = word[i++];
            int cnt = 1;

            while (i < n && cnt < 9 && word[i] == c)
                cnt++, i++;
            res += to_string(cnt) + c;
        }

        return res;
    }
};
