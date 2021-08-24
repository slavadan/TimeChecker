#include "timechanger.h"


void TimeChanger::correct_system_time(std::string& date){
    
    std::system("sudo timedatectl set-timezone 'GMT-0'");
    std::system("sudo timedatectl set-ntp no");

    std::string result = "sudo date --set '" + date + "'";

    char char_command[result.length() + 1];
    strcpy(char_command, result.c_str());

    std::system(char_command);
    std::system("sudo timedatectl set-timezone 'Europe/Moscow'");

}