class Solution {
    enum Type {
        Atom,
        Number,
        Extra,
    };

  public:
    string countOfAtoms(const string &formula) const {
        string res;

        vector<string> tokens;
        string crnt;
        Type type = Extra;

        for (const char c : formula) {
            if (c == '(' || c == ')') {
                tokens.push_back(crnt);
                type = Extra;
                crnt = "";
            } else if (isdigit(c)) {
                if (type != Number) {
                    tokens.push_back(crnt);
                    type = Number;
                    crnt = "";
                }
            } else {
                if (type != Atom || isupper(c)) {
                    tokens.push_back(crnt);
                    type = Atom;
                    crnt = "";
                }
            }

            crnt += c;
        }
        tokens.push_back(crnt);

        using map_t = map<string, long long>;

        map_t last_count;
        stack<map_t> count;
        string last_atom;

        type = Extra;
        count.push({});
        tokens.erase(tokens.begin());
        for (const auto &token : tokens) {
            if (token[0] == '(') {
                if (type == Atom) count.top()[last_atom]++;
                count.push({});
                type = Extra;
            } else if (token[0] == ')') {
                if (type == Atom) count.top()[last_atom]++;
                last_count = std::move(count.top());
                count.pop();
                type = Extra;
            } else {
                if (isdigit(token[0])) {
                    const auto value = stoll(token);
                    if (type == Extra) {
                        for (auto &[_, v] : last_count)
                            v *= value;
                    } else {
                        count.top()[last_atom] += value;
                    }
                }

                if (type == Extra) {
                    for (const auto &[k, v] : last_count) {
                        count.top()[k] += v;
                    }
                    last_count = {};
                }

                if (isdigit(token[0]))
                    type = Number;
                else {
                    if (type == Atom) count.top()[last_atom]++;
                    last_atom = token;
                    type = Atom;
                }
            }
        }

        if (type == Extra) {
            for (const auto &[k, v] : last_count)
                count.top()[k] += v;
        } else if (type == Atom)
            count.top()[last_atom]++;

        for (const auto &[e, c] : count.top()) {
            res += e;
            if (c > 1) res += to_string(c);
        }

        return res;
    }
};
