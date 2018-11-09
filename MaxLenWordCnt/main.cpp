#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void enter(string word, int cword);	 //������� ��� ������
void work(ifstream& in); //������� ��� ������ � ������   

int main() 
{
	setlocale(LC_ALL, "");
	ifstream io("input.txt");

	work(io);

	io.close();//��������� ����										   
	system("pause>>void");
}

void enter(string word, int cword)
{
	cout << "count = " << cword << '\n';
	cout << word;// ������� �����������
}

void work(ifstream& in)
{
	string line;//�����
	stringstream ss;	//��������� �����
	int maxlen = -1; //������������ ��������
	int cnt = 1;//������� 1 ��� ��� ���� ����� ������ ����
	while (in >> line) {//��������� �� �����������
		int o = line.length();
		//���� ������ �����������
		if (o > maxlen) {
			maxlen = o;
			cnt = 1;
			ss.str(std::string());//�������
			ss << line;
		}
		//���� ���� ����� ������������
		else if (o == maxlen && ss.str() == line) {
			++cnt;
		}

	}
	enter(ss.str(), cnt);
}