#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define fir first
#define se second
#define bit(i,j) ((i>>j)&1)
#define bit2(i) (1<<(i-1))
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define maxn 250005
#define maxm 1000006
#define mod 65536
#define Seraphine "median"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;

int n, seed, mul, add, k, a[maxn];

int main(){
    faster
    freopen(Seraphine".inp","r",stdin);
    freopen(Seraphine".out","w",stdout);
    int ntest;
    cin >> ntest;
    fi(nn, 1, ntest){
        ll res = 0;
        cin >> seed >> mul >> add >> n >> k;
        ordered_set tt;
        a[1] = seed;
        fi(i, 2, n){
            a[i] = (1ll * a[i-1] * mul + add) % mod;
        }
        fi(i, 1, k){
            tt.insert(a[i]);
        }
        res = *(tt.find_by_order((k+1)/2-1));
        fi(i, k+1, n){
            tt.insert(a[i]);
            tt.erase(a[i-k]);
            res += *(tt.find_by_order((k+1)/2-1));
            //res %= mod;
        }
        printf("Case #%d: %lld\n", nn, res);
    }

}
