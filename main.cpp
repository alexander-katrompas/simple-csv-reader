/**
 * Name: Alexander Katrompas
 * Assignment: Demonstration Code
 * Purpose: Demonstrates reading, parsing, converting, and displaying CSV data.
 */

#include "main.h"

int main(int argc, char* argv[]) {

    int status = 0;
    int lineNumber = 0;
    bool recordValid = false;
    std::string filename = DEFAULT_INPUT_FILE;
    std::string line;
    std::string fields[PRODUCT_FIELD_COUNT];
    Product product = {0, "", "", 0};

    if (argc > 1) {
        filename = argv[1];
    }

    std::ifstream input(filename);

    if (!input.is_open()) {

        std::cerr << "Unable to open input file: "
                  << filename << std::endl;

        status = 1;

    } else {

        if (std::getline(input, line)) {
            lineNumber++;
        }

        while (std::getline(input, line)) {

            lineNumber++;

            recordValid = parseDelimitedLine(
                line,
                fields,
                PRODUCT_FIELD_COUNT
            );

            if (recordValid) {
                recordValid = buildProduct(fields, product);
            }

            if (recordValid) {
                displayProduct(product);
            } else {
                std::cerr << "Skipping invalid record on line "
                          << lineNumber << "." << std::endl;
            }
        }

        input.close();
    }

    return status;
}
