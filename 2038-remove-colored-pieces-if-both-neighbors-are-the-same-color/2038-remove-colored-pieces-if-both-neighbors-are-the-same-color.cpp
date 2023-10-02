class Solution {
public:
    bool winnerOfGame(string s) {
        s.push_back('.');
        char prev=s[0];
        int cc=0;
        int alice=0,bob=0;
        for(auto t:s)
        {
            if(prev!=t)
            {
                if(prev=='A')
                {
                    alice+=max(cc-2,0);
                }
                else if(prev=='B')
                {
                    bob+=max(cc-2,0);
                }
                prev=t;
                cc=1;
            }
            else
            {
                cc++;
            }
        }
        return alice>bob;
    }
};