class Solution {
    unordered_map<string, int> um;
    vector<string> str;

  public:
    string encode(const string &longUrl) {
        if (um.count(longUrl)) return to_string(um[longUrl]);

        um.insert({longUrl, str.size()});
        str.push_back(longUrl);
        return to_string(str.size() - 1);
    }

    string decode(const string &shortUrl) { return str[stoi(shortUrl)]; }
};
