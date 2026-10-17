class Solution {
private:
    int digitSum(int a) {
        int s = 0;
        while (a > 0) {
            s += a % 10;
            a /= 10;
        }
        return s;
    }
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<int, int>> m;
        for (int i = 0; i < nums.size(); ++i) {
            m.emplace_back(digitSum(nums[i]), nums[i]);
        }
        sort(m.begin(), m.end(), [](const auto& a, const auto& b){
            if (a.first != b.first) return a.first < b.first;
            else return a.second < b.second;
        });
        vector<int> sorted;
        for (auto p : m) {
            sorted.push_back(p.second);
        }
        
        int res = 0;
        bool vis[100001];
        fill(vis, vis+100001, 0);
        unordered_map<int, int> ind;
        for (int i = 0; i < sorted.size(); ++i) {
            ind[sorted[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!vis[i]) {
                int tmp = i;
                int cycle = 0;
                while (!vis[tmp]) {
                    vis[tmp] = 1;
                    tmp = ind[nums[tmp]];
                    cycle++;
                }
                if (cycle > 1) {
                    res += cycle - 1;
                }
            }
        }
        return res;
    }
};