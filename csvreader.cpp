/**
 * Name: Alexander Katrompas
 * Assignment: Demonstration Code
 * Purpose: Implements a simple, generic delimited-line parser.
 */

#include "csvreader.h"

/**
 * @brief Splits one line into an expected number of fields.
 * @param line The delimited input line.
 * @param fields Caller-owned array that receives the parsed fields.
 * @param expectedFieldCount Required number of fields.
 * @param delimiter Character separating fields.
 * @exception none
 * @return true when the line contains exactly the expected number of fields.
 * @note This is a constrained educational parser. It does not process quoted
 *       fields, escaped delimiters, or multiline records.
 *       fields must reference an array containing at least
 *       expectedFieldCount std::string elements.
 */
bool parseDelimitedLine(
    const std::string& line,
    std::string fields[],
    int expectedFieldCount,
    char delimiter
) {

    bool valid = fields && expectedFieldCount > 0;
    int fieldIndex = 0;
    std::string currentField;
    std::string workingLine = line;

    if (valid) {

        if (!workingLine.empty() && workingLine.back() == '\r') {
            workingLine.pop_back();
        }

        for (int i = 0; i < expectedFieldCount; i++) {
            fields[i].clear();
        }

        for (std::size_t i = 0; valid && i < workingLine.length(); i++) {

            if (workingLine[i] == delimiter) {

                if (fieldIndex < expectedFieldCount - 1) {
                    fields[fieldIndex] = currentField;
                    currentField.clear();
                    fieldIndex++;
                } else {
                    valid = false;
                }

            } else {

                currentField += workingLine[i];
            }
        }

        if (valid && fieldIndex < expectedFieldCount) {
            fields[fieldIndex] = currentField;
            fieldIndex++;
        }

        valid = valid && fieldIndex == expectedFieldCount;
    }

    return valid;
}
