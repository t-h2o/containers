// This file is included into headers/Vector.hpp

template <typename T> iterator<T>::iterator(void) : _pointer(0), _position(0)
{
}

template <typename T>
iterator<T>::iterator(T *pointer, size_t position)
	: _pointer(pointer), _position(position)
{
}

template <typename T>
T &
iterator<T>::operator*(void)
{
	return this->_pointer[_position];
}

template <typename T>
T &
iterator<T>::operator[](size_t position)
{
	return this->_pointer[_position + position];
}

template <typename T>
iterator<T> &
iterator<T>::operator++(void)
{
	this->_position++;
	return *this;
}

template <typename T>
iterator<T>
iterator<T>::operator++(int)
{
	iterator<T> prev;

	prev = *this;
	this->_position++;
	return prev;
}

template <typename T>
iterator<T> &
iterator<T>::operator--(void)
{
	this->_position--;
	return *this;
}

template <typename T>
iterator<T>
iterator<T>::operator--(int)
{
	iterator<T> prev;

	prev = *this;
	this->_position--;
	return prev;
}

template <typename T>
bool
iterator<T>::operator==(iterator<T> const &other)
{
	return (&(this->_pointer[this->_position])
			== &(other._pointer[other._position]));
}

template <typename T>
bool
iterator<T>::operator!=(iterator<T> const &other)
{
	return !(*this == other);
}

template <typename T>
bool
iterator<T>::operator>(iterator<T> const &other)
{
	return (&(this->_pointer[this->_position])
			> &(other._pointer[other._position]));
}

template <typename T>
bool
iterator<T>::operator<(iterator<T> const &other)
{
	return (&(this->_pointer[this->_position])
			< &(other._pointer[other._position]));
}

template <typename T>
bool
iterator<T>::operator>=(iterator<T> const &other)
{
	return (!(*this < other));
}

template <typename T>
bool
iterator<T>::operator<=(iterator<T> const &other)
{
	return (!(*this > other));
}

template <typename T>
iterator<T>
iterator<T>::operator+(const long add)
{
	iterator<T> diff(this->_pointer, this->_position + add);
	return diff;
}

template <typename T>
iterator<T>
iterator<T>::operator-(const long remove)
{
	iterator<T> diff(this->_pointer, this->_position - remove);
	return diff;
}

template <typename T>
std::ptrdiff_t
iterator<T>::operator-(iterator const &other)
{
	return this->_position - other._position;
}

template <typename T>
iterator<T> &
iterator<T>::operator+=(const long add)
{
	this->_position += add;
	return *this;
}

template <typename T>
iterator<T> &
iterator<T>::operator-=(const long remove)
{
	this->_position -= remove;
	return *this;
}
