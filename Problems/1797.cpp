class AuthenticationManager {
    const int ttl;
    mutable unordered_map<string, int> expire;

  public:
    AuthenticationManager(int timeToLive) : ttl(timeToLive) {}

    void generate(const string &tokenId, int currentTime) const {
        expire.emplace(tokenId, currentTime + ttl);
    }

    void renew(const string &tokenId, int currentTime) const {
        auto it = expire.find(tokenId);
        if (it == end(expire)) return;
        if (it->second <= currentTime) {
            expire.erase(it);
            return;
        }
        it->second = currentTime + ttl;
    }

    int countUnexpiredTokens(int currentTime) const {
        for (auto it = begin(expire); it != end(expire);) {
            if (it->second <= currentTime)
                it = expire.erase(it);
            else
                it++;
        }
        return size(expire);
    }
};
