class Solution {
  public:
    int stoneGameVI(const vector<int> &aliceValues, const vector<int> &bobValues) {
        const int n = size(aliceValues);
        vector<int> idx(n);

        iota(begin(idx), end(idx), 0);
        sort(begin(idx), end(idx),
             [&](int a, int b) { return aliceValues[a] + bobValues[a] > aliceValues[b] + bobValues[b]; });

        int alice = 0, bob = 0, turn = 1;
        for (const int i : idx) {
            (turn ? alice : bob) += turn ? aliceValues[i] : bobValues[i];
            turn = !turn;
        }
        return alice == bob ? 0 : alice > bob ? 1 : -1;
    }
};
