#include <string>
#include <fstream>
#include <regex>
#include <vector>
#include "get.h"
#include <iostream>

class Parser
{
public:

    static std::string find_date();

private:

    static void format_date(std::string& date);

};