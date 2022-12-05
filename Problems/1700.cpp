class Solution {
public:
  int countStudents(vector<int> &students, vector<int> &sandwiches) {
    vector<int> count(2, 0);
    queue<int> q;

    for (int s : students) {
      q.push(s);
      count[s]++;
    }

    for (int i = 0; i < sandwiches.size() && count[sandwiches[i]] != 0; q.pop())
      if (q.front() == sandwiches[i]) {
        count[sandwiches[i]]--;
        i++;
      } else
        q.push(q.front());

    return q.size();
  }
};
