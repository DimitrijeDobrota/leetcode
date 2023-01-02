class Solution {
  const int SIZE = 101;

public:
  vector<string> findAllRecipes(vector<string> &recipes,
                                vector<vector<string>> &ingredients,
                                vector<string> &supplies) {
    unordered_map<string, int> hash;
    unordered_set<string> us(supplies.begin(), supplies.end());
    vector<vector<int>> adj(SIZE);
    vector<int> count(SIZE);
    vector<string> finished;

    for (int i = 0; i < recipes.size(); i++) hash.insert({recipes[i], i});
    for (int i = 0; i < recipes.size(); i++) {
      for (string &s : ingredients[i])
        if (!us.count(s)) {
          count[i]++;
          if (!hash.count(s))
            count[i] = INT_MAX;
          else
            adj[hash[s]].push_back(i);
        }
    }

    queue<int> q;
    for (int i = 0; i < recipes.size(); i++) {
      if (!count[i]) {
        q.push(i);
        finished.push_back(recipes[i]);
      }
    }

    while (!q.empty()) {
      int root = q.front();
      q.pop();
      for (int c : adj[root]) {
        if (!--count[c]) {
          q.push(c);
          finished.push_back(recipes[c]);
        }
      }
    }

    return finished;
  }
};
