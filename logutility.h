#include <string>
#include <iostream>
#include <ctime>
#include <thread>
#include <fstream>


class LogUtility
{
public:

    static void Info(std::string message);
    static void Error(std::string message);

private:
    
    static std::string get_current_time();
    static void save_to_file(std::string formated_message);

};