class Solution {
  public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> um;
        unordered_set<char> us;

        for (int i = 0; i < s.size(); i++) {
            if (!um.count(s[i])) {
                if (us.count(t[i])) return false;
                um[s[i]] = t[i];
                us.insert(t[i]);
            } else if (um[s[i]] != t[i])
                return false;
        }

        return true;
    }
};
