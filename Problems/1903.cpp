class Solution {
  public:
    string largestOddNumber(const string &num) const {
        for (int i = num.size() - 1; i >= 0; i--) {
            if ((num[i] & 0x1F) % 2) return num.substr(0, i + 1);
        }
        return "";
    }
};
