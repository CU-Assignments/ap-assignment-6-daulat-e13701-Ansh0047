class Solution {
    long long nCr(int n,int r){
        long long ans = 1;
        for(int i=1;i<=min(n-r,r);i++){
            ans = (ans*(n-i+1))/i;
        }
        return ans;
    }
public:
    int uniquePaths(int m, int n) {
        return nCr(m+n-2,n-1);
    }
};