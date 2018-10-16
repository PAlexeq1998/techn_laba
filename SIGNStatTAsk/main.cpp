#include "SIGN.hpp"

using namespace std;

int main(){
	const int size = 5;//размер массива
	setlocale(LC_ALL, "");
	SIGN signs[size];//сам массив знаков зодиака
	int a;
	while(true){
		 cout << "\n1. Считать данные\n2. Поиск\n3. Выход\n-> ";
		 cin >> a;
		 if(a == 1){
			 cout << "Имя Фамилия Знак DD MM YY\n";
			 try{
				 //считываем данные
				for(int i = 0; i < size; ++i){
				   cin >> signs[i];
				}
				/*Сортируем*/
				int j, n = size;
				do {
				int nn = 0;
				for (j = 1; j < n; ++j)
					if (signs[j-1].Date()[0] > signs[j].Date()[0] && 
						signs[j-1].Date()[1] > signs[j].Date()[1] && 
						signs[j-1].Date()[2] > signs[j].Date()[2]) {
						SIGN temp = signs[j-1];
						signs[j-1] = signs[j];
						signs[j] = temp;
						nn = j;
					}
					n = nn;
				} while (n);
			 }
			 catch(const Exception& e){
				cout << "\n" << e.what();
			 }
		 }
		 if(a == 2){
			 cout << "Введите фамилию: ";
			 string targ;
			 cin >> targ;
			 int i;
			 int flag  = 0;
			 for(i = 0; i < size; ++i){
				if(signs[i].Surname() == targ){
					cout << "\n" << signs[i];
					flag = 1;
				}
			 }
			 if(flag == 0){
				cout << "Не найдено!";
			 }
		 }
		 if (a == 3) {
			 return 0;
		 }
		 else {
			 if (a != 1 && a != 2) {
				 cout << "\nНекорректный ввод!";
				 cin.clear();
				 while (cin.get() != '\n')
					 continue;
			 }
		 }
	}
}