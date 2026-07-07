class Twitter {
public:
    Twitter() : timestamp(0) {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    std::vector<int> getNewsFeed(int userId) {
        // {time, tweetId, userId, index into that user's tweet vector}
        using Entry = std::tuple<int,int,int,int>;
        std::priority_queue<Entry> maxHeap;

        // Seed heap with the most recent tweet from the user and each followee
        auto addLatest = [&](int uid) {
            auto it = tweets.find(uid);
            if (it != tweets.end() && !it->second.empty()) {
                int idx = (int)it->second.size() - 1;
                auto& [time, tid] = it->second[idx];
                maxHeap.push({time, tid, uid, idx});
            }
        };

        addLatest(userId);
        for (int followeeId : following[userId]) {
            addLatest(followeeId);
        }

        std::vector<int> result;
        while (!maxHeap.empty() && result.size() < 10) {
            auto [time, tid, uid, idx] = maxHeap.top();
            maxHeap.pop();
            result.push_back(tid);

            if (idx - 1 >= 0) {
                auto& [prevTime, prevTid] = tweets[uid][idx - 1];
                maxHeap.push({prevTime, prevTid, uid, idx - 1});
            }
        }
        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }

private:
    int timestamp;
    std::unordered_map<int, std::vector<std::pair<int,int>>> tweets; // userId -> list of (time, tweetId)
    std::unordered_map<int, std::unordered_set<int>> following;      // userId -> set of followeeIds
};
