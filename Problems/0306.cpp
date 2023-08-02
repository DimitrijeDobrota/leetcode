class Solution {
public:
  bool isAdditiveNumber(const string &num) {
    for (int i = 1; i < num.size(); i++) {
      long num1 = stol(num.substr(0, i));
      for (int j = i + 1; j < num.size(); j++) {
        long n1 = num1, n2 = stol(num.substr(i, j - i)), n3;
        int next = j;
        while (next < num.size()) {
          const string pre = to_string(n3 = n1 + n2);

          auto res =
              std::mismatch(pre.begin(), pre.end(), num.substr(next).begin());
          if (res.first != pre.end()) break;

          next += pre.size();
          n1 = n2, n2 = n3;
        }
        if (next == num.size()) return true;
        if (num[i] == '0') break;
      }
      if (num[0] == '0') break;
    }
    return false;
  }
};
