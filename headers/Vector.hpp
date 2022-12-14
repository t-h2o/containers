#include	"color.hpp"

template <typename T>
class	Vector
{
	public:
		Vector(void);
		~Vector(void);

		void	assign(unsigned int, T);

	private:
		int		*_list;
};

template <typename T>
std::ostream	&operator<<(std::ostream &output, Vector<T> const &)
{
	output << "Vector: operator <<" << std::endl;
	return output;
}

#include "../templates/Vector.cpp"
