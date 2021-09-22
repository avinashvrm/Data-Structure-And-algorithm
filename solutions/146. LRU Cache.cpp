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

//USING DLL
class Node
{
public:
    int key,val;
    Node* left;
    Node* right;
    Node(int key,int val)
    {
        this->key = key;
        this->val = val;
        this->left = NULL;
        this->right= NULL;
    }
};
class LRUCache {
public:
    Node *head,*tail;
    unordered_map<int,Node*> mp;
    int n,cap;
    LRUCache(int capacity) 
    {
        this->cap=capacity;
        this->n=0;
        this->head=NULL;
        this->tail=NULL;
    }
    void del(Node *x)
    {
        if(x->left!=NULL)
        {
            x->left->right = x->right;
            
        }
        else
            head = x->right;
        
        if(x->right!=NULL)
        {
            x->right->left = x->left;
        }
        else
            tail = x->left;
        // delete(x);
        x->left=NULL;
        x->right=NULL;
    }
    void insert(Node *x)
    {
        if(head==NULL)
        {
            head = x;
            tail = x;
            return;
        }
        tail->right = x;
        x->left = tail;
        tail  = x;
    }
     /*
    Logic for get function:
    -> if key not found return -1
    ->if found then return val
    */
    int get(int key) 
    {
        if(mp.find(key)!=mp.end())
        {
            Node *x = mp[key];
            del(x);
            insert(x);
            return x->val;
        }
        else
            return -1;
    }
    /*Logic for Put function:
    ->if key already present thenchange the value of the key insert it at last
    ->if key not present
        Case1:if size== capacity then first value removed in LRU Cache
        Case2:if size!=capacity value inserted at last  
    */
    void put(int key, int value) 
    {
         
        if(mp.find(key)!=mp.end())
        {
            mp[key]->val = value;
            del(mp[key]);
            insert(mp[key]);//becoz of here we are not performing delete() at line 43
        }
        else
        {
            Node *newnode = new Node(key,value);
            mp[key] = newnode;
            if(n==cap)
            {
                mp.erase(head->key);
                del(head);
                insert(newnode);
            }
            else
            {
                n++;
                insert(newnode);
            }
        }
        
    }
};
