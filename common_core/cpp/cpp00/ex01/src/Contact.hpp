#pragma once

#include <iostream>
#include <cstdlib>
#include <string>

class Contact {

    private :

    std::string info[5];

    public :

    Contact(void);

    void        set(void);
    void        display(void);
    std::string get(int element);
    
};