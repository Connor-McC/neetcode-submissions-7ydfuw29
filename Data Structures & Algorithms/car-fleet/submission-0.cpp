class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars(n);
        for (int i = 0; i < n; i++) cars[i] = {position[i], speed[i]};
        sort(cars.begin(), cars.end(), greater<>()); // descending by position

        stack<double> etas;
        for (auto& [pos, spd] : cars) {
            double eta = (double)(target - pos) / spd;
            if (etas.empty() || eta > etas.top()) {
                etas.push(eta);
            }
        }
        return etas.size();
    }
};
