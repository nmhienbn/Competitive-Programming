#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "cream"
const int maxn = 1e6+5;
using namespace std;

pii a[maxn];
ll res;
int n, cnt;

bool cmp(pii a, pii b){
    return a.first - a.second > b.first - b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].first;
    fi(i, 1, n) cin >> a[i].second;
    sort(a+1, a+n+1, cmp);
    fi(i, 1, n){
        if (res + a[i].first - a[i].second > 0){
            res += a[i].first - a[i].second;
            cnt++;
        }
        else break;
    }
    cout << cnt;
}
