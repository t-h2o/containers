#include <cstddef>
#include <iostream>

namespace ft
{

///@{
///  Marking input iterators.
struct input_iterator_tag
{
};

///  Marking output iterators.
struct output_iterator_tag
{
};

/// Forward iterators support a superset of input iterator operations.
struct forward_iterator_tag : public input_iterator_tag
{
};

/// Bidirectional iterators support a superset of forward iterator
/// operations.
struct bidirectional_iterator_tag : public forward_iterator_tag
{
};

/// Random-access iterators support a superset of bidirectional
/// iterator operations.
struct random_access_iterator_tag : public bidirectional_iterator_tag
{
};
///@}

/**
 *  @brief  Common %iterator class.
 *
 *  This class does nothing but define nested typedefs.  %Iterator classes
 *  can inherit from this class to save some work.  The typedefs are then
 *  used in specializations and overloading.
 *
 *  In particular, there are no default implementations of requirements
 *  such as @c operator++ and the like.  (How could there be?)
 */
template <typename _Category, typename _Tp, typename _Distance = ptrdiff_t, typename _Pointer = _Tp *,
		  typename _Reference = _Tp &>
struct iterator
{
	iterator() { std::cout << "struct iterator" << std::endl; }
	/// One of the @link iterator_tags tag types@endlink.
	typedef _Category iterator_category;
	/// The type "pointed to" by the iterator.
	typedef _Tp value_type;
	/// Distance between iterators is represented as this type.
	typedef _Distance difference_type;
	/// This type represents a pointer-to-value_type.
	typedef _Pointer pointer;
	/// This type represents a reference-to-value_type.
	typedef _Reference reference;
};

/**
 *  @brief  Traits class for iterators.
 *
 *  This class does nothing but define nested typedefs.  The general
 *  version simply @a forwards the nested typedefs from the Iterator
 *  argument.  Specialized versions for pointers and pointers-to-const
 *  provide tighter, more correct semantics.
 */
template <typename _Iterator> struct iterator_traits;

/**
 *  @brief  Traits class for iterators.
 *
 *  This class does nothing but define nested typedefs.  The general
 *  version simply @a forwards the nested typedefs from the Iterator
 *  argument.  Specialized versions for pointers and pointers-to-const
 *  provide tighter, more correct semantics.
 */
/// Partial specialization for pointer types.
template <typename _Tp> struct iterator_traits<_Tp *>
{
	iterator_traits() { std::cout << "template <typename _Tp> struct iterator_traits<_Tp *>" << std::endl; }
	typedef random_access_iterator_tag iterator_category;
	typedef _Tp						   value_type;
	typedef ptrdiff_t				   difference_type;
	typedef _Tp						  *pointer;
	typedef _Tp						  &reference;
};

/// Partial specialization for const pointer types.
template <typename _Tp> struct iterator_traits<const _Tp *>
{
	iterator_traits()
	{
		std::cout << "template <typename _Tp> struct iterator_traits<const _Tp *>" << std::endl;
	}
	typedef random_access_iterator_tag iterator_category;
	typedef _Tp						   value_type;
	typedef ptrdiff_t				   difference_type;
	typedef const _Tp				  *pointer;
	typedef const _Tp				  &reference;
};

template <typename _Iterator> struct iterator_traits
{
	iterator_traits() { std::cout << "template <typename _Iterator> struct iterator_traits" << std::endl; }
	typedef typename _Iterator::iterator_category iterator_category;
	typedef typename _Iterator::value_type		  value_type;
	typedef typename _Iterator::difference_type	  difference_type;
	typedef typename _Iterator::pointer			  pointer;
	typedef typename _Iterator::reference		  reference;
};

} /* namespace ft */

template <typename _Tp> class myiterator : public ft::iterator<ft::random_access_iterator_tag, _Tp>
{
	typedef typename ft::iterator_traits<myiterator<_Tp> >::value_type value_type;

  public:
	myiterator()
	{
		std::cout << "class myiterator : public ft::iterator<random_access_iterator_tag, _Tp>" << std::endl;
		;
	}
};

void
iterator_traits(void)
{
	int vec[4] = { 0, 1, 2, 3 };

	std::cout << "Vector:";
	for (int i = 0; i < 4; ++i)
		std::cout << ' ' << vec[i];
	std::cout << '\n';

	myiterator<int>						   it;
	ft::iterator_traits<int *>			   it_t;
	ft::iterator_traits<int *>::value_type number = 12;
	ft::iterator_traits<int const *>	   c_it_t;

	int a = number;
	(void)a;
	(void)it;
	(void)it_t;
	(void)c_it_t;
}
