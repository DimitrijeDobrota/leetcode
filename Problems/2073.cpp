class Solution {
public:
  int timeRequiredToBuy(vector<int> &tickets, int k) {
    int time = 0;
    for (int i = 0; i < tickets.size(); i++)
      if (tickets[i] >= tickets[k])
        time += tickets[k] - (i > k);
      else
        time += tickets[i];
    return time;
  }
};
