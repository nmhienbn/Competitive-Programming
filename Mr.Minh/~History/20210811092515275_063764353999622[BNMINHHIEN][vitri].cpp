#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "vitri"
const int maxn = 1e4+5;

using namespace std;

int n, k, a[maxn];

bool check(int g){
    int cnt = 0, now = a[1];
    a[n+1] = a[n]+g+1;
    fi(i, 2, n+1){
        if (a[i] > now+g){
            cnt++;
            int be = a[i-1];
            while (a[i] <= be+g && i <= n) i++;
            now = a[i];
        }
    }
    return cnt >= k;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n) cin >> a[i];
    int d = 0, c = a[n]-a[1];
    while (d <= c){
        int g = (d+c) >> 1;
        if (check(g)) d = g+1;
        else c = g-1;
    }
    vector<int> res;
    int now = a[1];
    a[n+1] = a[n]+c+1;
    fi(i, 2, n+1){
        if (a[i] > now+c){
            int be = a[i-1];
            res.pb(i-1);
            while (a[i] <= be+c && i <= n) i++;
            now = a[i];
        }
    }
    for (auto be : res) cout << be << '\n';
}
