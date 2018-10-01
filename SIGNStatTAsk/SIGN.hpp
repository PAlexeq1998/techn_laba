#pragma once
#include "Exception.hpp"
#include <iostream>

class SIGN{
private:
	std::string name;//���
	std::string surname;//�������
	std::string sign;//��� �������
	int date[3];//���� ��������
public:
	SIGN(const std::string& name = "", const std::string& surname = "", const std::string& sign = "", int* date = nullptr);
	SIGN(const SIGN& s);
	~SIGN();
	SIGN& operator=(const SIGN& s);//�������� ������������
	//������� � �������
	const std::string& Name() const;
	void Name(const std::string& name);
	const std::string& Surname()const;
	void Surname(const std::string& surname);
	const std::string& Sign()const;
	void Sign(const std::string& sign);
	void Date(int *date);
	int* Date();

	friend std::istream& operator>>(std::istream& in, SIGN& s);//�������� �����
	friend std::ostream& operator<<(std::ostream& out, const SIGN& s);//�������� ������
};