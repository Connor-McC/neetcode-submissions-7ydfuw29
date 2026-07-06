class Solution {
public:
    priority_queue<pair<int, vector<int>>> maxHeap;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(vector<int> coords : points){
            int distance = (coords[0]*coords[0]) + (coords[1]*coords[1]);
            
            maxHeap.push({distance, coords});
            if(maxHeap.size() > k) maxHeap.pop();
        }

        vector<vector<int>> retCoords;

        while (!maxHeap.empty()) {
            retCoords.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return retCoords;
    }
};
