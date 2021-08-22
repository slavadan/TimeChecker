#include "timechanger.h"


void TimeChanger::correct_system_time(){
    
    std::system("sudo date --set 'Mon Aug 22 12:58:47 2021'");

}