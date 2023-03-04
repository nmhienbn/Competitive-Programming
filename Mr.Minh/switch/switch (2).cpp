#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "switch"
const int maxn = 25, N = (1 << 25) + 5;
using namespace std;

int k, st, fn, L[N];
queue<int> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> k;
    fi(i, 1, k){
        int x;
        cin >> x;
        st |= x << (i-1);
    }
    L[st] = 1;
    q.push(st);
    while (q.size()){
        int u = q.front();
        q.pop();
        fi(i, 0, k-1){
            if (((u >> i) & 1) == 0){
                int v = (u | (1 << i)), cnt = 0;
                fi(j, 0, k){
                    if (((v >> j) & 1) == 1) cnt++;
                    else {
                        if (cnt >= 4){
                            fi(t, j-cnt, j-1) v -= (1 << t);
                        }
                        cnt = 0;
                    }
                }
                if (L[v] == 0){
                    L[v] = L[u] + 1;
                    if (v == 0){
                        cout << L[v] - 1;
                        exit(0);
                    }
                    q.push(v);
                }
            }
        }
    }
    cout << L[0]-1;

}
