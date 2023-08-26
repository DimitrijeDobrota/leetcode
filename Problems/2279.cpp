class Solution {
  public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks) {
        for (int i = 0; i < capacity.size(); i++)
            rocks[i] = capacity[i] - rocks[i];
        sort(rocks.begin(), rocks.end());

        int res = 0;
        for (int i = 0; i < capacity.size(); i++)
            if (rocks[i] <= additionalRocks)
                additionalRocks -= rocks[i], res++;
            else
                break;
        return res;
    }
};
