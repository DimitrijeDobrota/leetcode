class Solution {
  public:
    string removeOccurrences(string s, const string &part) {
        for (int pos = s.find(part); pos != string::npos; pos = s.find(part))
            s.erase(pos, part.size());
        return s;
    }
};
