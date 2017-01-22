/*==================================================================================================
 PROGRAMMER:			Yang Wang
 COURSE:				CSC 525/625
 MODIFIED BY:			Victoria Hagan, Victoria014
 LAST MODIFIED DATE:	8/31/2015
 DESCRIPTION:			Drawing lines with patterns based on user input.   
 NOTE:					N/A
 FILES:					lab3.cpp; labProject.sln
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
	glColor3f( 1 , 0 , 0 ); //specify color: red
	glLineWidth( 3 ); //specify line width: 3
	if( i == 0 ) {
		// if i == 0, draw a solid line
		glBegin( GL_LINES );
		glVertex2i( -150 , 30 );  //specify right point
		glVertex2i( 150 , 30 );   //specify left point
	}
	
	else if( i == 1 ) {
		// if i == 1, draw a simple dashed line (0x0300)
		glEnable( GL_LINE_STIPPLE );
		glLineStipple( 1 , 0x0300 );
		glBegin( GL_LINES );
		glVertex2i( -150 , 30 );
		glVertex2i( 150 , 30 );
		glEnd( );
		glDisable( GL_LINE_STIPPLE );
	}
	else if( i == 2 ) {
		//if i == 2, draw a complex dashed line (0x2E81)
		glEnable( GL_LINE_STIPPLE );
		glLineStipple( 1 , 0x2E81 );
		glBegin( GL_LINES );
		glVertex2i( -150 , 30 );
		glVertex2i( 150 , 30 );
		glEnd( );
		glDisable( GL_LINE_STIPPLE );
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
	cout << "Please select a line pattern" << endl; 
	cout << "For a solid line enter: 0" << endl; 
	cout << "For a simple dash enter: 1" << endl; 
	cout << "for a complex dash enter: 2" << endl; 
	cin >> i; //obtain pattern selection
	do {
		cout << "Please enter a valid pattern option" << endl;
		cin >> i; 
	} while( i < 0 || i > 2 ); //make sure pattern selection is valid

 glutInit(& argc, argv);

 glutInitWindowSize(400, 400);				// specify a window size
 glutInitWindowPosition(100, 0);			// specify a window position
 glutCreateWindow("Simple Point Drawing");	// create a titled window

 myInit();									// setting up

 glutDisplayFunc(myDisplayCallback);		// register a callback

 glutMainLoop();							// get into an infinite loop
}
