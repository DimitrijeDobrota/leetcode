class Solution {
public:
  string getHint(string secret, string guess) {
    int n = secret.size(), cows = 0, bulls = 0;
    unordered_map<char, int> ums;
    for (int i = 0; i < n; i++)
      if (guess[i] == secret[i])
        bulls++;
      else
        ums[secret[i]]++;

    for (int i = 0; i < n; i++) {
      if (guess[i] == secret[i])
        continue;
      else if (ums[guess[i]] > 0)
        cows++;
      ums[guess[i]]--;
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
  }
};
