#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "rock"
const int maxn = 5e4+5;

using namespace std;

int l, n, m, a[maxn];

bool check(int g){
    int cnt = 0, now = a[0];
    fi(i, 1, n+1){
        if (a[i] <= now+g){
            cnt++;
        }
        else {
            now = a[i--];
            cnt--;
        }
    }
    return cnt >= m;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> l >> n >> m;
    fi(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    a[n+1] = l;
    int d = max(a[1], l-a[n]), c = l;
    while (d <= c){
        int g = (d+c) >> 1;
        if (check(g)) c = g-1;
        else d = g+1;
    }
    cout << d;
}
