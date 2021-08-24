#include <string>
#include <regex>


class Parser
{
public:

    struct  Date
    {
        int day, hour, minite, sec, year, m;
    };

    static Date parse();

private:

};