#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
	setlocale(LC_ALL, "");
	ifstream in("input.txt");
	string line;//�����
	stringstream ss;	//��������� �����
	int maxlen = -1; //������������ ��������
	int cnt = 1;//������� 1 ��� ��� ���� ����� ������ ����
	while(in >> line){//��������� �� �����������
		int o =	line.length();
		//���� ������ �����������
		if(o > maxlen){
			 maxlen = o;
			 cnt = 1;
			 ss.str(std::string());//�������
			 ss << line;
		}
		//���� ���� ����� ������������
		else if(o == maxlen && ss.str() == line) {
			 ++cnt;
		}

	}
	cout << "count = " << cnt << '\n';
	cout << ss.str();// ������� �����������
	in.close();//��������� ����										   
	system("pause>>void");
}