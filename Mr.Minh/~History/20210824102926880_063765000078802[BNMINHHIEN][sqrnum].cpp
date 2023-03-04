#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "sqrnum"
const int maxn = 1e6+5;

using namespace std;

int n, p[maxn], cnt[maxn], dem;

void Era(){
    fi(i, 2, 1e3){
        if (!p[i]){
            p[i] = i;
            for (int j = i*i; j <= 1e6; j += i){
                p[j] = i;
            }
        }
    }
    fi(i, 1e3+1, 1e6) if (!p[i]) p[i] = i;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    Era();
    cin >> n;
    while (n--){
        int x;
        cin >> x;
        while (x > 1){
            int v = p[x], d = 0;
            while (x % v == 0){
                d++;
                x /= v;
            }
            if (d&1){
                cnt[v] = 1 - cnt[v];
                if (cnt[v]) dem++;
                else dem--;
            }
        }
        if (dem) cout << "NO\n";
        else cout << "YES\n";
    }
}
