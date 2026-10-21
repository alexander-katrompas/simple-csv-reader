# Simple CSV Reader in C++

A small, self-contained academic example showing how to:

1. open a text file;
2. read it one line at a time;
3. split each line into fields;
4. convert text fields into typed data;
5. reject malformed records;
6. keep file parsing separate from application storage.

The repository is intentionally simple enough to study and adapt.

## Important limitation

This is a **constrained educational CSV reader**, not a complete implementation of the CSV standard.

It supports:

- one record per line;
- one configurable delimiter;
- a known field count;
- empty fields;
- Windows or Unix line endings.

It does **not** support:

- quoted fields;
- commas inside quoted values;
- escaped quotes;
- multiline records.

Use a production CSV library when those features are required.

## Project structure

```text
.
├── csvreader.h          Generic parser interface
├── csvreader.cpp        Generic parser implementation
├── product.h            Example typed record
├── product.cpp          Example field conversion
├── main.h               Driver dependencies and constants
├── main.cpp             File-reading demonstration
├── test.h               Test declarations and constants
├── test.cpp             Parser and conversion tests
├── test_main.cpp        Test driver
├── data/
│   ├── products.csv
│   └── products_with_errors.csv
├── Makefile
└── README.md
```

## Code flow

```text
CSV file
   |
   v
std::getline()
   |
   v
parseDelimitedLine()
   |
   v
array of string fields
   |
   v
buildProduct()
   |
   v
typed Product record
   |
   v
application decides what to do with the record
```

The generic parser does not know about `Product` and does not store records in a collection. That separation makes it easy to adapt the reader to another domain.

## Input format

The demonstration file contains:

```text
id,name,category,quantity
101,Notebook,Office,25
102,USB Cable,Electronics,12
```

The first row is treated as a header and skipped.

Each subsequent row must contain exactly four fields.

## Build and run

```bash
make
./csv_demo
```

Use another input file:

```bash
./csv_demo data/products_with_errors.csv
```

## Run tests

```bash
make test
```

Run the tests with AddressSanitizer:

```bash
make sanitize
```

Remove compiled programs:

```bash
make clean
```

## Compile without Make

Demonstration:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -g \
    main.cpp csvreader.cpp product.cpp -o csv_demo
```

Tests:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -g \
    test_main.cpp test.cpp csvreader.cpp product.cpp -o csv_tests
```

## Adapting the example

To adapt the repository to another record type:

1. define your record structure;
2. define the expected field count;
3. write a conversion function similar to `buildProduct()`;
4. leave `parseDelimitedLine()` unchanged;
5. decide what your application should do with each valid record.

For example, a support-ticket program could parse one ticket and then insert it into an application-specific data structure. The CSV reader should not decide which structure stores the record.

## Error handling

The demonstration uses several mechanisms deliberately:

- file-open failure causes the driver to report an error and return failure;
- malformed rows are reported and skipped;
- `parseDelimitedLine()` returns `false` for an incorrect field count;
- `buildProduct()` returns `false` for invalid typed data;
- integer conversion uses narrow `try` blocks around `std::stoi()`.

The output object is updated only after a complete record validates.

## Example output

```text
ID: 101 | Name: Notebook | Category: Office | Quantity: 25
ID: 102 | Name: USB Cable | Category: Electronics | Quantity: 12
ID: 103 | Name: Coffee Mug | Category: Kitchen | Quantity: 8
ID: 104 | Name: Ethernet Cable | Category: Electronics | Quantity: 30
```

## Educational objective

The point of this repository is not to build a production-grade CSV library. It is to demonstrate the boundary between:

- reading raw file data;
- parsing fields;
- validating and converting types;
- storing or processing application records.

That boundary keeps file-ingestion code independent from the rest of a program's architecture.
