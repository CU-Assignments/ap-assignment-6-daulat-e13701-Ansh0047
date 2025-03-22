class Solution {
    int dp[301];
    int solve(int ind,string &s,set<string>&st){
        if(ind == s.size()) return 1;

        if(dp[ind] != -1) return dp[ind];

        // keep iterating and checking if word is there in dictionary and for that word the string can
        // be genrated or not
        int ans = 0;
        for(int i=ind;i<s.size();i++){
            string ss = s.substr(ind,i-ind+1);
            if(st.find(ss) != st.end()){
                ans |= solve(i+1,s,st);
            }
        }

        return dp[ind] = ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st(begin(wordDict),end(wordDict));
        memset(dp,-1,sizeof(dp));
        return solve(0,s,st);
    }
};