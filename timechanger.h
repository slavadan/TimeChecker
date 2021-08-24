#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>


class TimeChanger
{
public:

    static void correct_system_time(std::string& date);

private:

    static char* create_command(std::string& date);
    
};