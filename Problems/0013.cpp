class Solution {
public:
  int value(char c) {
    switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return -10000;
    }
  }

  int romanToInt(string s) {
    int size = s.size();
    int res = 0;
    for (int i = 0; i < size - 1; i++) {
      int a = value(s[i]);
      int b = value(s[i + 1]);
      if (a >= b)
        res += a;
      else
        res -= a;
    }
    res += value(s[size - 1]);

    return res;
  }
};
