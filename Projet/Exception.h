#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <string>

class Exception : public std::exception
{
protected :
    std::string info;

public:
    Exception(const std::string& i = "") throw() : info(i) {}
    ~Exception() throw() {}
    const char* what() const throw() { return info.c_str(); }
};

#endif // EXCEPTION_H
