template <typename T1, typename T2> map<T1, T2>::map(void) : _root(0), _size(0)
{
}

template <typename T1, typename T2> map<T1, T2>::~map(void)
{
	_free_tree(_root);
}

/**
 * Capacity
 */

template <typename T1, typename T2>
bool
map<T1, T2>::empty(void) const
{
	return !_size;
}

template <typename T1, typename T2>
size_t
map<T1, T2>::size(void) const
{
	return _size;
}

template <typename T1, typename T2>
pair<T1, T2> &
map<T1, T2>::operator[](const T1 &key)
{
	t_node	   *ptr;
	enum e_side side;

	side = static_cast<enum e_side>(_size % 2);
	ptr = _root;
	while (ptr && ptr->child[side])
	{
		ptr = ptr->child[side];
	}

	if (ptr)
	{
		ptr->child[side] = new t_node;
		ptr = ptr->child[side];
		ptr->color = RED;
	}
	else
	{
		ptr = new t_node;
		_root = ptr;
		ptr->color = BLACK;
	}
	++_size;

	ptr->child[LEFT] = 0;
	ptr->child[RIGHT] = 0;
	ptr->dual.first = key;
	return ptr->dual;
}

/**
 * Modifiers
 */

template <typename T1, typename T2>
void
map<T1, T2>::insert(pair const &pair)
{
	t_node *ptr;

	ptr = _root;
	while (ptr && ptr->child[LEFT])
	{
		ptr = ptr->child[LEFT];
	}

	if (ptr)
	{
		ptr->child[LEFT] = new t_node;
		ptr = ptr->child[LEFT];
		ptr->color = RED;
	}
	else
	{
		ptr = new t_node;
		ptr->color = BLACK;
		_root = ptr;
	}
	++_size;

	ptr->child[LEFT] = 0;
	ptr->child[RIGHT] = 0;

	ptr->dual.first = pair.first;
	ptr->dual.second = pair.second;
}

template <typename T1, typename T2>
void
map<T1, T2>::print_tree(void) const
{
	_print_tree(_root, 0);
}

template <typename T1, typename T2>
void
map<T1, T2>::print(void) const
{
	t_node *ptr(_root);

	std::cout << "map: size = " << _size << std::endl;

	while (ptr)
	{
		std::cout << ptr->dual;
		ptr = ptr->child[LEFT];
	}
}

/**
 * Private
 */

template <typename T1, typename T2>
void
map<T1, T2>::_print_tree(t_node *ptr, size_t level) const
{
	if (ptr == 0)
		return;

	_print_tree(ptr->child[LEFT], level + 1);

	std::cout << std::endl;

	for (size_t i = 0; i < level; ++i)
		std::cout << "  ";

	if (ptr->color == RED)
		std::cout << COL_RED;
	else
		std::cout << COL_YEL;

	std::cout << ptr->dual << std::endl << COL_RES;

	_print_tree(ptr->child[RIGHT], level + 1);
}

template <typename T1, typename T2>
void
map<T1, T2>::_free_tree(t_node *ptr)
{
	if (ptr == 0)
		return;

	_free_tree(ptr->child[LEFT]);
	_free_tree(ptr->child[RIGHT]);
	delete ptr;
}
