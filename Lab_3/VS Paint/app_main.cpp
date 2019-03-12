#include <iostream>
#include <vector>
#include <deque>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif


using namespace std;

//stores current color (black default)
float red = 0.0, green = 0.0, blue = 0.0;
//Stores width of paint brush
int brushWidth = 6;
//Checks if user wants to erase
bool erase = false;

//Holds values for location and color
struct Point {
    //Used to track mouse
    float x;
    float y;
    
    //used to store color selection
    float r;
    float g;
    float b;
    
    //Used to store brush width
    float brushWidth;
    
    //default constructor with special
    Point(float x=0, float y=0, float r=0, float g=0, float b=0, int brushWidth=6) {
        this->x = x;
        this->y = y;
        this->r = r;
        this->g = g;
        this->b = b;
        this->brushWidth = brushWidth;
    }
};

//deque to store all the points
deque<Point> points;

// Store the width and height of the window
int width = 640, height = 640;

//Close button functionality
void clickClose(float mx, float my){
    if (mx >= -0.92 && mx <= -0.84 && my <= 0.93 && my >= 0.87){
        exit(0);
    }
}

void colorSelection(float mx, float my){
    //in button area
    if(my <= -0.87 && my >= -0.93){
        //red button
        if(mx >= -0.9 && mx <= -0.8){
            red = 1.0;
            green = 0.0;
            blue = 0.0;
        }
        //green button
        if(mx >= -0.7 && mx <= -0.6){
            red = 0.0;
            green = 1.0;
            blue = 0.0;
        }
        //blue button
        if(mx >= -0.5 && mx <= -0.4){
            red = 0.0;
            green = 0.0;
            blue = 1.0;
        }
        //black button
        if(mx >= -0.3 && mx <= -0.2){
            red = 0.0;
            green = 0.0;
            blue = 0.0;
        }
        //increase button
        if(mx >= 0.1 && mx <= 0.2){
            brushWidth++;
        }
        //decrease button
        if(mx >= 0.3 && mx <= 0.4){
            brushWidth--;
        }
        //erase button
        if(mx >= 0.5 && mx <= 0.6){
            erase = true;
        }
        //draw button
        if(mx >= 0.7 && mx <= 0.8){
            erase = false;
        }
    }
}

//-------------------------------------------------------
// A function to draw the scene
//-------------------------------------------------------
void appDrawScene() {
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glClearColor(0.0, 0.0, 0.0, 0.0);

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    
    //ToolBar
    //Select Color Red
    //button press animation
    if(red == 1.0){
        glColor3f(1.0, 0.7, 0.7);
    }
    else{
        glColor3f(1.0, 0.0, 0.0);
    }
    glBegin(GL_POLYGON);
    glVertex2d(-0.9, -0.87);
    glVertex2d(-0.80, -0.87);
    glVertex2d(-0.80, -0.93);
    glVertex2d(-0.9, -0.93);
    glEnd();
    //Select Color Green
    //button press animation
    if(green == 1.0){
        glColor3f(0.7, 1.0, 0.7);
    }
    else{
        glColor3f(0.0, 1.0, 0.0);
    }
    glBegin(GL_POLYGON);
    glVertex2d(-0.7, -0.87);
    glVertex2d(-0.6, -0.87);
    glVertex2d(-0.6, -0.93);
    glVertex2d(-0.7, -0.93);
    glEnd();
    //Select Color Blue
    //button press animation
    if(blue == 1.0){
        glColor3f(0.7, 0.7, 1.0);
    }
    else{
        glColor3f(0.0, 0.0, 1.0);
    }
    glBegin(GL_POLYGON);
    glVertex2d(-0.5, -0.87);
    glVertex2d(-0.4, -0.87);
    glVertex2d(-0.4, -0.93);
    glVertex2d(-0.5, -0.93);
    glEnd();
    //Select Color Black
    //button press animation
    if(red == 0.0 && green == 0.0 && blue == 0.0){
        glColor3f(0.7, 0.7, 0.7);
    }
    else{
        glColor3f(0.0, 0.0, 0.0);
    }
    glBegin(GL_POLYGON);
    glVertex2d(-0.3, -0.87);
    glVertex2d(-0.2, -0.87);
    glVertex2d(-0.2, -0.93);
    glVertex2d(-0.3, -0.93);
    glEnd();
    //Increase Brush Size Icon
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2d(0.15, -0.88);
    glVertex2d(0.15, -0.92);
    glVertex2d(0.13, -0.90);
    glVertex2d(0.17, -0.90);
    glEnd();
    //Increase Brush Size Button
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2d(0.1, -0.87);
    glVertex2d(0.2, -0.87);
    glVertex2d(0.2, -0.93);
    glVertex2d(0.1, -0.93);
    glEnd();
    //Decrease Brush Size Icon
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2d(0.33, -0.90);
    glVertex2d(0.37, -0.90);
    glEnd();
    //Decrease Brush Size
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2d(0.3, -0.87);
    glVertex2d(0.4, -0.87);
    glVertex2d(0.4, -0.93);
    glVertex2d(0.3, -0.93);
    glEnd();
    //Eraser Button
    //button press animation
    if(erase){
        glColor3f(0.7, 0.7, 0.7);
    }
    else{
        glColor3f(0.5, 0.5, 0.5);
    }
    glBegin(GL_POLYGON);
    glVertex2d(0.5, -0.87);
    glVertex2d(0.6, -0.87);
    glVertex2d(0.6, -0.93);
    glVertex2d(0.5, -0.93);
    glEnd();
    //Draw Button
    //button press animation
    if(!erase){
        glColor3f(0.7, 0.7, 0.7);
    }
    else{
        glColor3f(0.5, 0.5, 0.5);
    }
    glBegin(GL_POLYGON);
    glVertex2d(0.7, -0.87);
    glVertex2d(0.8, -0.87);
    glVertex2d(0.8, -0.93);
    glVertex2d(0.7, -0.93);
    glEnd();
    //ToolBar Window
    glColor3f(0.80, 0.80, 0.80);
    glBegin(GL_POLYGON);
    glVertex2d(-0.95, -0.85);
    glVertex2d(0.95, -0.85);
    glVertex2d(0.95, -0.95);
    glVertex2d(-0.95, -0.95);
    glEnd();
    //ToolBar Border
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2d(-0.95, -0.85);
    glVertex2d(0.95, -0.85);
    glEnd();
    
    
    //Menu Bar
    //X sign
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2d(-0.90, 0.92);
    glVertex2d(-0.86, 0.88);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-0.86, 0.92);
    glVertex2d(-0.90, 0.88);
    glEnd();
    //Close Button
    glColor3f(1.0, 0.25, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-0.92, 0.93);
    glVertex2d(-0.84, 0.93);
    glVertex2d(-0.84, 0.87);
    glVertex2d(-0.92, 0.87);
    glEnd();
    //Close Button Border
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-0.925, 0.935);
    glVertex2d(-0.835, 0.935);
    glVertex2d(-0.835, 0.865);
    glVertex2d(-0.925, 0.865);
    glEnd();
    
    
    //Menu
    glColor3f(0.80, 0.80, 0.80);
    glBegin(GL_POLYGON);
    glVertex2d(-0.95, 0.95);
    glVertex2d(0.95, 0.95);
    glVertex2d(0.95, 0.85);
    glVertex2d(-0.95, 0.85);
    glEnd();
    //Menu Bar Border
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2d(-0.95, 0.85);
    glVertex2d(0.95, 0.85);
    glEnd();
    
    //Window Area Border
    glColor3f(0.6, 0.6, 0.6);
    glLineWidth(35);
    glBegin(GL_LINES);
    glVertex2d(-1.0, 1.0);
    glVertex2d(1.0, 1.0);
    
    glVertex2d(-1.0, -1.0);
    glVertex2d(1.0, -1.0);
    
    glVertex2d(-1.0, 1.0);
    glVertex2d(-1.0, -1.0);
    
    glVertex2d(1.0, 1.0);
    glVertex2d(1.0, -1.0);
    
    glEnd();
    
    // Set the color to the current values of the global vars
    //glColor3f(red, green, blue);
    //change brush size
    //glPointSize(brushWidth);
    //Draw all the points
    for (int i = 0; i < points.size(); i++) {
        

        //check if erase
        if(erase == true){
           // cout << "Yes" <<endl;
            glColor3f(points[i].r = 1.0, points[i].g = 1.0, points[i].b = 1.0);
            glPointSize(points[i].brushWidth);
            
            glBegin(GL_POINTS);
        
            // Draw
            glVertex2d(points[i].x, points[i].y);
            
            glEnd();
            i++;
        }
        //check if not erase
        else{
            //cout << "No" <<endl;
            glColor3f(points[i].r, points[i].g, points[i].b);
            glPointSize(points[i].brushWidth);
            
            glBegin(GL_POINTS);
            
            // Draw
            glVertex2d(points[i].x, points[i].y);
            
            glEnd();
        }
    }

    
    //Window Draw Area
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2d(-0.95, 0.95);
    glVertex2d(0.95, 0.95);
    glVertex2d(0.95, -0.95);
    glVertex2d(-0.95, -0.95);
    glEnd();
    
	// We have been drawing everything to the back buffer
	// Swap the buffers to see the result of what we drew
	glFlush();
	glutSwapBuffers();
}

//-------------------------------------------------------
// A function to convert window coordinates to scene
// We use it when a mouse event is handled
// Arguments: 	
//	x, y - the coordinates to be updated
//-------------------------------------------------------
void windowToScene(float& x, float& y) {
	x = (2.0f*(x / float(width))) - 1.0f;
	y = 1.0f - (2.0f*(y / float(height)));
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
// A function to handle mouse clicks
// Called every time the mouse button goes up or down
// Arguments: 	
//	b    - mouse button that was clicked, left or right
//	s 	 - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appMouseFunc(int b, int s, int x, int y) {
	// Convert from Window to Scene coordinates
	float mx = (float)x;
	float my = (float)y;

	windowToScene(mx, my);
    
    //check if close clicked
    clickClose(mx,my);
    //check what color is clicked
    colorSelection(mx, my);
    
    //Lets use draw points by clicking
    points.push_front(Point(mx, my, red, green, blue, brushWidth));

	// Redraw the scene by calling appDrawScene above
	// so that the point we added above will get painted
	glutPostRedisplay();
}



//-------------------------------------------------------
// A function to handle mouse dragging
// Called every time mouse moves while button held down
// Arguments: 	
//	x, y - current coordinates of the mouse
//-------------------------------------------------------
void appMotionFunc(int x, int y) {
    // Convert from Window to Scene coordinates
    float mx = (float)x;
    float my = (float)y;
    
    windowToScene(mx, my);
    
    //lets us draw with the mouse by clicking and draging
    points.push_front(Point(mx, my, red, green, blue, brushWidth));

	// Again, we redraw the scene
	glutPostRedisplay();
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
        //quit application
        case 27:
            exit(0);
            break;
//        //increase brush width
//        case '+':
//            brushWidth++;
//            break;
//        //decrease brush width
//        case '-':
//            brushWidth--;
//            break;
//        //change color to red
//        case 'r':
//            red = 1.0;
//            green = 0.0;
//            blue = 0.0;
//            break;
//        //change color to green
//        case 'g':
//            red = 0.0;
//            green = 1.0;
//            blue = 0.0;
//            break;
//        //change color to blue
//        case 'b':
//            red = 0.0;
//            green = 0.0;
//            blue = 1.0;
//            break;
//        //select eraser
//        case 'e':
//            erase = !erase;
//            red = 0.0;
//            green = 0.0;
//            blue = 0.0;
//            break;
//        //clear screen
//        case ' ':
//            points.clear();
//            break;
        default:
            break;
    }

	// After all the state changes, redraw the scene
	glutPostRedisplay();
}

void idle() {

}


int main(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

	// Setup window position, size, and title
	glutInitWindowPosition(20, 60);
	glutInitWindowSize(width, height);
	glutCreateWindow("CSE165 - VS Paint");

	// Setup some OpenGL options
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);


	// Set callback for drawing the scene
	glutDisplayFunc(appDrawScene);

	// Set callback for resizing th window
    glutReshapeFunc(appReshapeFunc);

	// Set callback to handle mouse clicks
	glutMouseFunc(appMouseFunc);

	// Set callback to handle mouse dragging
	glutMotionFunc(appMotionFunc);

	// Set callback to handle keyboad events
	glutKeyboardFunc(appKeyboardFunc);
    
    glutIdleFunc(idle);

	// Start the main loop
	glutMainLoop();
}
