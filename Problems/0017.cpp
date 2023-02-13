class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> um = {"abc", "def",  "ghi", "jkl",
                         "mno", "pqrs", "tuv", "wxyz"},
                   res = {""};

    for (char d : digits) {
      vector<string> tmp;
      for (char l : um[d - '2'])
        for (const string &s : res) tmp.push_back(s + l);
      res = tmp;
    }

    return res.size() > 1 ? res : vector<string>();
  }
};
