#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "maxmed"
const int maxn = 2e5+5;

using namespace std;

int n, k, a[maxn];

bool check(int g){
    int cnt = 0;
    fi(i, n/2+1, n) if (a[i] < g){
        cnt += g-a[i];
        if (cnt > k) return false;
    }
    else break;
    return true;
}

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    int d = a[n/2+1], c = 1e9;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) d = g+1;
        else c = g-1;
    }
    cout << c;
}
