class Solution {
  public:
    string interpret(const string command) const {
        string res;

        for (int i = 0; i < size(command); i++) {
            if (command[i] == 'G')
                res += 'G';
            else if (command[i + 1] == ')')
                res += 'o', i += 1;
            else
                res += "al", i += 3;
        }

        return res;
    }
};
