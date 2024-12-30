class Solution {
  public:
    string defangIPaddr(const string &address) const {
        string res;

        for (const char c : address) {
            if (c != '.')
                res += c;
            else
                res += "[.]";
        }

        return res;
    }
};
