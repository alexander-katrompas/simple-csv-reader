/**
 * Name: Alexander Katrompas
 * Assignment: Demonstration Code
 * Purpose: Converts parsed text fields into an example Product record.
 */

#include "product.h"

/**
 * @brief Converts one complete string to an integer.
 * @param text Text to convert.
 * @param value Caller-owned integer that receives the result on success.
 * @exception none
 * @return true when the entire string contains a valid integer.
 * @note The try block is intentionally narrow and contains only the conversion
 *       operation that may throw.
 */
static bool parseInteger(const std::string& text, int& value) {

    bool parsed = false;
    std::size_t charactersUsed = 0;
    int convertedValue = 0;

    try {
        convertedValue = std::stoi(text, &charactersUsed);
    }
    catch (const std::invalid_argument&) {
        charactersUsed = 0;
    }
    catch (const std::out_of_range&) {
        charactersUsed = 0;
    }

    if (!text.empty() && charactersUsed == text.length()) {
        value = convertedValue;
        parsed = true;
    }

    return parsed;
}

/**
 * @brief Builds a typed Product from four parsed text fields.
 * @param fields Parsed field array in id, name, category, quantity order.
 * @param product Caller-owned Product that receives the converted record.
 * @exception none
 * @return true when every field is valid and the Product is created.
 * @note The caller's Product is changed only after all fields validate.
 */
bool buildProduct(const std::string fields[], Product& product) {

    bool built = fields;
    int id = 0;
    int quantity = 0;
    Product candidate = {0, "", "", 0};

    if (built) {
        built = parseInteger(fields[PRODUCT_ID_FIELD], id);
    }

    if (built) {
        built = !fields[PRODUCT_NAME_FIELD].empty();
    }

    if (built) {
        built = !fields[PRODUCT_CATEGORY_FIELD].empty();
    }

    if (built) {
        built = parseInteger(fields[PRODUCT_QUANTITY_FIELD], quantity);
    }

    if (built) {
        built = id > 0 && quantity >= 0;
    }

    if (built) {
        candidate.id = id;
        candidate.name = fields[PRODUCT_NAME_FIELD];
        candidate.category = fields[PRODUCT_CATEGORY_FIELD];
        candidate.quantity = quantity;
        product = candidate;
    }

    return built;
}

/**
 * @brief Displays one Product record.
 * @param product Product to display.
 * @exception none
 * @return none
 */
void displayProduct(const Product& product) {

    std::cout << "ID: " << product.id
              << " | Name: " << product.name
              << " | Category: " << product.category
              << " | Quantity: " << product.quantity
              << std::endl;
}
