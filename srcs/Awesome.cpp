#include "Awesome.hpp"

Awesome::Awesome(int number) { this->_number = new int(number); }
Awesome::~Awesome(void)
{
	delete this->_number;
	this->_number = 0;
}
Awesome::Awesome(Awesome const &other) : _number(0) { *this = other; }

Awesome &
Awesome::operator=(Awesome const &other)
{
	delete this->_number;
	this->_number = new int(*(other._number));

	return *this;
}

bool
Awesome::operator==(Awesome const &other) const
{
	return (*(this->_number) == *(other._number));
}

int
Awesome::get_number(void) const
{
	return *(this->_number);
}
void
Awesome::set_number(int number)
{
	*(this->_number) = number;
}

std::ostream &
operator<<(std::ostream &output, Awesome const &object)
{
	output << "Awesome : " << object.get_number();

	return output;
}
