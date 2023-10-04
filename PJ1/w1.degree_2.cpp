#include <bits/stdc++.h>
using namespace std;

void degree_2(int a, int b, int c){
    float delta = (float)(b*b - 4*a*c);
    if(delta<0) cout << "NO SOLUTION";
    else if(delta == 0){
        printf("%.2f", (float)(-b/(2*a)));
    }
    else{
        printf("%.2f %.2f", (float)(-b-sqrt(delta))/(2*a), (float)(-b+sqrt(delta))/(2*a));
    }
}

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    degree_2(a, b, c);
}