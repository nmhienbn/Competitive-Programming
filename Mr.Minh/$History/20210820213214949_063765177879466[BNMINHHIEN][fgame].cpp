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

int n, m, a[maxn][maxn], s[maxn][maxn], t[maxn][maxn], L[maxn][maxn];

int calc(int i, int j){
    if(L[i][j] != -1) return L[i][j];
    int best = 0, md = 0;
    fid(k, i, 1){
        md = (md + s[k][j]) % 3;
        if (md == 1) best = max(best, 1 - calc(k-1, j));
    }
    md = 0;
    fid(k, j, 1){
        md = (md + t[i][k]) % 3;
        if (md == 1) best = max(best, 1 - calc(i, k-1));
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
                s[i][j] = (s[i][j-1] + a[i][j]) % 3; //tong hang i
                t[i][j] = (t[i-1][j] + a[i][j]) % 3; // tong cot j
            }
        }
        fi(i, 1, n) fi(j, 1, m) L[i][j] = -1;
        cout << calc(n, m) << '\n';
    }
}
