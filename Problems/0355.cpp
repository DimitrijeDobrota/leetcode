class Twitter {
    vector<pair<int, int>> posts[501];
    bool following[501][501] = {0};
    int time = 0;

  public:
    Twitter() {
        for (int i = 0; i <= 500; i++) {
            following[i][i] = true;
        }
    }

    void postTweet(int userId, int tweetId) { posts[userId].emplace_back(time++, tweetId); }

    vector<int> getNewsFeed(int userId) {
        using type_t = tuple<int, int, int>;
        static const auto cmp = [](const type_t &a, const type_t &b) { return get<0>(a) < get<0>(b); };
        priority_queue<type_t, vector<type_t>, decltype(cmp)> pq(cmp);

        for (int i = 0; i <= 500; i++) {
            if (!following[userId][i]) continue;

            const int n = size(posts[i]);
            if (n == 0) continue;

            pq.emplace(posts[i][n - 1].first, i, n - 1);
            if (size(pq) > 10) pq.pop();
        }

        vector<int> res;
        while (!pq.empty() && size(res) < 10) {
            const auto [time, user, idx] = pq.top();
            pq.pop();
            res.push_back(posts[user][idx].second);
            if (idx - 1 >= 0) pq.emplace(posts[user][idx - 1].first, user, idx - 1);
        }

        return res;
    }

    void follow(int followerId, int followeeId) { following[followerId][followeeId] = true; }

    void unfollow(int followerId, int followeeId) { following[followerId][followeeId] = false; }
};
