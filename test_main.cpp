/**
 * Name: Alexander Katrompas
 * Assignment: Demonstration Code
 * Purpose: Runs and reports the CSV reader demonstration tests.
 */

#include "test.h"

int main() {

    int status = 0;
    TestResult parsing = {0, 0};
    TestResult conversion = {0, 0};
    TestResult overall = {0, 0};

    testDelimitedParsing(parsing);
    testProductConversion(conversion);

    overall.passed = parsing.passed + conversion.passed;
    overall.total = parsing.total + conversion.total;

    std::cout << "Delimited parsing: "
              << parsing.passed << "/" << parsing.total
              << " passed" << std::endl;

    std::cout << "Product conversion: "
              << conversion.passed << "/" << conversion.total
              << " passed" << std::endl;

    std::cout << "Overall: "
              << overall.passed << "/" << overall.total
              << " passed" << std::endl;

    if (overall.total != TEST_EXPECTED_TOTAL ||
        overall.passed != overall.total) {

        status = 1;
    }

    return status;
}
