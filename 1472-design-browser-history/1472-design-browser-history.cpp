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