class TopVotedCandidate {
    map<int, int> um;

  public:
    TopVotedCandidate(const vector<int> &persons, const vector<int> &times) {
        static int votes[5001];
        int maxi = 0, candid = 0;

        memset(votes, 0x00, sizeof(votes));
        for (int i = 0; i < size(persons); i++) {
            const int crnt = ++votes[persons[i]];

            if (crnt >= maxi) {
                candid = persons[i];
                maxi = crnt;
            }

            um[times[i]] = candid;
        }
    }

    int q(int t) const { return prev(um.upper_bound(t))->second; }
};
