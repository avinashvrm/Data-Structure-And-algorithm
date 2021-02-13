class LRUCache {
    list<pair<int,int>> dq;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    
    void refresh(int key,int value)
    {
        dq.erase(mp[key]);
        dq.push_front({key,value});
        mp[key] = dq.begin();        
    }
    int capacity;
public:
    LRUCache(int capacity) 
    {
        this->capacity = capacity;
    }
    
    int get(int key) 
    {
        if(mp.find(key)!=mp.end())
        {
            refresh(key,(*mp[key]).second);
            return (*mp[key]).second;
        }
        return -1; 
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key)!=mp.end())
            refresh(key,value);
        else
        {
            dq.push_front({key,value});
            mp[key] = dq.begin();
            if(mp.size()>capacity)
            {
                mp.erase(dq.back().first);
                dq.pop_back();
            }
        }
    }
};
​
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
