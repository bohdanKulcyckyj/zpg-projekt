#include "Rectangle.h"

Rectangle::Rectangle(Vertex* points, size_t pointsSize, ShaderProgram* sp) : BaseModel(sp) {
	// Vertex Buffer Object (VBO)
	this->VBO = 0;
	glGenBuffers(1, &this->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, pointsSize, points, GL_STATIC_DRAW);

	// Vertex Array Object (VAO)
	this->VAO = 0;
	glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));

	glBindVertexArray(0);
}

void Rectangle::draw() {
	this->shaderProgram->use();
	glBindVertexArray(this->VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}