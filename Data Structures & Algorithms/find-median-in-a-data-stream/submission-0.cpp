class MedianFinder {
private:
    priority_queue<int> small;                              
    priority_queue<int, vector<int>, greater<int>> large;    

public:
    MedianFinder() {}

    void addNum(int num) {
        small.push(num);

        if (!small.empty() && !large.empty() && small.top() > large.top()) {
            int val = small.top();
            small.pop();
            large.push(val);
        }

        if (small.size() > large.size() + 1) {
            int val = small.top();
            small.pop();
            large.push(val);
        } else if (large.size() > small.size() + 1) {
            int val = large.top();
            large.pop();
            small.push(val);
        }
    }

    double findMedian() {
        if (small.size() > large.size()) {
            return small.top();
        } else if (large.size() > small.size()) {
            return large.top();
        }
        return (small.top() + large.top()) / 2.0;
    }
};
