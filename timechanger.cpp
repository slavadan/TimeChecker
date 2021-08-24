#include "timechanger.h"


void TimeChanger::correct_system_time(Parser::Date& date){
    
    std::system("sudo timedatectl set-timezone 'GMT-0'");
    std::system("sudo timedatectl set-ntp no");
    std::system("sudo timedatectl set-time '2017-09-06 20:43:36'");
    std::system("sudo timedatectl set-timezone 'Europe/Moscow'");

}

