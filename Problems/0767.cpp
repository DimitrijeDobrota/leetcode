class Solution {
  typedef pair<int, char> pic;

public:
  string reorganizeString(const string &s) {
    priority_queue<pic> pq;
    int count[27] = {0};
    string res;

    for (char c : s) count[c & 0x1F]++;
    for (int i = 1; i <= 26; i++)
      if (count[i] > 0) pq.push({count[i], 'a' + i - 1});

    while (!pq.empty()) {
      const auto [cnt, c] = pq.top();
      pq.pop();
      if (pq.empty()) {
        if (cnt == 1)
          return res + c;
        else
          return "";
      } else {
        const auto [ocnt, oc] = pq.top();
        pq.pop();
        res += c, res += oc;
        if (cnt - 1) pq.push({cnt - 1, c});
        if (ocnt - 1) pq.push({ocnt - 1, oc});
      }
    }
    return res;
  }
};
