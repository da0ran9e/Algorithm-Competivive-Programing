#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> linked_list;
    cin >> n;

    for (int i = 0; i < n; i++){
        int v;
        cin >> v;
        linked_list.push_back(v);
    }

    while (cin>>command && command!="#")
    {
        if (command == "addlast"){
            cin>>value; 
        }
        else if (command == "addfirst"){

        }
        else if (command == "addafter"){

        }
        else if (command == "addbefore"){

        }
        else if (command == "remove"){

        }
        else if (command == "reverse"){

        }
    }
}