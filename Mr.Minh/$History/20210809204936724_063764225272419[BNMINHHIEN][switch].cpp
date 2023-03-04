#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "switch"
const int maxn = 4e7;

using namespace std;

int n, L[maxn], now;

int calc(int u){
    int cnt = 0, res = u;
    fi(i, 0, n){
        if ((u >> i)&1) cnt++;
        else if (cnt >= 4){
            fi(j, i-cnt, i-1) res -= 1<<j;
            cnt = 0;
        }
        else cnt = 0;
    }
    return res;
}

int q[maxn], d = 0, c = 0; //queue

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    memset(L, 60, sizeof(L));
    cin >> n;
    fi(i, 1, n){
        int x;
        cin >> x;
        now += x << (n-i);
    }
    L[now] = 0;
    q[++c] = now;
    while (d <= c){
        int u = q[++d];
        fi(i, 0, n-1){
            if (!((u >> i)&1)){
                int v = calc(u + (1 << i));
                if (L[v] > L[u] + 1){
                    L[v] = L[u] + 1;
                    q[++c] = v;
                }
            }
        }
    }
    cout << L[0];
}
