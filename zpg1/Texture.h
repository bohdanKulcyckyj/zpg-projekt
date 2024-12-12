#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>  
#include <string>
#include <SOIL.h>
#include <iostream>

class Texture
{
protected:
	GLint ID;
	int position;
public:
	void setPosition(int pos);
	int getPosition();
	int getId();
	virtual void bind(int n) = 0;
};
