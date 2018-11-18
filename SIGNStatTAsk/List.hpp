#pragma once
  
template<typename T>
struct node{//������� ������
  	T _data; // �������� ��������
	node *_next;	//������ �� �������� �������
	node *_prev;	//������ �� ���������� �������
};

#include <iostream>
#include <cstring>

template<typename T>
class list {
private:
    node<T> *_head; //������ ������
	node<T> *_tail; //������ ������
    int _size; //������
public:
   list();//�����������
   void add(const T &_data);//������� ������� � ����� ������
   T remove(int index);//������� i-�� �������
   int size(); //������
   T operator[](int index)const;//��������� i-�� ��������
   T & operator[](int index);//��������� i-�� ��������
   template<typename U>
   friend std::ostream& operator <<(std::ostream& out, const list<U>& l); //����� ������ �� �����
   template<typename U>
   friend std::istream& operator >>(std::istream& in, list<U>& l); //����� ��������� ������
   ~list(); //����������
};

template<typename T>
list<T>::list<T>():_head(nullptr), _tail(nullptr), _size(0){
   }

template<typename T>
void list<T>::add(const T &_data){
	    node<T> *buf = new node<T>;
		buf->_data = _data;
		buf->_next = nullptr;
		buf->_prev = _tail;
		if (_tail) {
			_tail->_next = buf;
		}
		if (_head == nullptr) {
			_head = buf;
		}
		_tail = buf;
		++_size;
}

template<typename T>
T list<T>::remove(int index){
	   if(index < 0 || index >= _size){//���� ��������  ������
			return T(0);
	   }
		node<T> *temp = _head;
		for(int i = 0; i < _size && i < index; ++i) {	// �������� ������ �������
			temp = temp->_next;
		}

		if (temp == nullptr) {// ���� �� �����
			return T(0); 
		}
		if (temp->_prev) {
			temp->_prev->_next = temp->_next;
		}
		if (temp->_next) {
			temp->_next->_prev = temp->_prev;
		}
		T _data = temp->_data;
 
		if (temp->_prev == nullptr) {
			_head = temp->_next;
		}
		if (temp->_next == nullptr) {
			_tail = temp->_prev;
		}
		delete temp;
		--_size;
		return _data;
}

template<typename T>
int list<T>::size(){ 
	return _size; 
}

template<typename T>
T & list<T>::operator[](int index){
	    node<T> *buf = _head;
		for(int i = 0; i < _size && i < index; ++i) { //���� ������ �������
			buf = buf->_next;
		}
		return buf->_data;
}

template<typename T>
T list<T>::operator[](int index)const{
	    node<T> *buf = _head;
		for(int i = 0; i < _size && i < index; ++i) { //���� ������ �������
			buf = buf->_next;
		}
		return buf->_data;
}

template<typename T>
std::ostream& operator <<(std::ostream& out, const list<T>& l){
	for(int i = 0; i < l._size; ++i){//�������� �� ������� ��������
		   out << l[i];
		}
	return out;
}

template<typename T>
std::istream& operator >>(std::istream& in, list<T>& l){
	 T buf;
	 in >> buf;
	 l.add(buf);
	 return in;
}

template<typename T>
list<T>::~list(){ //����������
		for(int i = 0; i < _size; --_size){//�������� �� ������� ��������
		   node<T> *buf = _head;
		   _head = _head->_next;//��������� � ����������
		   delete buf;//������� ����������
		}
}


