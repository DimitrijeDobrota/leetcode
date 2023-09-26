class Solution {
  public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers) {
        sort(begin(players), end(players));
        sort(begin(trainers), end(trainers));

        int res = 0;
        for (int i = 0; res < players.size() && i < trainers.size(); i++)
            res += trainers[i] >= players[res];
        return res;
    }
};
