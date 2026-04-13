class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<pair<int, int>> qSorted;
        for (int i = 0; i < queries.size(); ++i) {
            qSorted.push_back({queries[i], i});
        }
        sort(intervals.begin(), intervals.end());
        sort(qSorted.begin(), qSorted.end());
        vector<int> res(queries.size(), 0);
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int ind = 0;
        for (auto &[q, i] : qSorted) {
            while (ind < intervals.size() && intervals[ind][0] <= q) {
                int gap = intervals[ind][1] - intervals[ind][0] + 1;
                pq.push({gap, intervals[ind][1]});
                ++ind;
            }
            while (!pq.empty() && pq.top().second < q) {
                pq.pop();
            }
            if (pq.empty()) res[i] = -1;
            else res[i] = pq.top().first;
        }
        return res;
    }
};