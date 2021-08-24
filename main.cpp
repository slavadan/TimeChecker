#include <stdio.h>
#include "Requests/get.h"
#include "timechanger.h"
 

int main(void)
{
    std::system("sudo timedatectl set-timezone 'GMT-0'");
    std::system("sudo timedatectl set-time '2017-09-06 20:43:36'");
    std::system("sudo timedatectl set-timezone 'Europe/Moscow'");
    return 0;
}