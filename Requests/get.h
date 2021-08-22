#include "../requests.h"


class Get: HttpRequest
{
public:

    void send_http_request();
    void send_https_request();

};