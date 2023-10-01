class Solution {
  public:
    string reverseWords(string &s) {
        s.push_back(' ');
        for (int k = 0, last = -1; k <= s.size(); k++) {
            if (s[k] != ' ') continue;
            int i = last + 1, j = k - 1;
            while (i < j)
                swap(s[i++], s[j--]);
            last = k;
        }
        s.pop_back();
        return s;
    }
};
