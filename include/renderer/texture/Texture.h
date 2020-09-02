#pragma once


class Texture
{
public:
	SDL_Surface* m_Surface;
	SDL_Texture* m_Texture;
	SDL_Rect m_Rect{0,0,0,0};
	bool needBinding = false;
public:
	/*
	*	if renderer == nullptr -> needs to be bind with the renderer;
	*	the position is automatically set to {0,0}
	*	the dimension matches the texture's one
	*/
	Texture(const char* dir, SDL_Renderer* renderer = nullptr);
	/*
	*	The texture only needs to be bind
	*/
	Texture(const char* dir, size_t x = 0, size_t y = 0, size_t width = 0, size_t height = 0);
	/*
	*	The texture is fully created
	*	no concept of layer here
	*/
	Texture(SDL_Renderer* renderer, const char* dir, size_t x = 0, size_t y = 0, size_t width = 0, size_t height = 0);
	/*
	*	move semantics constructor
	*/
	Texture(Texture&& texture);

	/*
	*	default copie constructor
	*/
	Texture(const Texture&) = default;

	/*
	*	operator for the std::set
	*/
	bool operator<(const Texture& texture) const;

	~Texture();

	void Bind(SDL_Renderer* renderer);

private:
	Texture() = default;
};
