class TimeMap {
public:
    unordered_map<string, map<int,string>> timebased;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timebased[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(timebased.find(key)==timebased.end())return "";
        
        auto it = timebased[key].upper_bound(timestamp);
        if(it==timebased[key].begin())return "";
        
        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */