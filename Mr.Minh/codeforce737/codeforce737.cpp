#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define fir first
#define se secondC:\Users\Admin\Desktop\minhcode\KaitoNMH#OCEE\codeforce737\codeforce737.inp
#define bit(i,j) ((i>>j)&1)
#define bit2(i) (1<<(i-1))
#define ll long long
#define pii pair<int,int>

#define maxn 100005
#define maxm 1000006
#define MOD 1000000007
#define MinhDz "codeforce737"

using namespace std;

pii a[maxn];

ll binpow(ll a, ll k){
    if (k == 0) return 1ll;
    ll tg = (binpow(a, k/2));
    if (k&1) return tg*tg*a %MOD;
    return tg*tg %MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(MinhDz".inp","r",stdin);
    freopen(MinhDz".out","w",stdout);
    int t;
    cin >> t;
    while (t--){
        ll n, k;
        cin >> n >> k;
        if (k==0){
            cout << "1\n";
            continue;
        }
        //cout << (binpow(2, k)-1) << '\n';
        if (n&1) cout << binpow(binpow(2, n-1)+1, k) << '\n';
        else cout << 1ll*binpow(2, (n-1)*k%(MOD-1))*(binpow(2, k)-1) % MOD << '\n';
    }
}
