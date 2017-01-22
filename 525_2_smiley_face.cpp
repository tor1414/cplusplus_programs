/*==================================================================================================
 PROGRAMMER:			Yang Wang
 COURSE:				CSC 525/625
 MODIFIED BY:			Victoria Hagan, Victoria014
 LAST MODIFIED DATE:	8/26/2015
 DESCRIPTION:			Drawing a yellow smiling face icon using only points.  
 NOTE:					N/A
 FILES:					lab2.cpp; labProject.sln
 IDE/COMPILER:			MicroSoft Visual Studio 2013
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1.		Double click on labProject.sln	to OPEN the project
	2.		Press Ctrl+F7					to COMPILE
	3.		Press Ctrl+Shift+B				to BUILD (COMPILE+LINK)
	4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/
#include <GL/glut.h>				// include GLUT library
#include <math.h>					// include the math library to obtain the sin & cos functions

//***********************************************************************************
void drawPoints()
{
//-----Program Modifications By Victoria follows------//
 glColor3f( 1 , 1 , 0 );			// specify drawing color: yellow 

 glPointSize( 7 );					// specify point size of eyes to 7
 glBegin(GL_POINTS);
 //spefify right eye location: perimeter ring
 for( int t = 0; t <= 360; t++ ) {
	 double c = -40 + 10 * sin( ( t*3.14 ) / 180 );
	 double d = 40 + 10 * cos( ( t*3.14 ) / 180 );
	 glVertex2d( c , d );
 }
 //specify right eye location: middle ring
 for( int t = 0; t <= 360; t++ ) {
	 double c = -40 + 6 * sin( ( t*3.14 ) / 180 );
	 double d = 40 + 6 * cos( ( t*3.14 ) / 180 );
	 glVertex2d( c , d );
 }
 //specify right eye location: center ring
 for( int t = 0; t <= 360; t++ ) {
	 double c = -40 + 2 * sin( ( t*3.14 ) / 180 );
	 double d = 40 + 2 * cos( ( t*3.14 ) / 180 );
	 glVertex2d( c , d );
 }

 // Specify left eye location: perimeter ring
 for( int t = 0; t <= 360; t++ ) {
	 double e = 40 + 10 * sin( ( t*3.14 ) / 180 );
	 double f = 40 + 10 * cos( ( t*3.14 ) / 180 );
	 glVertex2d( e , f );
 }
 // specify left eye loaction: middle ring
 for( int t = 0; t <= 360; t++ ) {
	 double e = 40 + 6 * sin( ( t*3.14 ) / 180 );
	 double f = 40 + 6 * cos( ( t*3.14 ) / 180 );
	 glVertex2d( e , f );
 }
 //specify left eye location: center ring
 for( int t = 0; t <= 360; t++ ) {
	 double e = 40 + 2 * sin( ( t*3.14 ) / 180 );
	 double f = 40 + 2 * cos( ( t*3.14 ) / 180 );
	 glVertex2d( e , f );
 }
 glEnd( ); 

 glPointSize( 15 );			//specify point size of smile to 15
 glBegin( GL_POINTS );
 // specify smile location 
 // note that the circle is drawn clockwise
 // quadI = 0-90, quadIV = 90-180 , quadIII = 180-270 & quadII = 270-360
 // a smile will exist in quad III & quad IV
   for( int t = 90; t <= 270; t++ ) {
	   double g = 65 * sin( ( t*3.14 ) / 180 );
	   double h = 65 * cos( ( t*3.14 ) / 180 );
	   glVertex2d( g , h );
   }
  glEnd( );

  glPointSize( 20 );		//specify point size of face perimeter to 20
  glBegin( GL_POINTS );
  //specify face location
   for( int t = 0; t <= 360; t++ ) {
	   double x = 100 * sin( ( t*3.14 ) / 180 );
	   double y = 100 * cos( ( t*3.14 ) / 180 );
	   glVertex2d( x , y );
   }
 glEnd();

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
{glutInit(& argc, argv);

 glutInitWindowSize(400, 400);				// specify a window size
 glutInitWindowPosition(100, 0);			// specify a window position
 glutCreateWindow("Simple Point Drawing");	// create a titled window

 myInit();									// setting up

 glutDisplayFunc(myDisplayCallback);		// register a callback

 glutMainLoop();							// get into an infinite loop
}
