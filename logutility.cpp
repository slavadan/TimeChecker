#include "logutility.h"


void LogUtility::Info(std::string& message){

    std::ofstream file("logs.log", std::ios_base::app);
    
    file << "[Info]" << message << "[" << LogUtility::get_current_time() << "]" << "\n";

    file.close();
}

void LogUtility::Warning(std::string& message){

}

void LogUtility::Error(std::string& message){

}

std::string LogUtility::get_current_time(){

    time_t current = time(0);

    char* dt = ctime(&current);

    std::string str_dt(dt);
    str_dt.pop_back();

    return str_dt;
}