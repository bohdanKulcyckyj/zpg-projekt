#include "Triangle.h"

Triangle::Triangle(float* points, size_t pointsSize, ShaderProgram* sp) : BaseModel(sp) {
	// Vertex buffer object (VBO)
	this->VBO = 0;
	glGenBuffers(1, &this->VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, pointsSize, points, GL_STATIC_DRAW);
	// Vertex Array Object (VAO)
	this->VAO = 0;
	glGenVertexArrays(1, &this->VAO); //generate the VAO
	glBindVertexArray(this->VAO); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

void Triangle::draw() {
	this->shaderProgram->use();
	glBindVertexArray(this->VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}