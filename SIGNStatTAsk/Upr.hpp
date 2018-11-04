#include <ostream>
#include "SIGN.hpp"

class Upr {
private:
	SIGN **data;
	int size;
public:
	Upr();

	friend std::ostream &operator<<(std::ostream &os, const Upr &list);
	void add(SIGN &w);

	int getSize() const;
	void remove(int index);
	void getSIGNs(int size);
	void sort();
	void showByYear(int maxAge);
	WorkerList *filter(int maxAge);

	~WorkerList();
};