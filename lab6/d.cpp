#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Date {
    int day, month, year;
    string original;
    
    Date(string date_str) {
        original = date_str;
        day = stoi(date_str.substr(0, 2));
        month = stoi(date_str.substr(3, 2));
        year = stoi(date_str.substr(6, 4));
    }

    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<Date> dates;
    
    for (int i = 0; i < n; ++i) {
        string date_str;
        cin >> date_str;
        dates.push_back(Date(date_str));
    }
    
    sort(dates.begin(), dates.end());
    
    for (const Date& date : dates) {
        cout << date.original << endl;
    }
    
    return 0;
}