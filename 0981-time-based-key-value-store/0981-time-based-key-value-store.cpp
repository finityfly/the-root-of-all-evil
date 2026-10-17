class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> m; // key, {timestamp, value}
    TimeMap() {
        
    }
    
    void set(const string& key, const string& value, int timestamp) {
        pair<int, string> temp = {timestamp, value};
        m[key].push_back(temp);
    }
    
    string get(const string& key, int timestamp) {
        auto found = m.find(key);
        if (found == m.end()) return "";
        auto& v = found->second;

        int l = 0, r = v.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (v[mid].first <= timestamp) l = mid + 1;
            else r = mid;
        }
        return l == 0 ? "" : v[l - 1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */