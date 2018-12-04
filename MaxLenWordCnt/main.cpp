#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void enter(string word, int cword);	 //функция для вывода
void work(ifstream& in); //функция для работы с файлом 


int main() 
{
	setlocale(LC_ALL, "");
	ifstream io("input.txt");

	io.exceptions(ifstream::failbit);
	try
	{
		io.open("input.txt");
		work(io);
		io.close();
	}
	catch (const ifstream::failure& exc)
	{
		cout << "Error while opening file: " << endl << exc.what() << endl;
	}
									   
	system("pause>>void");
}



void enter(string word, int cword)
{
	cout << "count = " << cword << '\n';
	cout << word;// выводим предложение
}


void work(ifstream& in)
{
	string line;//слово
	stringstream ss;	//строковый поток
	int maxlen = -1; //максимальное значение
	int cnt = 1;//счётчик 1 так как одно слово всегда есть
	while (in >> line) {//считываем по слову
		int o = line.length();
		//если больше предыдущего
		if (o > maxlen) {
			maxlen = o;
			cnt = 1;
			ss.str(string());//очищаем
			ss << line;
		}
		//если длна равна максимальной
		else if (o == maxlen && ss.str() == line) {
			++cnt;
		}

	}
	enter(ss.str(), cnt);
}
