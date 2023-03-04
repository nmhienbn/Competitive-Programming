#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "moomoo"
const int maxn = 105;

using namespace std;

int n, m, L[100005], a[maxn], b[25], t;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, m) cin >> b[i];
    fi(i, 1, n) cin >> a[i];
    int pre = 0;
    fi(i, 1, n){
        if (pre > 0) pre--, a[i] -= pre;
        if (a[i] > 0) pre += a[i];
        t = max(t, a[i]);
    }
    fi(i, 1, t) L[i] = 1e9;
    fi(i, 1, t){
        fi(j, 1, m){
            if (i >= b[j]){
                L[i] = min(L[i], L[i-b[j]] + 1);
            }
        }
    }
    int res = 0;
    fi(i, 1, n) res += L[a[i]];
    cout << res;
}
