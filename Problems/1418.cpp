class Solution {
public:
  vector<vector<string>> displayTable(vector<vector<string>> &orders) {
    map<int, vector<string>> tables;
    vector<vector<string>> res;
    set<string> foods;

    for (const auto &order : orders) {
      tables[stoi(order[1])].push_back(order[2]);
      foods.insert(order[2]);
    }

    unordered_map<string, int> pos;

    int j = 1;
    res.push_back({{"Table"}});
    for (auto &food : foods) {
      res[0].push_back(food);
      pos[food] = j++;
    }

    for (auto &[table, foods] : tables) {
      vector<int> row(res[0].size(), 0);
      vector<string> rows;
      rows.reserve(res[0].size());
      for (const auto &food : foods) row[pos[food]]++;
      row[0] = table;
      for (int r : row) rows.push_back(to_string(r));
      res.push_back(rows);
    }

    return res;
  }
};
