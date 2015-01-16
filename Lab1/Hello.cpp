/*
* hello.c
* This is a simple, introductory OpenGL program.
*/
#include <stdlib.h>
#include <GL/freeglut.h>
#include <stdio.h>

void display(void)
{
	printf("display\n");
	/* clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);

	/* draw white polygon (rectangle) with corners at
	* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/

	/* House Base */
	glColor3f(0.94, 0.87, 0.73);
	glLineWidth(2.0);
	glBegin(GL_POLYGON);
	glVertex2d(0.10, 0.10);
	glVertex2d(0.90, 0.10);
	glVertex2d(0.90, 0.75);
	glVertex2d(0.10, 0.75);
	glEnd();

	/* Roof */
	glColor3f(0.76, 0.60, 0.42);
	glBegin(GL_QUAD_STRIP);
	glVertex2d(0.00, 0.75);
	glVertex2d(0.50, 1.00);
	glVertex2d(1.00, 0.75);
	glVertex2d(1.00, 0.75);
	glEnd();

	/* Window Left */
	glColor3f(0.92, 0.98, 1.00);
	glLineWidth(2.0);
	glBegin(GL_POLYGON);
	glVertex2d(0.15, 0.35);
	glVertex2d(0.375, 0.35);
	glVertex2d(0.375, 0.60);
	glVertex2d(0.15, 0.60);
	glEnd();

	/* Window Right */
	glColor3f(0.92, 0.98, 1.00);
	glLineWidth(2.0);
	glBegin(GL_POLYGON);
	glVertex2d(0.85, 0.35);
	glVertex2d(0.625, 0.35);
	glVertex2d(0.625, 0.60);
	glVertex2d(0.85, 0.60);
	glEnd();

	/* Door */
	glColor3f(0.40, 0.30, 0.16);
	glLineWidth(2.0);
	glBegin(GL_POLYGON);
	glVertex2d(0.425, 0.10);
	glVertex2d(0.425, 0.35);
	glVertex2d(0.575, 0.35);
	glVertex2d(0.575, 0.10);
	glEnd();

	/* Door Knob */
	glColor3f(0.89, 0.52, 0.00);
	glBegin(GL_LINE_LOOP);
	glLineWidth(5.0);
	glVertex2d(0.52, 0.17);
	glVertex2d(0.52, 0.19);
	glVertex2d(0.55, 0.19);
	glVertex2d(0.55, 0.17);
	glEnd();

	/* Door Window */
	glColor3f(0.92, 0.98, 1.00);
	glBegin(GL_POLYGON);
	glLineWidth(5.0);
	glVertex2d(0.455, 0.24);
	glVertex2d(0.455, 0.33);
	glVertex2d(0.545, 0.33);
	glVertex2d(0.545, 0.24);
	glEnd();

	/* Sky Top */
	glColor3f(0.34, 0.63, 0.83);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2d(0.50, 1.00);
	glVertex2d(1.00, 0.75);
	glVertex2d(1.00, 1.00);
	glVertex2d(0.50, 1.50);
	glVertex2d(0.00, 1.00);
	glVertex2d(0.00, 0.75);
	glEnd();

	/* Sky Side Left */
	glColor3f(0.34, 0.63, 0.83);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2d(0.00, 0.10);
	glVertex2d(0.10, 0.10);
	glVertex2d(0.10, 0.75);
	glVertex2d(0.00, 0.75);
	glVertex2d(0.00, 0.00);
	glEnd();

	/* Sky Side Right */
	glColor3f(0.34, 0.63, 0.83);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2d(1.00, 0.10);
	glVertex2d(0.90, 0.10);
	glVertex2d(0.90, 0.75);
	glVertex2d(1.00, 0.75);
	glVertex2d(1.00, 0.00);
	glEnd();

	/* Ground */
	glColor3f(0.29, 0.21, 0.13);
	glLineWidth(2.0);
	glBegin(GL_POLYGON);
	glVertex2d(0.00, 0.00);
	glVertex2d(1.00, 0.00);
	glVertex2d(1.00, 0.10);
	glVertex2d(0.00, 0.10);
	glEnd();

	/* Grass */
	glColor3f(0.48, 0.71, 0.38);
	glLineWidth(2.0);
	glBegin(GL_POLYGON);
	glVertex2d(0.00, 0.07);
	glVertex2d(1.00, 0.07);
	glVertex2d(1.00, 0.10);
	glVertex2d(0.00, 0.10);
	glEnd();

	/* don't wait!
	* start processing buffered OpenGL routines
	*/
	glFlush();
}

void init(void)
{
	/* select clearing color 	*/
	glClearColor(0.0, 0.0, 0.0, 0.0);

	/* initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

static void
key(unsigned char k, int x, int y)
{
	switch (k) {
	case 27:  /* Escape */
		exit(0);
		break;
	default:
		return;
	}
	glutPostRedisplay();
}

/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA).  Open window with "hello"
* in its title bar.  Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{
	const int WINDOW_LENGTH = 640;
	const int WINDOW_HEIGHT = 480;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_LENGTH, WINDOW_HEIGHT);
	
	/* Display window at center of screen */
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-WINDOW_LENGTH)/2, 
		(glutGet(GLUT_SCREEN_HEIGHT)-WINDOW_HEIGHT)/2);

	glutCreateWindow("draw");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}