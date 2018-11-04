#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
	setlocale(LC_ALL, "");
	ifstream in("input.txt");
	string line;//слово
	stringstream ss;	//строковый поток
	int maxlen = -1; //максимальное значение
	int cnt = 1;//счётчик 1 так как одно слово всегда есть
	while(in >> line){//считываем по предложению
		int o =	line.length();
		//если больше предыдущего
		if(o > maxlen){
			 maxlen = o;
			 cnt = 1;
			 ss.str(std::string());//очищаем
			 ss << line;
		}
		//если длна равна максимальной
		else if(o == maxlen && ss.str() == line) {
			 ++cnt;
		}

	}
	cout << "count = " << cnt << '\n';
	cout << ss.str();// выводим предложение
	in.close();//закрываем файл										   
	system("pause>>void");
}