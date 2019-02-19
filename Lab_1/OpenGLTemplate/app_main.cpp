#include <iostream>
#include <cmath>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

// Store the width and height of the window
int width = 640, height = 640;


//-------------------------------------------------------
// A function to draw the scene
//-------------------------------------------------------
void appDrawScene() {
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set background color to black
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    

    // Draw stuff here
    
    
    
    // V
    
    glColor3f(0.0, 0.0, 0.0);
    
    glBegin(GL_POLYGON);
    
    glVertex2d(-0.85, 0.25);
    glVertex2d(-0.7, -0.05);
    glVertex2d(-0.6, 0.25);
    
    glEnd();
    
    glColor3f(0.0, 1.0, 0.0);
    
    glBegin(GL_POLYGON);
    
    glVertex2d(-0.95, 0.25);
    glVertex2d(-0.7, -0.25);
    glVertex2d(-0.5, 0.25);
    
    glEnd();
    
    
    
    
    
    // E
    
    glColor3f(0.0, 0.0, 0.0);
    
    glBegin(GL_POLYGON);
    
    glVertex2d(-0.3, 0.15);
    glVertex2d(-0.3, 0.05);
    glVertex2d(-0.1, 0.05);
    glVertex2d(-0.1, 0.15);
    
    glEnd();
    
    
    glColor3f(0.0, 0.0, 0.0);
    
    glBegin(GL_POLYGON);
    
    glVertex2d(-0.3, -0.15);
    glVertex2d(-0.3, -0.05);
    glVertex2d(-0.1, -0.05);
    glVertex2d(-0.1, -0.15);
    
    glEnd();
    
    
    glColor3f(0.0, 0.0, 1.0);
    
    glBegin(GL_POLYGON);
    
    glVertex2d(-0.4, 0.25);
    glVertex2d(-0.4, -0.25);
    glVertex2d(-0.1, -0.25);
    glVertex2d(-0.1, 0.25);
    
    glEnd();

    
    
    // E
    
    glColor3f(0.0, 0.0, 0.0);
    
    glBegin(GL_POLYGON);
    
    glVertex2d(0.1, 0.15);
    glVertex2d(0.1, 0.05);
    glVertex2d(0.3, 0.05);
    glVertex2d(0.3, 0.15);
    
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    
    glBegin(GL_POLYGON);
    
    glVertex2d(0.1, -0.15);
    glVertex2d(0.1, -0.05);
    glVertex2d(0.3, -0.05);
    glVertex2d(0.3, -0.15);
    
    glEnd();
    
    glColor3f(0.0, 1.0, 0.0);
    
    glBegin(GL_POLYGON);
    
    glVertex2d(0.0, 0.25);
    glVertex2d(0.0, -0.25);
    glVertex2d(0.3, -0.25);
    glVertex2d(0.3, 0.25);
    
    glEnd();

    
    
    
    
    // R
    
    glColor3f(0.0, 0.0, 1.0);
    
    glBegin(GL_POLYGON);
    
    glVertex2d(0.4, 0.25);
    glVertex2d(0.4, -0.25);
    glVertex2d(0.5, -0.25);
    glVertex2d(0.5, 0.25);
    
    
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    
    float theta = 0;
    
    float thetaInc = M_PI/100;
    
    float radius = 0.07;
    
    float xOffset = 0.55;
    
    float yOffset = 0.10;
    
    
    glBegin(GL_POLYGON);
    
    for (theta; theta < 2*M_PI; theta+=thetaInc) {
        glVertex2f(radius * cos(theta) + xOffset, radius * sin(theta) + yOffset);
    }
    glEnd();
    
    
    glColor3f(0.0, 0.0, 1.0);
    
    float theta2 = 0;
    
    float thetaInc2 = M_PI/100;
    
    float radius2 = 0.15;
    
    float xOffset2 = 0.55;
    
    float yOffset2 = 0.10;
    
    
    glBegin(GL_POLYGON);
    
    for (theta2; theta2 < 2*M_PI; theta2+=thetaInc2) {
        glVertex2f(radius2 * cos(theta2) + xOffset2, radius2 * sin(theta2) + yOffset2);
    }
    glEnd();
    
    
    glColor3f(0.0, 0.0, 1.0);
    
    glBegin(GL_POLYGON);
    
    glVertex2d(0.4, 0.25);
    glVertex2d(0.4, -0.25);
    glVertex2d(0.5, -0.25);
    glVertex2d(0.5, -0.125);
    glVertex2d(0.6, -0.25);
    glVertex2d(0.7, -0.25);
    
    glEnd();
    

	// We have been drawing everything to the back buffer
	// Swap the buffers to see the result of what we drew
	glFlush();
	glutSwapBuffers();
}

//-------------------------------------------------------
// A function to handle window resizing
// Called every time the window is resized
// Arguments: 	
//	b    - mouse button that was clicked, left or right
//	s 	 - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appReshapeFunc(int w, int h) {
	// Window size has changed
	width = w;
	height = h;

	double scale, center;
	double winXmin, winXmax, winYmin, winYmax;

	// Define x-axis and y-axis range
	const double appXmin = -1.0;
	const double appXmax = 1.0;
	const double appYmin = -1.0;
	const double appYmax = 1.0;

	// Define that OpenGL should use the whole window for rendering
	glViewport(0, 0, w, h);

	// Set up the projection matrix using a orthographic projection that will
	// maintain the aspect ratio of the scene no matter the aspect ratio of
	// the window, and also set the min/max coordinates to be the disered ones
	w = (w == 0) ? 1 : w;
	h = (h == 0) ? 1 : h;

	if ((appXmax - appXmin) / w < (appYmax - appYmin) / h) {
		scale = ((appYmax - appYmin) / h) / ((appXmax - appXmin) / w);
		center = (appXmax + appXmin) / 2;
		winXmin = center - (center - appXmin)*scale;
		winXmax = center + (appXmax - center)*scale;
		winYmin = appYmin;
		winYmax = appYmax;
	}
	else {
		scale = ((appXmax - appXmin) / w) / ((appYmax - appYmin) / h);
		center = (appYmax + appYmin) / 2;
		winYmin = center - (center - appYmin)*scale;
		winYmax = center + (appYmax - center)*scale;
		winXmin = appXmin;
		winXmax = appXmax;
	}

	// Now we use glOrtho to set up our viewing frustum
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(winXmin, winXmax, winYmin, winYmax, -1, 1);
}

//-------------------------------------------------------
// A function to handle keyboard events
// Called every time a key is pressed on the keyboard
// Arguments: 	
//	key  - the key that was pressed
//	x, y - coordinates of the mouse when key is pressed
//-------------------------------------------------------
void appKeyboardFunc(unsigned char key, int x, int y) {
	
    switch (key) {
        case 27:
            exit(0);
            break;
        default:
            break;
    }

	// After all the state changes, redraw the scene
	glutPostRedisplay();
}


int main(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

	// Setup window position, size, and title
	glutInitWindowPosition(20, 60);
	glutInitWindowSize(width, height);
	glutCreateWindow("CSE165-Lab 1");

	// Setup some OpenGL options
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);


	// Set callback for drawing the scene
	glutDisplayFunc(appDrawScene);
    
    // Set callback to handle keyboad events
    glutKeyboardFunc(appKeyboardFunc);

	// Set callback for resizing th window
    glutReshapeFunc(appReshapeFunc);

	// Start the main loop
	glutMainLoop();
}
