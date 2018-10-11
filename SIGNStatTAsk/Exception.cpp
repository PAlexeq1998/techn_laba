#include "Exception.hpp"

Exception::Exception(const std::string &mes):mes(mes){}
const std::string& Exception::what() const { return mes; }