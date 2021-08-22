#include "get.h"

void Requests::send_https_request(const std::string& url){

        CURL *curl = curl_easy_init();

        if(curl) {

            curl_easy_setopt(curl, CURLOPT_URL, url);
 
            curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
 
            curl_easy_perform(curl);

            curl_easy_cleanup(curl);

        }
}

void Requests::send_http_request(const std::string& url){

}



