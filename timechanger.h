#include <stdlib.h> 
#include "parser.h"


class TimeChanger
{
public:

    static void correct_system_time(Parser::Date& date);

private:

    static std::string& format_string(std::string& command);
    
};