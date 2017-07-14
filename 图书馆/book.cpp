#include <iomanip>
#include "book.h"
char *Book::getname()
{
	return name;
}
int Book::getnote()
{
	return note;
}
int Book::getnumber()
{
	return number;
}
void Book::setnote()
{
	note = 0;
}
void Book::setname(char na[])
{
	strcpy_s(name, na);
}
void Book::addbook(int n, char *na)
{
	note = 0;
	number = n;
	strcpy_s(name, na);
	onshelf = 1;
}
void Book::delbook()
{
	note = 1;
}
int Book::borrowbook()
{
	return onshelf;
}
void Book::retbook()
{
	onshelf = 1;
}
void Book::borrbook()
{
	onshelf = 0;
}
void Book::list()
{
	cout << setw(5) << number <<"  "<< setw(25) << name << "  "<<setw(5) << onshelf << endl;
}