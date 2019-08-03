	
//g++ welcome.c -o l -lGL -lGLU -lglut

#include<iostream>
#include <GL/glut.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
GLboolean flag = false;
int n, k;
char a[100], rev[100];
int yellow_color[100];
int red_color[100];
GLfloat space;
int index_i = 1, index_j;
char temp = '\0';
char line1[100] = { "JSS ACADEMY OF TECHNICAL EDUCATION" };
char line2[100] = { "DEPT. OF COMPUTER SCIENCE & ENGG" };
char line3[100] = { "Computer Graphics project" };
char line4[100] = { "CYCLE SORT ALGORITHM ANIMATION" };
char line5[100] = { "VEDANT V Y : 1JS16CS114" };
char line6[100] = { "SIDDHARTH: 1JS16CS100" };
char line7[100] = { "GUIDED BY: PROF MAHESH KUMAR M R" };
void maincycy();
void displayfirst();
void drawerrev();
void delay();
void RenderString(float x, float y, void *font, char string);

void drawer();
void cycleSort(char arr[], int n);


void cycleSortR(char arr[], int n);
void menu(int id);


void keyquit(unsigned char key, int x, int y);
void maincyc();
void display() {
	drawer();
	cycleSort(a, n);
	glutPostRedisplay();
}

void displayrev() {
	if (!flag)
	{
		drawer();
		cycleSortR(a, n);
	}
	else
	{
		drawerrev();
	}
	glutPostRedisplay();
}


void myInit() {
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1000, 0, 700);
}
void menu(int id)
{
	switch (id)
	{
	case 1: //  display first page
		
		glClear(GL_COLOR_BUFFER_BIT);

		displayfirst();

		break;
	case 2: // ascending
		glClear(GL_COLOR_BUFFER_BIT);
		maincyc();
		//display();


		break;
	case 3: // descending
		//idc = 3;
		glClear(GL_COLOR_BUFFER_BIT);
		maincycy();
		//displayrev();
		break;

	default:
		break;
	}

}
void drawer() {
	delay();
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	for (int i = 1; i <= n; i++) {
		glColor3f(1.0, 1.0, 1.0);
		if (yellow_color[i - 1])
			glColor3f(0.0, 1.0, 0.0);
		else if (red_color[i - 1])
			glColor3f(1.0, 0.0, 0.0);
		glRectf(space*i - 25, 300, space*i + 25, 400);
		RenderString(space*i - 3, 345, GLUT_BITMAP_TIMES_ROMAN_24, a[i - 1]);
		glColor3f(0.5, 0.5, 0.5);
		glRectf(475, 450, 525, 550);
		glColor3f(0.5, 0, 0.5);
		RenderString(500 - 3, 495, GLUT_BITMAP_TIMES_ROMAN_24, temp);
	}
	glFlush();
	//glutSwapBuffers();

}

void cycleSort(char arr[], int n)
{
	// count number of memory writes 
	int writes = 0;

	// traverse array elements and put it to on 
	// the right place 
	int i, j, min_idx;

	for (i = 0; i < n; i++)

	{
		red_color[i] = 1;

		min_idx = i;
		drawer();
		memset(red_color, 0, sizeof(red_color));
		for (j = i + 1; j < n; j++)
		{
			red_color[j] = 1;

			drawer();
			memset(red_color, 0, sizeof(red_color));
			for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
				// initialize item as starting point 
				int item = arr[cycle_start];

				// Find position where we put the item. We basically 
				// count all smaller elements on right side of item. 
				int pos = cycle_start;
				for (int i = cycle_start + 1; i < n; i++)
					if (arr[i] < item)
					{
						red_color[j] = 1;
						min_idx = j;
						drawer();
						memset(red_color, 0, sizeof(red_color));
						pos++;
					}

				// If item is already in correct position 
				if (pos == cycle_start)
				{

					continue;
				}
				// ignore all duplicate  elements 
				while (item == arr[pos])
				{
					red_color[j] = 1;
					min_idx = j;
					drawer();
					memset(red_color, 0, sizeof(red_color));

					pos += 1;
				}

				// put the item to it's right position 
				if (pos != cycle_start) {
					//swap(item, arr[pos]);
					temp = item;
					item = arr[pos];
					arr[pos] = temp;
					red_color[j] = 1;
					min_idx = j;
					drawer();
					memset(red_color, 0, sizeof(red_color));
					writes++;
				}

				// Rotate rest of the cycle 
				while (pos != cycle_start) {
					pos = cycle_start;

					// Find position where we put the element 
					for (int i = cycle_start + 1; i < n; i++)
						if (arr[i] < item) {
							red_color[j] = 1;
							min_idx = j;
							drawer();
							memset(red_color, 0, sizeof(red_color));
							pos += 1;
						}
					// ignore all duplicate  elements 
					while (item == arr[pos])
						pos += 1;

					// put the item to it's right position 
					if (item != arr[pos]) {
						//swap(item, arr[pos]);
						temp = item;
						item = arr[pos];
						arr[pos] = temp;
						red_color[j] = 1;
						min_idx = j;
						drawer();
						memset(red_color, 0, sizeof(red_color));
						writes++;
					}
				}
			}
		}
		yellow_color[min_idx] = 1;
		yellow_color[i] = 1;
		drawer();
		delay();
		// THIS SHIT IS NOT REQUIRED
		//temp = a[min_idx];
		//a[min_idx] = a[i];
		//a[i] = temp;
	}

	// Number of memory writes or swaps 
	// cout << writes << endl ; 
}



void cycleSortR(char arr[], int n)
{
	// count number of memory writes 
	int writes = 0;

	// traverse array elements and put it to on 
	// the right place 
	int i, j, min_idx;

	for (i = 0; i < n; i++)

	{
		red_color[i] = 1;

		min_idx = i;
		drawer();
		memset(red_color, 0, sizeof(red_color));
		for (j = i + 1; j < n; j++)
		{
			red_color[j] = 1;

			drawer();
			memset(red_color, 0, sizeof(red_color));
			for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
				// initialize item as starting point 
				int item = arr[cycle_start];

				// Find position where we put the item. We basically 
				// count all smaller elements on right side of item. 
				int pos = cycle_start;
				for (int i = cycle_start + 1; i < n; i++)
					if (arr[i] < item)
					{
						red_color[j] = 1;
						min_idx = j;
						drawer();
						memset(red_color, 0, sizeof(red_color));
						pos++;
					}

				// If item is already in correct position 
				if (pos == cycle_start)
				{

					continue;
				}
				// ignore all duplicate  elements 
				while (item == arr[pos])
				{
					red_color[j] = 1;
					min_idx = j;
					drawer();
					memset(red_color, 0, sizeof(red_color));

					pos += 1;
				}

				// put the item to it's right position 
				if (pos != cycle_start) {
					//swap(item, arr[pos]);
					temp = item;
					item = arr[pos];
					arr[pos] = temp;
					red_color[j] = 1;
					min_idx = j;
					drawer();
					memset(red_color, 0, sizeof(red_color));
					writes++;
				}

				// Rotate rest of the cycle 
				while (pos != cycle_start) {
					pos = cycle_start;

					// Find position where we put the element 
					for (int i = cycle_start + 1; i < n; i++)
						if (arr[i] < item) {
							red_color[j] = 1;
							min_idx = j;
							drawer();
							memset(red_color, 0, sizeof(red_color));
							pos += 1;
						}
					// ignore all duplicate  elements 
					while (item == arr[pos])
						pos += 1;

					// put the item to it's right position 
					if (item != arr[pos]) {
						//swap(item, arr[pos]);
						temp = item;
						item = arr[pos];
						arr[pos] = temp;
						red_color[j] = 1;
						min_idx = j;
						drawer();
						memset(red_color, 0, sizeof(red_color));
						writes++;
					}
				}
			}
		}
		yellow_color[min_idx] = 1;
		yellow_color[i] = 1;
		drawer();
		delay();

	}
	k = n - 1;
	for (i = 0; i < n; i++)
	{
		rev[k--] = a[i];
	}
	flag = true;

	// Number of memory writes or swaps 
	// cout << writes << endl ; 
}

void keyquit(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 114: // r
		glClear(GL_COLOR_BUFFER_BIT);
		displayrev();
		break;

		// ESC
	case 27:
		exit(0); // quit
		break;
	default:
		break;
	}
}

void drawerrev() {
	delay();
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	for (int i = 1; i <= n; i++) {
		glColor3f(1.0, 1.0, 1.0);
		if (yellow_color[i - 1])
			glColor3f(0.0, 1.0, 0.0);
		else if (red_color[i - 1])
			glColor3f(1.0, 0.0, 0.0);
		glRectf(space*i - 25, 300, space*i + 25, 400);
		RenderString(space*i - 3, 345, GLUT_BITMAP_TIMES_ROMAN_24, rev[i - 1]);
		glColor3f(0.5, 0.5, 0.5);
		glRectf(475, 450, 525, 550);
		glColor3f(0.5, 0, 0.5);
		RenderString(500 - 3, 495, GLUT_BITMAP_TIMES_ROMAN_24, temp);
	}
	glFlush();
	//glutSwapBuffers();

}
void delay() {
	for (int c = 1; c <= 10000; c++)
	{
		for (int d = 1; d <= 10000; d++)
		{
		}
	}
}

void RenderString(float x, float y, void *font, char string)
{
	glColor3f(0.0, 0.0, 1.0);
	glRasterPos2f(x, y);
	glutBitmapCharacter(font, string);
}

void init(void)
{
	glClearColor(0.0, 0.1, 0.0, 1.0); // White display window.
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 600.0, 0.0, 500.0);
}




void displayText(float x, float y, int r, int g, int b, const char *string) {
	int j = strlen(string);
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	for (int i = 0; i < j; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	glFlush();

}

void displayfirst(void) {
	displayText(350, 450, 0, 0, 1, line1);
	displayText(350, 400, 1, 1, 1, line2);
	displayText(350, 350, 1, 1, 1, line3);
	displayText(80, 250, 1, 1, 1, line4);
	displayText(80, 200, 1, 1, 1, line5);
	displayText(80, 150, 1, 1, 1, line6);
	displayText(80, 100, 1, 1, 1, line7);
}

void keys(unsigned char key, int x, int y)
{

	if (key == '1') {

		glClear(GL_COLOR_BUFFER_BIT);
		displayfirst();
	}

	if (key == '2') {
		glClear(GL_COLOR_BUFFER_BIT);
		displayText(250, 400, 1, 1, 1, line7);

	}


}

void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, GLdouble(newWidth), 0.0, GLdouble(newHeight));
	glClear(GL_COLOR_BUFFER_BIT);

}
void maincycy()
{
	cout << "Enter Number of Elements\n";
	cin >> n;
	cout << "Enter Elements\n";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	space = (1000 / (n + 1.0));
	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(1500, 700);
	glutCreateWindow("Cycle  descend Sort");
	glutDisplayFunc(displayrev);
	myInit();
}
void maincyc()
{
	cout<< "Enter Number of Elements\n";
	cin>> n;
	cout << "Enter Elements\n";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	space = 1000 / (n + 1.0);
	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(1500, 700);
	glutCreateWindow("Cycle ascend  Sort");
	myInit();
	glutDisplayFunc(display);
	
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(1000, 700);
	glutCreateWindow("Cycle Sort");
	glutCreateMenu(menu);
	glutAddMenuEntry("INTRO", 1);
	glutAddMenuEntry("ASCENDING", 2);
	glutAddMenuEntry("DESCENDING", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	myInit();
	glutKeyboardFunc(keyquit);
	glutReshapeFunc(winReshapeFcn);
	glutDisplayFunc(displayfirst);
	glutMainLoop();
}


