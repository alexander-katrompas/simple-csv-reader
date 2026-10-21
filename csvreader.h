/**
 * Name: Alexander Katrompas
 * Assignment: Demonstration Code
 * Purpose: Declares a simple, generic delimited-line parser.
 */

#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>

constexpr char DEFAULT_DELIMITER = ',';

bool parseDelimitedLine(
    const std::string&,
    std::string[],
    int,
    char = DEFAULT_DELIMITER
);

#endif // CSVREADER_H
