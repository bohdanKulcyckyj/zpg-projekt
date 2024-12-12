#pragma once

#include "Texture.h"

class Texture2D : public Texture
{
private:
	const char* path;
public:
	Texture2D(const char* path);
	void bind(int n) override;
};

