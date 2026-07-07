class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::unordered_map<char, int> freq;
        for (char t : tasks) freq[t]++;

        std::priority_queue<int> maxHeap;
        for (auto& [task, count] : freq) maxHeap.push(count);

        std::queue<std::pair<int, int>> cooldown;

        int cycle = 0;

        while (!maxHeap.empty() || !cooldown.empty()) {
            cycle++;

            if (!maxHeap.empty()) {
                int count = maxHeap.top();
                maxHeap.pop();
                count--;
                if (count > 0) {
                    cooldown.push({count, cycle + n});
                }
            }
            // else: heap is empty, this cycle is idle

            // If a cooling-down task becomes eligible at this cycle, push it back to the heap
            if (!cooldown.empty() && cooldown.front().second == cycle) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return cycle;
    }
};
