#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string command;
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
            int v;
            cin>>v; 
            auto itv = find(linked_list.begin(), linked_list.end(), v);
            if(itv==linked_list.end())
            {
                linked_list.push_back(v);
            }
            
        }
        else if (command == "addfirst"){
            int v;
            cin>>v; 
            auto itv = find(linked_list.begin(), linked_list.end(), v);
            if(itv==linked_list.end())
            {
                linked_list.insert(linked_list.begin(), v);
            }
        }
        else if (command == "addafter"){
            int v, p;
            cin>>v>>p; 
            auto itv = find(linked_list.begin(), linked_list.end(), v);
            auto itp = find(linked_list.begin(), linked_list.end(), p);
            if(itv==linked_list.end() && itp!=linked_list.end()){
                linked_list.insert(itp+1, v);
            }
        }
        else if (command == "addbefore"){
            int v, p;
            cin>>v>>p; 
            
            auto itv = find(linked_list.begin(), linked_list.end(), v);
            auto itp = find(linked_list.begin(), linked_list.end(), p);
            if(itv==linked_list.end() && itp!=linked_list.end()){
                linked_list.insert(itp, v);
            }        
        }
        else if (command == "remove"){
            int v;
            cin>>v;

            linked_list.erase(remove(linked_list.begin(), linked_list.end(), v), linked_list.end());
        }
        else if (command == "reverse"){
            reverse(linked_list.begin(), linked_list.end());
        }
    }
    for (int i : linked_list) {
        cout << i << " ";
    }
}