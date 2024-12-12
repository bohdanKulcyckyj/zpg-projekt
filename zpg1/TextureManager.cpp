#include "TextureManager.h"

void TextureManager::addTexture(Texture* t)
{
	t->setPosition((int)textures.size());
	textures.push_back(t);
	texturesCount += 1;
	t->bind(t->getPosition());
}

Texture* TextureManager::getTexture(int index)
{
	if (index >= 0 && texturesCount >= index + 1) {
		return textures.at(index);
	}
	throw exception("Index out of range");
}
