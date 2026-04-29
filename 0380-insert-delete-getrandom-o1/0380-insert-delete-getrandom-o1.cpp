class RandomizedSet {
public:
    unordered_map<int, int> m;
    vector<int> arr;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (m.find(val) == m.end()) {
            arr.push_back(val);
            m[val] = arr.size()-1;
            return true;
        } else {
            return false;
        }
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end()) {
            return false;
        } else {
            arr[m[val]] = arr.back();
            m[arr.back()] = m[val];
            arr.pop_back();
            m.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */