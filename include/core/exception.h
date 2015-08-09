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

namespace mg
{
namespace core
{
class Exception
{
public:
    Exception(){}

    explicit Exception(const char* str)
        :exception_string_(str)
    {}
    
    ~Exception(){}

    const char* getExceptionString()const { return exception_string_; }

private:
    const char* exception_string_;
};
}    // end of core namespace
}    // end of mg namespace
#endif