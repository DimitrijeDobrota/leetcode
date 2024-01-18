class Solution {
  public:
    string pushDominoes(const string &dominoes) const {
        static int forces[100001];

        const int n = size(dominoes);
        string res(n, '.');

        for (int i = 0, force = 0; i < n; i++) {
            if (dominoes[i] == 'R')
                force = n;
            else if (dominoes[i] == 'L')
                force = 0;
            else
                force = max(force - 1, 0);
            forces[i] = force;
        }

        for (int i = n - 1, force = 0; i >= 0; i--) {
            if (dominoes[i] == 'L')
                force = n;
            else if (dominoes[i] == 'R')
                force = 0;
            else
                force = max(force - 1, 0);
            if (forces[i] != force) res[i] = forces[i] > force ? 'R' : 'L';
        }

        return res;
    }
};
