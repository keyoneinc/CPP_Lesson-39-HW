#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "Violation.h"

using namespace std;

class TrafficDatabase {
private:
    map<string, vector<Violation>> database;

public:
    void addViolation(const string& carNumber, const Violation& violation);
    void printDatabase() const;
    void printViolations(const string& carNumber) const;
    double totalFines(const string& carNumber) const;
    void payFine(const string& carNumber, const string& date);
    void findViolationsByPeriod(const string& startDate, const string& endDate) const;

};
