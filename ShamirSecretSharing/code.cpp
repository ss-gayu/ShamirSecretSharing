#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include "json.hpp" // github file

using json = nlohmann::json;
using namespace std;


long long baseToDecimal(const string& value, int base) {
    long long result = 0;
    for (char c : value) {
        int digit = (isdigit(c)) ? c - '0' : tolower(c) - 'a' + 10;
        result = result * base + digit;
    }
    return result;
}


long long lagrangeInterpolation(const vector<pair<int, long long>>& points) {
    long long secret = 0;
    int k = points.size();

    for (int i = 0; i < k; ++i) {
        long long xi = points[i].first;
        long long yi = points[i].second;
        long long numerator = 1;
        long long denominator = 1;

        for (int j = 0; j < k; ++j) {
            if (i != j) {
                numerator *= -points[j].first;
                denominator *= (xi - points[j].first);
            }
        }

        secret += yi * (numerator / denominator);
    }

    return secret;
}


vector<pair<int, long long>> parseJSON(const string& filename, int& k_out) {
    ifstream file(filename);
    json j;
    file >> j;

    int k = j["keys"]["k"];
    k_out = k;

    vector<pair<int, long long>> points;

    for (auto& [key, value] : j.items()) {
        if (key == "keys") continue;

        int x = stoi(key);
        int base = stoi(value["base"].get<string>());
        string encoded = value["value"].get<string>();
        long long y = baseToDecimal(encoded, base);

        points.push_back({x, y});
    }

    
    sort(points.begin(), points.end());
    points.resize(k);
    return points;
}

int main() {
    int k1, k2;
    auto points1 = parseJSON("testcase1.json", k1);
    auto points2 = parseJSON("testcase2.json", k2);

    long long secret1 = lagrangeInterpolation(points1);
    long long secret2 = lagrangeInterpolation(points2);

    cout << "Secret from Test Case 1: " << secret1 << endl;
    cout << "Secret from Test Case 2: " << secret2 << endl;

    return 0;
}
