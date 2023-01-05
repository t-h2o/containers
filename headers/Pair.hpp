#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{

template <typename T1, typename T2> class pair
{
  public:
	/* Member Funcion */
	pair(void);
	pair(const pair &);
	pair(T1 const &, const T2 &);

	pair &operator=(const pair &);
	pair &operator=(const T2 &);

	void swap(pair &);

	T1	  first;
	T2	  second;
};

#include "../templates/Pair.cpp"

} /* namespace ft */

#endif /* PAIR_HPP */
