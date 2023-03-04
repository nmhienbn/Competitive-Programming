#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "lamp"
const int maxn = 505;
using namespace std;

int n, m, L[maxn][maxn];
bool a[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> m;
    fi(i, 1, n){
        fi(j, 1, m){
            char c;
            cin >> c;
            a[i][j] = (c == '\\');
        }
    }
    deque<pii> q;
    fi(i, 1, n+1) fi(j, 1, m+1) L[i][j] = 1e9;
    L[1][1] = 1;
    q.push_front({1, 1});
    while (q.size()){
        int i = q.front().first, j = q.front().second;
        if (i == n+1 && j == m+1) break;
        q.pop_front();
        if (L[i-1][j-1] > L[i][j] && a[i-1][j-1]){
            L[i-1][j-1] = L[i][j];
            q.push_front({i-1, j-1});
        }
        if (L[i-1][j-1] > L[i][j]+1 && !a[i-1][j-1]){
            L[i-1][j-1] = L[i][j] + 1;
            q.push_back({i-1, j-1});
        }
        if (L[i+1][j+1] > L[i][j] && a[i][j]){
            L[i+1][j+1] = L[i][j];
            q.push_front({i+1, j+1});
        }
        if (L[i+1][j+1] > L[i][j]+1 && !a[i][j]){
            L[i+1][j+1] = L[i][j] + 1;
            q.push_back({i+1, j+1});
        }
        if (L[i-1][j+1] > L[i][j] && !a[i-1][j]){
            L[i-1][j+1] = L[i][j];
            q.push_front({i-1, j+1});
        }
        if (L[i-1][j+1] > L[i][j]+1 && a[i-1][j]){
            L[i-1][j+1] = L[i][j] + 1;
            q.push_back({i-1, j+1});
        }
        if (L[i+1][j-1] > L[i][j] && !a[i][j-1]){
            L[i+1][j-1] = L[i][j];
            q.push_front({i+1, j-1});
        }
        if (L[i+1][j-1] > L[i][j]+1 && a[i][j-1]){
            L[i+1][j-1] = L[i][j] + 1;
            q.push_back({i+1, j-1});
        }
    }
    if (L[n+1][m+1] == 1e9) cout << "NO SOLUTION";
    else cout << L[n+1][m+1]-1;
}
