#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "truck"
const int maxn = 1e5+5;

using namespace std;

int n, k;
int a[maxn];
ll d, c;

bool check(ll g){
    int cnt = 0;
    ll now = 0;
    fi(i, 1, n){
        if (now+a[i] <= g){
            if (i == n) cnt++;
            now += a[i];
        }
        else {
            now = a[i];
            cnt++;
        }
    }
    return cnt <= k;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n){
        cin >> a[i];
        d = max(d, 1ll*a[i]);
        c += a[i];
    }
    while (d <= c){
        ll g = (d+c) >> 1;
        if (check(g)) c = g-1;
        else d = g+1;
    }
    cout << d;
}
