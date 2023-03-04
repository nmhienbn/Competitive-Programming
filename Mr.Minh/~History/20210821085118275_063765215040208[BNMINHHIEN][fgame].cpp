#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "fgame"
const int maxn = 1005;

using namespace std;

int n, m, a[maxn][maxn], s[maxn][maxn], L[maxn][maxn];

int calc(int i, int j){
    if(L[i][j] != -1) return L[i][j];
    int best = 0;
    if (s[i][j] == 1) return L[i][j] = 1;
    fi(k, 1, i-1){
        if ((s[i][j] - s[k][j] + 3) % 3 == 1) best = max(best, 1 - calc(k, j));
        if (best) return L[i][j] = best;
    }
    fi(k, 1, j-1){
        if ((s[i][j] - s[i][k] + 3) % 3 == 1) best = max(best, 1 - calc(i, k));
        if (best) return L[i][j] = best;
    }
    return L[i][j] = best;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    while (cin >> n >> m){
        fi(i, 1, n){
            fi(j, 1, m){
                cin >> a[i][j];
                s[i][j] = (s[i][j-1] + s[i-1][j] + a[i][j] - s[i-1][j-1]) % 3;
            }
        }
        fi(i, 1, n) fi(j, 1, m) L[i][j] = -1;
        cout << calc(n, m) << '\n';
    }
}
