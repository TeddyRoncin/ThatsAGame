#pragma once

class Context
{
public:
	Context(Uint32 flags);
	~Context();
public:
	bool IsInitialised() const;
};