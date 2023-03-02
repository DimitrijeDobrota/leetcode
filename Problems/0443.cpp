class Solution {
public:
  int compress(vector<char> &chars) {
    char prev = chars[0];
    int count = 1, crnt = 0;
    for (int i = 1; i < chars.size(); i++) {
      if (chars[i] == prev)
        count++;
      else {
        chars[crnt++] = prev;
        if (count != 1)
          for (char c : to_string(count)) chars[crnt++] = c;
        count = 1;
        prev = chars[i];
      }
    }
    chars[crnt++] = prev;
    if (count != 1)
      for (char c : to_string(count)) chars[crnt++] = c;

    return crnt;
  }
};
