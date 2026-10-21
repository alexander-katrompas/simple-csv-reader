/**
 * Name: Alexander Katrompas
 * Assignment: Demonstration Code
 * Purpose: Defines the example record used by the CSV reader demonstration.
 */

#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <stdexcept>
#include <string>

constexpr int PRODUCT_ID_FIELD = 0;
constexpr int PRODUCT_NAME_FIELD = 1;
constexpr int PRODUCT_CATEGORY_FIELD = 2;
constexpr int PRODUCT_QUANTITY_FIELD = 3;
constexpr int PRODUCT_FIELD_COUNT = 4;

struct Product {
    int id;
    std::string name;
    std::string category;
    int quantity;
};

bool buildProduct(const std::string[], Product&);
void displayProduct(const Product&);

#endif // PRODUCT_H
