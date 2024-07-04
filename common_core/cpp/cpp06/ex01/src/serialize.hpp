#pragma once

# include <iostream>

typedef struct Data {int val;}Data;

uintptr_t serialize(Data * ptr);
Data * deserialize(uintptr_t raw);
