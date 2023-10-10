#include<bits/stdc++.h>
using namespace std;

#define NMAX 1005

int a,b,c,vis[NMAX][NMAX];

void bfs(int x,int y,int step){
    if(x==c||y==c){
        cout<<step<<endl;
        exit(0);
    }
    if(x==0)
        vis[0][y]=1,bfs(a,y,step+1);
    if(y==0)
        vis[x][0]=1,bfs(x,b,step+1);
    int t=min(x,b-y);
    if(vis[x-t][y+t]==0){
        vis[x-t][y+t]=1;
        bfs(x-t,y+t,step+1);
    }
    t=min(y,a-x);
    if(vis[x+t][y-t]==0){
        vis[x+t][y-t]=1;
        bfs(x+t,y-t,step+1);
    }
}

int main(){
    cin >> a >> b >> c;

    if(c>a && c>b){
        cout<<-1<<endl;
        return 0;
    }
    memset(vis,0,sizeof(vis));
    bfs(0,0,0);
    cout<<-1<<endl;
}
