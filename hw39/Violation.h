#pragma once
#include <string>

using namespace std;

struct Violation {
    string date; 
    string description;
    double fineAmount;

    Violation(string d, string desc, double amount) : date(d), description(desc), fineAmount(amount) {};
};

