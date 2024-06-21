#ifndef CURRENCY_CONVERSION_H
#define CURRENCY_CONVERSION_H

#include <string>

namespace CurrencyConversion {

    std::string currency_conversion(double money);
    std::string One_Word(std::string word);
    std::string Two_Word(std::string word, int word_length, bool forCents);
    std::string Three_Word(std::string dollar_word, int dollar_length);
    std::string Cents_To_Words(std::string cents_word, int cents_length);
    std::string Dollars_To_Words(std::string dollar_word, int dollar_length);

}

#endif // CURRENCY_CONVERSION_H
