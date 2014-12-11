/*
 * character.cpp
 *
 *  Created on: Dec 8, 2014
 *      Author: rami
 */

#include "character.h"

GLuint Character::object = 0;
float Character::rotation = 0;
const GLfloat Character::iX = 0, Character::iY = -9, Character::iZ = 20;
GLfloat Character::x = iX, Character::y = iY, Character::z = iZ;

bool Character::hasObjectId() {
	return object != 0;
}

void Character::setObjectId(GLuint objectId) {
	object = objectId;
}

void Character::setRotation(float rot) {
	rotation = rot;
}

void Character::draw() {
	static Object plane("ARC170_2.obj", 0.001, 0.001, 0.005);
	static GLuint texture = PNGTextureLoader::loadTexture("ARC170_2.png");
	plane.rotY = 180;

	glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, texture);

	glColor3f(1, 1, 1);
	plane.makeList();
	plane.drawList(x, y, z);

	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	return;

	if(!hasObjectId())
		setObjectId(ObjectLoader::loadObject("al.obj"));

	glPushMatrix();
	glTranslated(x,y,z);
	glColor3d(0.3,0.1,0.9);
	//glScalef(0.1,0.1,0.1);
	glScaled(0.2,0.2,0.2);
	glRotated(rotation,0,1,0);
	glCallList(object);
	glPopMatrix();
}

GLfloat Character::getX() {
	return x;
}

void Character::setX(GLfloat X) {
	x = X;
}

GLfloat Character::getY() {
	return y;
}

void Character::setY(GLfloat Y) {
	y = Y;
}

GLfloat Character::getZ() {
	return z;
}

void Character::setZ(GLfloat Z) {
	z = Z;
}

void Character::resetPosition() {
	x = iX;
	y = iY;
	z = iZ;
}

void Character::moveForward(GLfloat value) {
	z += value;
}

void Character::moveLeft(GLfloat value) {
	if(x + value < Walkway::RIGHT_LIMIT)
		x += value;
}

void Character::moveRight(GLfloat value) {
	if(x - value >= Walkway::LEFT_LIMIT)
		x -= value;
}
