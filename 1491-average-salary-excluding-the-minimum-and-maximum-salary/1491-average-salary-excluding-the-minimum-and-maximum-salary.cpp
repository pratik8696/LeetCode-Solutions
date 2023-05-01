class Solution {
public:
    double average(vector<int>& salary) {
        sort(begin(salary),end(salary));
        double num=0;
        for(int i=1;i<salary.size()-1;i++)
        {
            num+=salary[i];
        }
        double denom=salary.size()-2;
        return num/denom;
    }
};