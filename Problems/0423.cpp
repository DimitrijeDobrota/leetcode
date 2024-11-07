class Solution {
  public:
    string originalDigits(const string &s) {
        string word[10] = {"zero", "two", "six", "eight", "three", "seven", "five", "four", "one", "nine"};
        uint8_t mapping[10] = {0, 2, 6, 8, 3, 7, 5, 4, 1, 9};
        uint32_t count[26] = {0}, digits[10] = {0};
        char *letters = "zwxghsvuoi";
        string res;

        for (const char c : s)
            count[c - 'a']++;
        for (int i = 0; i <= 9; i++) {
            const int cnt = digits[mapping[i]] = count[letters[i] - 'a'];
            for (const char c : word[i])
                count[c - 'a'] -= cnt;
        }
        for (int i = 0; i <= 9; i++)
            res += string(digits[i], '0' + i);

        return res;
    }
};
