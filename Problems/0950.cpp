class Solution {
public:
  vector<int> deckRevealedIncreasing(vector<int> &deck) {
    sort(deck.begin(), deck.end(),
         [](const int a, const int b) { return a > b; });
    deque<int> q;
    vector<int> res;

    for (int i = 0; i < deck.size() - 1; i++) {
      q.push_back(deck[i]);
      q.push_back(q.front());
      q.pop_front();
    }
    q.push_back(deck[deck.size() - 1]);

    while (!q.empty()) {
      res.push_back(q.back());
      q.pop_back();
    }
    return res;
  }
};
