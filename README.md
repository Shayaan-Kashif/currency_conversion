# Currency Conversion Library

A simple C++ library to convert numerical currency values into their word representations. This library handles both dollars and cents, providing a way to display monetary values in a human-readable format.

## Features

- Convert dollar and cent amounts to words
- Handles single digits, tens, hundreds, and thousands
- Supports proper pluralization for dollars and cents

## Usage

### Example

Here's a simple example demonstrating how to use the library:

```cpp
#include <iostream>
#include "currency_conversion.h"

int main() {
    double money = 1234.56;
    std::cout << currency_conversion(money) << std::endl;
    return 0;
}
