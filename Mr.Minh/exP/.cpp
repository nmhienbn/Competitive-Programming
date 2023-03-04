#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a, _b = b; i <= _b; i++)
#define fid(i, a, b) for(int i = a, _b = b; i >= _b; i--)
#define pp pair<int,int>
#define hien "icpc"
#define maxn 1009
#define M 1000000

using namespace std;

int n;
bool flag;
char b[2*maxn];
int l2[maxn][maxn], l5[maxn][maxn], u;
int8_t v2[M + 10], v5[M + 10], s2[maxn][maxn], s5[maxn][maxn], vt1, vt2;

void cbi(){
    for (int i = 2; i <= M; i += 2){
        v2[i] = v2[i / 2] + 1;
    }
    for (int i = 5; i <= M; i += 5){
        v5[i] = v5[i / 5] + 1;
    }
}

void xuli(int l[][maxn], int8_t v[][maxn]){
    cout << l[n][n] << '\n';
    int i = n, j = n;
    fid(t, n * 2 - 2, 1){
        if (l[i][j] == l[i][j-1] + v[i][j] && j > 1){
            j--;
            b[t] = 'R';
        }
        else {
            i--;
            b[t] = 'D';
        }
    }
}

void except(int i, int j){
    cout << 1 << '\n';
    fi(t, 1, i-1) cout << 'D';
    fi(t, 1, j-1) cout << 'R';
    fi(t, i, n-1) cout << 'D';
    fi(t, j, n-1) cout << 'R';
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cbi();
    cin >> n;
    fi(i, 2, n) l2[0][i] = l2[i][0] = l5[0][i] = l5[i][0] = 1e9;
    fi(i, 1, n){
        fi(j, 1, n){
            cin >> u;
            if (u == 0){
                l2[i][j] = l5[i][j] = 1;
                vt1 = i, vt2 = j;
                flag = 1;
                continue;
            }
            while (u % 2 == 0){
                if (u > M) s2[i][j]++, u /= 2;
                else {s2[i][j] += v2[u]; break;}
            }
            while (u % 5 == 0){
                if (u > M) s5[i][j]++, u /= 5;
                else {s5[i][j] += v5[u]; break;}
            }
            l2[i][j] = min(l2[i-1][j], l2[i][j-1]) + s2[i][j];
            l5[i][j] = min(l5[i-1][j], l5[i][j-1]) + s5[i][j];
        }
    }
    if (flag && min(l2[n][n], l5[n][n])){
        except(vt1, vt2);
    }
    if (l2[n][n] < l5[n][n]){
        xuli(l2, s2);
    }
    else {
        xuli(l5, s5);
    }
    fi(i, 1, n * 2 - 2) cout << b[i];
}
