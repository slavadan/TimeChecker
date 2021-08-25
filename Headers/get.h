#include <curl/curl.h>
#include <string>
#define _XOPEN_SOURCE 700
#include <arpa/inet.h>
#include <assert.h>
#include <netdb.h>
#include "logutility.h"
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fstream>


class Requests
{
public:

    static void send_http_request(const char* hostname);
    static void send_https_request(const char* url);

};
