class Solution {
  public:
    bool rotateString(const string &s, const string &goal) const {
        return size(s) == size(goal) && (s + s).find(goal) != string::npos;
    }
};
