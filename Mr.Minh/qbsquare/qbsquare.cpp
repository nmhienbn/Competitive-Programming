#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define fir first
#define se second
#define bit(i,j) ((i>>j)&1)
#define bit2(i) (1<<(i-1))
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

#define maxn 1005
#define maxm 1000006
#define MOD
#define Seraphine "qbsquare"

using namespace std;

int n, m, a[maxn][maxn], L[maxn], res, pre[maxn], nex[maxn];
int st[maxn], top; // stack

int main(){
    faster
    freopen(Seraphine".inp","r",stdin);
    freopen(Seraphine".out","w",stdout);
    cin >> m >> n;
    fi(i, 1, m){
        fi(j, 1, n){
            cin >> a[i][j];
        }
    }
    fi(t, 0, 1){
        fi(i, 1, n) L[i] = 0;
        fi(i, 1, m){
            fi(j, 1, n){
                if (a[i][j] == t) L[j]++;
                else L[j] = 0;
            }
            top = 0, st[0] = 0;
            fi(j, 1, n){
                while (top > 0 && L[st[top]] >= L[j]){
                    top--;
                }
                pre[j] = st[top];
                st[++top] = j;
            }
            top = 0, st[top] = n+1;
            fid(j, n, 1){
                while (top > 0 && L[st[top]] >= L[j]){
                    top--;
                }
                nex[j] = st[top];
                st[++top] = j;
            }
            fi(j, 1, n){
                res = max(res, min(L[j], nex[j] - pre[j] - 1));
            }
        }
    }
    cout << res;
}
