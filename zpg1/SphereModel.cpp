#include "SphereModel.h"

SphereModel::SphereModel() : Model() {
	// Vertex buffer object (VBO)
	this->VBO = 0;
	glGenBuffers(1, &this->VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(sphere), sphere, GL_STATIC_DRAW);
	// Vertex Array Object (VAO)
	this->VAO = 0;
	glGenVertexArrays(1, &this->VAO); //generate the VAO
	glBindVertexArray(this->VAO); //bind the VAO
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), NULL);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
}

void SphereModel::draw() {
	glBindVertexArray(this->VAO);
	glDrawArrays(GL_TRIANGLES, 0, 2880);
}