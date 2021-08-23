#include "get.h"

void Requests::send_https_request(const char* url){

        CURL *curl = curl_easy_init();

        if(curl) {

            curl_easy_setopt(curl, CURLOPT_URL, url);
 
            curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
 
            curl_easy_perform(curl);

            curl_easy_cleanup(curl);

        }
}

void Requests::send_http_request(const char* hostname){
    
    char buffer[BUFSIZ];

    enum CONSTEXPR { MAX_REQUEST_LEN = 1024};

    char request[MAX_REQUEST_LEN];
    char request_template[] = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";

    struct protoent *protoent;

    in_addr_t in_addr;

    int request_len;
    int socket_file_descriptor;

    ssize_t nbytes_total, nbytes_last;

    struct hostent *hostent;
    struct sockaddr_in sockaddr_in;

    unsigned short server_port = 80;

    std::ofstream file("response.txt", std::ios_base::out | std::ios_base::trunc);

    request_len = snprintf(request, MAX_REQUEST_LEN, request_template, hostname);

    if (request_len >= MAX_REQUEST_LEN) {

        fprintf(stderr, "request length large: %d\n", request_len);

        exit(EXIT_FAILURE);

    }


    protoent = getprotobyname("tcp");

    if (protoent == NULL) {

        perror("getprotobyname");

        exit(EXIT_FAILURE);

    }

    socket_file_descriptor = socket(AF_INET, SOCK_STREAM, protoent->p_proto);

    if (socket_file_descriptor == -1) {

        perror("socket");

        exit(EXIT_FAILURE);

    }

    hostent = gethostbyname(hostname);

    if (hostent == NULL) {

        fprintf(stderr, "error: gethostbyname(\"%s\")\n", hostname);

        exit(EXIT_FAILURE);

    }

    in_addr = inet_addr(inet_ntoa(*(struct in_addr*)*(hostent->h_addr_list)));

    if (in_addr == (in_addr_t)-1) {

        fprintf(stderr, "error: inet_addr(\"%s\")\n", *(hostent->h_addr_list));

        exit(EXIT_FAILURE);
        
    }

    sockaddr_in.sin_addr.s_addr = in_addr;
    sockaddr_in.sin_family = AF_INET;
    sockaddr_in.sin_port = htons(server_port);


    if (connect(socket_file_descriptor, (struct sockaddr*)&sockaddr_in, sizeof(sockaddr_in)) == -1) {

        perror("connect");
        exit(EXIT_FAILURE);

    }


    nbytes_total = 0;

    while (nbytes_total < request_len) {

        nbytes_last = write(socket_file_descriptor, request + nbytes_total, request_len - nbytes_total);

        if (nbytes_last == -1) {

            perror("write");
            exit(EXIT_FAILURE);

        }

        nbytes_total += nbytes_last;

    }


    fprintf(stderr, "debug: before first read\n");
    
    while ((nbytes_total = read(socket_file_descriptor, buffer, BUFSIZ)) > 0) {

        std::cout << buffer << std::endl;
        file << buffer;
        break;
        
    }

    
    if (nbytes_total == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    close(socket_file_descriptor);
    file.close();
    exit(EXIT_SUCCESS);

}




