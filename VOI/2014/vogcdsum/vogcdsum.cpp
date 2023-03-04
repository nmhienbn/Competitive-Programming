#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "vogcdsum"
const int maxn = 1e5 + 5, mod = 1e9 + 7;
using namespace std;

int n;
ll a[maxn], val[30];
int cnt[30], num;
ll res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, n){
        //update
        //num is at most log2(n)
        fi(j, 1, num) val[j] = __gcd(val[j], a[i]);
        val[++num] = a[i];
        cnt[num] = 1;
        //merge if val[j] = val[j + 1]
        int id = 0;
        fi(j, 1, num){
            if (val[j] != val[j - 1]) val[++id] = val[j], cnt[id] = cnt[j];
            else cnt[id] += cnt[j];
        }
        num = id;
        //calculate res
        fi(j, 1, num){
            res = (res + val[j] * cnt[j]) % mod;
        }
    }
    cout << res;
}
