vector<int> arr;
unordered_map<int,int> hsh;

class RandomizedSet {
public:
    RandomizedSet() {
        arr.clear();
        hsh.clear();
    }
    
    bool insert(int val) {
        if(hsh[val])
        {
            return false;
        }
        arr.push_back(val);
        hsh[val]=arr.size();
        // for(auto t:arr)
        // {
        //     cout<<t<<" ";
        // }
        // cout<<endl;
        return true;
    }
    
    bool remove(int val) {
        if(hsh[val]==0)
        {
            return false;
        }
        int prev_idx=hsh[val]-1;
        // cout<<"Index is "<<prev_idx<<endl;
        if(arr[prev_idx]!=arr.back())
        {
            // then swap
            hsh[arr.back()]=prev_idx+1;
            swap(arr[prev_idx],arr[arr.size()-1]);
            arr.pop_back();
        }
        else
        {
            // no need to swap
            arr.pop_back();
        }
        hsh[val]=0;
        // for(auto t:arr)
        // {
        //     cout<<t<<" ";
        // }
        // cout<<endl;
        return true;
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