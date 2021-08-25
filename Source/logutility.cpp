#include "../Headers/logutility.h"


void LogUtility::Info(const std::string& message)
{
    Log("Info", message);
}

void LogUtility::Error(const std::string& message)
{
    Log("Error", message);
}

void LogUtility::Log(const std::string& preamble, const std::string& message)
{
    std::string formated_message = "[" + preamble + ": " + LogUtility::get_current_time() + "] " + message + "\n";

    std::thread second_thread(save_to_file, formated_message);
    second_thread.join();
}

std::string LogUtility::get_current_time(){

    time_t current = time(0);

    char* dt = ctime(&current);

    std::string str_dt(dt);
    str_dt.pop_back();

    return str_dt;
}

void LogUtility::save_to_file(std::string formated_message){


    std::ofstream file("logs.log", std::ios_base::app);

    file << formated_message;

    file.close();
}