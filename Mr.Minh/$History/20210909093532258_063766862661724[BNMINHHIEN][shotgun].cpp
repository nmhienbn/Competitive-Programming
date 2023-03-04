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

#define maxn 300005
#define maxm 1000006
#define MOD
#define Seraphine "shotgun"

using namespace std;

struct node {
    int child[2];
    int deg, val;
} T[maxm*2];

int cnt;

void add(int n){
    int x = 0;
    fid(i, 19, 0){
        T[x].deg++;
        int c = ((n >> i) & 1);
        if (!T[x].child[c]) T[x].child[c] = ++cnt;
        x = T[x].child[c];
    }
    T[x].deg++;
    T[x].val = n;
}

int get(int vt){
    int x = 0;
    fid(i, 19, 0){
        T[x].deg--;
        int left = T[x].child[0];
        if (T[left].deg >= vt) x = left;
        else {
            x = T[x].child[1];
            vt -= T[left].deg;
        }
    }
    T[x].deg--;
    return T[x].val;
}

int a[maxn][4], m, n;
ll gt[maxm], res;
int b[maxm];

int main(){
    faster
    freopen(Seraphine".inp","r",stdin);
    freopen(Seraphine".out","w",stdout);
    cin >> n;
    fi(i, 1, 3){
        fi(j, 1, n){
            cin >> a[j][i];
            a[j][i] += a[j][i-1];
        }
    }
    fi(i, 1, 1e6){
        add(i);
    }
    cin >> m;
    fi(i, 1, m){
        int k;
        cin >> k;
        b[i] = get(k);
    }
    fi(i, 1, n){
        gt[1]++;
        gt[a[i][1] + 1]++;
        gt[a[i][2] + 1] += 3;
        gt[a[i][3] + 1] -= 5;
    }
    fi(i, 1, 1e6) gt[i] += gt[i-1];
    fi(i, 1, m){
        cout << gt[b[i]] << '\n';
    }
}
