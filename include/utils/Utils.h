#include <utility>

template<typename T>
struct Position
{
public:
	std::pair<T, T> position;

	Position(const T& x, const T& y)
		:position(x,y)
	{
	}

	T getX() const;
	T getY() const;
	std::pair<T, T> getPosition() const;
};

template<typename T>
struct Dimension
{
	std::pair<T, T> dimension;

	Dimension(const T& width, const T& height)
		:dimension(width, height)
	{
	}

	T getWidth() const;
	T getHeight() const;
	std::pair<T, T> getDimension() const;
};
