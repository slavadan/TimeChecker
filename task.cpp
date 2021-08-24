#include "task.h"

void Task::start_solution(){
    std::cout << "2 step" << std::endl;
    Requests::send_http_request("google.com");
    std::cout << "3 step" << std::endl;
    std::string date = Parser::find_date();
    std::cout << date << std::endl;
    TimeChanger::correct_system_time(date);

    Requests::send_https_request("https://example.com");

}