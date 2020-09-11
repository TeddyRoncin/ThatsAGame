#include <utility>

template<typename T>
struct Position
{
	std::pair<T, T> position;

	T getX() const;
	T getY() const;
	std::pair<T, T> getPosition() const;
};

template<typename T>
struct Dimension
{
	std::pair<T, T> dimension;

	T getWidth() const;
	T getHeight() const;
	std::pair<T, T> getDimension() const;
};
