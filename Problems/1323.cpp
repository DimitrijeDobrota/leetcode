class Solution {
public:
  int maximum69Number(int num) {
    string s = to_string(num);
    for (int i = 0; i < size(s); i++) {
      if (s[i] == '9') continue;
      s[i] = '9';
      return stoi(s);
    }
    return num;
  }
};
