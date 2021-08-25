#include <string>
#include <iostream>
#include <ctime>
#include <thread>
#include <fstream>


class LogUtility
{
public:

    static void Info(const std::string& message);
    static void Error(const std::string& message);

private:
    
    static std::string get_current_time();
    static void save_to_file(std::string formated_message);
    static void Log(const std::string& preamble, const std::string& message);

};