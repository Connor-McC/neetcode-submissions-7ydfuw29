class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;
    
public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = store.find(key);
        if (it == store.end()) return "";

        const auto& entries = it->second;

        int lo = 0, hi = entries.size() - 1;
        string result = "";

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (entries[mid].first <= timestamp) {
                result = entries[mid].second; 
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return result;
    }
};
