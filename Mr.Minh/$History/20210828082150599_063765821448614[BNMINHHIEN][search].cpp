#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "search"
const int maxn = 1e5+5;

using namespace std;

int m, n, p, res, cnt, t, c[maxn], kt[maxn];
bool a[maxn], b[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> m >> n >> p;
    fi(i, 1, m){
        int x;
        cin >> x;
        if (!a[x]) t++;
        a[x] = 1;
    }
    fi(i, 1, n){
        int x;
        cin >> x;
        b[x] = 1;
    }
    fi(i, 1, p) cin >> c[i];
    int j = 1, dem = 0;
    fi(i, 1, p){
        int x = c[i];
        if (a[x] && !b[x]){
            cnt++;
            kt[x]++;
            if (kt[x] == 1) dem++;
            if (dem == t) res = max(res, cnt);
        }
        else {
            while (j <= i){
                kt[c[j]]--;
                j++;
            }
            cnt = dem = 0;
        }
    }
    cout << res;
}
