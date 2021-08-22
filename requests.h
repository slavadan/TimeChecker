

class HttpRequest
{
public:

    virtual void send_http_request() = 0;
    virtual void send_https_request() = 0;

};