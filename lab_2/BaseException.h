#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <exception>
#include <iostream>

class BaseException: public std::exception
{
    public:
        BaseException(std::string fileName, std::string className,
                  int currentLine, const char *errorTime,
                  std::string information);
        virtual const char *what() const noexcept override;

        virtual ~BaseException() { }

protected:
    std::string information;
};

#include "BaseException.hpp"
#endif // BASEEXCEPTION_H
