#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "qbticket"
const int maxn = 1e5+5;

using namespace std;

int n, s, f, id[4];
ll l[4], c[4], L[maxn], d[maxn];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    fi(i, 1, 3) cin >> l[i];
    fi(i, 1, 3) cin >> c[i];
    cin >> n >> s >> f;
    fi(i, 2, n) cin >> d[i];
    fi(i, 1, n) L[i] = 2e18;
    if (s > f) swap(s, f);
    L[s] = 0;
    fi(i, 1, 3) id[i] = s;
    fi(i, s+1, f){
        fi(j, 1, 3){
            while (d[i] - d[id[j]] > l[j] && id[j] < i) id[j]++;
            if (id[j] < i) L[i] = min(L[i], L[id[j]] + c[j]);
        }
    }
    cout << L[f];
}
