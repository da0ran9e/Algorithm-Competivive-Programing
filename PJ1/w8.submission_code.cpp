#include <bits/stdc++.h>
using namespace std;

#define M 100000
#define N 90000

int totalErr = 0;
int totalSubmission = 0;

struct User {
    char userId[11];
    int err;
    int point;
};

std::unordered_map<std::string, int> users[M][2];
int timePeriod[N];

int hashUserId(const char* s) {
    int h = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        h = (h * 256 + s[i]) % M;
    return h;
}

int hashTime(const char* t) {
    return ((t[0] - '0') * 10000 + (t[1] - '0') * 1000 + (t[3] - '0') * 100 +
            (t[4] - '0') * 10 + (t[6] - '0') * 1 + (t[7] - '0') * 0.1);
}

void init() {
    for (int i = 0; i <= N; i++) {
        timePeriod[i] = 0;
    }
    for (int i = 0; i <= M; i++) {
        users[i][0].clear();
        users[i][1].clear();
    }
}

int main() {
    init();
    char userId[11];
    char problemId[10];
    char time[8];
    char status[3];
    int point;
    char query[50];

    do {
        std::cin >> userId;
        if (!strcmp(userId, "#"))
            continue;
        std::cin >> problemId >> time >> status >> point;

        totalSubmission++;

        int tIndex = hashTime(time);
        int uIndex = hashUserId(userId);

        if (!strcmp(status, "ERR")) {
            totalErr++;
            users[uIndex][0][problemId] += 1;
        }

        // timePeriod[tIndex] = totalSubmission;

    } while (userId[0] != '#');

    do {
        std::cin >> query;
        if (!strcmp(query, "?total_number_submissions")) {
            std::cout << totalSubmission << std::endl;
        } else if (!strcmp(query, "?number_error_submision")) {
            std::cout << totalErr << std::endl;
        } else if (!strcmp(query, "?number_error_submision_of_user")) {
            char ID[11];
            std::cin >> ID;
            int idx = hashUserId(ID);
            std::cout << users[idx][0].size() << std::endl;
        } else if (!strcmp(query, "?total_point_of_user")) {
            char ID[11];
            std::cin >> ID;
            int idx = hashUserId(ID);
            int totalPoints = 0;
            for (const auto& entry : users[idx][1]) {
                totalPoints += entry.second;
            }
            std::cout << totalPoints << std::endl;
        } else if (!strcmp(query, "?number_submission_period")) {
            char from[8];
            char to[8];
            std::cin >> from >> to;
            int F = hashTime(from);
            int T = hashTime(to);
            if (F == 0)
                std::cout << timePeriod[T] << std::endl;
            else
                std::cout << timePeriod[T] - timePeriod[F - 1] << std::endl;
        }
    } while (query[0] != '#');

    return 0;
}
