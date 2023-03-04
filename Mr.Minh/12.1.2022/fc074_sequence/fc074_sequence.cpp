#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "fc074_sequence"
const int maxn = 1e5 + 5;
using namespace std;

int n, k, a[maxn];
ll b[maxn], s[maxn];

bool check(int g){
    ll mn = 1e18;
    int j = 0;
    fi(i, 1, n){
        b[i] = b[i - 1] + a[i] - g;
        while (j <= n && s[i] - s[j] >= k){
            mn = min(mn, b[j]);
            j++;
        }
        if (b[i] >= mn) return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    int d = 0, c = 1e9;
    while (d <= c){
        int g = (d + c) >> 1;
        if (check(g)) d = g + 1;
        else c = g - 1;
    }
    cout << c;
}
