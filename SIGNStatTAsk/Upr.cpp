#include "Upr.hpp"

#include <iostream>

using namespace std;

Upr::Upr() {
	size = 0;
	data = new SIGN*[size];
}

Upr::~Upr() {
	for (int i = 0; i < this->size; ++i) {
		delete this->data[i];
	}
	this->size = 0;
}

int Upr::getSize() const {
	return size;
}

std::ostream &operator<<(std::ostream &os, const Upr &list) {
	for (int i = 0; i < list.size; ++i) {
		cout << *list.data[i] << endl;
	}
	return os;
}

void Upr::add(SIGN &w) {
	this->size++;
	auto **copy = new SIGN*[this->size - 1];
	for (int i = 0; i < this->size - 1; ++i) {
		copy[i] = this->data[i];
	}
	this->data = new SIGN*[this->size];
	for (int i = 0; i < this->size - 1; ++i) {
		this->data[i] = copy[i];
	}
	this->data[this->size - 1] = &w;
	delete[]copy;
}

void Upr::remove(int index) {
	try {
		auto **copy = new SIGN*[this->size];
		for (int i = 0; i < this->size; ++i) {
			copy[i] = this->data[i];
		}
		this->size--;
		this->data = new SIGN*[this->size];
		int k = 0;
		for (int i = 0; i < this->size + 1; ++i) {
			if (i == index) {
				continue;
			}
			this->data[k] = copy[i];
			k++;
		}
		delete[]copy;
	}
	catch (Exception e) {
		cout << "Error, please enter valid index" << endl << e.what() << endl;
	}
}

void Upr::getSIGNs(int size) {
	if (size <= 0) {
		return;
	}
	cout << "Enter " << size << endl;
	for (int i = 0; i < size; ++i) {
		SIGN *wr = new SIGN();
		cin >> *wr;
		add(*wr);
	}
	sort();
	cout << *this;
}

void Upr::sort() {
	SIGN *wr;
	// Bubble sort
	for (int j = 0; j < size - 1; ++j) {
		for (int i = j; i < size - 1; ++i) {
			if (data[i]->getSurname() > data[i + 1]->getSurname()) {
				wr = data[i];
				data[i] = data[i + 1];
				data[i + 1] = wr;
			}
		}
	}
}

Upr *Upr::filter(int maxAge) {
	Upr *wr = new Upr();
	for (int i = 0; i < size; ++i) {
		if (data[i]->getYear() >= maxAge) {
			wr->add(*data[i]);
			cout << "filtering" << *wr << endl;
			return wr;
		}

		void Upr::showByYear(int maxAge) {
			Upr *wr = this->filter(maxAge);
			if (wr->getSize() == 0) {
				cout << "No SIGNs with maxAge" << endl;
				return;
			}
			cout << wr->getSize();
			cout << *wr << endl;
		}
