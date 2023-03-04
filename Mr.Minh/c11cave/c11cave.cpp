#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "c11cave"
const int maxn = 2e5+5, maxh = 5e5+5;

using namespace std;

int n, a[maxn], b[maxn], h, res = 1e9, cnt;

int BS(int k, int a[]){
    int d = 1, c = n;
    while (d <= c){
        int g = (d + c) >> 1;
        if (a[g] >= k) c = g-1;
        else d = g+1;
    }
    return n-d+1;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> h;
    n /= 2;
    fi(i, 1, n) cin >> a[i] >> b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    fi(i, 1, h){
        int ans = BS(i, a) + BS(h-i+1, b);
        if (ans < res) res = ans, cnt = 0;
        if (res == ans) cnt++;
    }
    cout << res << ' ' << cnt;
}
