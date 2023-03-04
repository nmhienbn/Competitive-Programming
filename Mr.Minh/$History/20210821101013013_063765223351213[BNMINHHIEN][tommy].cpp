#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "tommy"
const int maxn = 1e7+5;

using namespace std;

int p[maxn], n, m;
ll cnt[maxn];

void Erathosenes(){
    fi(i, 1, 1e7) p[i] = i;
    int u = sqrt(1e7);
    fi(i, 2, u) if (p[i] == i){
        for (int j = i*i; j <= 1e7; j += i){
            p[j] = i;
        }
    }
}

ll f(int n){
    if (n > 1e7) return 0;
    return cnt[n];
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    Erathosenes();
    cin >> n;
    fi(i, 1, n){
        int x;
        cin >> x;
        while (x > 1){
            int t = p[x];
            cnt[t]++;
            while (x % t == 0){
                x /= t;
            }
        }
    }
    fi(i, 1, 1e7) cnt[i] += cnt[i-1];
    cin >> m;
    while (m--){
        int l, r;
        cin >> l >> r;
        cout << f(r) - f(l-1) << '\n';
    }
}
