#include <bits/stdc++.h>

using namespace std;
int t,m,n;
//long long base=322122547;
char a[2005][2005],b[2005][2005];
long long poww[2000005];
long long tonga[2005][2005];
long long tongb[2005][2005];
long long gettonga(int x,int y,int u,int v) {
    long long tong=(tonga[u][v]-tonga[u][y-1]-tonga[x-1][v]+tonga[x-1][y-1]);
    int vv=n*(m-u)+n-v;
    return (tong*poww[vv]);
}
long long gettongb(int x,int y,int u,int v) {
    long long tong=(tongb[u][v]-tongb[u][y-1]-tongb[x-1][v]+tongb[x-1][y-1]);
    int vv=n*(m-u)+n-v;
    return (tong*poww[vv]);
}
unordered_map<long long,bool>dd;
bool kt(int h,int c) {
    dd.clear();
    for(int i=h; i<=m; i++)
        for(int j=c; j<=n; j++)
            dd[gettonga(i-h+1,j-c+1,i,j)]=1;
    for(int i=h; i<=m; i++)
        for(int j=c; j<=n; j++)
            if(dd.count(gettongb(i-h+1,j-c+1,i,j))==1)return 1;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        cin>>m>>n;
        poww[0]=1;
    for(int i=1; i<=m*n; i++)poww[i]=(poww[i-1]*33);
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
                cin>>a[i][j];
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
                cin>>b[i][j];
        int dem=0;
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++) {
                tonga[i][j]=poww[dem]*(a[i][j]-'a'+1);
                dem++;
            }
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
                tonga[i][j]=(tonga[i][j]+tonga[i-1][j]+tonga[i][j-1]-tonga[i-1][j-1]);
        dem=0;
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++) {
                tongb[i][j]=poww[dem]*(b[i][j]-'a'+1);
                dem++;
            }
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
                tongb[i][j]=(tongb[i][j]+tongb[i-1][j]+tongb[i][j-1]-tongb[i-1][j-1]);
        int maxx=0;
        int ddd=n;
        for(int i=1; i<=m; i++) {
            while(kt(i,ddd)==0)ddd--;
            maxx=max(maxx,i*ddd);
        }
        cout<<maxx<<'\n';
    }
    return 0;
}
