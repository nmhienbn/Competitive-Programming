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

int m, n, p, res, cnt;
bool a[maxn], b[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> m >> n >> p;
    fi(i, 1, m){
        int x;
        cin >> x;
        a[x] = 1;
    }
    fi(i, 1, n){
        int x;
        cin >> x;
        b[x] = 1;
    }
    fi(i, 1, p){
        int x;
        cin >> x;
        if (a[x] && !b[x]) cnt++;
        else cnt = 0;
        res = max(res, cnt);
    }
    cout << res;
}
