#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "prime"
const int maxn = 1e6 + 5;

using namespace std;

int p[maxn], cnt[10][maxn], omega[maxn];

void Erathosenes(){
    fi(i, 1, maxn - 5) p[i] = i;
    fi(i, 2, 1e3) if (p[i] == i){
        for (int j = i * i; j <= maxn - 5; j += i){
            p[j] = i;
        }
    }
    fi(i, 2, maxn - 5){
        int u = i, v = p[i];
        while (u % v == 0) u /= v;
        omega[i] = omega[u] + 1;
        fi(j, 1, 7) cnt[j][i] = cnt[j][i - 1];
        cnt[omega[i]][i]++;
    }
}

int q, a, b, k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//    freopen(Irelia".inp", "r", stdin);
//    freopen(Irelia".out", "w", stdout);
    Erathosenes();
    cin >> q;
    while (q--){
        cin >> a >> b >> k;
        cout << cnt[k][b] - cnt[k][a - 1] << '\n';
    }

}
