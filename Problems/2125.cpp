// 2125. Number of Laser Beams in a Bank
class Solution {
  public:
    int numberOfBeams(const vector<string> &bank) {
        vector<int> count;
        count.reserve(bank.size());
        for (const auto &floor : bank) {
            int cnt = 0;
            for (char c : floor)
                if (c == '1') cnt++;
            if (cnt) count.push_back(cnt);
        }

        int res = 0;
        for (int i = 1; i < count.size(); i++)
            res += count[i] * count[i - 1];
        return res;
    }
};
