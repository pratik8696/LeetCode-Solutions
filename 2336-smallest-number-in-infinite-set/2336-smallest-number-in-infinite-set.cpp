class SmallestInfiniteSet {
public:
    multiset<int> s;
    SmallestInfiniteSet() {
        for(int i=0;i<=2000;i++)
        {
            s.insert(i+1);
        }
    }
    
    int popSmallest() {
        int val=0;
        if(s.size())
        {
            val=*s.begin();
            s.erase(s.begin());
        }
        return val;
    }
    
    void addBack(int num) {
        if(s.count(num)==0)
        {
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */