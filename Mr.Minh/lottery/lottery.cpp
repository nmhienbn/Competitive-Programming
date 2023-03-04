#include <bits/stdc++.h>
#define BPhuong "lottery"
#define maxn 4005
#define mod 1000000007
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <>
#define f first
#define se second
using namespace std;

int n, m, res[maxn];
bool a[maxn], b[maxn];
vector<int> g[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(BPhuong".inp", "r", stdin);
    freopen(BPhuong".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    fi(i, 1, n){
        fi(j, 1, n){

        }
    }

}
