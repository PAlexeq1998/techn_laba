#pragma once
#include "Exception.hpp"
#include <iostream>

class SIGN{
private:
	std::string name;//имя
	std::string surname;//фамилия
	std::string sign;//нак зодиака
	int date[3];//дата рождения
public:
	SIGN(const std::string& name = "", const std::string& surname = "", const std::string& sign = "", int* date = nullptr);
	SIGN(const SIGN& s);
	~SIGN();
	SIGN& operator=(const SIGN& s);//оператор присваивания
	//геттеры и сеттеры
	const std::string& Name() const;
	void Name(const std::string& name);
	const std::string& Surname()const;
	void Surname(const std::string& surname);
	const std::string& Sign()const;
	void Sign(const std::string& sign);
	void Date(int *date);
	int* Date();

	friend std::istream& operator>>(std::istream& in, SIGN& s);//оператор ввода
	friend std::ostream& operator<<(std::ostream& out, const SIGN& s);//оператор вывода
};