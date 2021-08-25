#include "task.h"

void Task::start_solution(){
    
    Requests::send_http_request("google.com");

    std::string date = Parser::find_date();
    TimeChanger::correct_system_time(date);

    Requests::send_https_request("https://example.com");

}