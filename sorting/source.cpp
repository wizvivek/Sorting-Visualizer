#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<glut.h>

#define SORT_NO 3	// Number of sorting algorithms
#define MAX 10	// Number of values in the array
#define SPEED 8000

int a[MAX];
int swapflag = 0;
int i = 0, j = 0;
int flag = 0;
int k = 0;
int sorting = 0;		// 1 if Sorted
const char* sort_string[] = { "BUBBLE  SORT","SELECTION  SORT","INSERTION  SORT" };
int sort_count = 0;	// To cycle through the string



void bitmap_output(int x, int y, const char* string, void* font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}

// Function to integer to string
void int_str(int rad, char text[])
{
	_itoa_s(rad, text, sizeof(text), 10);
}

void display_text()
{
	glColor3f(0.6, 0.5, 1.0);
	bitmap_output(295, 765, "SORTING  VISUALIZER", GLUT_BITMAP_TIMES_ROMAN_24);
	/*glBegin(GL_LINE_LOOP);
	glVertex2f(145, 660);
	glVertex2f(520, 660);
	glEnd();*/

	// other text small font
	glColor3f(0.0, 1.0, 1.0);
	bitmap_output(10, 705, "This program sorts a random set of numbers using the selected sort technique in ascending order displaying them graphically as bars with varying height.", GLUT_BITMAP_9_BY_15);


	if (sorting == 0)	// if not sorting display menu
	{
		bitmap_output(10, 675, "---MENU---", GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 645, "1.Press s to SORT", GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 620, "2.Press r to RANDOMIZE", GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 595, "3.Press c to CHANGE the sort algorithm", GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 570, "4.Esc to QUIT", GLUT_BITMAP_9_BY_15);
		glColor3f(0.4, 1.0, 0.0);
		bitmap_output(550, 575, *(sort_string + sort_count), GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (sorting == 1)	// while sorting
	{
		glColor3f(0.5, 0.5, 0.5);
		bitmap_output(10, 555, "Sorting in progress...", GLUT_BITMAP_9_BY_15);
		//bitmap_output(10, 535, "Press p to PAUSE", GLUT_BITMAP_9_BY_15);
		glColor3f(0.0, 0.0, 0.0);
	}
}

void front()
{
	glColor3f(0.6, 0.5, 1.0);
	bitmap_output(205, 765, "VISUALIZATION  OF  VARIOUS  SORTING  ALGORITHMS", GLUT_BITMAP_TIMES_ROMAN_24);
	/*glBegin(GL_LINE_LOOP);
	glVertex2f(205, 760);
	glVertex2f(497, 760);
	glEnd();*/
	//bitmap_output(280, 725, "SORTING ALGORITHMS", GLUT_BITMAP_TIMES_ROMAN_24);
	/*glBegin(GL_LINE_LOOP);
	glVertex2f(325, 521);
	glVertex2f(360, 521);
	glEnd();*/
	glColor3f(1.0, 0.0, 0.0);
	bitmap_output(10, 675, "BUBBLE SORT: Bubble sort is a simple comparison-based sorting algorithm. It repeatedly compares adjacent elements in a ", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(90, 635, "list and swaps them if they are in the wrong order. The algorithm continues this process until the entire list is", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(90, 595, "sorted. The name bubble sort comes from the way smaller elements bubble to the top of the list during", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(90, 555, " each iteration.", GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.0, 1.0, 0.0);
	bitmap_output(10, 525, "SELECTION SORT: Insertion sort is another comparison-based sorting algorithm that builds the final sorted list one element ", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(106, 485, "at a time. It divides theinput into a sorted and an unsorted region. The algorithm iterates over the unsorted ", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(106, 445, "region, taking one element at a time and inserting it into its correct position within the sorted region. It ", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(106, 405, "continues this process until the entire list is sorted.", GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.0, 0.5, 1.0);
	bitmap_output(10, 375, "INSERTION SORT: Selection sort is a simple in-place comparison-based sorting algorithm. It divides the input into a sorted and an ", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(106, 335, "unsorted region. The algorithm repeatedly selects the smallest (or largest) element from the unsorted region", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(106, 295, "and swaps it with the leftmost element of the unsorted region, expanding the sorted region. This process ", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(106, 255, " is repeated until all the elements are sorted. ", GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0.6, 0.5, 1.0);
	bitmap_output(10, 125, "Project By:-", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(10, 85, "Name: SWASTIK", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(10, 45, "USN: 1RN20CS163", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(560, 125, "Project By:-", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(560, 85, "Name: VIVEK KUMAR", GLUT_BITMAP_TIMES_ROMAN_24);
	bitmap_output(560, 45, "USN: 1RN20CS183", GLUT_BITMAP_TIMES_ROMAN_24);
	/*glBegin(GL_LINE_LOOP);
	glVertex2f(145, 470);
	glVertex2f(520, 470);
	glEnd();*/
	/*glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(300, 120.0);
	glVertex2f(300, 170);
	glVertex2f(430, 170);
	glVertex2f(430, 120.0);
	glEnd();*/
	glColor3f(0.9, 1.0, 0.0);
	bitmap_output(290, 135, "Press ENTER to continue.......", GLUT_BITMAP_HELVETICA_18);
}

void myinit()
{
	int temp1;

	// Reset the array
	for (temp1 = 0; temp1 < MAX; temp1++) {
		a[temp1] = rand() % 100 + 1;
		printf("%d ", a[temp1]);
	}

	// Reset all values
	i = j = 0;
	flag = 0;

	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 699, 0, 799);
}

// Return 1 if not sorted
int notsorted() {
	int q;
	for (q = 0; q < MAX - 1; q++)
	{
		if (a[q] > a[q + 1])
			return 1;
	}
	return 0;
}

void display()
{
	int ix, temp;
	glClear(GL_COLOR_BUFFER_BIT);

	if (k == 0)
		front();
	else {
		display_text();
		char text[10];

		for (ix = 0; ix < MAX; ix++)
		{
			glColor3f(1.0, 0.5, 0.0);
			glBegin(GL_LINE_LOOP);
			glVertex2f(10 + (700 / (MAX + 1)) * ix, 50);
			glVertex2f(10 + (700 / (MAX + 1)) * (ix + 1), 50);
			glVertex2f(10 + (700 / (MAX + 1)) * (ix + 1), 50 + a[ix] * 4);
			glVertex2f(10 + (700 / (MAX + 1)) * ix, 50 + a[ix] * 4);
			glEnd();

			int_str(a[ix], text);
			//printf("\n%s",text);
			glColor3f(1, 1, 1);
			bitmap_output(12 + (700 / (MAX + 1)) * ix, 20, text, GLUT_BITMAP_HELVETICA_18);
		}

		if (swapflag || sorting == 0)
		{
			glColor3f(1.0, 0.2, 0.0);
			glBegin(GL_POLYGON);
			glVertex2f(10 + (700 / (MAX + 1)) * j, 50);
			glVertex2f(10 + (700 / (MAX + 1)) * (j + 1), 50);
			glVertex2f(10 + (700 / (MAX + 1)) * (j + 1), 50 + a[j] * 4);
			glVertex2f(10 + (700 / (MAX + 1)) * j, 50 + a[j] * 4);
			glEnd();
			swapflag = 0;
		}
	}
	glFlush();
}

// Insertion Sort
void insertionsort()
{
	int temp;

	while (i < MAX)
	{
		if (flag == 0) { j = i; flag = 1; }
		while (j < MAX - 1)
		{
			if (a[j] > a[j + 1])
			{
				swapflag = 1;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;

				goto A;
			}
			j++;
			if (j == MAX - 1) { flag = 0; }
			printf("\nswap %d and %d\n", a[j], a[j + 1]);
		}
		i++;
	}
	sorting = 0;
A:
	i = j = 0;
}

// Selection Sort
void selectionsort()
{
	int temp, j, min, pos;

	while (notsorted())
	{

		while (i < MAX - 1)
		{
			min = a[i + 1];
			pos = i + 1;
			if (i != MAX - 1)
			{
				for (j = i + 2; j < MAX; j++)
				{
					if (min > a[j])
					{
						min = a[j];
						pos = j;
					}
				}
			}
			printf("\ni=%d min=%d at %d", i, min, pos);
			printf("\nchecking %d and %d", min, a[i]);
			if (min < a[i])
			{

				//j=pos;
				printf("\nswapping %d and %d", min, a[i]);
				temp = a[pos];
				a[pos] = a[i];
				a[i] = temp;
				goto A;
			}
			i++;
		}
	}
	sorting = 0;
	i = j = 0;
A:  printf("");
}

//Bubble Sort
void bubblesort()
{
	int temp;
	while (notsorted())
	{
		while (j < MAX - 1)
		{
			if (a[j] > a[j + 1])
			{
				swapflag = 1;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;

				goto A;
			}
			j++;
			if (j == MAX - 1) j = 0;
			printf("\nswap %d and %d\n", a[j], a[j + 1]);
		}
	}
	sorting = 0;
A: printf("");
}


// Timer Function, takes care of sort selection
void makedelay(int)
{
	if (sorting)
	{
		switch (sort_count)
		{
		case 0:	bubblesort();		break;
		case 1:	selectionsort();	break;
		case 2: insertionsort();	break;
		}
	}
	glutPostRedisplay();
	glutTimerFunc(SPEED / MAX, makedelay, 1);
}

// Keyboard Function
void keyboard(unsigned char key, int x, int y)
{
	if (key == 13)			// 13 is the ascii code for Enter key
		k = 1;
	if (k == 1 && sorting != 1)
	{
		switch (key)
		{
		case 27:	exit(0); // 27 is the ascii code for the ESC key

		case 's':	sorting = 1;
			break;
		case 'r':	myinit();
			break;
		case 'c':	sort_count = (sort_count + 1) % SORT_NO;
			break;
		}
	}


}


int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Sorting Visualizer");
	myinit();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(1000, makedelay, 1);
	glutMainLoop();
}