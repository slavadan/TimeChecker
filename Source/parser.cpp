#include "../Headers/parser.h"

std::string Parser::find_date(){

    std::ifstream file("response.txt");

    std::string file_content;
    std::string file_string;

    std::cmatch result;
    std::regex regular("(\\d{1,2})\\s(\\D{1,3})\\s(\\d{4})\\s(\\d\\d:\\d\\d:\\d\\d)");
    std::string str_res;

    while (std::getline(file, file_string))
        file_content += file_string + "\n";

    if (std::regex_search(file_content.c_str(), result, regular)){

        LogUtility::Info("Date was found");
        str_res = result.str();

        Parser::format_date(str_res);

    }  
    else {
        LogUtility::Info("Вate not found");
    }
        

    file.close();

    return str_res;
}

void Parser::format_date(std::string& date){

    std::cmatch result;
    std::string str_result;
    std::regex regular("([a-zA-z]{1,3})");

    if (std::regex_search(date.c_str(), result, regular)){

        LogUtility::Info("Month was found");

        str_result = result.str() + " ";

        int pos = date.find(str_result[0]);

        date.erase(pos, 4);

        date.insert(0, str_result);
    }
    else {
        LogUtility::Info("Month not found");
    }
        

    

}
