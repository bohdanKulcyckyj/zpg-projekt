#include "Texture2D.h"

Texture2D::Texture2D(const char* path)
{
    this->path = path;
    this->position = position;
}

void Texture2D::bind(int n)
{
    glActiveTexture(GL_TEXTURE0 + position);

    this->ID = SOIL_load_OGL_texture(path, SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);

    if (this->ID == NULL) {
        std::cout << "An error occurred while loading texture." << std::endl;
        exit(EXIT_FAILURE);
    }

    glBindTexture(GL_TEXTURE_2D, this->ID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}