#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "sumlr"
const int maxn = 1e5+5;

using namespace std;

int n, L, R;
ll a[maxn], res = -1e9;
int q[maxn*2], d, c;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> L >> R;
    fi(i, 1, n){
        cin >> a[i];
        a[i] += a[i-1];
    }
    q[0] = 0;
    fi(i, L, n){
        while (c >= d && a[q[c]] >= a[i-L]) c--;
        q[++c] = i-L;
        while (d <= c && q[d] < i-R) d++;
        res = max(res, a[i] - a[q[d]]);
    }
    cout << res;
}
