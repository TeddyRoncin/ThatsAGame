#include "pch.h"

#include "renderer/Texture.h"
#include "renderer/TextureManager.h"

Texture::Texture(const Position<float>* _position, const Dimension<float>* _size, bool _drawOnTheFly)
	:position(_position), size(_size), drawOnTheFly(_drawOnTheFly), texture(nullptr)
{
}

Texture::Texture(const Position<float>* _position, const Dimension<float>* _size, SDL_Texture* _texture, const char* _path)
	:position(_position), size(_size), texture(_texture), texture_path(_path), drawOnTheFly(false)
{
}

Texture::~Texture()
{
	position = nullptr;
	size = nullptr;
	texture = nullptr;
	texture_path = nullptr;
}

Position<int> Texture::ComputeActualPosition(Dimension<int> mapSize, Dimension<int> windowSize) const
{
	return Position<int>(std::ceil(position->getX() * windowSize.getWidth() / mapSize.getWidth()),
							std::ceil(position->getY() * windowSize.getHeight() / mapSize.getHeight()));
}

Dimension<int> Texture::ComputeActualSize(Dimension<int> mapSize, Dimension<int> windowSize) const
{
	return Dimension<int>(std::ceil(size->getWidth() * windowSize.getWidth() / mapSize.getWidth()),
							std::ceil(size->getHeight() * windowSize.getHeight() / mapSize.getHeight()));
}
