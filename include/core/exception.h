/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_CORE_EXCEPTION_H_
#define MG_CORE_EXCEPTION_H_

#include <string>

namespace mg
{
namespace core
{
class Exception
{
public:
    Exception(){}

    explicit Exception(std::wstring str)
        :exception_string_(str)
    {}
    
    virtual ~Exception(){}

    std::wstring getExceptionString() const { return exception_string_; }

private:
    std::wstring exception_string_;
};
}    // end of core namespace
}    // end of mg namespace
#endif