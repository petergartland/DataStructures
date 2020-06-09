#ifndef INTCELLHEAD_H
#define INTCELLHEAD_H

class IntCellPoint
{
public:
	IntCellPoint(int value = 0);
	IntCellPoint(const IntCellPoint & rhs);
	~IntCellPoint();
	const IntCellPoint & operator=(const IntCellPoint & rhs);
	int read() const;
	void write(int value);
private:
	int *storedValue;
};

#endif
