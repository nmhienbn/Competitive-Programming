#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define NunuAndWillump "lis2vn"
const int maxn = 1e5+5;

using namespace std;

struct pii{
    int f, s;
};

pii a[maxn];
int n, b[maxn], k;

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    cin >> n;
    fi(i, 1, n) cin >> a[i].f >> a[i].s;
    k = 1;
    b[1] = a[1].s;
    fi(i, 2, n){
        int d = 1, c = k;
        while (d <= c){
            int g = (d + c) >> 1;
            if (b[g] < a[i].s) d = g+1;
            else c = g-1;
        }
        if (c == k) b[++k] = 1e9;
        b[c+1] = min(b[c+1], a[i].s);
    }
    cout << k;
}
