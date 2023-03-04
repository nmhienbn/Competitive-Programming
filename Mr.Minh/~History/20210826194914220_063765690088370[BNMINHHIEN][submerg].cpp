#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "submerg"
const int maxn = 55, ngg[4] = {-1, 0, 0, 1}, doc[4] = {0, -1, 1, 0};

using namespace std;

int n, m, su, sv, du, dv, L[maxn][maxn], d[maxn][maxn];
int kt[maxn][maxn];
queue<pii> q;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> m >> n;
    fi(i, 1, m){
        fi(j, 1, n){
            d[i][j] = L[i][j] = 1e9;
            kt[i][j] = 1;
            char c;
            cin >> c;
            if (c == 'S'){
                su = i, sv = j;
            }
            else if (c == 'D'){
                du = i, dv = j;
            }
            else if (c == 'X'){
                kt[i][j] = 2;
            }
            else if (c == '*'){
                q.push({i, j});
                L[i][j] = 0;
            }
        }
    }
    while (q.size()){
        int u = q.front().first, v = q.front().second;
        q.pop();
        fi(i, 0, 3){
            int uu = u + ngg[i], vv = v + doc[i];
            if (kt[uu][vv]){
                if (L[uu][vv] > L[u][v] + 1){
                    L[uu][vv] = L[u][v] + 1;
                    q.push({uu, vv});
                }
            }
        }
    }
    L[du][dv] = 1e9;
    d[su][sv] = 0;
    q.push({su, sv});
    while (q.size()){
        int u = q.front().first, v = q.front().second;
        q.pop();
        fi(i, 0, 3){
            int uu = u + ngg[i], vv = v + doc[i];
            if (kt[uu][vv] == 1){
                if (d[uu][vv] > d[u][v] + 1 && d[u][v] + 1 < L[uu][vv]){
                    d[uu][vv] = d[u][v] + 1;
                    q.push({uu, vv});
                }
            }
        }
    }
    d[du][dv] == 1e9 ? cout << "KAKTUS" : cout << d[du][dv];
}
