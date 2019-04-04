class LRUCache {
private:
    // key -> <value, age>
    unordered_map<int, pair<int, int>> k2va;
    
    // age -> key
    unordered_map<int, int> a2k;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    int capacity;
    int nextAge = 0;
    
    unordered_set<int> orphanedAges;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        int value = -1;
        if (k2va.count(key)) {
            value = k2va[key].first;
            put(key, value);
        }
        // printf("get key %d return %d\n", key, value);
        return value;
    }
    
    void put(int key, int value) {
        // printf("put %d->%d with age %d\n", key, value, nextAge);
        // skip orphaned ages
        while (!pq.empty() && orphanedAges.count(pq.top()) > 0) {
            int age = pq.top();
            // printf("age=%d\n", age);
            pq.pop();
            orphanedAges.erase(orphanedAges.find(age));
            a2k.erase(age);
            // printf("remove orphaned %d\n", age);
        }
        
        if (k2va.count(key) == 0 && k2va.size() == capacity) {
            // remove the oldest key
            int oldestAge = pq.top();
            pq.pop();
            int oldestKey = a2k[oldestAge];
            a2k.erase(oldestAge);
            k2va.erase(oldestKey);
            // printf("remove the oldest key %d with age %d\n", oldestKey, oldestAge);
        } 
        
        // replace?
        if (k2va.count(key) > 0) {
            auto p = k2va[key];
            orphanedAges.insert(p.second);
            // printf("mark age %d as orphaned\n", p.second);
        }
        
        // insert
        k2va[key] = {value, nextAge};
        a2k[nextAge] = key;
        pq.push(nextAge);
        nextAge++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
