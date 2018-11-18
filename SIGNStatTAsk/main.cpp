#include "SIGN.hpp"
#include "List.hpp"

using namespace std;

int main(){
	const int size = 5;//размер массива
	setlocale(LC_ALL, "");
	list<SIGN> signs;//сам массив знаков зодиака
	for(int i = 0; i < size; ++i){
		signs.add(SIGN());
	}
	int a;
	while(true){
		 cout << "\n1. Считать данные\n2. Поиск\n3. Вывод всех\n4. Выход\n-> ";
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
			 for(i = 0; i < size; ++i){
				if(signs[i].Surname() == targ){
					cout << "\n" << signs[i];
				}
			 }
			 if(i >= size){
				cout << "Не найдено!";
			 }
		 }
		 else if(a == 3){
		   for(int i = 0; i < size; ++i){
					cout << "\n" << signs[i];
			 }
		 }
		 if(a == 4){
			 return 0;
		 }
	}
}
