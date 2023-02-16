#ifndef BIDIRECTIONAL_ITERATOR
#define BIDIRECTIONAL_ITERATOR

#include "Iterator.hpp"
#include "node.hpp"

namespace ft
{

template <typename _Node, typename _Iter> class bidirectional_iterator
{
	typedef _Node								 Node;
	typedef _Iter								 iterator_type;
	typedef bidirectional_iterator<_Node, _Iter> _self;
	typedef _self								&_self_reference;

  public:
	typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
	typedef typename iterator_traits<iterator_type>::value_type		   value_type;
	typedef typename iterator_traits<iterator_type>::difference_type   difference_type;
	typedef typename iterator_traits<iterator_type>::pointer		   pointer;
	typedef typename iterator_traits<iterator_type>::reference		   reference;

	bidirectional_iterator(void);
	bidirectional_iterator(Node **, Node *);
	bidirectional_iterator(Node **, Node *, Node *);

	_self_reference operator=(_self_reference);
	reference		operator*(void);

	_self_reference operator++(void);
	_self_reference operator--(void);

	_self operator++(int);
	_self operator--(int);

	bool operator==(bidirectional_iterator const &) const;
	bool operator!=(bidirectional_iterator const &) const;

	Node *_bigger(Node *) const;

  private:
	Node **_root;
	Node  *_actual;
	Node  *_end;
};

#include "../templates/bidirectional_iterator.cpp"

} /* namespace ft */

#endif /* BIDIRECTIONAL_ITERATOR */
