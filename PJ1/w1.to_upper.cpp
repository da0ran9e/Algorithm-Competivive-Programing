#include <bits/stdc++.h>
using namespace std;

char upper_case_of(char c){
	char C = c;
	if (c<=122&&c>=97) //(c.isalpha() && c.islower()) 
	{
		C -= 32;
	}
	return C;
}

int main(){
	char c;
	while(cin.get(c)){
		cout << upper_case_of(c);
	}
}
// a - 97
// A - 65
// z - 122
// Z - 90