/**
 * Name: Alexander Katrompas
 * Assignment: Demonstration Code
 * Purpose: Implements tests for the CSV reader demonstration.
 */

#include "test.h"

/**
 * @brief Records one test result.
 * @param condition Condition being tested.
 * @param result Caller-owned test result aggregate.
 * @exception none
 * @return none
 */
void recordTest(bool condition, TestResult& result) {

    result.total++;

    if (condition) {
        result.passed++;
    }
}

/**
 * @brief Tests valid, empty, malformed, and alternate-delimiter parsing.
 * @param result Caller-owned test result aggregate.
 * @exception none
 * @return none
 */
void testDelimitedParsing(TestResult& result) {

    result.passed = 0;
    result.total = 0;

    std::string fields[PRODUCT_FIELD_COUNT];

    recordTest(
        parseDelimitedLine(
            "101,Notebook,Office,25",
            fields,
            PRODUCT_FIELD_COUNT
        ),
        result
    );

    recordTest(fields[PRODUCT_ID_FIELD] == "101", result);
    recordTest(fields[PRODUCT_NAME_FIELD] == "Notebook", result);
    recordTest(fields[PRODUCT_CATEGORY_FIELD] == "Office", result);
    recordTest(fields[PRODUCT_QUANTITY_FIELD] == "25", result);

    recordTest(
        parseDelimitedLine(
            "101||Office|25",
            fields,
            PRODUCT_FIELD_COUNT,
            '|'
        ),
        result
    );

    recordTest(fields[PRODUCT_NAME_FIELD].empty(), result);

    recordTest(
        !parseDelimitedLine(
            "101,Notebook,Office",
            fields,
            PRODUCT_FIELD_COUNT
        ),
        result
    );

    recordTest(
        !parseDelimitedLine(
            "101,Notebook,Office,25,Extra",
            fields,
            PRODUCT_FIELD_COUNT
        ),
        result
    );

    recordTest(
        parseDelimitedLine(
            "101,Notebook,Office,",
            fields,
            PRODUCT_FIELD_COUNT
        ),
        result
    );

    recordTest(fields[PRODUCT_QUANTITY_FIELD].empty(), result);

    recordTest(
        parseDelimitedLine(
            "101,Notebook,Office,25\r",
            fields,
            PRODUCT_FIELD_COUNT
        ),
        result
    );

    recordTest(fields[PRODUCT_QUANTITY_FIELD] == "25", result);
}

/**
 * @brief Tests successful and failed typed-record conversion.
 * @param result Caller-owned test result aggregate.
 * @exception none
 * @return none
 */
void testProductConversion(TestResult& result) {
    result.passed = 0;
    result.total = 0;

    std::string validFields[PRODUCT_FIELD_COUNT] = {
        "101", "Notebook", "Office", "25"
    };

    std::string invalidInteger[PRODUCT_FIELD_COUNT] = {
        "ABC", "Notebook", "Office", "25"
    };

    std::string invalidQuantity[PRODUCT_FIELD_COUNT] = {
        "101", "Notebook", "Office", "-2"
    };

    Product product = {-1, "unchanged", "unchanged", -1};

    recordTest(buildProduct(validFields, product), result);
    recordTest(
        product.id == TEST_PRODUCT_ID &&
        product.quantity == TEST_PRODUCT_QUANTITY,
        result
    );

    recordTest(!buildProduct(invalidInteger, product), result);
    recordTest(!buildProduct(invalidQuantity, product), result);

    recordTest(
        product.id == TEST_PRODUCT_ID &&
        product.quantity == TEST_PRODUCT_QUANTITY,
        result
    );
}
