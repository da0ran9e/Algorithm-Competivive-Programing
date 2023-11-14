#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

struct Transaction {
    std::string from_account;
    std::string to_account;
    int money;
    std::string time_point;
    std::string atm;
};

int main() {
    std::vector<Transaction> transactions;
    std::map<std::string, int> money_from_account;

    // Read data block
    while (true) {
        std::string line;
        std::getline(std::cin, line);
        if (line == "#") {
            break;
        }

        Transaction transaction;
        std::istringstream iss(line);
        iss >> transaction.from_account >> transaction.to_account >> transaction.money >> transaction.time_point >> transaction.atm;

        transactions.push_back(transaction);
        money_from_account[transaction.from_account] += transaction.money;
    }

    // Read query block
    while (true) {
        std::string query;
        std::getline(std::cin, query);
        if (query == "#") {
            break;
        }

        if (query == "?number_transactions") {
            std::cout << transactions.size() << std::endl;
        } else if (query == "?total_money_transaction") {
            int total_money = 0;
            for (const auto& transaction : transactions) {
                total_money += transaction.money;
            }
            std::cout << total_money << std::endl;
        } else if (query == "?list_sorted_accounts") {
            std::set<std::string> unique_accounts;
            for (const auto& transaction : transactions) {
                unique_accounts.insert(transaction.from_account);
                unique_accounts.insert(transaction.to_account);
            }
            for (const auto& account : unique_accounts) {
                std::cout << account << " ";
            }
            std::cout << std::endl;
        } else if (query.find("?total_money_transaction_from") == 0) {
            std::string account = query.substr(query.find(" ") + 1);
            std::cout << money_from_account[account] << std::endl;
        } else if (query.find("?inspect_cycle") == 0) {
            std::istringstream iss(query);
            std::string dummy, account;
            int k;
            iss >> dummy >> account >> k;

            std::set<std::string> visited_accounts;
            std::string current_account = account;
            bool cycle_found = false;

            for (int i = 0; i < k; ++i) {
                visited_accounts.insert(current_account);
                bool transaction_found = false;

                for (const auto& transaction : transactions) {
                    if (transaction.from_account == current_account && visited_accounts.find(transaction.to_account) == visited_accounts.end()) {
                        current_account = transaction.to_account;
                        transaction_found = true;
                        break;
                    }
                }

                if (!transaction_found) {
                    break;
                }

                if (i == k - 1) {
                    cycle_found = true;
                }
            }

            std::cout << (cycle_found ? "1" : "0") << std::endl;
        }
    }

    return 0;
}
