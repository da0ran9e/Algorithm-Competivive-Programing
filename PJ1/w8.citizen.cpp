#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Person {
    string code;
    string date_of_birth;
    string father_code;
    string mother_code;
    char is_alive;
    string region_code;
};

int main() {
    vector<Person> database;
    map<string, int> birth_count;
    map<string, int> generation_distance;

    // Read the database block
    string line;
    while (getline(cin, line) && line != "*") {
        Person person;
        cin >> person.code >> person.date_of_birth >> person.father_code >> person.mother_code >> person.is_alive >> person.region_code;
        database.push_back(person);
        birth_count[person.date_of_birth]++;
    }

    // Read and process queries
    while (cin >> line && line != "***") {
        if (line == "NUMBER_PEOPLE") {
            cout << database.size() << endl;
        } else if (line == "NUMBER_PEOPLE_BORN_AT") {
            string date;
            cin >> date;
            cout << birth_count[date] << endl;
        } else if (line == "MOST_ALIVE_ANCESTOR") {
            string code;
            cin >> code;
            int distance = 0;
            while (code != "0000000") {
                distance++;
                for (const Person& person : database) {
                    if (person.code == code) {
                        code = (person.is_alive == 'Y') ? person.father_code : "0000000";
                        break;
                    }
                }
            }
            cout << distance << endl;
        } else if (line == "NUMBER_PEOPLE_BORN_BETWEEN") {
            string from_date, to_date;
            cin >> from_date >> to_date;
            int count = 0;
            for (const Person& person : database) {
                if (person.date_of_birth >= from_date && person.date_of_birth <= to_date) {
                    count++;
                }
            }
            cout << count << endl;
        } else if (line == "MAX_UNRELATED_PEOPLE") {
            // Your implementation for MAX_UNRELATED_PEOPLE
        }
    }

    return 0;
}
