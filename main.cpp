#include <stdio.h>
#include "logutility.h"
#include "timechanger.h"
 
int main(void)
{
    TimeChanger::correct_system_time();
    return 0;
}