#include <stdio.h>
#include "Requests/get.h"
 

int main(void)
{
    Requests::send_http_request("google.com");
    return 0;
}