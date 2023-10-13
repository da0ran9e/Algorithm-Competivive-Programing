#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
	string humanname;
 	int decendant;
 	int generation;
 	Node* parent;
} Node;

void addDesToParents(Node * person, Node * parent, int toAdd, int generation) {
	if (parent == NULL) {
		return;
	}

	parent->decendant += toAdd;
	parent->generation = max(parent->generation, generation + 1);
	
	addDesToParents(parent, parent->parent, toAdd, generation + 1);
	
	// cout << ":" << parent->humanname << ":" << parent->decendant << ":" << parent->generation << ":\n";
}

int main(){
	unordered_map<string, Node*> family;
	string person_name, father_name;

	do{
		cin >> person_name;
		if (person_name == "***") {
			break;
		}
		cin >> father_name;

		Node* father;
		Node* person;
		auto search = family.find(father_name);
		if (search != family.end()) {
			father = search->second;
		} else {
			father = new Node();
				father->humanname = father_name;

			father->decendant = 0;
			father->generation = 1;
			father->parent = NULL;

			family[father_name] = father;
		}

		search = family.find(person_name);
		if (search != family.end()) {
			person = search->second;
			person->parent = father;
			addDesToParents(person, father, person->decendant + 1, person->generation);
		} else {
			person = new Node();
				person->humanname = person_name;

			person->decendant = 0;
			person->generation = 0;
			person->parent = father;

			family[person_name] = person;

			Node* next = father;

			addDesToParents(person, father, 1, 0);
		}
	} while(1);


	string query;
	while(1) {
		cin >> query;
		if(query == "***") {
			break;
		}

		cin >> person_name;
		// cout << "Query: " << query << " " << person_name << ":\n";

		if (query == "descendants") {
			auto search = family.find(person_name);
			cout << search->second->decendant << '\n';
		} else if (query == "generation") {
			auto search = family.find(person_name);
			cout << search->second->generation << '\n';
		}
	}
}