#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Person {
    string code;
    string date_of_birth;
    string father_code;
    string mother_code;
    char is_alive;
    string region_code;
    int generation;  // To store the generation of the person in the family tree
};

unordered_map<string, Person> database;
unordered_map<string, int> subset_sizes;

int findGeneration(const string& code) {
    if (database[code].generation == -1) {
        // If the generation is not calculated yet
        int father_gen = findGeneration(database[code].father_code);
        int mother_gen = findGeneration(database[code].mother_code);
        database[code].generation = 1 + max(father_gen, mother_gen);
    }
    return database[code].generation;
}

int maxUnrelatedPeople() {
    // Initialize generation information for all people
    for (auto& entry : database) {
        entry.second.generation = -1;
    }

    // Calculate the generation for each person
    for (auto& entry : database) {
        findGeneration(entry.first);
    }

    // Count the size of each subset of unrelated people
    for (auto& entry : database) {
        subset_sizes[entry.second.code]++;
    }

    // Find the maximum subset size
    int max_size = 0;
    for (const auto& entry : subset_sizes) {
        max_size = max(max_size, entry.second);
    }

    return max_size;
}

int mostAliveAncestor(const string& code) {
    int ancestor_gen = findGeneration(code) - 1;
    return ancestor_gen;
}

int main() {
    string input;
    vector<string> queries;

    // Read input until ***
    while (getline(cin, input) && input != "***") {
        if (input == "*") {
            // Switch to processing queries
            break;
        }

        // Process the citizen information
        Person person;
        sscanf(input.c_str(), "%s %s %s %s %c %s",
               &person.code[0], &person.date_of_birth[0], &person.father_code[0],
               &person.mother_code[0], &person.is_alive, &person.region_code[0]);
        database[person.code] = person;
    }

    // Process queries
    while (getline(cin, input) && input != "***") {
        queries.push_back(input);
    }

    // Execute queries
    for (const auto& query : queries) {
        if (query == "NUMBER_PEOPLE") {
            cout << database.size() << endl;
        } else if (query.substr(0, 19) == "NUMBER_PEOPLE_BORN_AT") {
            string date = query.substr(20);
            int count = 0;
            for (const auto& entry : database) {
                if (entry.second.date_of_birth == date) {
                    count++;
                }
            }
            cout << count << endl;
        } else if (query.substr(0, 19) == "MOST_ALIVE_ANCESTOR") {
            string code = query.substr(20);
            int ancestor_gen = mostAliveAncestor(code);
            cout << ancestor_gen << endl;
        } else if (query.substr(0, 26) == "NUMBER_PEOPLE_BORN_BETWEEN") {
            string from_date = query.substr(27, 10);
            string to_date = query.substr(38, 10);
            int count = 0;
            for (const auto& entry : database) {
                if (entry.second.date_of_birth >= from_date && entry.second.date_of_birth <= to_date) {
                    count++;
                }
            }
            cout << count << endl;
        } else if (query == "MAX_UNRELATED_PEOPLE") {
            int max_size = maxUnrelatedPeople();
            cout << max_size << endl;
        }
    }

    return 0;
}
