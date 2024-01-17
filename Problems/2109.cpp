class Solution {
  public:
    string addSpaces(const string &s, const vector<int> &spaces) const {
        static char res[600001];
        int i = 0, j = 0, k = 0;
        while (i < size(s)) {
            if (j < size(spaces) && i == spaces[j])
                res[k++] = ' ', j++;
            else
                res[k++] = s[i++];
        }
        return string(res, k);
    }
};
