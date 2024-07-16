#include <iostream>
#include "TrafficDatabase.h"

int main() {
    TrafficDatabase db;

    db.addViolation("QWE123", Violation("01.01.2024", "Speeding", 100.0));
    db.addViolation("QWE124", Violation("12.07.2024", "Illegal parking", 50.0));
    db.addViolation("QWE123", Violation("01.01.2024", "Running a red light", 200.0));

    db.printDatabase();

    db.printViolations("QWE123");
    cout << "Total fines for QWE123: " << db.totalFines("QWE123") << endl;
    db.payFine("QWE124", "12.07.2024");
    db.printViolations("ABC123");

    db.findViolationsByPeriod("01.01.2024", "01.03.2024");

    return 0;
}
