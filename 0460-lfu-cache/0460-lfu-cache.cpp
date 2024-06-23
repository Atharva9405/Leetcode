class LFUCache {
private:
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int>> keyToVal;
    unordered_map<int, list<int>::iterator> keyToIter;
    unordered_map<int, list<int>> freqToKeys;  

    void touch(int key) {
        int freq = keyToVal[key].second;
        freqToKeys[freq].erase(keyToIter[key]);
        freq++;
        freqToKeys[freq].push_back(key);
        keyToIter[key] = --freqToKeys[freq].end();
        keyToVal[key].second = freq;
        
        if (freqToKeys[minFreq].empty()) {
            minFreq++;
        }
    }

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}
    
    int get(int key) {
        if (keyToVal.find(key) == keyToVal.end()) {
            return -1;
        }
        touch(key);
        return keyToVal[key].first;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyToVal.find(key) != keyToVal.end()) {
            keyToVal[key].first = value;
            touch(key);
        } else {
            if (keyToVal.size() == capacity) {
                int lfu_key = freqToKeys[minFreq].front();
                freqToKeys[minFreq].pop_front();
                keyToVal.erase(lfu_key);
                keyToIter.erase(lfu_key);
            }
            keyToVal[key] = {value, 1};
            freqToKeys[1].push_back(key);
            keyToIter[key] = --freqToKeys[1].end();
            minFreq = 1;
        }
    }
};