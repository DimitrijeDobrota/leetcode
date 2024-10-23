class Solution {
    vector<string> res;

    vector<long long> operan;
    vector<char> operat;

    void rec(long long target, const string &num, int start, long long total, long long prev) {
        if (start == size(num)) {
            if (total != target) return;

            res.push_back(to_string(operan[0]));
            for (int i = 0; i < size(operat); i++) {
                res.back() += operat[i] + to_string(operan[i + 1]);
            }

            return;
        }

        operan.push_back(-1);
        operat.push_back('_');
        for (long long i = start, crnt = 0; i < size(num); i++) {
            operan.back() = crnt = crnt * 10 + num[i] - '0';

            operat.back() = '+';
            rec(target, num, i + 1, total + crnt, crnt);

            operat.back() = '-';
            rec(target, num, i + 1, total - crnt, -crnt);

            operat.back() = '*';
            rec(target, num, i + 1, total + prev * (crnt - 1), prev * crnt);

            if (num[start] == '0') break;
        }
        operan.pop_back();
        operat.pop_back();
    }

  public:
    vector<string> addOperators(const string &num, int target) {

        operan.push_back(-1);
        for (long long i = 0, crnt = 0; i < size(num); i++) {
            operan.back() = crnt = crnt * 10 + num[i] - '0';
            rec(target, num, i + 1, crnt, crnt);

            if (num[0] == '0') break;
        }

        return res;
    }
};
