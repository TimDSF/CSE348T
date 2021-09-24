class LRUCache {
public:
    int n = 0, N; // n: current size of the cache; N: capacity
    list< pair<int,int> > li; // li: list for storing all the elements, ordered by most recently used
    unordered_map<int, list< pair<int,int> >::iterator > mp; // mp: maps key --> iterator containing it
    
    LRUCache(int n) {
        this -> N = n;
    }
    
    int get(int key) {
        if (! mp.count(key)){ // the key does not exist in the cache
            return -1;
        }else{ // key exists
            list< pair<int,int> >::iterator pos = mp[key]; // get the iterator associated with the key
            int val = pos -> second; // get the value associated with the key
            li.splice(li.begin(), li, pos); // move the element to the beginning
            
            return val;
        }
    }
    
    void put(int key, int val) {
        if (! mp.count(key)){ // the key does not exist in the cache
            if (n == N){ // cache is full
                mp.erase(li.back().first); // erase the < key, iterator > pair from the map
                li.pop_back(); // pop the least recently used element
            }else{
                ++ n; // increase the size of the cache
            }
            
            li.push_front(make_pair(key, val)); // make a new pair and insert to the beginning
            mp[key] = li.begin(); // make new map entry from the key to the iterator
        }else{ // the key exists
            list< pair<int,int> >::iterator pos = mp[key]; // get the iterator
            pos -> second = val; // update the value
            li.splice(li.begin(), li, pos); // move the element to the beginning
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */