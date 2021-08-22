#include <string>
#include <iostream>
#include <ctime>
#include <fstream>


class LogUtility
{
public:

    static void Info(std::string& message);
    static void Warning(std::string& message);
    static void Error(std::string& message);

private:
    
    static std::string get_current_time();

};