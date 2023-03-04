#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "meawater"
const int maxn = 5005;
using namespace std;

int n, a[3], b[3], c[3], L[maxn][maxn];
ll res = 1e18;
map<pii, ll> M;

void sub1(){
    fi(i, 0, 5e3) fi(j, 0, 5e3) L[i][j] = 1e9;
    L[b[0]][b[1]] = 0;
    queue<pii> q;
    q.push({b[0], b[1]});
    while (q.size()){
        int d[3] = {q.front().first, q.front().second,
                n - q.front().first - q.front().second};
        int C = L[d[0]][d[1]];
        //cout << d[0] << ' ' << d[1] << ' ' << C << '\n';
        q.pop();
        fi(i, 0, 2){
            fi(j, 0, 2) if (i != j){
                if (d[i] > 0){
                    int kc = a[j] - d[j];
                    int e[3] = {d[0], d[1], d[2]};
                    if (d[i] <= kc){
                        e[j] += e[i];
                        e[i] = 0;
                    }
                    else {
                        e[i] -= kc;
                        e[j] = a[j];
                    }
                    if (L[e[0]][e[1]] > C + 1){
                        L[e[0]][e[1]] = C + 1;
                        q.push({e[0], e[1]});
                    }
                }
            }
        }
    }
    fi(i, 0, 2) fi(j, 0, 2) if (i != j) res = min(res, 1ll*L[c[i]][c[j]]);
    cout << (res >= 1e9 ? -1 : res);
    exit(0);
}

void sub2(){
    M[{b[0], b[1]}] = 0;
    queue<pii> q;
    q.push({b[0], b[1]});
    while (q.size()){
        int d[3] = {q.front().first, q.front().second,
                n - q.front().first - q.front().second};
        int C = M[q.front()];
        q.pop();
        fi(i, 0, 2){
            fi(j, 0, 2) if (i != j){
                if (d[i] > 0){
                    int kc = a[j] - d[j];
                    int e[3] = {d[0], d[1], d[2]};
                    if (d[i] <= kc){
                        e[j] += e[i];
                        e[i] = 0;
                    }
                    else {
                        e[i] -= kc;
                        e[j] = a[j];
                    }
                    if (M.find({e[0], e[1]}) == M.end()){
                        M[{e[0], e[1]}] = C + 1;
                        q.push({e[0], e[1]});
                    }
                }
            }
        }
    }
    fi(i, 0, 2) fi(j, 0, 2) if (i != j){
        if (M.find({c[i], c[j]}) != M.end()){
            res = min(res, M[{c[i], c[j]}]);
        }
    }
    cout << (res >= 1e9 ? -1 : res);
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    fi(i, 0, 2) cin >> a[i];
    fi(i, 0, 2) cin >> b[i], n += b[i];
    fi(i, 0, 2) cin >> c[i];
    if (n != c[0] + c[1] + c[2]){
        cout << -1;
        exit(0);
    }
    if (*max_element(a, a+3) <= 5e3){
        sub1();
    }
    sub2();
}
