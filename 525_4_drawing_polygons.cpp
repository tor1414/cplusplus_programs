/*==================================================================================================
 PROGRAMMER:			Yang Wang
 COURSE:				CSC 525/625
 MODIFIED BY:			Victoria Hagan, Victoria014
 LAST MODIFIED DATE:	09/09/2015
 DESCRIPTION:			Drawing polygons with patterns based on user input.   
 NOTE:					N/A
 FILES:					lab4.cpp; labProject.sln
 IDE/COMPILER:			MicroSoft Visual Studio 2013
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1.		Double click on labProject.sln	to OPEN the project
	2.		Press Ctrl+F7					to COMPILE
	3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
	4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/
#include <iostream>
#include <GL/glut.h>				// include GLUT library
#include <math.h>					// include the math library to obtain the sin & cos functions

using namespace std; 
int i; //global variable

//***********************************************************************************
void drawPoints()
{
//-----Program Modifications By Victoria follows------//
	GLubyte pattern[ ] = {
		0x01 , 0x80 , 0x01 , 0x80 ,
		0x01 , 0x80 , 0x01 , 0x80 ,
		0x03 , 0xC0 , 0x03 , 0xC0 ,
		0x07 , 0xE0 , 0x07 , 0xE0 ,
		0x0E , 0xF0 , 0x0E , 0xF0 ,
		0x0F , 0x70 , 0x0F , 0x70 ,
		0x0F , 0x70 , 0x0F , 0x70 ,
		0x0F , 0x70 , 0x0F , 0x70 ,
		0x0F , 0x70 , 0x0F , 0x70 ,
		0x0F , 0x70 , 0x0F , 0x70 ,
		0x0F , 0x70 , 0x0F , 0x70 ,
		0x06 , 0xE0 , 0x06 , 0xE0 ,
		0x03 , 0xC0 , 0x03 , 0xC0 ,
		0x01 , 0x80 , 0x01 , 0x80 ,
		0x01 , 0x00 , 0x01 , 0x00 ,
		0x00 , 0x00 , 0x00 , 0x00 ,
		0x01 , 0x80 , 0x01 , 0x80 ,
		0x01 , 0x80 , 0x01 , 0x80 ,
		0x03 , 0xC0 , 0x03 , 0xC0 ,
		0x07 , 0xE0 , 0x07 , 0xE0 ,
		0x0E , 0xF0 , 0x0E , 0xF0 ,
		0x0F , 0x70 , 0x0F , 0x70 ,
		0x0F , 0x70 , 0x0F , 0x70 ,
		0x0F , 0x70 , 0x0F , 0x70 ,
		0x0F , 0x70 , 0x0F , 0x70 ,
		0x0F , 0x70 , 0x0F , 0x70 ,
		0x0F , 0x70 , 0x0F , 0x70 ,
		0x06 , 0xE0 , 0x06 , 0xE0 ,
		0x03 , 0xC0 , 0x03 , 0xC0 ,
		0x01 , 0x80 , 0x01 , 0x80 ,
		0x01 , 0x00 , 0x01 , 0x00 ,
		0x00 , 0x00 , 0x00 , 0x00
	}; 
	if( i == 1 ) {
		glPolygonMode( GL_FRONT , GL_FILL );
	}
	else if( i == 2 ) {
		glPolygonMode( GL_FRONT , GL_LINE );
	}
	else if( i == 3 ) {
		glPointSize( 3 );
		glPolygonMode( GL_FRONT , GL_POINT );
	} 
	else if( i == 4 ) {
		glPolygonMode( GL_FRONT , GL_FILL );
		glEnable( GL_POLYGON_STIPPLE );
		glPolygonStipple( pattern ); 

	}; 

		glBegin( GL_POLYGON);
		glColor3f( 1 , 0 , 0 ); //specify color: red
		glVertex2i( 0 , 80 );
		glColor3f( 0 , 1 , 0 ); //specify color: green
		glVertex2i( -70 , 0 );
		glColor3f( 0 , 0 , 1 ); //specify color: blue
		glVertex2i( -30 , -60 ); 
		glColor3f( 1 , 1 , 0 ); //specify color: yellow
		glVertex2i( 30 , -60 ); 
		glColor3f( 1 , 0 , 1 ); //specify color: pink
		glVertex2i( 70 , 0 ); 
		glEnd( ); 

	if( i == 4 ) {
		glDisable( GL_POLYGON_STIPPLE ); 		
	}; 

 //----code by Dr. Wang follows-----//

 glPointSize(1);		// change point size back to 1
 
 glBegin(GL_POINTS);	// use points to form X-/Y-axes
   glColor3f(0, 0, 0);			 // change drawing color to black
   for (int x=-150; x<=150; x++) // draw X-axis
     glVertex2i(x, 0);
   for (int y=-150; y<=150; y++) // draw Y-axis
     glVertex2i(0, y);
 glEnd();
}

//***********************************************************************************
void myInit()
{glClearColor(1, 1, 1, 0);			// specify a background clor: white 
 gluOrtho2D(-200, 200, -200, 200);  // specify a viewing area
}

//***********************************************************************************
void myDisplayCallback()
{glClear(GL_COLOR_BUFFER_BIT);	// draw the background

 drawPoints();

 glFlush(); // flush out the buffer contents
}

//***********************************************************************************
void main(int argc, char ** argv)
{
	cout << "Please select a shape fill" << endl; 
	cout << "For a solid fill (i.e. GL_FILL) enter: 1" << endl; 
	cout << "For an outlined polygon (i.e. GL_LINE) enter: 2" << endl; 
	cout << "for points at the verticies (i.e. GL_POINT) enter: 3" << endl; 
	cout << "for a pattern fill  (i.e. GL_PATTERN) enter: 4" << endl; 
	cin >> i; //obtain pattern selection

 glutInit(& argc, argv);

 glutInitWindowSize(400, 400);				// specify a window size
 glutInitWindowPosition(100, 0);			// specify a window position
 glutCreateWindow("Simple Polygon Drawing");	// create a titled window

 myInit();									// setting up

 glutDisplayFunc(myDisplayCallback);		// register a callback

 glutMainLoop();							// get into an infinite loop
}
