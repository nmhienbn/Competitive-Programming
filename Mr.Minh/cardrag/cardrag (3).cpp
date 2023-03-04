#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL);
#define NunuAndWillump "cardrag"
const int maxn = 2005;

using namespace std;

int n, m, nex[4][maxn], res;

char a[maxn][maxn];
// t[4] = {'N', 'E', 'S', 'W'};

int main(){
    faster
    freopen(NunuAndWillump".inp", "r", stdin);
    freopen(NunuAndWillump".out", "w", stdout);
    while (cin >> m >> n){
        if (m == 0 && n == 0) break;
        res = 0;
        fi(i, 1, m) fi(j, 1, n){
            cin >> a[i][j];
        }

        fi(i, 1, n) nex[0][i] = 1, nex[2][i] = m;
        fi(i, 1, m) nex[1][i] = n, nex[3][i] = 1;
        while (true){
            bool flag = 1;
            fi(i, 1, n){
                while (nex[0][i] <= m && (a[nex[0][i]][i] == '.' || a[nex[0][i]][i] == 'N')){
                    if (a[nex[0][i]][i] == 'N'){
                        a[nex[0][i]][i] = '.';
                        res++;
                        flag = 0;
                    }
                    nex[0][i]++;
                }
            }
            fi(i, 1, m){
                while (nex[1][i] >= 1 && (a[i][nex[1][i]] == '.' || a[i][nex[1][i]] == 'E')){
                    if (a[i][nex[1][i]] == 'E'){
                        a[i][nex[1][i]] = '.';
                        res++;
                        flag = 0;
                    }
                    nex[1][i]--;
                }
            }
            fi(i, 1, n){
                while (nex[2][i] >= 1 && (a[nex[2][i]][i] == '.' || a[nex[2][i]][i] == 'S')){
                    if (a[nex[2][i]][i] == 'S'){
                        a[nex[2][i]][i] = '.';
                        res++;
                        flag = 0;
                    }
                    nex[2][i]--;
                }
            }
            fi(i, 1, m){
                while (nex[3][i] <= n && (a[i][nex[3][i]] == '.' || a[i][nex[3][i]] == 'W')){
                    if (a[i][nex[3][i]] == 'W'){
                        a[i][nex[3][i]] = '.';
                        res++;
                        flag = 0;
                    }
                    nex[3][i]++;
                }
            }
            if (flag) break;
        }
        cout << res << '\n';
    }
}
