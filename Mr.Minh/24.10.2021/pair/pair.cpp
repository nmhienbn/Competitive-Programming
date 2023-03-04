#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "pair"
const int maxn = 1e6+5;

using namespace std;

int n, m, k, a[maxn], b[maxn], d, c;

bool check(int g){
    int cnt = 0;
    int j = 1;
    fi(i, 1, n){
        while (b[j] < a[i] - g && j <= m) j++;
        if (j <= m && abs(a[i] - b[j]) <= g){
            cnt++;
            j++;
        }
        if (cnt >= k) return true;
    }
    return false;
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> m >> k;
    fi(i, 1, n) cin >> a[i];
    fi(i, 1, m) cin >> b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);
    c = a[n];
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) c = g-1;
        else d = g+1;
    }
    cout << d;
}
