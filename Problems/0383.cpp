class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> us;

        for (char c : magazine)
            us[c]++;

        for (char c : ransomNote)
            if (!us[c]--) return false;

        return true;
    }
};
