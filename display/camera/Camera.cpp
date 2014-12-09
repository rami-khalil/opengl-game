/*
 * Camera.cpp
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#include "Camera.h"

GLfloat Camera::cameraEyeInitial[3] = { 0, 0, 0 },
		Camera::cameraCenterInitial[3] = { 0, 0, 1 };

GLfloat Camera::cameraEye[3] = { 0, 0, 0 },
		Camera::cameraCenter[3] = { 0, 0, 1 },
		Camera::cameraUp[3] = { 0, 1, 0 };

void Camera::setupCamera() {
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1, 0.01, 10000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(	0,0,0,
				0,0,1,
				0,1,0);

	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
}