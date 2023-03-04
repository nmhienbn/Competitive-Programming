#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "rescue"
const int maxn = 1e5+5;

using namespace std;

int n, k, b[maxn], dau[maxn], cuoi[maxn], res, c[maxn];
pii a[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n >> k;
    fi(i, 1, n){
        int x;
        char c;
        cin >> x >> c;
        if (c == 'R') a[i].first = a[i-1].first + x;
        else a[i].first = a[i-1].first - x;
        a[i].second = i;
        //cout << a[i].first << ' ';
    }
    sort(a, a+n+1);
    int id = 0;
    b[a[0].second] = ++id;
    c[id] = a[0].first;
    fi(i, 1, n){
        if (a[i].first != a[i-1].first){
            b[a[i].second] = ++id;
            c[id] = a[i].first;
        }
        else b[a[i].second] = id;
    }
    fi(i, 0, n-1){
        int u = min(b[i], b[i+1]), v = max(b[i], b[i+1]);
        dau[u]++;
        dau[v]--;
        cuoi[v]++;
        cuoi[u]--;
    }
    fi(i, 2, id){
        dau[i] += dau[i-1];
    }
    fid(i, id-1, 1){
        cuoi[i] += cuoi[i+1];
    }
    fi(i, 1, id-1){
        if (dau[i] >= k && cuoi[i+1] >= k) res += abs(c[i]-c[i+1]);
    }
    cout << res;
}
