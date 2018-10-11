#pragma once
#include <string>

class Exception{
private:
	std::string mes;
public:
	explicit Exception(const std::string &mes = "");
	const std::string& what() const;
};