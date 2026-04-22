class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> results(n, 0);
        stack<int> indecies;
        for (int index = 0; index < n; index++) {
            while (!indecies.empty() && temperatures[index] > temperatures[indecies.top()]) {
                int j = indecies.top();
                indecies.pop();
                results[j] = index - j;
            }
            indecies.push(index);
        }
        return results;
    }
};
