class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>> Store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        Store[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>> & vals = Store[key];
        int low = 0;
        int high = vals.size()-1;
        string result;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if (vals[mid].first==timestamp) return vals[mid].second;
            else if (vals[mid].first<timestamp)
            {
                result = vals[mid].second;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
