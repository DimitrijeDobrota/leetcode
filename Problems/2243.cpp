class Solution {
public:
  string digitSum(string s, int k) {
    while (s.size() > k) {
      string tmp = "";
      for (int i = 0; i < s.size();) {
        int sum = 0;
        for (int j = 0; j < k && i < s.size(); i++, j++) sum += s[i] - '0';
        tmp += to_string(sum);
      }
      s = tmp;
    }
    return s;
  }
};
