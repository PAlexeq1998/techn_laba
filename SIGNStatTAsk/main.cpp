#include "Upr.hpp"

using namespace std;

int main(){
	const int size = 3;//������ �������
	setlocale(LC_ALL, "");

	Upr *wr = new Upr();
	int a;
	while(true){
		 cout << "\n1. ������� ������\n2. ����� \n3. �����\n4. �����\n-> ";
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
			 cout << "������� �������: ";
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
				 cout << "�� �������!";
			 }
		 }
		 {
			 cout << "������� �������: ";
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
				 cout << "\n������������ ����!";
				 cin.clear();
				 while (cin.get() != '\n')
					 continue;
			 }
		 }
	}
}