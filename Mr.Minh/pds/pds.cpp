#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "pds"
const int maxn = 185, mm = 171;

using namespace std;

ll L[maxn][maxn][maxn], M[maxn][maxn][maxn], pre, n, now = 9;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    if (n <= 10){
        cout << n;
        exit(0);
    }
    fi(i, 1, mm){
        fi(j, 1, 9){
            L[j][j%i][i]++;
        }
    }
    fi(l, 2, 19){
        fi(i, 1, min(l*9, mm)){
            fi(j, 0, min(mm, l*9)){
                fi(k, 1, mm){
                    fi(t, 0, 9){
                        M[i+t][(j*t)%k][k] += L[i][j][k];
                    }
                }
            }
        }
        pre = now;
        fi(i, 1, mm) now += M[i][0][i];
        fi(i, 1, mm){
            fi(j, 0, mm){
                fi(k, 1, mm){
                    L[i][j][k] = M[i][j][k];
                    M[i][j][k] = 0;
                }
            }
        }

        cout << now << '\n';
    }
}
