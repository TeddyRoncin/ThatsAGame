#pragma once

template<typename T>
struct Position
{
	std::pair<T, T> position;

	Position(const T& x, const T& y)
		:position(std::pair<T, T>(x,y))
	{
	}

	Position(const Position& pos)
		:position(pos.position)
	{
	}

	T getX() const { return (position.first); }
	T getY() const { return (position.second); }
	std::pair<T, T> getPosition() const { return (position); }

	T DistanceFrom(Position<T> otherPoint)
	{
		return std::sqrt(std::pow(getX() - otherPoint.getX(), 2) + std::pow(getY() - otherPoint.getY(), 2));
	}
};

template<typename T>
struct Dimension
{
	std::pair<T, T> dimension;

	Dimension(const T& width, const T& height)
		:dimension(std::pair<T, T>(width, height))
	{
	}

	Dimension(const Dimension& dim)
		:dimension(dim.dimension)
	{
	}

	T getWidth() const { return (dimension.first); }
	T getHeight() const { return (dimension.second); }
	std::pair<T, T> getDimension() const { return (dimension); }
};
