class Solution {
  public:
    string rankTeams(const vector<string> &votes) const {
        static int count[27][27];
        memset(count, 0x00, sizeof(count));

        const int n = votes.size(), m = votes[0].size();
        for (const auto &vote : votes) {
            for (int i = 0; i < m; i++) {
                count[vote[i] & 0x1F][i]++;
            }
        }

        string s = votes[0];
        sort(s.begin(), s.end(), [&](char a, char b) {
            const int i = a & 0x1F, j = b & 0x1F;
            for (int k = 0; k < m; k++) {
                if (count[i][k] == count[j][k]) continue;
                return count[i][k] > count[j][k];
            }
            return a < b;
        });
        return s;
    }
};
