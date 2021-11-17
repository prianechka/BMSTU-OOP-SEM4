#include "BaseException.h"

BaseException::BaseException(std::string filename, std::string classname, int number_of_line,
                             const char *time, std::string information = "Error")
{
   information = "\nFile: " + filename + "\nClass: " + classname + "\nAt line: " +
           std::to_string(number_of_line) + "\nIn time: " + time +
           "About error: " + information;
}

const char *BaseException::what() const noexcept
{
    const char *result = information.c_str();
    return result;
}
