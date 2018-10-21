#include "SIGN.hpp"

SIGN::SIGN(const std::string& name, const std::string& surname, const std::string& sign, int * date):
name(name), surname(surname), sign(sign){
	if(date != nullptr){
		this->date[0] = date[0];
		this->date[1] = date[1];
		this->date[2] = date[2];
	}
	else{
		 this->date[0] = 0;
		this->date[1] = 0;
		this->date[2] = 0;
	}
    std::cout << "\n����������� SIGN"; 
}

SIGN::SIGN(const SIGN& s):
name(s.name), surname(s.surname), sign(s.sign){
	date[0] = s.date[0];
	date[1] = s.date[1];
	date[2] = s.date[2];
	 std::cout << "\n����������� ����������� SIGN"; 
}

SIGN::~SIGN(){ std::cout << "\n���������� SIGN"; }

SIGN& SIGN::operator=(const SIGN& s){//�������� ������������
	name = s.name;
	surname = s.surname;
	sign = s.sign;
	date[0] = s.date[0];
	date[1] = s.date[1];
	date[2] = s.date[2];
	return *this;
}
//������� � �������
const std::string& SIGN::Name()const{ return name; }
const std::string& SIGN::Surname()const{ return surname; }
const std::string& SIGN::Sign()const{ return sign; }
int* SIGN::Date(){
	return date;
}

void SIGN::Date(int *date){
	if(date != nullptr){
		this->date[0] = date[0];
		this->date[1] = date[1];
		this->date[2] = date[2];
	}
	else{
		 this->date[0] = 0;
		this->date[1] = 0;
		this->date[2] = 0;
	}
}

void SIGN::Sign(const std::string& sign){
	 this->sign = sign;
}

void SIGN::Name(const std::string& name){
	 this->name = name;
}

void SIGN::Surname(const std::string& surname){
	 this->surname = surname;
}

std::istream& operator>>(std::istream& in, SIGN& s){//�������� �����
	if(!(in >> s.name >> s.surname >> s.sign >> s.date[0] >> s.date[1] >> s.date[2])){
		throw Exception("������������ ����");
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const SIGN& s){//�������� ������
	out << "���: " << s.name
		<< "\n�������: " << s.surname
		<< "\n����: " << s.sign
		<< "\n����: " << s.date[0] << '/' << s.date[1] << '/' << s.date[2];
	return out;
}