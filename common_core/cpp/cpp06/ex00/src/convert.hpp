#pragma once

# include <string>
# include <iostream>

typedef void (*ptr)(std::string);

void toInt(std::string);
void toChar(std::string);
void toFloat(std::string);
void toDouble(std::string);
