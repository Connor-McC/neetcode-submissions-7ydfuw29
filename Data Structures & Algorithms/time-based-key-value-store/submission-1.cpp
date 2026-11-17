class TimeMap {
    private:
    unordered_map<string, vector<pair<int,string>>> keyStore;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keyStore[key].emplace_back(timestamp,value);
    }
    
    string get(string key, int timestamp) {
        auto& keys = keyStore[key];

        int left = 0, right = keys.size() - 1;
        string output = "";

        while (left <= right){
            int mid = left + (right - left) / 2;
            if (keys[mid].first <= timestamp){
                output = keys[mid].second;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return output;
    }
};
