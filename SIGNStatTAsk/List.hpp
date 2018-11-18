#pragma once
  
template<typename T>
struct node{//элемент списка
  	T _data; // значенеи элемента
	node *_next;	//ссылка на следущий элемент
	node *_prev;	//ссылка на предыдущий элемент
};

#include <iostream>
#include <cstring>

template<typename T>
class list {
private:
    node<T> *_head; //начало списка
	node<T> *_tail; //начало списка
    int _size; //размер
public:
   list();//конструктор
   void add(const T &_data);//заносим элемент в конец списка
   T remove(int index);//удаляем i-ый элемент
   int size(); //размер
   T operator[](int index)const;//получение i-го элемента
   T & operator[](int index);//получение i-го элемента
   template<typename U>
   friend std::ostream& operator <<(std::ostream& out, const list<U>& l); //вывод списка на экран
   template<typename U>
   friend std::istream& operator >>(std::istream& in, list<U>& l); //вввод элементов списка
   ~list(); //деструктор
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
	   if(index < 0 || index >= _size){//если неверный  индекс
			return T(0);
	   }
		node<T> *temp = _head;
		for(int i = 0; i < _size && i < index; ++i) {	// получаем нужный элемент
			temp = temp->_next;
		}

		if (temp == nullptr) {// если не нашли
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
		for(int i = 0; i < _size && i < index; ++i) { //ищем нужный элемент
			buf = buf->_next;
		}
		return buf->_data;
}

template<typename T>
T list<T>::operator[](int index)const{
	    node<T> *buf = _head;
		for(int i = 0; i < _size && i < index; ++i) { //ищем нужный элемент
			buf = buf->_next;
		}
		return buf->_data;
}

template<typename T>
std::ostream& operator <<(std::ostream& out, const list<T>& l){
	for(int i = 0; i < l._size; ++i){//проходим по каждому элементу
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
list<T>::~list(){ //деструктор
		for(int i = 0; i < _size; --_size){//проходим по каждому элементу
		   node<T> *buf = _head;
		   _head = _head->_next;//переходим к следующему
		   delete buf;//удаляем предыдущий
		}
}


