#include <stdio.h>
#include <curl/curl.h>
 
int main(void)
{
  CURL *curl = curl_easy_init();
   if(curl) {
      curl_easy_setopt(curl, CURLOPT_URL, "http://google.com");
 
      curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
 
      curl_easy_perform(curl);
    }
  return 0;
}