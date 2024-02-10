class SmallestInfiniteSet {
public:
    set<int> s;
    int cc = 0;
    SmallestInfiniteSet() {
        for(int i=1;i<=1010;i++)
        {
            s.insert(i);
        }
    }
    
    int popSmallest() {
        int val=*s.begin();
        s.erase(s.begin());
        return val;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */