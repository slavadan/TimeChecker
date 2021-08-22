#include <curl/curl.h>
#include <string>


class Requests
{
public:

    static void send_http_request(const std::string& url);
    static void send_https_request(const std::string& url);

};
