/* This file contains everything var related.
 * It is meant to cause less hassle with EZ.hpp.
 * Lots of things break, but we plan on fixing them.
 * In the meantime, use this file for EZ.hpp.
 */
#include <iostream>
// var class, similar to Java's Object
class var {
private:
	int* idata;
	char* cdata;
	char* sdata;
	bool* bdata;
	float* fdata;
	double* ddata;
	long int* ldata;
	long long int* lldata;
	unsigned long long int* ulldata;
public:
	// constructors
	var();
	var(int val);
	var(float val);
	var(char val);
	var(double val);
	var(bool val);
	var(const char* val);
	var(long int val);
	var(long long int val);
	var(unsigned long long int val);
	// getting
	const int* getidata() const;
	const char* getcdata() const;
	const float* getfdata() const;
	const double* getddata() const;
	const bool* getbdata() const;
	const long int* getldata() const;
	const long long int* getlldata() const;
	const unsigned long long int* getulldata() const;
	const char* getsdata() const;
	// operators
	friend std::ostream& operator<<(std::ostream& os, const var& val);
	friend std::istream& operator>>(std::istream& input, var& val);
	var operator++(int);
	var operator--(int);
	var operator-();
	var& operator++();
	var& operator--();
	var& operator+=(const var& rhs);
	var& operator*=(const var& rhs);
	var& operator-=(const var& rhs);
	var& operator/=(const var& rhs);
	var& operator=(const var& rhs);
	char& operator[](int pos);
};
// for math funcs
namespace Math {
	float calc(float x, char sign, float y);
	int abs(int num);
}
// gets len of anything until first null character
template <class T>
int len(T *_thing)
{
	for (int i = 0;; i++) if (_thing[i] == '\0' || _thing[i] == 0) return i;
}
// global overloader
var operator*(const var& lhs, const var& rhs)
{
	if (lhs.getidata()) {
		if (rhs.getidata()) return lhs.getidata()[0] * rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getidata()[0] * rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getidata()[0] * rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getidata()[0] * rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getidata()[0] * rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getidata()[0] * rhs.getulldata()[0];
	}
	else if (lhs.getddata()) {
		if (rhs.getidata()) return lhs.getddata()[0] * rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getddata()[0] * rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getddata()[0] * rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getddata()[0] * rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getddata()[0] * rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getddata()[0] * rhs.getulldata()[0];
	}
	else if (lhs.getfdata()) {
		if (rhs.getidata()) return lhs.getfdata()[0] * rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getfdata()[0] * rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getfdata()[0] * rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getfdata()[0] * rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getfdata()[0] * rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getfdata()[0] * rhs.getulldata()[0];
	}
	else if (lhs.getldata()) {
		if (rhs.getidata()) return lhs.getldata()[0] * rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getldata()[0] * rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getldata()[0] * rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getldata()[0] * rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getldata()[0] * rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getldata()[0] * rhs.getulldata()[0];
	}
	else if (lhs.getlldata()) {
		if (rhs.getidata()) return lhs.getlldata()[0] * rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getlldata()[0] * rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getlldata()[0] * rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getlldata()[0] * rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getlldata()[0] * rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getlldata()[0] * rhs.getulldata()[0];
	}
	else if (lhs.getulldata()) {
		if (rhs.getidata()) return lhs.getulldata()[0] * rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getulldata()[0] * rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getulldata()[0] * rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getulldata()[0] * rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getulldata()[0] * rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getulldata()[0] * rhs.getulldata()[0];
	} return 0;
}
// global overloader
var operator/(const var& lhs, const var& rhs)
{
	if (lhs.getidata()) {
		if (rhs.getidata()) return lhs.getidata()[0] / rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getidata()[0] / rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getidata()[0] / rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getidata()[0] / rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getidata()[0] / rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getidata()[0] / rhs.getulldata()[0];
	}
	else if (lhs.getddata()) {
		if (rhs.getidata()) return lhs.getddata()[0] / rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getddata()[0] / rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getddata()[0] / rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getddata()[0] / rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getddata()[0] / rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getddata()[0] / rhs.getulldata()[0];
	}
	else if (lhs.getfdata()) {
		if (rhs.getidata()) return lhs.getfdata()[0] / rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getfdata()[0] / rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getfdata()[0] / rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getfdata()[0] / rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getfdata()[0] / rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getfdata()[0] / rhs.getulldata()[0];
	}
	else if (lhs.getldata()) {
		if (rhs.getidata()) return lhs.getldata()[0] / rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getldata()[0] / rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getldata()[0] / rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getldata()[0] / rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getldata()[0] / rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getldata()[0] / rhs.getulldata()[0];
	}
	else if (lhs.getlldata()) {
		if (rhs.getidata()) return lhs.getlldata()[0] / rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getlldata()[0] / rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getlldata()[0] / rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getlldata()[0] / rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getlldata()[0] / rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getlldata()[0] / rhs.getulldata()[0];
	}
	else if (lhs.getulldata()) {
		if (rhs.getidata()) return lhs.getulldata()[0] / rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getulldata()[0] / rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getulldata()[0] / rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getulldata()[0] / rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getulldata()[0] / rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getulldata()[0] / rhs.getulldata()[0];
	} return 0;
}
// global overloader
var operator+(const var& lhs, const var& rhs)
{
	if (lhs.getidata()) {
		if (rhs.getidata()) return lhs.getidata()[0] + rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getidata()[0] + rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getidata()[0] + rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getidata()[0] + rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getidata()[0] + rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getidata()[0] + rhs.getulldata()[0];
	}
	else if (lhs.getddata()) {
		if (rhs.getidata()) return lhs.getddata()[0] + rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getddata()[0] + rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getddata()[0] + rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getddata()[0] + rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getddata()[0] + rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getddata()[0] + rhs.getulldata()[0];
	}
	else if (lhs.getfdata()) {
		if (rhs.getidata()) return lhs.getfdata()[0] + rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getfdata()[0] + rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getfdata()[0] + rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getfdata()[0] + rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getfdata()[0] + rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getfdata()[0] + rhs.getulldata()[0];
	}
	else if (lhs.getldata()) {
		if (rhs.getidata()) return lhs.getldata()[0] + rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getldata()[0] + rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getldata()[0] + rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getldata()[0] + rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getldata()[0] + rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getldata()[0] + rhs.getulldata()[0];
	}
	else if (lhs.getlldata()) {
		if (rhs.getidata()) return lhs.getlldata()[0] + rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getlldata()[0] + rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getlldata()[0] + rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getlldata()[0] + rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getlldata()[0] + rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getlldata()[0] + rhs.getulldata()[0];
	}
	else if (lhs.getulldata()) {
		if (rhs.getidata()) return lhs.getulldata()[0] + rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getulldata()[0] + rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getulldata()[0] + rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getulldata()[0] + rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getulldata()[0] + rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getulldata()[0] + rhs.getulldata()[0];
	} return 0;
}
// global overloader
var operator-(const var& lhs, const var& rhs)
{
	if (lhs.getidata()) {
		if (rhs.getidata()) return lhs.getidata()[0] - rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getidata()[0] - rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getidata()[0] - rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getidata()[0] - rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getidata()[0] - rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getidata()[0] - rhs.getulldata()[0];
	}
	else if (lhs.getddata()) {
		if (rhs.getidata()) return lhs.getddata()[0] - rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getddata()[0] - rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getddata()[0] - rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getddata()[0] - rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getddata()[0] - rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getddata()[0] - rhs.getulldata()[0];
	}
	else if (lhs.getfdata()) {
		if (rhs.getidata()) return lhs.getfdata()[0] - rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getfdata()[0] - rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getfdata()[0] - rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getfdata()[0] - rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getfdata()[0] - rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getfdata()[0] - rhs.getulldata()[0];
	}
	else if (lhs.getldata()) {
		if (rhs.getidata()) return lhs.getldata()[0] - rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getldata()[0] - rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getldata()[0] - rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getldata()[0] - rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getldata()[0] - rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getldata()[0] - rhs.getulldata()[0];
	}
	else if (lhs.getlldata()) {
		if (rhs.getidata()) return lhs.getlldata()[0] - rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getlldata()[0] - rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getlldata()[0] - rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getlldata()[0] - rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getlldata()[0] - rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getlldata()[0] - rhs.getulldata()[0];
	}
	else if (lhs.getulldata()) {
		if (rhs.getidata()) return lhs.getulldata()[0] - rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getulldata()[0] - rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getulldata()[0] - rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getulldata()[0] - rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getulldata()[0] - rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getulldata()[0] - rhs.getulldata()[0];
	} return 0;
}
// global overloader
var operator%(const var& lhs, const var& rhs)
{
	if (lhs.getidata()) {
		if (rhs.getidata()) return lhs.getidata()[0] % rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getidata()[0] % rhs.getldata()[0];
		else if (rhs.getlldata()) return lhs.getidata()[0] % rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getidata()[0] % rhs.getulldata()[0];
	}
	else if (lhs.getldata()) {
		if (rhs.getidata()) return lhs.getldata()[0] % rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getldata()[0] % rhs.getldata()[0];
		else if (rhs.getlldata()) return lhs.getldata()[0] % rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getldata()[0] % rhs.getulldata()[0];
	}
	else if (lhs.getlldata()) {
		if (rhs.getidata()) return lhs.getlldata()[0] % rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getlldata()[0] % rhs.getldata()[0];
		else if (rhs.getlldata()) return lhs.getlldata()[0] % rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getlldata()[0] % rhs.getulldata()[0];
	}
	else if (lhs.getulldata()) {
		if (rhs.getidata()) return lhs.getulldata()[0] % rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getulldata()[0] % rhs.getldata()[0];
		else if (rhs.getlldata()) return lhs.getulldata()[0] % rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getulldata()[0] % rhs.getulldata()[0];
	} return 0;
}
// global overloader
long& operator*=(long& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs *= rhs.getidata()[0];
	else if (rhs.getfdata()) lhs *= rhs.getfdata()[0];
	else if (rhs.getddata()) lhs *= rhs.getddata()[0];
	else if (rhs.getldata()) lhs *= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs *= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs *= rhs.getulldata()[0];
	return lhs;
}
// global overloader
int& operator*=(int& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs *= rhs.getidata()[0];
	else if (rhs.getfdata()) lhs *= rhs.getfdata()[0];
	else if (rhs.getddata()) lhs *= rhs.getddata()[0];
	else if (rhs.getldata()) lhs *= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs *= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs *= rhs.getulldata()[0];
	return lhs;
}
// global overloader
float& operator*=(float& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs *= rhs.getidata()[0];
	else if (rhs.getfdata()) lhs *= rhs.getfdata()[0];
	else if (rhs.getddata()) lhs *= rhs.getddata()[0];
	else if (rhs.getldata()) lhs *= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs *= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs *= rhs.getulldata()[0];
	return lhs;
}
// global overloader
double& operator*=(double& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs *= rhs.getidata()[0];
	else if (rhs.getfdata()) lhs *= rhs.getfdata()[0];
	else if (rhs.getddata()) lhs *= rhs.getddata()[0];
	else if (rhs.getldata()) lhs *= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs *= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs *= rhs.getulldata()[0];
	return lhs;
}
// global overloader
long long& operator*=(long long& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs *= rhs.getidata()[0];
	else if (rhs.getfdata()) lhs *= rhs.getfdata()[0];
	else if (rhs.getddata()) lhs *= rhs.getddata()[0];
	else if (rhs.getldata()) lhs *= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs *= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs *= rhs.getulldata()[0];
	return lhs;
}
// global overloader
unsigned long long& operator*=(unsigned long long& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs *= rhs.getidata()[0];
	else if (rhs.getfdata()) lhs *= rhs.getfdata()[0];
	else if (rhs.getddata()) lhs *= rhs.getddata()[0];
	else if (rhs.getldata()) lhs *= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs *= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs *= rhs.getulldata()[0];
	return lhs;
}
// global overloader
long& operator+=(long& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs += rhs.getidata()[0];
	else if (rhs.getfdata()) lhs += rhs.getfdata()[0];
	else if (rhs.getddata()) lhs += rhs.getddata()[0];
	else if (rhs.getldata()) lhs += rhs.getldata()[0];
	else if (rhs.getlldata()) lhs += rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs += rhs.getulldata()[0];
	return lhs;
}
// global overloader
int& operator+=(int& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs += rhs.getidata()[0];
	else if (rhs.getfdata()) lhs += rhs.getfdata()[0];
	else if (rhs.getddata()) lhs += rhs.getddata()[0];
	else if (rhs.getldata()) lhs += rhs.getldata()[0];
	else if (rhs.getlldata()) lhs += rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs += rhs.getulldata()[0];
	return lhs;
}
// global overloader
float& operator+=(float& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs += rhs.getidata()[0];
	else if (rhs.getfdata()) lhs += rhs.getfdata()[0];
	else if (rhs.getddata()) lhs += rhs.getddata()[0];
	else if (rhs.getldata()) lhs += rhs.getldata()[0];
	else if (rhs.getlldata()) lhs += rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs += rhs.getulldata()[0];
	return lhs;
}
// global overloader
double& operator+=(double& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs += rhs.getidata()[0];
	else if (rhs.getfdata()) lhs += rhs.getfdata()[0];
	else if (rhs.getddata()) lhs += rhs.getddata()[0];
	else if (rhs.getldata()) lhs += rhs.getldata()[0];
	else if (rhs.getlldata()) lhs += rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs += rhs.getulldata()[0];
	return lhs;
}
// global overloader
long long& operator+=(long long& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs += rhs.getidata()[0];
	else if (rhs.getfdata()) lhs += rhs.getfdata()[0];
	else if (rhs.getddata()) lhs += rhs.getddata()[0];
	else if (rhs.getldata()) lhs += rhs.getldata()[0];
	else if (rhs.getlldata()) lhs += rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs += rhs.getulldata()[0];
	return lhs;
}
// global overloader
unsigned long long& operator+=(unsigned long long& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs += rhs.getidata()[0];
	else if (rhs.getfdata()) lhs += rhs.getfdata()[0];
	else if (rhs.getddata()) lhs += rhs.getddata()[0];
	else if (rhs.getldata()) lhs += rhs.getldata()[0];
	else if (rhs.getlldata()) lhs += rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs += rhs.getulldata()[0];
	return lhs;
}
// global overloader
long& operator-=(long& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs -= rhs.getidata()[0];
	else if (rhs.getfdata()) lhs -= rhs.getfdata()[0];
	else if (rhs.getddata()) lhs -= rhs.getddata()[0];
	else if (rhs.getldata()) lhs -= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs -= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs -= rhs.getulldata()[0];
	return lhs;
}
// global overloader
int& operator-=(int& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs -= rhs.getidata()[0];
	else if (rhs.getfdata()) lhs -= rhs.getfdata()[0];
	else if (rhs.getddata()) lhs -= rhs.getddata()[0];
	else if (rhs.getldata()) lhs -= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs -= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs -= rhs.getulldata()[0];
	return lhs;
}
// global overloader
float& operator-=(float& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs -= rhs.getidata()[0];
	else if (rhs.getfdata()) lhs -= rhs.getfdata()[0];
	else if (rhs.getddata()) lhs -= rhs.getddata()[0];
	else if (rhs.getldata()) lhs -= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs -= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs -= rhs.getulldata()[0];
	return lhs;
}
// global overloader
double& operator-=(double& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs -= rhs.getidata()[0];
	else if (rhs.getfdata()) lhs -= rhs.getfdata()[0];
	else if (rhs.getddata()) lhs -= rhs.getddata()[0];
	else if (rhs.getldata()) lhs -= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs -= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs -= rhs.getulldata()[0];
	return lhs;
}
// global overloader
long long& operator-=(long long& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs -= rhs.getidata()[0];
	else if (rhs.getfdata()) lhs -= rhs.getfdata()[0];
	else if (rhs.getddata()) lhs -= rhs.getddata()[0];
	else if (rhs.getldata()) lhs -= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs -= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs -= rhs.getulldata()[0];
	return lhs;
}
// global overloader
unsigned long long& operator-=(unsigned long long& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs -= rhs.getidata()[0];
	else if (rhs.getfdata()) lhs -= rhs.getfdata()[0];
	else if (rhs.getddata()) lhs -= rhs.getddata()[0];
	else if (rhs.getldata()) lhs -= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs -= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs -= rhs.getulldata()[0];
	return lhs;
}
// global overloader
long& operator/=(long& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs /= rhs.getidata()[0];
	else if (rhs.getfdata()) lhs /= rhs.getfdata()[0];
	else if (rhs.getddata()) lhs /= rhs.getddata()[0];
	else if (rhs.getldata()) lhs /= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs /= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs /= rhs.getulldata()[0];
	return lhs;
}
// global overloader
int& operator/=(int& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs /= rhs.getidata()[0];
	else if (rhs.getfdata()) lhs /= rhs.getfdata()[0];
	else if (rhs.getddata()) lhs /= rhs.getddata()[0];
	else if (rhs.getldata()) lhs /= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs /= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs /= rhs.getulldata()[0];
	return lhs;
}
// global overloader
float& operator/=(float& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs /= rhs.getidata()[0];
	else if (rhs.getfdata()) lhs /= rhs.getfdata()[0];
	else if (rhs.getddata()) lhs /= rhs.getddata()[0];
	else if (rhs.getldata()) lhs /= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs /= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs /= rhs.getulldata()[0];
	return lhs;
}
// global overloader
double& operator/=(double& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs /= rhs.getidata()[0];
	else if (rhs.getfdata()) lhs /= rhs.getfdata()[0];
	else if (rhs.getddata()) lhs /= rhs.getddata()[0];
	else if (rhs.getldata()) lhs /= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs /= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs /= rhs.getulldata()[0];
	return lhs;
}
// global overloader
long long& operator/=(long long& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs /= rhs.getidata()[0];
	else if (rhs.getfdata()) lhs /= rhs.getfdata()[0];
	else if (rhs.getddata()) lhs /= rhs.getddata()[0];
	else if (rhs.getldata()) lhs /= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs /= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs /= rhs.getulldata()[0];
	return lhs;
}
// global overloader
unsigned long long& operator/=(unsigned long long& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs /= rhs.getidata()[0];
	else if (rhs.getfdata()) lhs /= rhs.getfdata()[0];
	else if (rhs.getddata()) lhs /= rhs.getddata()[0];
	else if (rhs.getldata()) lhs /= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs /= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs /= rhs.getulldata()[0];
	return lhs;
}
// global overloader
long& operator%=(long& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs %= rhs.getidata()[0];
	else if (rhs.getldata()) lhs %= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs %= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs %= rhs.getulldata()[0];
	return lhs;
}
// global overloader
int& operator%=(int& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs %= rhs.getidata()[0];
	else if (rhs.getldata()) lhs %= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs %= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs %= rhs.getulldata()[0];
	return lhs;
}
// global overloader
long long& operator%=(long long& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs %= rhs.getidata()[0];
	else if (rhs.getldata()) lhs %= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs %= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs %= rhs.getulldata()[0];
	return lhs;
}
// global overloader
unsigned long long& operator%=(unsigned long long& lhs, const var& rhs)
{
	if (rhs.getidata()) lhs %= rhs.getidata()[0];
	else if (rhs.getldata()) lhs %= rhs.getldata()[0];
	else if (rhs.getlldata()) lhs %= rhs.getlldata()[0];
	else if (rhs.getulldata()) lhs %= rhs.getulldata()[0];
	return lhs;
}
// default constructor
var::var()
{
	idata = 0;
	ddata = 0;
	fdata = 0;
	cdata = 0;
	bdata = 0;
	sdata = 0;
	ldata = 0;
	lldata = 0;
	ulldata = 0;
}
// integer constructor
var::var(int val)
{
	idata = new int[1];
	idata[0] = val;
	ddata = 0;
	fdata = 0;
	cdata = 0;
	bdata = 0;
	sdata = 0;
	ldata = 0;
	lldata = 0;
	ulldata = 0;
}
// float constructor
var::var(float val)
{
	fdata = new float[1];
	fdata[0] = val;
	ddata = 0;
	idata = 0;
	cdata = 0;
	bdata = 0;
	sdata = 0;
	ldata = 0;
	lldata = 0;
	ulldata = 0;
}
// char constructor
var::var(char val)
{
	cdata = new char[1];
	cdata[0] = val;
	ddata = 0;
	fdata = 0;
	idata = 0;
	bdata = 0;
	sdata = 0;
	ldata = 0;
	lldata = 0;
	ulldata = 0;
}
// double constructor
var::var(double val)
{
	ddata = new double[1];
	ddata[0] = val;
	fdata = 0;
	idata = 0;
	cdata = 0;
	bdata = 0;
	sdata = 0;
	ldata = 0;
	lldata = 0;
	ulldata = 0;
}
// bool constructor
var::var(bool val)
{
	bdata = new bool[1];
	bdata[0] = val;
	ddata = 0;
	fdata = 0;
	idata = 0;
	cdata = 0;
	sdata = 0;
	ldata = 0;
	lldata = 0;
	ulldata = 0;
}
// string constructor
var::var(const char* val)
{
	sdata = new char[len(val) + 1];
	for (int i = 0;; i++) {
		if (val[i] == '\0') break;
		sdata[i] = val[i];
	}
	sdata[len(val)] = '\0';
	ddata = 0;
	fdata = 0;
	idata = 0;
	cdata = 0;
	bdata = 0;
	ldata = 0;
	lldata = 0;
	ulldata = 0;
}
// bignum constructor
var::var(unsigned long long int val)
{
	ulldata = new unsigned long long int[1];
	ulldata[0] = val;
	ddata = 0;
	fdata = 0;
	idata = 0;
	cdata = 0;
	bdata = 0;
	sdata = 0;
	ldata = 0;
	lldata = 0;
}
// long constructor
var::var(long int val)
{
	ldata = new long int[1];
	ldata[0] = val;
	ddata = 0;
	fdata = 0;
	idata = 0;
	cdata = 0;
	bdata = 0;
	sdata = 0;
	lldata = 0;
	ulldata = 0;
}
// long long constructor
var::var(long long int val)
{
	lldata = new long long int[1];
	lldata[0] = val;
	ddata = 0;
	fdata = 0;
	idata = 0;
	cdata = 0;
	bdata = 0;
	sdata = 0;
	ldata = 0;
	ulldata = 0;
}
// overloading the postfix ++
var var::operator++(int)
{
	return *this += 1;
}
// overloading the prefix ++
var& var::operator++()
{
	return *this += 1;
}
// overloading the postfix --
var var::operator--(int)
{
	return *this -= 1;
}
// overloading the prefix --
var& var::operator--()
{
	return *this -= 1;
}
// overloading the negative symbol
var var::operator-()
{
	if (idata) return -idata[0];
	else if (ldata) return -ldata[0];
	else if (lldata) return -lldata[0];
	else return 0;
}
// overloading the input operator
inline std::istream& operator>>(std::istream& input, var& val)
{
	if (val.cdata) input >> val.cdata[0];
	else if (val.ddata) input >> val.ddata[0];
	else if (val.idata) input >> val.idata[0];
	else if (val.fdata) input >> val.fdata[0];
	else if (val.bdata) input >> val.bdata[0];
	else if (val.ldata) input >> val.ldata[0];
	else if (val.sdata) {
		val = "";
		input >> val.sdata;
	}
	else if (val.lldata) input >> val.lldata[0];
	else if (val.ulldata) input >> val.ulldata[0];
	return input;
}
// overloading the == operator
bool operator==(const var& lhs, const var& rhs)
{
	if (lhs.getidata()) {
		if (rhs.getidata()) return lhs.getidata()[0] == rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getidata()[0] == rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getidata()[0] == rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getidata()[0] == rhs.getfdata()[0];
		else if (rhs.getsdata()) {
			int k = ::len(rhs.getsdata());
			for (int i = 0; i < ::len(rhs.getsdata()); i++) if (rhs.getsdata()[i] == lhs.getidata()[0]) k--;
			return !(k == ::len(rhs.getsdata()));
		}
		else if (rhs.getlldata()) return lhs.getidata()[0] == rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getidata()[0] == rhs.getulldata()[0];
		else if (rhs.getcdata()) return lhs.getidata()[0] == rhs.getcdata()[0];
	}
	else if (lhs.getddata()) {
		if (rhs.getidata()) return lhs.getddata()[0] == rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getddata()[0] == rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getddata()[0] == rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getddata()[0] == rhs.getfdata()[0];
		else if (rhs.getsdata()) {
			int k = ::len(rhs.getsdata());
			for (int i = 0; i < ::len(rhs.getsdata()); i++) if (rhs.getsdata()[i] != lhs.getddata()[0]) k--;
			return !(k == ::len(rhs.getsdata()));
		}
		else if (rhs.getlldata()) return lhs.getddata()[0] == rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getddata()[0] == rhs.getulldata()[0];
		else if (rhs.getcdata()) return lhs.getddata()[0] == rhs.getcdata()[0];
	}
	else if (lhs.getfdata()) {
		if (rhs.getidata()) return lhs.getfdata()[0] == rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getfdata()[0] == rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getfdata()[0] == rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getfdata()[0] == rhs.getfdata()[0];
		else if (rhs.getsdata()) {
			int k = ::len(rhs.getsdata());
			for (int i = 0; i < ::len(rhs.getsdata()); i++) if (rhs.getsdata()[i] != lhs.getfdata()[0]) k--;
			return !(k == ::len(rhs.getsdata()));
		}
		else if (rhs.getlldata()) return lhs.getfdata()[0] == rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getfdata()[0] == rhs.getulldata()[0];
		else if (rhs.getcdata()) return lhs.getfdata()[0] == rhs.getcdata()[0];
	}
	else if (lhs.getldata()) {
		if (rhs.getidata()) return lhs.getldata()[0] == rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getldata()[0] == rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getldata()[0] == rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getldata()[0] == rhs.getfdata()[0];
		else if (rhs.getsdata()) {
			int k = ::len(rhs.getsdata());
			for (int i = 0; i < ::len(rhs.getsdata()); i++) if (rhs.getsdata()[i] == lhs.getldata()[0]) k--;
			return !(k == ::len(rhs.getsdata()));
		}
		else if (rhs.getlldata()) return lhs.getldata()[0] == rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getldata()[0] == rhs.getulldata()[0];
		else if (rhs.getcdata()) return lhs.getldata()[0] == rhs.getcdata()[0];
	}
	else if (lhs.getlldata()) {
		if (rhs.getidata()) return lhs.getlldata()[0] == rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getlldata()[0] == rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getlldata()[0] == rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getlldata()[0] == rhs.getfdata()[0];
		else if (rhs.getsdata()) {
			int k = ::len(rhs.getsdata());
			for (int i = 0; i < ::len(rhs.getsdata()); i++) if (rhs.getsdata()[i] == lhs.getlldata()[0]) k--;
			return !(k == ::len(rhs.getsdata()));
		}
		else if (rhs.getlldata()) return lhs.getlldata()[0] == rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getlldata()[0] == rhs.getulldata()[0];
		else if (rhs.getcdata()) return lhs.getlldata()[0] == rhs.getcdata()[0];
	}
	else if (lhs.getulldata()) {
		if (rhs.getidata()) return lhs.getulldata()[0] == rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getulldata()[0] == rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getulldata()[0] == rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getulldata()[0] == rhs.getfdata()[0];
		else if (rhs.getsdata()) {
			int k = ::len(rhs.getsdata());
			for (int i = 0; i < ::len(rhs.getsdata()); i++) if (rhs.getsdata()[i] == lhs.getulldata()[0]) k--;
			return !(k == ::len(rhs.getsdata()));
		}
		else if (rhs.getlldata()) return lhs.getulldata()[0] == rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getulldata()[0] == rhs.getulldata()[0];
		else if (rhs.getcdata()) return lhs.getulldata()[0] == rhs.getcdata()[0];
	}
	else if (lhs.getsdata()) {
		if (rhs.getidata()) {
			int k = ::len(lhs.getsdata());
			for (int i = 0; i < ::len(lhs.getsdata()); i++) if (rhs.getidata()[0] == lhs.getsdata()[i]) k--;
			return !(k == ::len(lhs.getsdata()));
		}
		else if (rhs.getldata()) {
			int k = ::len(lhs.getsdata());
			for (int i = 0; i < ::len(lhs.getsdata()); i++) if (rhs.getldata()[0] == lhs.getsdata()[i]) k--;
			return !(k == ::len(lhs.getsdata()));
		}
		else if (rhs.getddata()) {
			int k = ::len(lhs.getsdata());
			for (int i = 0; i < ::len(lhs.getsdata()); i++) if (rhs.getddata()[0] == lhs.getsdata()[i]) k--;
			return !(k == ::len(lhs.getsdata()));
		}
		else if (rhs.getfdata()) {
			int k = ::len(lhs.getsdata());
			for (int i = 0; i < ::len(lhs.getsdata()); i++) if (rhs.getfdata()[0] == lhs.getsdata()[i]) k--;
			return !(k == ::len(lhs.getsdata()));
		}
		else if (rhs.getsdata()) {
			if (::len(rhs.getsdata()) > ::len(lhs.getsdata()) || ::len(lhs.getsdata()) > ::len(rhs.getsdata())) return 0;
			int k = ::len(rhs.getsdata());
			for (int i = 0; i < ::len(rhs.getsdata()); i++) if (rhs.getsdata()[i] == lhs.getsdata()[i]) k--;
			return !(k == ::len(rhs.getsdata()));
		}
		else if (rhs.getlldata()) {
			int k = ::len(lhs.getsdata());
			for (int i = 0; i < ::len(lhs.getsdata()); i++) if (rhs.getlldata()[0] == lhs.getsdata()[i]) k--;
			return !(k == ::len(lhs.getsdata()));
		}
		else if (rhs.getulldata()) {
			int k = ::len(lhs.getsdata());
			for (int i = 0; i < ::len(lhs.getsdata()); i++) if (rhs.getulldata()[0] == lhs.getsdata()[i]) k--;
			return !(k == ::len(lhs.getsdata()));
		}
		else if (rhs.getcdata()) return rhs.getcdata()[0] == lhs.getsdata()[0];
	}
	else if (lhs.getcdata()) {
		if (rhs.getidata()) return rhs.getidata()[0] == lhs.getcdata()[0];
		else if (rhs.getldata()) return rhs.getldata()[0] == lhs.getcdata()[0];
		else if (rhs.getddata()) return rhs.getddata()[0] == lhs.getcdata()[0];
		else if (rhs.getfdata()) return rhs.getfdata()[0] == lhs.getcdata()[0];
		else if (rhs.getcdata()) return rhs.getcdata()[0] == lhs.getcdata()[0];
		else if (rhs.getlldata()) return rhs.getlldata()[0] == lhs.getcdata()[0];
		else if (rhs.getulldata()) return rhs.getulldata()[0] == lhs.getcdata()[0];
		else if (rhs.getsdata()) return lhs.getcdata()[0] == rhs.getsdata()[0];
	} return 0;
}
// overloading the != operator
bool operator!=(const var& lhs, const var& rhs)
{
	if (lhs.getidata()) {
		if (rhs.getidata()) return lhs.getidata()[0] != rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getidata()[0] != rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getidata()[0] != rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getidata()[0] != rhs.getfdata()[0];
		else if (rhs.getsdata()) {
			int k = ::len(rhs.getsdata());
			for (int i = 0; i < ::len(rhs.getsdata()); i++) if (rhs.getsdata()[i] != lhs.getidata()[0]) k--;
			return !(k == ::len(rhs.getsdata()));
		}
		else if (rhs.getlldata()) return lhs.getidata()[0] != rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getidata()[0] != rhs.getulldata()[0];
		else if (rhs.getcdata()) return lhs.getidata()[0] != rhs.getcdata()[0];
	}
	else if (lhs.getddata()) {
		if (rhs.getidata()) return lhs.getddata()[0] != rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getddata()[0] != rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getddata()[0] != rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getddata()[0] != rhs.getfdata()[0];
		else if (rhs.getsdata()) {
			int k = ::len(rhs.getsdata());
			for (int i = 0; i < ::len(rhs.getsdata()); i++) if (rhs.getsdata()[i] != lhs.getddata()[0]) k--;
			return !(k == ::len(rhs.getsdata()));
		}
		else if (rhs.getlldata()) return lhs.getddata()[0] != rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getddata()[0] != rhs.getulldata()[0];
		else if (rhs.getcdata()) return lhs.getddata()[0] != rhs.getcdata()[0];
	}
	else if (lhs.getfdata()) {
		if (rhs.getidata()) return lhs.getfdata()[0] != rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getfdata()[0] != rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getfdata()[0] != rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getfdata()[0] != rhs.getfdata()[0];
		else if (rhs.getsdata()) {
			int k = ::len(rhs.getsdata());
			for (int i = 0; i < ::len(rhs.getsdata()); i++) if (rhs.getsdata()[i] != lhs.getfdata()[0]) k--;
			return !(k == ::len(rhs.getsdata()));
		}
		else if (rhs.getlldata()) return lhs.getfdata()[0] != rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getfdata()[0] != rhs.getulldata()[0];
		else if (rhs.getcdata()) return lhs.getfdata()[0] != rhs.getcdata()[0];
	}
	else if (lhs.getldata()) {
		if (rhs.getidata()) return lhs.getldata()[0] != rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getldata()[0] != rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getldata()[0] != rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getldata()[0] != rhs.getfdata()[0];
		else if (rhs.getsdata()) {
			int k = ::len(rhs.getsdata());
			for (int i = 0; i < ::len(rhs.getsdata()); i++) if (rhs.getsdata()[i] != lhs.getldata()[0]) k--;
			return !(k == ::len(rhs.getsdata()));
		}
		else if (rhs.getlldata()) return lhs.getldata()[0] != rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getldata()[0] != rhs.getulldata()[0];
		else if (rhs.getcdata()) return lhs.getldata()[0] != rhs.getcdata()[0];
	}
	else if (lhs.getlldata()) {
		if (rhs.getidata()) return lhs.getlldata()[0] != rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getlldata()[0] != rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getlldata()[0] != rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getlldata()[0] != rhs.getfdata()[0];
		else if (rhs.getsdata()) {
			int k = ::len(rhs.getsdata());
			for (int i = 0; i < ::len(rhs.getsdata()); i++) if (rhs.getsdata()[i] != lhs.getlldata()[0]) k--;
			return !(k == ::len(rhs.getsdata()));
		}
		else if (rhs.getlldata()) return lhs.getlldata()[0] != rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getlldata()[0] != rhs.getulldata()[0];
		else if (rhs.getcdata()) return lhs.getlldata()[0] != rhs.getcdata()[0];
	}
	else if (lhs.getulldata()) {
		if (rhs.getidata()) return lhs.getulldata()[0] != rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getulldata()[0] != rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getulldata()[0] != rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getulldata()[0] != rhs.getfdata()[0];
		else if (rhs.getsdata()) {
			int k = ::len(rhs.getsdata());
			for (int i = 0; i < ::len(rhs.getsdata()); i++) if (rhs.getsdata()[i] != lhs.getulldata()[0]) k--;
			return !(k == ::len(rhs.getsdata()));
		}
		else if (rhs.getlldata()) return lhs.getulldata()[0] != rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getulldata()[0] != rhs.getulldata()[0];
		else if (rhs.getcdata()) return lhs.getulldata()[0] != rhs.getcdata()[0];
	}
	else if (lhs.getsdata()) {
		if (rhs.getidata()) {
			int k = ::len(lhs.getsdata());
			for (int i = 0; i < ::len(lhs.getsdata()); i++) if (rhs.getidata()[0] != lhs.getsdata()[i]) k--;
			return k == ::len(lhs.getsdata());
		}
		else if (rhs.getldata()) {
			int k = ::len(lhs.getsdata());
			for (int i = 0; i < ::len(lhs.getsdata()); i++) if (rhs.getldata()[0] != lhs.getsdata()[i]) k--;
			return k == ::len(lhs.getsdata());
		}
		else if (rhs.getddata()) {
			int k = ::len(lhs.getsdata());
			for (int i = 0; i < ::len(lhs.getsdata()); i++) if (rhs.getddata()[0] != lhs.getsdata()[i]) k--;
			return k == ::len(lhs.getsdata());
		}
		else if (rhs.getfdata()) {
			int k = ::len(lhs.getsdata());
			for (int i = 0; i < ::len(lhs.getsdata()); i++) if (rhs.getfdata()[0] != lhs.getsdata()[i]) k--;
			return k == ::len(lhs.getsdata());
		}
		else if (rhs.getsdata()) {
			if (::len(rhs.getsdata()) > ::len(lhs.getsdata()) || ::len(lhs.getsdata()) > ::len(rhs.getsdata())) return 1;
			int k = ::len(rhs.getsdata());
			for (int i = 0; i < ::len(rhs.getsdata()); i++) if (rhs.getsdata()[i] != lhs.getsdata()[i]) k--;
			return !(k == ::len(rhs.getsdata()));
		}
		else if (rhs.getlldata()) {
			int k = ::len(lhs.getsdata());
			for (int i = 0; i < ::len(lhs.getsdata()); i++) if (rhs.getlldata()[0] != lhs.getsdata()[i]) k--;
			return k == ::len(lhs.getsdata());
		}
		else if (rhs.getulldata()) {
			int k = ::len(lhs.getsdata());
			for (int i = 0; i < ::len(lhs.getsdata()); i++) if (rhs.getulldata()[0] != lhs.getsdata()[i]) k--;
			return k == ::len(lhs.getsdata());
		}
		else if (rhs.getcdata()) return rhs.getcdata()[0] != lhs.getsdata()[0];
	}
	else if (lhs.getcdata()) {
		if (rhs.getidata()) return rhs.getidata()[0] != lhs.getcdata()[0];
		else if (rhs.getldata()) return rhs.getldata()[0] != lhs.getcdata()[0];
		else if (rhs.getddata()) return rhs.getddata()[0] != lhs.getcdata()[0];
		else if (rhs.getfdata()) return rhs.getfdata()[0] != lhs.getcdata()[0];
		else if (rhs.getcdata()) return rhs.getcdata()[0] != lhs.getcdata()[0];
		else if (rhs.getlldata()) return rhs.getlldata()[0] != lhs.getcdata()[0];
		else if (rhs.getulldata()) return rhs.getulldata()[0] != lhs.getcdata()[0];
		else if (rhs.getsdata()) return lhs.getcdata()[0] != rhs.getsdata()[0];
	} return 0;
}
// overloading the > operator
bool operator>(const var& lhs, const var& rhs)
{
	if (lhs.getidata()) {
		if (rhs.getidata()) return lhs.getidata()[0] > rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getidata()[0] > rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getidata()[0] > rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getidata()[0] > rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getidata()[0] > rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getidata()[0] > rhs.getulldata()[0];
	}
	else if (lhs.getddata()) {
		if (rhs.getidata()) return lhs.getddata()[0] > rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getddata()[0] > rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getddata()[0] > rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getddata()[0] > rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getddata()[0] > rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getddata()[0] > rhs.getulldata()[0];
	}
	else if (lhs.getfdata()) {
		if (rhs.getidata()) return lhs.getfdata()[0] > rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getfdata()[0] > rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getfdata()[0] > rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getfdata()[0] > rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getfdata()[0] > rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getfdata()[0] > rhs.getulldata()[0];
	}
	else if (lhs.getldata()) {
		if (rhs.getidata()) return lhs.getldata()[0] > rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getldata()[0] > rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getldata()[0] > rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getldata()[0] > rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getldata()[0] > rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getldata()[0] > rhs.getulldata()[0];
	}
	else if (lhs.getlldata()) {
		if (rhs.getidata()) return lhs.getlldata()[0] > rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getlldata()[0] > rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getlldata()[0] > rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getlldata()[0] > rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getlldata()[0] > rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getlldata()[0] > rhs.getulldata()[0];
	}
	else if (lhs.getulldata()) {
		if (rhs.getidata()) return lhs.getulldata()[0] > rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getulldata()[0] > rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getulldata()[0] > rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getulldata()[0] > rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getulldata()[0] > rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getulldata()[0] > rhs.getulldata()[0];
	} return 0;
}
// overloading the < operator
bool operator<(const var& lhs, const var& rhs)
{
	return operator>(rhs, lhs);
}
// overloading the >= operator
bool operator>=(const var& lhs, const var& rhs)
{
	if (lhs.getidata()) {
		if (rhs.getidata()) return lhs.getidata()[0] >= rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getidata()[0] >= rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getidata()[0] >= rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getidata()[0] >= rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getidata()[0] >= rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getidata()[0] >= rhs.getulldata()[0];
	}
	else if (lhs.getddata()) {
		if (rhs.getidata()) return lhs.getddata()[0] >= rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getddata()[0] >= rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getddata()[0] >= rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getddata()[0] >= rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getddata()[0] >= rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getddata()[0] >= rhs.getulldata()[0];
	}
	else if (lhs.getfdata()) {
		if (rhs.getidata()) return lhs.getfdata()[0] >= rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getfdata()[0] >= rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getfdata()[0] >= rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getfdata()[0] >= rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getfdata()[0] >= rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getfdata()[0] >= rhs.getulldata()[0];
	}
	else if (lhs.getldata()) {
		if (rhs.getidata()) return lhs.getldata()[0] >= rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getldata()[0] >= rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getldata()[0] >= rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getldata()[0] >= rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getldata()[0] >= rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getldata()[0] >= rhs.getulldata()[0];
	}
	else if (lhs.getlldata()) {
		if (rhs.getidata()) return lhs.getlldata()[0] >= rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getlldata()[0] >= rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getlldata()[0] >= rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getlldata()[0] >= rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getlldata()[0] >= rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getlldata()[0] >= rhs.getulldata()[0];
	}
	else if (lhs.getulldata()) {
		if (rhs.getidata()) return lhs.getulldata()[0] >= rhs.getidata()[0];
		else if (rhs.getldata()) return lhs.getulldata()[0] >= rhs.getldata()[0];
		else if (rhs.getddata()) return lhs.getulldata()[0] >= rhs.getddata()[0];
		else if (rhs.getfdata()) return lhs.getulldata()[0] >= rhs.getfdata()[0];
		else if (rhs.getlldata()) return lhs.getulldata()[0] >= rhs.getlldata()[0];
		else if (rhs.getulldata()) return lhs.getulldata()[0] >= rhs.getulldata()[0];
	} return 0;
}
// overloading the <= operator
bool operator<=(const var& lhs, const var& rhs)
{
	return operator>=(rhs, lhs);
}
// gets idata
const int* var::getidata() const
{
	return (idata != 0) ? idata : 0;
}
// gets cdata
const char* var::getcdata() const
{
	return (cdata != 0) ? cdata : 0;
}
// gets fdata
const float* var::getfdata() const
{
	return (fdata != 0) ? fdata : 0;
}
// gets ddata
const double* var::getddata() const
{
	return (ddata != 0) ? ddata : 0;
}
// gets bdata
const bool* var::getbdata() const
{
	return (bdata != 0) ? bdata : 0;
}
// gets ldata
const long int* var::getldata() const
{
	return (ldata != 0) ? ldata : 0;
}
// gets lldata
const long long int* var::getlldata() const
{
	return (lldata != 0) ? lldata : 0;
}
// gets ulldata
const unsigned long long int* var::getulldata() const
{
	return (ulldata != 0) ? ulldata : 0;
}
// gets sdata
const char* var::getsdata() const
{
	return (sdata != 0) ? sdata : 0;
}
// overloading the += operator
var& var::operator+=(const var& rhs)
{
	if (idata) {
		if (rhs.idata) idata[0] += rhs.idata[0];
		else if (rhs.ldata) idata[0] += rhs.ldata[0];
		else if (rhs.ddata) idata[0] += rhs.ddata[0];
		else if (rhs.fdata) idata[0] += rhs.fdata[0];
		else if (rhs.lldata) idata[0] += rhs.lldata[0];
		else if (rhs.ulldata) idata[0] += rhs.ulldata[0];
	}
	else if (ddata) {
		if (rhs.idata) ddata[0] += rhs.idata[0];
		else if (rhs.ldata) ddata[0] += rhs.ldata[0];
		else if (rhs.ddata) ddata[0] += rhs.ddata[0];
		else if (rhs.fdata) ddata[0] += rhs.fdata[0];
		else if (rhs.lldata) ddata[0] += rhs.lldata[0];
		else if (rhs.ulldata) ddata[0] += rhs.ulldata[0];
	}
	else if (fdata) {
		if (rhs.idata) fdata[0] += rhs.idata[0];
		else if (rhs.ldata) fdata[0] += rhs.ldata[0];
		else if (rhs.ddata) fdata[0] += rhs.ddata[0];
		else if (rhs.fdata) fdata[0] += rhs.fdata[0];
		else if (rhs.lldata) fdata[0] += rhs.lldata[0];
		else if (rhs.ulldata) fdata[0] += rhs.ulldata[0];
	}
	else if (ldata) {
		if (rhs.idata) ldata[0] += rhs.idata[0];
		else if (rhs.ldata) ldata[0] += rhs.ldata[0];
		else if (rhs.ddata) ldata[0] += rhs.ddata[0];
		else if (rhs.fdata) ldata[0] += rhs.fdata[0];
		else if (rhs.lldata) ldata[0] += rhs.lldata[0];
		else if (rhs.ulldata) ldata[0] += rhs.ulldata[0];
	}
	else if (lldata) {
		if (rhs.idata) lldata[0] += rhs.idata[0];
		else if (rhs.ldata) lldata[0] += rhs.ldata[0];
		else if (rhs.ddata) lldata[0] += rhs.ddata[0];
		else if (rhs.fdata) lldata[0] += rhs.fdata[0];
		else if (rhs.lldata) lldata[0] += rhs.lldata[0];
		else if (rhs.ulldata) lldata[0] += rhs.ulldata[0];
	}
	else if (ulldata) {
		if (rhs.idata) ulldata[0] += rhs.idata[0];
		else if (rhs.ldata) ulldata[0] += rhs.ldata[0];
		else if (rhs.ddata) ulldata[0] += rhs.ddata[0];
		else if (rhs.fdata) ulldata[0] += rhs.fdata[0];
		else if (rhs.lldata) ulldata[0] += rhs.lldata[0];
		else if (rhs.ulldata) ulldata[0] += rhs.ulldata[0];
	}
	else if (sdata) {
		if (rhs.cdata) {
			char* new_data = sdata;
			new_data[::len(sdata)] = rhs.cdata[0];
			new_data[::len(sdata) + 1] = 0;
			sdata = new_data;
		}
		else if (rhs.sdata) for (int i = 0; i < ::len(rhs.sdata); i++) this->operator+=(rhs.sdata[i]);
	} return *this;
}
// overloading the *= operator
var& var::operator*=(const var& rhs)
{
	if (idata) {
		if (rhs.idata) idata[0] *= rhs.idata[0];
		else if (rhs.ldata) idata[0] *= rhs.ldata[0];
		else if (rhs.ddata) idata[0] *= rhs.ddata[0];
		else if (rhs.fdata) idata[0] *= rhs.fdata[0];
		else if (rhs.lldata) idata[0] *= rhs.lldata[0];
		else if (rhs.ulldata) idata[0] *= rhs.ulldata[0];
	}
	else if (ddata) {
		if (rhs.idata) ddata[0] *= rhs.idata[0];
		else if (rhs.ldata) ddata[0] *= rhs.ldata[0];
		else if (rhs.ddata) ddata[0] *= rhs.ddata[0];
		else if (rhs.fdata) ddata[0] *= rhs.fdata[0];
		else if (rhs.lldata) ddata[0] *= rhs.lldata[0];
		else if (rhs.ulldata) ddata[0] *= rhs.ulldata[0];
	}
	else if (fdata) {
		if (rhs.idata) fdata[0] *= rhs.idata[0];
		else if (rhs.ldata) fdata[0] *= rhs.ldata[0];
		else if (rhs.ddata) fdata[0] *= rhs.ddata[0];
		else if (rhs.fdata) fdata[0] *= rhs.fdata[0];
		else if (rhs.lldata) fdata[0] *= rhs.lldata[0];
		else if (rhs.ulldata) fdata[0] *= rhs.ulldata[0];
	}
	else if (ldata) {
		if (rhs.idata) ldata[0] *= rhs.idata[0];
		else if (rhs.ldata) ldata[0] *= rhs.ldata[0];
		else if (rhs.ddata) ldata[0] *= rhs.ddata[0];
		else if (rhs.fdata) ldata[0] *= rhs.fdata[0];
		else if (rhs.lldata) ldata[0] *= rhs.lldata[0];
		else if (rhs.ulldata) ldata[0] *= rhs.ulldata[0];
	}
	else if (lldata) {
		if (rhs.idata) lldata[0] *= rhs.idata[0];
		else if (rhs.ldata) lldata[0] *= rhs.ldata[0];
		else if (rhs.ddata) lldata[0] *= rhs.ddata[0];
		else if (rhs.fdata) lldata[0] *= rhs.fdata[0];
		else if (rhs.lldata) lldata[0] *= rhs.lldata[0];
		else if (rhs.ulldata) lldata[0] *= rhs.ulldata[0];
	}
	else if (ulldata) {
		if (rhs.idata) ulldata[0] *= rhs.idata[0];
		else if (rhs.ldata) ulldata[0] *= rhs.ldata[0];
		else if (rhs.ddata) ulldata[0] *= rhs.ddata[0];
		else if (rhs.fdata) ulldata[0] *= rhs.fdata[0];
		else if (rhs.lldata) ulldata[0] *= rhs.lldata[0];
		else if (rhs.ulldata) ulldata[0] *= rhs.ulldata[0];
	} return *this;
}
// overloading the -= operator
var& var::operator-=(const var& rhs)
{
	if (idata) {
		if (rhs.idata) idata[0] -= rhs.idata[0];
		else if (rhs.ldata) idata[0] -= rhs.ldata[0];
		else if (rhs.ddata) idata[0] -= rhs.ddata[0];
		else if (rhs.fdata) idata[0] -= rhs.fdata[0];
		else if (rhs.lldata) idata[0] -= rhs.lldata[0];
		else if (rhs.ulldata) idata[0] -= rhs.ulldata[0];
	}
	else if (ddata) {
		if (rhs.idata) ddata[0] -= rhs.idata[0];
		else if (rhs.ldata) ddata[0] -= rhs.ldata[0];
		else if (rhs.ddata) ddata[0] -= rhs.ddata[0];
		else if (rhs.fdata) ddata[0] -= rhs.fdata[0];
		else if (rhs.lldata) ddata[0] -= rhs.lldata[0];
		else if (rhs.ulldata) ddata[0] -= rhs.ulldata[0];
	}
	else if (fdata) {
		if (rhs.idata) fdata[0] -= rhs.idata[0];
		else if (rhs.ldata) fdata[0] -= rhs.ldata[0];
		else if (rhs.ddata) fdata[0] -= rhs.ddata[0];
		else if (rhs.fdata) fdata[0] -= rhs.fdata[0];
		else if (rhs.lldata) fdata[0] -= rhs.lldata[0];
		else if (rhs.ulldata) fdata[0] -= rhs.ulldata[0];
	}
	else if (ldata) {
		if (rhs.idata) ldata[0] -= rhs.idata[0];
		else if (rhs.ldata) ldata[0] -= rhs.ldata[0];
		else if (rhs.ddata) ldata[0] -= rhs.ddata[0];
		else if (rhs.fdata) ldata[0] -= rhs.fdata[0];
		else if (rhs.lldata) ldata[0] -= rhs.lldata[0];
		else if (rhs.ulldata) ldata[0] -= rhs.ulldata[0];
	}
	else if (lldata) {
		if (rhs.idata) lldata[0] -= rhs.idata[0];
		else if (rhs.ldata) lldata[0] -= rhs.ldata[0];
		else if (rhs.ddata) lldata[0] -= rhs.ddata[0];
		else if (rhs.fdata) lldata[0] -= rhs.fdata[0];
		else if (rhs.lldata) lldata[0] -= rhs.lldata[0];
		else if (rhs.ulldata) lldata[0] -= rhs.ulldata[0];
	}
	else if (ulldata) {
		if (rhs.idata) ulldata[0] -= rhs.idata[0];
		else if (rhs.ldata) ulldata[0] -= rhs.ldata[0];
		else if (rhs.ddata) ulldata[0] -= rhs.ddata[0];
		else if (rhs.fdata) ulldata[0] -= rhs.fdata[0];
		else if (rhs.lldata) ulldata[0] -= rhs.lldata[0];
		else if (rhs.ulldata) ulldata[0] -= rhs.ulldata[0];
	} return *this;
}
// copy operator for var
var& var::operator=(const var& rhs)
{
	if (rhs.getidata()) {
		idata = new int[1];
		idata[0] = rhs.getidata()[0];
		ddata = 0;
		fdata = 0;
		ldata = 0;
		cdata = 0;
		bdata = 0;
		sdata = 0;
		lldata = 0;
		ulldata = 0;
	}
	else if (rhs.getddata()) {
		ddata = new double[1];
		ddata[0] = rhs.getddata()[0];
		idata = 0;
		fdata = 0;
		ldata = 0;
		cdata = 0;
		bdata = 0;
		sdata = 0;
		lldata = 0;
		ulldata = 0;
	}
	else if (rhs.getfdata()) {
		fdata = new float[1];
		fdata[0] = rhs.getfdata()[0];
		ddata = 0;
		idata = 0;
		ldata = 0;
		cdata = 0;
		bdata = 0;
		sdata = 0;
		lldata = 0;
		ulldata = 0;
	}
	else if (rhs.getldata()) {
		ldata = new long[1];
		ldata[0] = rhs.getldata()[0];
		ddata = 0;
		fdata = 0;
		idata = 0;
		cdata = 0;
		bdata = 0;
		sdata = 0;
		lldata = 0;
		ulldata = 0;
	}
	else if (rhs.getlldata()) {
		lldata = new long long int[1];
		lldata[0] = rhs.getlldata()[0];
		ddata = 0;
		fdata = 0;
		ldata = 0;
		cdata = 0;
		bdata = 0;
		sdata = 0;
		idata = 0;
		ulldata = 0;
	}
	else if (rhs.getulldata()) {
		ulldata = new unsigned long long int[1];
		ulldata[0] = rhs.getulldata()[0];
		ddata = 0;
		fdata = 0;
		ldata = 0;
		cdata = 0;
		bdata = 0;
		idata = 0;
		sdata = 0;
		lldata = 0;
	}
	else if (rhs.getsdata()) {
		sdata = new char[len(rhs.getsdata()) + 1];
		for (int i = 0; i < len(rhs.getsdata()); i++) sdata[i] = rhs.getsdata()[i];
		sdata[len(rhs.getsdata())] = '\0';
		ddata = 0;
		fdata = 0;
		ldata = 0;
		cdata = 0;
		bdata = 0;
		idata = 0;
		lldata = 0;
		ulldata = 0;
	}
	else if (rhs.getcdata()) {
		cdata = new char[1];
		cdata[0] = rhs.getcdata()[0];
		ddata = 0;
		fdata = 0;
		ldata = 0;
		bdata = 0;
		idata = 0;
		lldata = 0;
		ulldata = 0;
		sdata = 0;
	} return *this;
}
// gets single char from sdata
char& var::operator[](int pos)
{
	if (sdata) return sdata[pos];
	else {
		*this = "";
		return sdata[0];
	}
}
// overloading the output operator
inline std::ostream& operator<<(std::ostream& os, const var& val)
{
	if (val.cdata) os << val.cdata[0];
	else if (val.ddata) os << val.ddata[0];
	else if (val.idata) os << val.idata[0];
	else if (val.fdata) os << val.fdata[0];
	else if (val.bdata) os << val.bdata[0];
	else if (val.ldata) os << val.ldata[0];
	else if (val.sdata) os << val.sdata;
	else if (val.lldata) os << val.lldata[0];
	else if (val.ulldata) os << val.ulldata[0];
	return os;
}
// overloading the /= operator
var& var::operator/=(const var& rhs)
{
	if (idata) {
		if (rhs.idata) idata[0] /= rhs.idata[0];
		else if (rhs.ldata) idata[0] /= rhs.ldata[0];
		else if (rhs.ddata) idata[0] /= rhs.ddata[0];
		else if (rhs.fdata) idata[0] /= rhs.fdata[0];
		else if (rhs.lldata) idata[0] /= rhs.lldata[0];
		else if (rhs.ulldata) idata[0] /= rhs.ulldata[0];
	}
	else if (ddata) {
		if (rhs.idata) ddata[0] /= rhs.idata[0];
		else if (rhs.ldata) ddata[0] /= rhs.ldata[0];
		else if (rhs.ddata) ddata[0] /= rhs.ddata[0];
		else if (rhs.fdata) ddata[0] /= rhs.fdata[0];
		else if (rhs.lldata) ddata[0] /= rhs.lldata[0];
		else if (rhs.ulldata) ddata[0] /= rhs.ulldata[0];
	}
	else if (fdata) {
		if (rhs.idata) fdata[0] /= rhs.idata[0];
		else if (rhs.ldata) fdata[0] /= rhs.ldata[0];
		else if (rhs.ddata) fdata[0] /= rhs.ddata[0];
		else if (rhs.fdata) fdata[0] /= rhs.fdata[0];
		else if (rhs.lldata) fdata[0] /= rhs.lldata[0];
		else if (rhs.ulldata) fdata[0] /= rhs.ulldata[0];
	}
	else if (ldata) {
		if (rhs.idata) ldata[0] /= rhs.idata[0];
		else if (rhs.ldata) ldata[0] /= rhs.ldata[0];
		else if (rhs.ddata) ldata[0] /= rhs.ddata[0];
		else if (rhs.fdata) ldata[0] /= rhs.fdata[0];
		else if (rhs.lldata) ldata[0] /= rhs.lldata[0];
		else if (rhs.ulldata) ldata[0] /= rhs.ulldata[0];
	}
	else if (lldata) {
		if (rhs.idata) lldata[0] /= rhs.idata[0];
		else if (rhs.ldata) lldata[0] /= rhs.ldata[0];
		else if (rhs.ddata) lldata[0] /= rhs.ddata[0];
		else if (rhs.fdata) lldata[0] /= rhs.fdata[0];
		else if (rhs.lldata) lldata[0] /= rhs.lldata[0];
		else if (rhs.ulldata) lldata[0] /= rhs.ulldata[0];
	}
	else if (ulldata) {
		if (rhs.idata) ulldata[0] /= rhs.idata[0];
		else if (rhs.ldata) ulldata[0] /= rhs.ldata[0];
		else if (rhs.ddata) ulldata[0] /= rhs.ddata[0];
		else if (rhs.fdata) ulldata[0] /= rhs.fdata[0];
		else if (rhs.lldata) ulldata[0] /= rhs.lldata[0];
		else if (rhs.ulldata) ulldata[0] /= rhs.ulldata[0];
	} return *this;
}
// is a calculator
float Math::calc(float x, char sign, float y)
{
	if (sign == '*') return x * y;
	else if (sign == '/') return x / y;
	else if (sign == '+') return x + y;
	else if (sign == '-') return x - y;
	else if (sign == '^') {
		if (y == 0) return 1.0;
		float a = x;
		for (int i = 1; i < (int)y; i++) x *= a;
		return x;
	}
	else return 0.0;
}
// returns the absolute value of num
int Math::abs(int num)
{
	return (num < 0) ? -num : num;
}
// ends a program
int endp(int val, int flush = 0)
{
	std::cout << "Press enter to continue...";
	if (flush > 0) {
		std::cin.clear();
		std::cin.get();
	}
	std::cin.ignore();
	exit(val);
	return (val);
}
