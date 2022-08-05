//706. Design HashMap 设计哈希映射
//作者：lilyyueli
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class MyHashMap {
private:
    vector<list<pair<int,int>>> data;
    static const int num_bucket = 769;
    static int hash(int key) {
        return key % num_bucket;
    }
    
public:
    MyHashMap(): data(num_bucket) {

    }
    
    void put(int key, int value) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it)
        {
            if ((*it).first == key)
            {
                (*it).second = value;
                return;
            }
        }
        data[h].emplace_back(key,value);
    }
    
    int get(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it)
        {
            if ((*it).first == key)
                return (*it).second;
        }
        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it)
        {
            if ((*it).first == key)
            {
                data[h].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
