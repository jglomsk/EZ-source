/*
* Built with <3 on MS VSC Insiders.
* Distribution of this library is suggested.
* That being said, TELL YOUR FRIENDS ABOUT THIS!!
* Unless you have no friends. Then just use it yourself.
* This library is under no license or warranty.
* Basically, if you wish to add to this file, you can.
* If you believe you can make contributions, contact me at:
* jglomski316@gmail.com
* Docs for each function are found right above the function.
* Compile your code using this file with the following command (on mac or linux):
* g++ <yourfilename.cpp>
* Simply run your code with:
* ./<youroutfile>
* And now for a hierarchy of what my classes look like graphically.
*        |----------Global Namespace----|
*        |                |       |     |
*        |                |       |     |
*    awesome but         var     swm  hashmap
* random functions        |\      /\
*                         | \    /  \
*                       None \  /    \
*                            List   String
*/
#ifndef MERE_HPP
#define MERE_HPP

#include <iostream>
#include <cstdlib>
#include <climits>
#include <ctime>
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
// similar to vector, short for swag money
template <class T, int how_big = 1>
class swm {
private:
	T* data;
	int len;
	bool snapped;
	bool formatted;
	const static int permalen = how_big;
public:
	// constructor
	swm();
	// get at pos
	T& operator[](int pos);
	const T operator[](int pos) const;
	T& at(int pos);
	int index(T to_get);
	T& back();
	T& front();
	// sizes
	int size();
	int length();
	const int length() const;
	const static int permalength();
	int max_size();
	// inserting
	void insert(int at_this_spot, T put_this_in);
	void snap();
	void bandage();
	void reserve(int new_size = 1);
	void resize(int new_size);
	void reverse();
	swm& operator+=(T rhs);
	void push_back(T elem);
	template <int bigness> void insert(int at_this_spot, swm<T, bigness>& to_insert);
	// checking
	bool empty();
	bool full();
	const bool is_formatted() const;
	int rfind(T to_find);
	int find(T to_find);
	int count(T x);
	// swapping
	template <int bigness> void swap(swm<T, bigness>& with_what);
	// erasing
	void clear();
	void erase();
	void shrink();
	void remchunk(int begin, int end, int skip = 1);
	void restart();
	T* slice(int begin, int end);
	// random
	void format();
	// getting
	T* get_alloc();
};
// void or NULL class
class None : public var {
public:
	// constructor
	None() : var(0) {}
};
// hash map, use keys to access vals
class hashmap {
private:
	var* values;
	int* keys;
	int len;
public:
	// constructor
	hashmap();
	// replacing
	void replace(int key, const var& to_in);
	// getting
	int getkey(const var& val);
	var getval(int key);
	// randomizing
	void randomize();
	// adds a val to the list
	void push_in(const var& val);
};
// the famous String class
class String : public swm<char> {
public:
	// constructor
	String(const char* val = 0);
	// checking
	bool contains(const char* thing);
	int totspaces();
	int totletters();
	// operators
	String& operator+=(const String& rhs);
	// changing
	void upper();
	void lower();
};
// similar to Python's list
class List : public swm<var> {};
// for array funcs
namespace Arrays {
	template <typename T> T* rowarr(T _array[][16], int row);
	template <typename T, unsigned S> int lenarr(const T(&v)[S]);
	int rosum(int _array[][16], int row);
	template <typename T> const static void remcol(T _array[][16], int col);
	bool isdiv(int _array[][16], int row);
	bool to_be_lab(bool _array[][9], int row, int col);
	template <typename T> bool contains(T _array[], T to_check);
	template <typename T> T* flattenarr(T _array[][16]);
	int arradd(int _array[]);
	template <typename T, unsigned S> int index(T(&_array)[S], T _search);
	template <typename T, unsigned S> int count(T(&_array)[S], T _search);
	template <typename T, unsigned S> const static void reversearr(T(&_array)[S]);
	template <typename T, unsigned S> T pop(T(&v)[S], int elem = S);
	template <typename T> const static void remchunk(T _array[], int begin, int end, int skip = 1);
	template <unsigned S> const static void fillint(int(&v)[S], int skip = 1);
	template <typename T> T* slice(T _array[], int begin, int end);
	template <typename T> T begi(T _array[]);
	template <typename T, unsigned S> bool equals(T(&_array)[S], T(&_other)[S]);
	template <typename T> const static void setelem(T _array[], int elem, T new_val);
	template <typename T> T getelem(T _array[], int elem);
	template <typename T, unsigned S> bool every(T(&_array)[S]);
	template <unsigned S> const static void sorti(int(&_array)[S]);
	template <typename T, unsigned S> T last(T(&_thing)[S]);
}
// for math funcs
namespace Math {
	int* range(int begin, int end);
	float calc(float x, char sign, float y);
	long int longconv(int to_convert);
	int abs(int num);
	int reciprocal(int num);
	void print_base(int val, unsigned base);
}
// returns an array of a specific row of any 2d array
template <typename T>
T* Arrays::rowarr(T _array[][16], int row)
{
	T *new_array = new T[16];
	if (row >= 16) return new_array;
	for (int n = 0, k = 0; k < 16; n++, k++) new_array[k] = _array[row][n];
	return new_array;
}
// returns the length of an array
template <typename T, unsigned S>
int Arrays::lenarr(const T(&v)[S])
{
	return S;
}
// overloading len
int len(const var& _thing)
{
	return 1;
}
// overloading len
template <class T, int how_big>
int len(const swm<T, how_big>& _thing)
{
	return _thing.length();
}
// gets len of anything until first null character
template <class T>
int len(T *_thing)
{
	for (int i = 0;; i++) if (_thing[i] == '\0' || _thing[i] == 0) return i;
}
// gets the sum of a row of an integer array
int Arrays::rosum(int _array[][16], int row)
{
	int k = 0;
	for (int n = 0; n < 16; n++) k += _array[row][n];
	return k;
}
// removes a column from any array
template <typename T>
const void Arrays::remcol(T _array[][16], int col)
{
	for (int i = 0; i < 16; i++) _array[i][col] = 0;
}
// prints a number in any base
void Math::print_base(int val, unsigned base)
{
	if (val < base || base <= 1) {
		std::cout << val;
		return;
	}
	int rem = val % base;
	print_base(val / base, base);
	std::cout << rem;
}
// flattens any array
template <typename T>
T* Arrays::flattenarr(T _array[][16])
{
	int k = 0;
	T *flattened_array = new T[256];
	for (int i = 0; i < 16; i++)
		for (int n = 0; n < 16; n++)
			flattened_array[k] = _array[i][n];
	k++;
	return flattened_array;
}
// checks to see if a row is diverse from the rest
bool Arrays::isdiv(int _array[][16], int row)
{
	for (int i = 0; i < 16; i++) if ((rosum(_array, row) == rosum(_array, i)) && i != row) return false;
	return true;
}
// crossword puzzle solution
bool Arrays::to_be_lab(bool _array[][9], int row, int col)
{
	return ((_array[row - 1][col] == false || _array[row][col - 1] == false) && _array[row][col] != false);
}
// checks to see if something is in an array
template <typename T>
bool Arrays::contains(T _array[], T to_check)
{
	for (int i = 0; i < ::len(_array); i++) if (_array[i] == to_check) return true;
	return false;
}
// returns the sum of the array
int Arrays::arradd(int _array[])
{
	int k = 0;
	for (int i = 0; _array[i] != 0; i++) k += _array[i];
	return k;
}
// shows the index of _search
template <typename T, unsigned S>
int Arrays::index(T(&_array)[S], T _search)
{
	for (int i = 0; i < S; i++) if (_array[i] == _search) return i;
	return -1;
}
// gets the amount of times _search appears in _array
template <typename T, unsigned S>
int Arrays::count(T(&_array)[S], T _search)
{
	int k = 0;
	for (int i = 0; i < S; i++) if (_array[i] == _search) k++;
	return k;
}
// reverses an array in place
template <typename T, unsigned S>
const static void Arrays::reversearr(T(&_array)[S])
{
	T *_reversed = new T[S];
	for (int i = 0, k = S - 1; i < S; i++, k--) _reversed[i] = _array[k];
	for (int i = 0; i < S; i++) _array[i] = _reversed[i];
	delete[] _reversed;
}
// makes an array from begin to end
int* Math::range(int begin, int end)
{
	int *_array = new int[Math::abs(end - begin)];
	for (int i = begin, k = 0; i <= end; i++, k++) _array[k] = i;
	return _array;
}
// returns and clears the last element or the index given
template <typename T, unsigned S>
T Arrays::pop(T(&v)[S], int elem)
{
	T pop_thing = v[elem - 1];
	delelem(v, elem - 1);
	return pop_thing;
}
// removes elements optionally skipping N amount of indexes
template <typename T>
const static void Arrays::remchunk(T _array[], int begin, int end, int skip)
{
	for (int i = begin; i <= end; i += skip) _array[i] = 0;
}
// fills an integer array with numbers
template <unsigned S>
const static void Arrays::fillint(int(&v)[S], int skip)
{
	for (int i = 0; i < S; i += skip) v[i] = i;
}
// slices an array from begin to end and returns it in array form
template <typename T>
T* Arrays::slice(T _array[], int begin, int end)
{
	T *new_array = new T[(end - begin) + 1];
	for (int i = begin, k = 0; i <= end; i++, k++) new_array[k] = _array[i];
	return new_array;
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
// smashing two strings into one
char* concat(const char* first, const char* second)
{
	char *new_array = new char[::len(first) + ::len(second)];
	for (int i = 0; i <= ::len(first); i++) new_array[i] = first[i];
	for (int i = 0, k = ::len(first); i <= ::len(second); i++, k++) new_array[k] = second[i];
	return new_array;
}
// returns the beginning of the array
template <typename T>
T Arrays::begi(T _array[])
{
	return _array[0];
}
// checks if two arrays are identical
template <typename T, unsigned S>
bool Arrays::equals(T(&_array)[S], T(&_other)[S])
{
	int k = 0;
	for (int i = 0; i <= S; i++) if (_array[i] == _other[i]) k++;
	return (k == S - 1) ? true : false;
}
// sets an array element to new_val
template <typename T>
const static void Arrays::setelem(T _array[], int elem, T new_val)
{
	_array[elem] = new_val;
}
// gets the element in _array
template <typename T>
T Arrays::getelem(T _array[], int elem)
{
	return _array[elem];
}
// converts an int to a long int
long int Math::longconv(int to_convert)
{
	return (long int)to_convert;
}
// returns true if every value in an array exists
template <typename T, unsigned S>
bool Arrays::every(T(&_array)[S])
{
	int k = 0;
	for (int i = 0; i < S; i++) if (_array[i]) k++;
	return (k == S - 1) ? true : false;
}
// sorts an integer array
template <unsigned S>
const static void Arrays::sorti(int(&_array)[S])
{
	for (int i = 0; i <= S; i++)
		for (int j = 0; j <= S - i; j++)
			if (_array[j] > _array[j + 1]) {
				int _other = _array[j];
				_array[j] = _array[j + 1];
				_array[j + 1] = _other;
			}
}
// returns the absolute value of num
int Math::abs(int num)
{
	return (num < 0) ? -num : num;
}
// makes something NULL
template <class T>
void nullify(T& to_null)
{
	to_null = 0;
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
// swaps a var with another
void swap(var& lhs, var& rhs)
{
	var y = rhs;
	rhs = lhs;
	lhs = y;
}
// swaps an swm with another
template <class T, int how_big, int bigness>
void swap(swm<T, how_big>& lhs, swm<T, bigness>& rhs)
{
	lhs.swap(rhs);
}
// returns the reciprocal of a number
int Math::reciprocal(int num)
{
	return -num;
}
// returns the last element
template <typename T, unsigned S>
T Arrays::last(T(&_thing)[S])
{
	return _thing[S - 1];
}
// returns the value of anything
template <class T>
T* memaddr(T &_thing)
{
	return &_thing;
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
// overloading the input operator
std::istream& operator>>(std::istream& in, None& rhs)
{
	return in;
}
// overloading the input operator
std::istream& operator>>(std::istream& in, String& rhs)
{
	in >> rhs.get_alloc();
	rhs = rhs.get_alloc();
	return in;
}
// default constructor
String::String(const char* val)
{
	if (val) {
		resize(::len(val));
		for (int i = 0; i < ::len(val); i++) at(i) = val[i];
	}
	else {
		resize(1);
		at(0) = 0;
	} format();
}
// reverses a custom String in place
template <class T, int how_big>
void swm<T, how_big>::reverse()
{
	swm<T, how_big> _reversed;
	for (int i = 0, k = length() - 1; i < length(); i++, k--) _reversed[i] = data[k];
	for (int i = 0; i < size(); i++) data[i] = _reversed[i];
}
// makes a String uppercase
void String::upper()
{
	char *new_array = new char[size()];
	for (int i = 0; i <= size(); i++)
		if (at(i) == 'a') new_array[i] = 'A';
		else if (at(i) == 'b') new_array[i] = 'B';
		else if (at(i) == 'c') new_array[i] = 'C';
		else if (at(i) == 'd') new_array[i] = 'D';
		else if (at(i) == 'e') new_array[i] = 'E';
		else if (at(i) == 'f') new_array[i] = 'F';
		else if (at(i) == 'g') new_array[i] = 'G';
		else if (at(i) == 'h') new_array[i] = 'H';
		else if (at(i) == 'i') new_array[i] = 'I';
		else if (at(i) == 'j') new_array[i] = 'J';
		else if (at(i) == 'k') new_array[i] = 'K';
		else if (at(i) == 'l') new_array[i] = 'L';
		else if (at(i) == 'm') new_array[i] = 'M';
		else if (at(i) == 'n') new_array[i] = 'N';
		else if (at(i) == 'o') new_array[i] = 'O';
		else if (at(i) == 'p') new_array[i] = 'P';
		else if (at(i) == 'q') new_array[i] = 'Q';
		else if (at(i) == 'r') new_array[i] = 'R';
		else if (at(i) == 's') new_array[i] = 'S';
		else if (at(i) == 't') new_array[i] = 'T';
		else if (at(i) == 'u') new_array[i] = 'U';
		else if (at(i) == 'v') new_array[i] = 'V';
		else if (at(i) == 'w') new_array[i] = 'W';
		else if (at(i) == 'x') new_array[i] = 'X';
		else if (at(i) == 'y') new_array[i] = 'Y';
		else if (at(i) == 'z') new_array[i] = 'Z';
		else new_array[i] = at(i);
		new_array[size() - 1] = 0;
		for (int i = 0; i < size(); i++) at(i) = new_array[i];
}
// makes a String lowercase
void String::lower()
{
	char *new_array = new char[size()];
	for (int i = 0; i <= size(); i++)
		if (at(i) == 'A') new_array[i] = 'a';
		else if (at(i) == 'B') new_array[i] = 'b';
		else if (at(i) == 'C') new_array[i] = 'c';
		else if (at(i) == 'D') new_array[i] = 'd';
		else if (at(i) == 'E') new_array[i] = 'e';
		else if (at(i) == 'F') new_array[i] = 'f';
		else if (at(i) == 'G') new_array[i] = 'g';
		else if (at(i) == 'H') new_array[i] = 'h';
		else if (at(i) == 'I') new_array[i] = 'i';
		else if (at(i) == 'J') new_array[i] = 'j';
		else if (at(i) == 'K') new_array[i] = 'k';
		else if (at(i) == 'L') new_array[i] = 'l';
		else if (at(i) == 'M') new_array[i] = 'm';
		else if (at(i) == 'N') new_array[i] = 'n';
		else if (at(i) == 'O') new_array[i] = 'o';
		else if (at(i) == 'P') new_array[i] = 'p';
		else if (at(i) == 'Q') new_array[i] = 'q';
		else if (at(i) == 'R') new_array[i] = 'r';
		else if (at(i) == 'S') new_array[i] = 's';
		else if (at(i) == 'T') new_array[i] = 't';
		else if (at(i) == 'U') new_array[i] = 'u';
		else if (at(i) == 'V') new_array[i] = 'v';
		else if (at(i) == 'W') new_array[i] = 'w';
		else if (at(i) == 'X') new_array[i] = 'x';
		else if (at(i) == 'Y') new_array[i] = 'y';
		else if (at(i) == 'Z') new_array[i] = 'z';
		else new_array[i] = at(i);
		new_array[size() - 1] = 0;
		for (int i = 0; i < size(); i++) at(i) = new_array[i];
}
// checks if a String contains thing
bool String::contains(const char* thing)
{
	int k = 0;
	for (int i = 0; i <= length(); i++) {
		if (at(i) == thing[i]) k++;
		else if (k == ::len(thing)) return true;
		else if (at(i) != thing[i]) k = 0;
	}
	return false;
}
// returns the number of nonspaces in a String
int String::totletters()
{
	int k = 0;
	for (int i = 0; i < size(); i++) if (at(i) != ' ') k++;
	return k;
}
// returns the number of spaces in a String
int String::totspaces()
{
	int k = 0;
	for (int i = 0; i < size(); i++) if (at(i) == ' ') k++;
	return k;
}
// default constructor
template <class T, int how_big>
swm<T, how_big>::swm()
{
	if (how_big > 0) {
		data = new T[how_big];
		len = how_big;
		for (int i = 0; i < len; i++) data[i] = 0;
		snapped = false;
		formatted = false;
	}
}
// overloading the subscript operator
template <class T, int how_big>
const T swm<T, how_big>::operator[](int pos) const
{
	return data[pos];
}
// returns the const length
template <class T, int how_big>
const int swm<T, how_big>::length() const
{
	return len;
}
// formats the data to make it print nicely
template <class T, int how_big>
void swm<T, how_big>::format()
{
	formatted = !formatted;
}
// returns part of data
template <class T, int how_big>
T& swm<T, how_big>::operator[](int pos)
{
	return data[pos];
}
// same as operator[]
template <class T, int how_big>
T& swm<T, how_big>::at(int pos)
{
	return data[pos];
}
// finds the index of an element
template <class T, int how_big>
int swm<T, how_big>::index(T to_get)
{
	for (int i = 0; i <= len; i++) if (data[i] == to_get) return i;
	return -1;
}
// getting for String
template <class T, int how_big>
T* swm<T, how_big>::get_alloc()
{
	return data;
}
// returns len
template <class T, int how_big>
int swm<T, how_big>::length()
{
	return len;
}
// returns the size of data
template <class T, int how_big>
int swm<T, how_big>::size()
{
	return ::len(data);
}
// gets the max size for swm
template <class T, int how_big>
int swm<T, how_big>::max_size()
{
	for (unsigned int i = 0; i <= 65535; i += 255) {
		try {
			resize(i);
		}
		catch (...) {
			break;
		}
	} return len;
}
// returns the last elem of data
template <class T, int how_big>
T& swm<T, how_big>::back()
{
	return data[len - 1];
}
// gets the front of an swm
template <class T, int how_big>
T& swm<T, how_big>::front()
{
	return data[0];
}
// finds the last occurrence of to_find
template <class T, int how_big>
int swm<T, how_big>::rfind(T to_find)
{
	for (int i = len; i >= 0; i--) if (to_find == data[i]) return i;
	return -1;
}
// finds the first occurence of to_find
template <class T, int how_big>
int swm<T, how_big>::find(T to_find)
{
	for (int i = 0; i < len; i++) if (to_find == data[i]) return i;
	return -1;
}
// inserts something into an area
template <class T, int how_big>
void swm<T, how_big>::insert(int at_this_spot, T put_this_in)
{
	resize(len + 1);
	for (int i = len - 1; i > at_this_spot; i--) data[i] = data[i - 1];
	data[at_this_spot] = put_this_in;
}
// inserts another swm into the original swm
template <class T, int how_big>
template <int bigness>
void swm<T, how_big>::insert(int at_this_spot, swm<T, bigness>& to_insert)
{
	resize(len + to_insert.length());
	for (int k = to_insert.length() - 1; k >= 0; k--) insert(at_this_spot, to_insert[k]);
}
// returns permalen
template <class T, int how_big>
const int swm<T, how_big>::permalength()
{
	return permalen;
}
// snaps data into 2
template <class T, int how_big>
void swm<T, how_big>::snap()
{
	insert(size() / 2, 0);
	snapped = true;
}
// shrinks to fit to the size of data
template <class T, int how_big>
void swm<T, how_big>::shrink()
{
	resize(size());
}
// undoes all snaps
template <class T, int how_big>
void swm<T, how_big>::bandage()
{
	if (snapped)
		for (int i = 0;; i++)
			if (data[i] == 0) {
				data[i] = data[i + 1];
				for (; i < size(); i++) data[i] = data[i + 1];
				break;
			}
	if (!data[size() + 2]) snapped = false;
}
// checks to see if the output is formatted
template <class T, int how_big>
const bool swm<T, how_big>::is_formatted() const
{
	return formatted;
}
// adds another String to the current one
String& String::operator+=(const String& rhs)
{
	resize(rhs.length() + length());
	for (int i = 0; i < rhs.length(); i++) insert(size(), rhs[i]);
	return *this;
}
// restarts an swm
template <class T, int how_big>
void swm<T, how_big>::restart()
{
	data = new T[1];
	snapped = false;
	len = 1;
}
// checks to see if an swm is empty
template <class T, int how_big>
bool swm<T, how_big>::empty()
{
	return data == 0;
}
// returns the amount of times x appears in data
template <class T, int how_big>
int swm<T, how_big>::count(T x)
{
	int k = 0;
	for (int i = 0; i < size(); i++) if (data[i] == x) k++;
	return k;
}
// same as x.~swm()
template <class T, int how_big>
void swm<T, how_big>::clear()
{
	this->~swm();
}
// same as x.~swm()
template <class T, int how_big>
void swm<T, how_big>::erase()
{
	this->~swm();
}
// removes part of data
template <class T, int how_big>
void swm<T, how_big>::remchunk(int begin, int end, int skip)
{
	Arrays::remchunk(data, begin, end, skip);
}
// aka resize with a default parameter
template <class T, int how_big>
void swm<T, how_big>::reserve(int new_size)
{
	resize(new_size);
}
// resizes data
template <class T, int how_big>
void swm<T, how_big>::resize(int new_size)
{
	T *temp = data;
	data = new T[new_size + 1];
	for (int i = 0; i < len; i++) data[i] = temp[i];
	for (int i = len; i < new_size; i++) data[i] = 0;
	len = new_size;
}
// returns a slice of the swm cake
template <class T, int how_big>
T* swm<T, how_big>::slice(int begin, int end)
{
	return Arrays::slice(data, begin, end);
}
// appends
template <class T, int how_big>
swm<T, how_big>& swm<T, how_big>::operator+=(T rhs)
{
	push_back(rhs);
	return *this;
}
// appends
template <class T, int how_big>
void swm<T, how_big>::push_back(T elem)
{
	insert(size(), elem);
}
// overloading the output operator
template <class T, int how_big>
std::ostream& operator<<(std::ostream& os, const swm<T, how_big>& rhs)
{
	if (!rhs.is_formatted()) {
		os << "[ ";
		for (int i = 0; i < rhs.length(); i++) os << rhs[i] << ' ';
		return os << ']';
	}
	else {
		for (int i = 0; i < rhs.length(); i++) os << rhs[i];
		return os;
	}
}
// overloading the input operator
template <class T, int how_big>
std::istream& operator>>(std::istream& in, swm<T, how_big>& rhs)
{
	for (int i = 0; i < rhs.length(); i++) in >> rhs[i];
	return in;
}
// swaps an swm with another
template <class T, int how_big>
template <int bigness>
void swm<T, how_big>::swap(swm<T, bigness>& with_what)
{
	swm<T, how_big> old_this;
	swm<T, bigness> old_with_what;
	for (int i = 0; i < old_this.length(); i++) old_this[i] = data[i];
	for (int i = 0; i < old_with_what.length(); i++) old_with_what[i] = with_what[i];
	with_what.resize(len);
	resize(old_with_what.length());
	for (int i = 0; i < with_what.length(); i++) with_what[i] = data[i];
	for (int i = 0; i < len; i++) data[i] = old_with_what[i];
}
// checks if an swm is full
template <class T, int how_big>
bool swm<T, how_big>::full()
{
	return len == ::len(data) + 1;
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
	sdata = new char[strlen(val) + 1];
	for (int i = 0;; i++) {
		if (val[i] == '\0') break;
		sdata[i] = val[i];
	}
	sdata[strlen(val)] = '\0';
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
bool operator==(const String& lhs, const String& rhs)
{
	if (lhs.length() > rhs.length() || rhs.length() > lhs.length()) return 0;
	int k = 0;
	for (int i = 0; i < lhs.length() && i < rhs.length(); i++) if (lhs[i] == rhs[i]) k++;
	return (k == lhs.length() + (lhs.length() % rhs.length()) || (k == rhs.length() + (rhs.length() % lhs.length())));
}
// overloading the == operator
bool operator!=(const String& lhs, const String& rhs)
{
	if (lhs.length() > rhs.length() || rhs.length() > lhs.length()) return 0;
	int k = 0;
	for (int i = 0; i < lhs.length() && i < rhs.length(); i++) if (lhs[i] == rhs[i]) k++;
	return (k != lhs.length() + (lhs.length() % rhs.length()) || (k != rhs.length() + (rhs.length() % lhs.length())));
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
	return idata;
}
// gets cdata
const char* var::getcdata() const
{
	return cdata;
}
// gets fdata
const float* var::getfdata() const
{
	return fdata;
}
// gets ddata
const double* var::getddata() const
{
	return ddata;
}
// gets bdata
const bool* var::getbdata() const
{
	return bdata;
}
// gets ldata
const long int* var::getldata() const
{
	return ldata;
}
// gets lldata
const long long int* var::getlldata() const
{
	return lldata;
}
// gets ulldata
const unsigned long long int* var::getulldata() const
{
	return ulldata;
}
// gets sdata
const char* var::getsdata() const
{
	return (sdata) ? sdata : 0;
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
// copy operator for hashmap
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
		sdata = new char[strlen(rhs.getsdata())];
		for (int i = 0; i < strlen(rhs.getsdata()); i++) sdata[i] = rhs.getsdata()[i];
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
// default constructor
hashmap::hashmap()
{
	values = new var[1];
	values[0] = 0;
	keys = new int[1];
	keys[0] = 0;
	len = 1;
}
// pushes a val into the map
void hashmap::push_in(const var& val)
{
	srand(time(0));
	if (len > 1) {
		var* temp = values;
		values = new var[len + 1];
		for (int i = 0; i < len - 1; i++) values[i] = temp[i];
		values[len - 1] = val;
		int* other_temp = keys;
		keys = new int[len + 1];
		for (int i = 0; i < len - 1; i++) keys[i] = other_temp[i];
	}
	else values[0] = val;
	++len;
	randomize();
}
// randomizes the keys
void hashmap::randomize()
{
	srand(time(0));
	int k = 0;
	do {
		keys[k] = rand();
		for (int i = 0;; i++) {
			if (keys[i] == keys[k]) {
				keys[k] = rand();
				i = 0;
			}
			else {
				k++;
				break;
			}
		}
	} while (k < len);
}
// gets the key to a certain value
int hashmap::getkey(const var& val)
{
	for (int i = 0; i < len; i++) if (values[i] == val) return keys[i];
	return -1;
}
// gets the value to a certain key
var hashmap::getval(int key)
{
	for (int i = 0; i < len; i++) if (keys[i] == key) return values[i];
	return -1;
}
// replaces a certain value
void hashmap::replace(int key, const var& to_in)
{
	for (int i = 0; i < len; i++) if (keys[i] == key) values[i] = to_in;
}
#endif
