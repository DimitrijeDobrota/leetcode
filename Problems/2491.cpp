class Solution {
  public:
    long long dividePlayers(const vector<int> &skill) const {
        static int count[1001];
        memset(count, 0x00, sizeof(count));

        const int sum = accumulate(begin(skill), end(skill), 0);
        const int n = size(skill), goal = sum / (n / 2);

        if (goal * n / 2 != sum) return -1;

        long long res = 0, cnt = 0;
        for (const int n : skill) {
            const int target = goal - n;
            if (!count[target])
                count[n]++;
            else {
                count[target]--;
                res += target * n;
                cnt += 2;
            }
        }

        return cnt == n ? res : -1;
    }
};
