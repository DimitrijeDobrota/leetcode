class Solution {
  public:
    string complexNumberMultiply(const string num1, const string num2) {
        int a, b, c, d;
        char t;
        stringstream(num1) >> a >> t >> b;
        stringstream(num2) >> c >> t >> d;
        return to_string(a * c - b * d) + "+" + to_string(a * d + b * c) + "i";
    }
};
