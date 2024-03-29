#include<bits/stdc++.h>
using namespace std;

#define NMAX 1005

int a,b,c,visited[NMAX][NMAX];

void bfs(int x,int y,int step){
    if (x>a || y>b || x<0 || y<0) return;
    cout << step ;
    for (int k=0; k<step; k++){
        cout << "_";
    }
    cout << x << "::" << y << endl;
    if(x==c||y==c){
        cout<<step<<endl;
        exit(0);
    }
    // jug a is empty
    if(x==0 && visited[a][y] == 0) {
        visited[0][y]=1;
        bfs(a,y,step+1);
    }
     // jug b is empty
    if(y==0 && visited[x][b] == 0) {
        visited[x][0]=1;
        bfs(x,b,step+1);
    }
    // jug a to b
    int t=b-y;
    if (t<=x){
        if(visited[x-t][b]==0){
            visited[x-t][b]=1;
            bfs(x-t,b,step+1);
        }
    }
    else{
        if(visited[0][x+y]==0){
            visited[0][x+y]=1;
            bfs(0,x+y,step+1);
        }
    }
    // jug b to a
    t=a-x;
    if (t<=y){
        if(visited[a][y-t]==0){
            visited[a][y-t]=1;
            bfs(a,y-t,step+1);
        }
    }
    else{
        if(visited[x+y][0]==0){
            visited[x+y][0]=1;
            bfs(x+y,0,step+1);
        }
    }
    //empty jug a
    if(visited[0][y]==0 && y!=b){
        visited[0][y]=1;
        bfs(0,y,step+1);
    }
    //empty jug b
    if(visited[x][0]==0 && x!=a){
        visited[x][0]=1;
        bfs(x,0,step+1);
    }
}

int main(){
    cin >> a >> b >> c;

    if(c>a && c>b){
        cout<<-1<<endl;
        return 0;
    }
    memset(visited,0,sizeof(visited));
    bfs(0,0,0);
    cout<<-1<<endl;
}
/*
    Example: 6 8 4

    |BFS from bfs(0,0,0)                                0,0
    |    
    |--| bfs(6,0,1) a empty                             6,0
    |  |     
    |  |--| bfs(6,8,2) b empty                          6,8
    |  |  | 
    |  |  |--| t = min(6, 8-8) = 0
    |  |  |
    |  |  |--| t = min(8, 6-6) = 0
    |  |  
    |  |--| t = min(6, 8-0) = 6
    |  |  | bfs(0,6,2)                                  0,6
    |  |  |
    |  |  |--| bfs(6,6,3) a empty                       6,6
    |  |  |   
    |  |  |--| t = min(6, 8-6) = 2
    |  |  |  | bfs(4,8,4)                               4,8 (cout)
    |  |  |  
    |  |  |--| t = min(6, 6-6) = 0
    |  |                         
    |  |--| t = min(0, 6-6) = 0
    |
    |--| bfs(0,8,1) b empty                             0,8
    |  |
    |  |--| bfs(6,8,2) a empty (visited)
    |  |  
    |  |--| t = min(0, 8-8) = 0
    |  |
    |  |--| t = min(8, 6-0) = 6
    |
    |--| t = min(0,8-0) = 0
    |
    |--| t = min(0,6-0) = 0

*/