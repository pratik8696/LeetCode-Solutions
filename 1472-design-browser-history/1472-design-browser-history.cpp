deque<string> arr;
int ind;
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        ind=0;
        arr.clear();
        arr.push_back(homepage);
    }
    
    void visit(string url) {
        int rem=arr.size()-1-ind;
        while(rem--)
        {
            arr.pop_back();
        }
        arr.push_back(url);
        ind++;
    }
    
    string back(int steps) {
        // 0 1 2 3 4 5 6 7 8 9
        int nidx=max(0,ind-steps);
        ind=nidx;
        return arr[ind];
    }
    
    string forward(int steps) {
        int nidx=min(int(arr.size()-1),ind+steps);
        ind=nidx;
        return arr[ind];        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */