#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "BaseException.h"

class NoObjectException: public BaseException
{
    public:
        NoObjectException(std::string filename, std::string classname,
                          int number_of_line, const char *time,
                          std::string information = "No object"):
        BaseException(filename, classname, number_of_line, time, information) {};

};

class EmptyVectorException: public BaseException
{
    public:
        EmptyVectorException(std::string filename, std::string classname,
                             int number_of_line, const char *time,
                             std::string information = "Is empty vector"):
        BaseException(filename, classname, number_of_line, time, information) {};
};

class MemoryException: public BaseException
{
    public:
        MemoryException(std::string filename, std::string classname,
                        int number_of_line, const char *time,
                        std::string information = "Memory Error"):
        BaseException(filename, classname, number_of_line, time, information) {};
};

class OutOfRangeException: public BaseException
{
    public:
        OutOfRangeException(std::string filename, std::string classname,
                            int number_of_line, const char *time,
                            std::string information = "Index is out of range"):
        BaseException(filename, classname, number_of_line, time, information) {};
};

class ZeroDivisionException: public BaseException
{
    public:
        ZeroDivisionException(std::string filename, std::string classname,
                              int number_of_line, const char *time,
                              std::string information = "Division by zero"):
        BaseException(filename, classname, number_of_line, time, information) {};
};

class InvalidCopyArrayPointer: public BaseException
{
    public:
        InvalidCopyArrayPointer(std::string filename, std::string classname,
                                int number_of_line, const char *time,
                                std::string information = "Is empty vector"):
        BaseException(filename, classname, number_of_line, time, information) {};
};

class ExpiredIterator: public BaseException
{
    public:
        ExpiredIterator(std::string filename, std::string classname,
                        int number_of_line, const char *time,
                        std::string information = "Expired iterator"):
        BaseException(filename, classname, number_of_line, time, information) {};
};

class InvalidIterator: public BaseException
{
    public:
        InvalidIterator(std::string filename, std::string classname,
                        int number_of_line, const char *time,
                        std::string information = "Expired iterator"):
        BaseException(filename, classname, number_of_line, time, information) {};
};

class InvalidVectorsSizes: public BaseException
{
    public:
        InvalidVectorsSizes(std::string filename, std::string classname,
                            int number_of_line, const char *time,
                            std::string information = "Invalid sizes of vectors"):
        BaseException(filename, classname, number_of_line, time, information) {};
};

class InvalidType: public BaseException
{
    public:
        InvalidType(std::string filename, std::string classname,
                            int number_of_line, const char *time,
                            std::string information = "Invalid type of vector"):
        BaseException(filename, classname, number_of_line, time, information) {};
};

#endif // EXCEPTIONS_H
