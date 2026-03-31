class Solution {
public:
    const int MOD = 1e9 +7;
    typedef long long ll;
    ll solve(ll a, ll b){
        if(b == 0) return 1;

        ll half = solve(a,b/2);
        ll result  = (half * half) % MOD;

        if(b%2 == 1){
            result = (a * result) % MOD;
        }
        return result % MOD;
    }
    int countGoodNumbers(long long n) {
        ll first = solve(5, ceil(n/2.0));
        ll second = solve(4,floor(n/2.0));
        cout<<first<<" "<<second;
        return (first * second) %MOD;
    }
};
