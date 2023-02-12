// Left to right
class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    if (s.size() <= 10) return {};

    unordered_map<string, int> um;
    vector<string> res;
    string sec = "";

    for (int i = 0; i < 10; i++) sec += s[i];
    um[sec]++;
    for (int i = 10; i < s.size(); i++) {
      sec = sec.substr(1) + s[i];
      if (um[sec]++ == 1) res.push_back(sec);
    }

    return res;
  }
};

// Right to left
class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    if (s.size() <= 10) return {};

    unordered_map<string, int> um;
    vector<string> res;
    string sec = "";

    for (int i = s.size() - 1; i >= s.size() - 10; i--) sec = s[i] + sec;
    um[sec]++;
    for (int i = s.size() - 10 - 1; i >= 0; i--) {
      sec.pop_back();
      sec = s[i] + sec;
      if (um[sec]++ == 1) res.push_back(sec);
    }

    return res;
  }
};

// Bit hacking
class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<unsigned, int> um;
    vector<string> res;

    for (unsigned i = 0, sec = 0; i < s.size(); i++) {
      sec = sec << 3 & 0x3FFFFFFF | s[i] & 7;
      if (um[sec]++ == 1) res.push_back(s.substr(i - 9, 10));
    }

    return res;
  }
};
