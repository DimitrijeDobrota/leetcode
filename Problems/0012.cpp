class Solution {
public:
  vector<vector<string>> vvs = {
      {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
      {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
      {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
      {"", "M", "MM", "MMM",  "*", "*",  "*",   "*",    "*",  "*"},
  };

  string intToRoman(int num) {
    int exp = 0;
    string res = "";
    do { res = vvs[exp++][num % 10] + res; } while ((num /= 10) > 0);

    return res;
  }
};
