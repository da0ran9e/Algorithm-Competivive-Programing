#include <bits/stdc++.h>

using namespace std;

struct Person {
    string code;
    string date_of_birth;
    string father_code;
    string mother_code;
    char is_alive;
    string region_code;
};

// Function to count the number of people born on a specific date
void number_people_born_at(const vector<Person>& database, const string& date) {
    int count = 0;
    for (const Person& person : database) {
        if (person.date_of_birth == date) {
            count++;
        }
    }
    cout << count << endl;
}

// Function to check if two people have a father/mother-child relationship
bool isRelated(const Person &person1, const Person &person2) {
    return person1.code == person2.father_code || person1.code == person2.mother_code ||
           person2.code == person1.father_code || person2.code == person1.mother_code;
}

// Function to find the size of the largest unrelated subset
int max_unrelated_people(const vector<Person> &database) {
    int n = database.size();
    int maxSubsetSize = 0;

    // Iterate through all possible subsets
    for (int i = 0; i < (1 << n); ++i) {
        vector<Person> subset;

        // Check each person in the database
        for (int j = 0; j < n; ++j) {
            if ((i & (1 << j)) != 0) {
                subset.push_back(database[j]);
            }
        }

        // Check if the subset is valid (no father/mother-child relationships)
        bool validSubset = true;
        for (const Person &person1 : subset) {
            for (const Person &person2 : subset) {
                if (&person1 != &person2 && isRelated(person1, person2)) {
                    validSubset = false;
                    break;
                }
            }
            if (!validSubset) {
                break;
            }
        }

        // Update the maximum subset size
        if (validSubset && subset.size() > maxSubsetSize) {
            maxSubsetSize = subset.size();
        }
    }

    return maxSubsetSize;
}

// Function to find the most alive ancestor
int findGenerationDistance(const vector<Person>& database, const string& code, int& maxDistance) {
    for (const Person& person : database) {
        if (person.code == code) {
            if (person.is_alive == 'N') {
                // If the person is not alive, return 0 distance
                maxDistance = 0;
                return 0;
            } else {
                // Recursively find the most alive ancestor
                int fatherDistance = findGenerationDistance(database, person.father_code, maxDistance) + 1;
                int motherDistance = findGenerationDistance(database, person.mother_code, maxDistance) + 1;
                int distance = max(fatherDistance, motherDistance);

                // Update maxDistance if the current distance is greater
                maxDistance = max(maxDistance, distance);
                return distance;
            }
        }
    }
    // Person not found
    return -1;
}

void most_alive_ancestor(const vector<Person>& database, const string& code) {
    int maxDistance = 0;
    int distance = findGenerationDistance(database, code, maxDistance);

    if (distance == -1) {
        cout << "0" << endl;
    } else {
        cout << maxDistance << endl;
    }
}

int main() {
    vector<Person> database;

    // Read the database
    string code;
    string date_of_birth;
    string father_code;
    string mother_code;
    char is_alive;
    string region_code;

    do {
        cin >> code;
        if (code != "*") {
            Person person;
            person.code = code;
            cin >> person.date_of_birth >> person.father_code >> person.mother_code >> person.is_alive >> person.region_code;
            database.push_back(person);
        }
    } while (code != "*");

    // Process queries
    string query;
    do {
        cin >> query;
        if (query == "NUMBER_PEOPLE") {
            cout << database.size() << endl;
        } else if (query == "NUMBER_PEOPLE_BORN_AT") {
            string date;
            cin >> date;
            number_people_born_at(database, date);
        } else if (query == "MOST_ALIVE_ANCESTOR") {
            // Extract code from the query
            string code;
            cin >> code;
            
            most_alive_ancestor(database, code);
        } else if (query == "NUMBER_PEOPLE_BORN_BETWEEN") {
            // Extract from_date and to_date from the query
            string from_date, to_date;
            int count = 0;
            cin >> from_date >> to_date;

            for (const Person &person : database) {
                if (person.date_of_birth >= from_date && person.date_of_birth <= to_date) {
                    count++;
                }
            }
            cout << count << endl;
        } else if (query == "MAX_UNRELATED_PEOPLE") {
            cout << max_unrelated_people(database) << endl;
        }
    } while(query != "***");

    return 0;
}
