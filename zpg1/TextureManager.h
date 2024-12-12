#pragma once

#include "Texture2D.h"
#include "TextureCubeMap.h"

#include <vector>

using namespace std;

class TextureManager
{
private:
	vector<Texture*> textures;
public:
	void addTexture(Texture* t);
	Texture* getTexture(int index);
	int texturesCount = 0;
};

