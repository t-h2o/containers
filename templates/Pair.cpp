template <typename T1, typename T2> pair<T1, T2>::pair(void) {}

template <typename T1, typename T2>
pair<T1, T2>::pair(T1 const &first, T2 const &second)
	: _first(first), _second(second)
{
}