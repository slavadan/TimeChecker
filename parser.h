#include <string>


class Parser
{
private:

    struct  date
    {
        int day, hour, minite, sec, year;
    };

public:

    static date parse();

};