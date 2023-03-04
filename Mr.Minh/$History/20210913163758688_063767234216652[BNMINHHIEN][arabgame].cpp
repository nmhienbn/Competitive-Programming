#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "arabgame"
const int maxn = 1e4+5, maxq = 4e7+5;

using namespace std;

map<char, int> tt = {{'A', 1}, {'B', 2}, {'C', 3}, {'D', 4},
                    {'a', 5}, {'b', 6}, {'c', 7}, {'d', 8}};
char ng[9] = {' ' , 'A', 'B', 'C', 'D', 'a', 'b', 'c', 'd'};
int pre[maxq];

class node {
    public:
    int a[9];
    node(){} void input() {
        fi(i, 0, 8)
            a[i] = i;
    }
    node bd(int c){
        node b;
        if (c == 1){
            b.a[0] = a[3];
            b.a[1] = a[0];
            b.a[2] = a[2];
            b.a[3] = a[4];
            b.a[4] = a[1];
            b.a[5] = a[5];
            b.a[6] = a[6];
            b.a[7] = a[7];
            b.a[8] = a[8];
        }
        else if (c == 2){
            b.a[0] = a[0];
            b.a[1] = a[4];
            b.a[2] = a[1];
            b.a[3] = a[3];
            b.a[4] = a[5];
            b.a[5] = a[2];
            b.a[6] = a[6];
            b.a[7] = a[7];
            b.a[8] = a[8];
        }
        else if (c == 3){
            b.a[0] = a[0];
            b.a[1] = a[1];
            b.a[2] = a[2];
            b.a[3] = a[6];
            b.a[4] = a[3];
            b.a[5] = a[5];
            b.a[6] = a[7];
            b.a[7] = a[4];
            b.a[8] = a[8];
        }
        else if (c == 4){
            b.a[0] = a[0];
            b.a[1] = a[1];
            b.a[2] = a[2];
            b.a[3] = a[3];
            b.a[4] = a[7];
            b.a[5] = a[4];
            b.a[6] = a[6];
            b.a[7] = a[8];
            b.a[8] = a[5];
        }
        else if (c == 5){
            b.a[0] = a[1];
            b.a[1] = a[4];
            b.a[2] = a[2];
            b.a[3] = a[0];
            b.a[4] = a[3];
            b.a[5] = a[5];
            b.a[6] = a[6];
            b.a[7] = a[7];
            b.a[8] = a[8];
        }
        else if (c == 6){
            b.a[0] = a[0];
            b.a[1] = a[2];
            b.a[2] = a[5];
            b.a[3] = a[3];
            b.a[4] = a[1];
            b.a[5] = a[4];
            b.a[6] = a[6];
            b.a[7] = a[7];
            b.a[8] = a[8];
        }
        else if (c == 7){
            b.a[0] = a[0];
            b.a[1] = a[1];
            b.a[2] = a[2];
            b.a[3] = a[4];
            b.a[4] = a[7];
            b.a[5] = a[5];
            b.a[6] = a[3];
            b.a[7] = a[6];
            b.a[8] = a[8];
        }
        else if (c == 8){
            b.a[0] = a[0];
            b.a[1] = a[1];
            b.a[2] = a[2];
            b.a[3] = a[3];
            b.a[4] = a[5];
            b.a[5] = a[8];
            b.a[6] = a[6];
            b.a[7] = a[4];
            b.a[8] = a[7];
        }
        return b;
    }
    bool isroot(){
        fi(i, 0, 8)
            if (a[i] != i) return false;
        return true;
    }
};

struct dl {
    node f;
    int s, t;
};

string s, res;
dl q[maxq];
int d, c;

int main(){
    faster
    freopen(Seraphine".in", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> s;
    node b;
    b.input();
    for (auto c : s){
        b = b.bd(tt[c]);
    }
    //fi(i, 0, 8){cout << b.a[i] << ' ';} cout << endl;
    q[++c] = {b, 0, 0};
    while(true){
        auto u = q[d++];
        b = u.f;
        fi(i, 1, 8){
            if (b.bd(i).isroot()){
                //cout << i << ' ' << u.t << '\n';
                res = ng[i] + res;
                int now = d-1;
                fid(j, u.s, 1){
                    res = ng[q[now].t] + res;
                    now = pre[now];
                }
                cout << res;
                exit(0);
            }
        }
        fi(i, 1, 8){
            q[++c] = {b.bd(i), u.s+1, i};
            pre[c] = d-1;
            //cout << i << ' ' << u.t << '\n';
        }
    }
    return 0;
}
