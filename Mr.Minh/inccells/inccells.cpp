#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define TwistedFate "inccells"
const int maxn = 505;
using namespace std;

struct dl {
    int w, x, y;
    bool operator < (const dl& x) const {
        return w < x.w;
    }
} a[maxn*maxn];

int n, m, d, k, res, L[maxn*maxn];
vector<int> tree(maxn*maxn*4);

bool inRange(int qx1,int qx2,int qy1,int qy2,int nx1,int nx2,int ny1,int ny2){
	if(nx2<nx1||ny2<ny1)
		return false;
	if(qx2<nx1||qx1>nx2)
		return false;
	if(qy2<ny1||qy1>ny2)
		return false;
	return true;
}

inline int child(int node,int number){
	return node*4+number;
}

void update(int qx1, int qx2, int qy1, int qy2, int nx1, int nx2, int ny1, int ny2, int node, int value){
	if(!inRange(qx1,qx2,qy1,qy2,nx1,nx2,ny1,ny2))
		return;
	else if(nx1 >= qx1 && nx2 <= qx2 && ny1 >= qy1&&ny2 <= qy2 && nx1 == nx2 && ny1 == ny2)
		tree[node] = value;
	else
	{
		update(qx1,qx2,qy1,qy2,	nx1,(nx1+nx2)/2,ny1,(ny2+ny1)/2,    child(node,1), value);
		update(qx1,qx2,qy1,qy2,	nx1, (nx1+nx2)/2, (ny1+ny2)/2+1, ny2,  child(node,2), value);
		update(qx1,qx2,qy1,qy2,	(nx1+nx2)/2+1, nx2,	ny1, (ny2+ny1)/2,  child(node,3), value);
		update(qx1,qx2,qy1,qy2,	(nx1+nx2)/2+1, nx2, (ny1+ny2)/2+1, ny2, child(node,4), value);

		tree[node] = max({tree[child(node,1)], tree[child(node,2)],
                            tree[child(node,3)], tree[child(node,4)]});
	}
}

int query(int qx1, int qx2, int qy1, int qy2, int nx1, int nx2, int ny1, int ny2, int node){
	if(!inRange(qx1,qx2,qy1,qy2,nx1,nx2,ny1,ny2))
		return 0;
	else if(nx1 >= qx1 && nx2 <= qx2 && ny1 >= qy1 && ny2 <= qy2)
		return tree[node];
	else
	{
		int LL = query(qx1,qx2,qy1,qy2, nx1,(nx1+nx2)/2, ny1,(ny2+ny1)/2,    child(node,1));
		int LR = query(qx1,qx2,qy1,qy2, nx1, (nx1+nx2)/2, (ny1+ny2)/2+1, ny2,  child(node,2));
		int RL = query(qx1,qx2,qy1,qy2, (nx1+nx2)/2+1, nx2, ny1, (ny2+ny1)/2,  child(node,3));
		int RR = query(qx1,qx2,qy1,qy2, (nx1+nx2)/2+1, nx2, (ny1+ny2)/2+1, ny2, child(node,4));
		return max({LL, LR, RL, RR});
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TwistedFate".inp", "r", stdin);
    freopen(TwistedFate".out", "w", stdout);
    cin >> n >> m >> d;
    fi(i, 1, n){
        fi(j, 1, m){
            int x;
            cin >> x;
            a[++k] = {x, i+j-1, j-i+n};
        }
    }
    sort(a+1, a+k+1);
    int t = 1;
    fi(i, 1, k){
        /*L[i] = 1;
        fi(j, 1, i-1) if (a[j].w >= a[i].w) break;
        else if (abs(a[i].x-a[j].x) + abs(a[i].y-a[j].y) <= d){
            L[i] = max(L[i], L[j] + 1);
        }*/
        while (a[t].w < a[i].w) update(a[t].x-d, a[t].x+d, a[t].y-d, a[t].y+d, 1, n, 1, m, 1, L[t]), t++;
        L[i] = max(L[i], query(a[i].x, a[i].x, a[i].y, a[i].y, 1, n, 1, m, 1) + 1);
        res = max(res, L[i]);
    }
    cout << res;
}
