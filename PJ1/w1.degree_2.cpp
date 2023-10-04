#include <bits/stdc++.h>
using namespace std;

void degree_2(int a, int b, int c){
    float delta = (float)(b*b - 4*a*c);
    if(delta<0) printf("NO SOLUTION");
    else if(delta == 0){
        printf("%.2f" , (float) -b/(2*a));
    }
    else{
        float x2 = (float)(-b+sqrt(delta))/(2*a);
        float x1 = (float)(-b-sqrt(delta))/(2*a);
        printf("%.2f %.2f" , x1, x2);
    }
}

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    degree_2(a, b, c);
}