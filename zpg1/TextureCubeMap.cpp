#include "TextureCubemap.h"

TextureCubeMap::TextureCubeMap(const char* right, const char* left, const char* top, const char* bottom, const char* front, const char* back)
{
	this->position = position;
	this->right = right;
	this->left = left;
	this->top = top;
	this->bottom = bottom;
	this->front = front;
	this->back = back;
}

void TextureCubeMap::bind(int n)
{
	glActiveTexture(GL_TEXTURE0 + position);

	this->ID = SOIL_load_OGL_cubemap(right, left, top, bottom, front, back, SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
	if (this->ID == NULL) {
		std::cout << "An error occurred while loading CubeMap." << std::endl;
		exit(EXIT_FAILURE);
	}

	glBindTexture(GL_TEXTURE_CUBE_MAP, this->ID);
}
