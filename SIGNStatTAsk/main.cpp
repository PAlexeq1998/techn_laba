#include "Upr.hpp"

using namespace std;

int main(){
	const int size = 3;//размер массива
	setlocale(LC_ALL, "");

	Upr *wr = new Upr();
	int a;
	while(true){
		 cout << "\n1. Считать данные\n2. Вывод \n3. Поиск\n4. Выход\n-> ";
		 cin >> a;
		 if(a == 1)
		 {
			 wr->getSIGNs(size);
		 }
		 if(a == 2)
		 {
			 cout << *wr;
		 }
		 if (a == 3) {
			 cout << "Введите фамилию: ";
			 string targ;
			 cin >> targ;
			 int i;
			 int flag = 0;
			 for (i = 0; i < size; ++i) {
				 if (signs[i].Surname() == targ) {
					 cout << "\n" << signs[i];
					 flag = 1;
				 }
			 }
			 if (flag == 0) {
				 cout << "Не найдено!";
			 }
		 }
		 {
			 cout << "Введите фамилию: ";
			 string targ;
			 cin >> targ;
			 wr->showBySername(targ);
		 }
		 if (a == 4) {
			 return 0;
		 }
		 {}
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