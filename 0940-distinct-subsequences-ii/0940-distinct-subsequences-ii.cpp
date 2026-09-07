class Solution {
public:
    typedef long long ll;
    ll mod =1e9+7;
    int distinctSubseqII(string s) {
        vector <ll> alpha(26,0);
        ll total=0;
        for(auto ch: s){
            int idx=ch-'a';
            ll newsub=(total+1-alpha[idx]+mod)%mod;
            total=(total+newsub)%mod;
            alpha[idx]=(alpha[idx]+newsub)%mod;
        }
        return (int)(total%mod);
    }
};