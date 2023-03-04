#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define getbit(x, t) ((x >> t) & 1)
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "mguard"
const int maxn = 25, nn = (1 << 20);

using namespace std;

struct dl {
    int u, v, w;
} a[maxn];

int n, h, res = -1, L[nn], S[nn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> h;
    fi(i, 1, n){
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    fi(x, 1, (1 << n) - 1){
        fi(i, 0, n-1){
            if (getbit(x, i)){
                S[x] = S[x - (1 << i)] + a[i].u;
            }
        }
    }
    fi(i, 0, n-1) L[1 << i] = a[i+1].w;
    fi(x, 1, (1 << n) - 1){
        fi(i, 0, n-1){
            if (!getbit(x, i)){
                if (L[x] > a[i].v){
                    L[x | (1 << i)] = max(L[x | (1 << i)],
                                    min(L[x] - a[i].v, a[i].w));
                    if (S[x | (1 << i)] >= h){
                        res = max(res, L[x | (1 << i)]);
                    }
                }
            }
        }
    }
    res == -1 ? cout << "Mark is too tall" : cout << res;
}
