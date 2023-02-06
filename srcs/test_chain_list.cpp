#include "Awesome.hpp"
#include "Tdd.hpp"
#include "color.hpp"
#include "test.hpp"

#include "chain_list.hpp"

template <typename T>
static void
test(void)
{
	ft::chain_list<T> a;

	std::cout << "size: " << a.size() << std::endl;
	a.last();

	a.put(42);
	std::cout << "size: " << a.size() << std::endl;
	a.last();

	a.put(1234);
	std::cout << "size: " << a.size() << std::endl;
	a.last();
}

void
test_chain_list(void)
{
	title("Chain list");
	section("test int");

	test<int>();
	section("test Awesome");
	test<Awesome>();
}