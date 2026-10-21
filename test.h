/**
 * Name: Alexander Katrompas
 * Assignment: Demonstration Code
 * Purpose: Declares tests for the CSV reader demonstration.
 */

#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>
#include "csvreader.h"
#include "product.h"

constexpr int TEST_EXPECTED_TOTAL = 18;
constexpr int TEST_PRODUCT_ID = 101;
constexpr int TEST_PRODUCT_QUANTITY = 25;

struct TestResult {
    int passed;
    int total;
};

void recordTest(bool, TestResult&);
void testDelimitedParsing(TestResult&);
void testProductConversion(TestResult&);

#endif // TEST_H
