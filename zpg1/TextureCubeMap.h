#pragma once

#include "Texture.h"

class TextureCubeMap : public Texture
{
private:
	const char* right;
	const char* left;
	const char* top;
	const char* bottom;
	const char* front;
	const char* back;
public:
	TextureCubeMap(const char* right, const char* left, const char* top, const char* bottom, const char* front, const char* back);
	void bind(int n) override;
};

