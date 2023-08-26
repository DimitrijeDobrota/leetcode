class Solution {
  public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string answer(num1.size() + num2.size(), '0');

        for (int p2 = 0; p2 < num2.size(); p2++) {
            int d2 = num2[p2] - '0';
            for (int p1 = 0; p1 < num1.size(); p1++) {
                int d1 = num1[p1] - '0';

                int numZero = p1 + p2;
                int carry = answer[numZero] - '0';
                int mul = d1 * d2 + carry;
                answer[numZero] = mul % 10 + '0';
                answer[numZero + 1] += mul / 10;
            }
        }
        if (answer.back() == '0') answer.pop_back();

        reverse(answer.begin(), answer.end());
        return answer;
    }
};
