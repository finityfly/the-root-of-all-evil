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
        // binary search to get timestamp less than or equal
        auto found = m.find(key);
        if (found == m.end()) return "";
        auto &v = found->second;
        auto it = upper_bound(v.begin(), v.end(), timestamp, [](int t, const pair<int, string>& p) {
            return t < p.first;
        });
        if (it == v.begin()) return "";
        else return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */