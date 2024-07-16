#include "TrafficDatabase.h"

void TrafficDatabase::addViolation(const string& carNumber, const Violation& violation)
{
    database[carNumber].push_back(violation);
}

void TrafficDatabase::printDatabase() const
{
    for (const auto& entry : database) {
        cout << "Car Number: " << entry.first << endl;
        for (const auto& violation : entry.second) {
            cout << "  Date: " << violation.date
                << ", Description: " << violation.description
                << ", Fine: " << violation.fineAmount << endl;
        }
    }
}

void TrafficDatabase::printViolations(const string& carNumber) const
{
    if (database.find(carNumber) != database.end()) {
        cout << "Car Number: " << carNumber << endl;
        for (const auto& violation : database.at(carNumber)) {
            cout << "  Date: " << violation.date
                << ", Description: " << violation.description
                << ", Fine: " << violation.fineAmount << endl;
        }
    }
    else {
        cout << "No violations found for car number: " << carNumber << endl;
    }
}

double TrafficDatabase::totalFines(const string& carNumber) const
{
    double total = 0.0;
    if (database.find(carNumber) != database.end()) {
        for (const auto& violation : database.at(carNumber)) {
            total += violation.fineAmount;
        }
    }
    return total;
}

void TrafficDatabase::payFine(const string& carNumber, const string& date)
{
    if (database.find(carNumber) != database.end()) {
        auto& violations = database[carNumber];
        for (auto it = violations.begin(); it != violations.end(); ++it) {
            if (it->date == date) {
                violations.erase(it);
                cout << "Fine paid for car number: " << carNumber << " on date: " << date << endl;
                return;
            }
        }
    }
    cout << "No fine found for car number: " << carNumber << " on date: " << date << endl;
}

void TrafficDatabase::findViolationsByPeriod(const string& startDate, const string& endDate) const
{
    for (const auto& entry : database) {
        for (const auto& violation : entry.second) {
            if (violation.date >= startDate && violation.date <= endDate) {
                cout << "Car Number: " << entry.first << endl;
                cout << "  Date: " << violation.date
                    << ", Description: " << violation.description
                    << ", Fine: " << violation.fineAmount << endl;
            }
        }
    }
}
