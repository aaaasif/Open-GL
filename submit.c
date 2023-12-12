/**********************************************************************
	Project 2 Demo
	Student ID:
	Student Name:
**********************************************************************/

/* -------- start various header files needed ---------- */
#include <stdio.h>
#include <stdlib.h>
#include "GL/glut.h"
#include <math.h>
#include "bitmap.h"
#include <iostream>
/* ---------- end of header files ----------- */

/* ----- start of glNewlist serial number (display list) definitions ----- */
#define TORSO			1
#define HIP				2
#define SHOULDER		3
#define UPPER_ARM		4
#define FOREARM			5
#define UPPER_LEG		6
#define LOWER_LEG		7
#define FOOT			8
#define HEAD			9	
#define ENVIRONMENT		10
/* ----- end of glNewlist serial number (display list) definitions ----- */

/* ----- start of motion rate definitions ----- */
#define TORSO_ROTATE_RATE	10		/* motion rate for variable "pivot" */
#define TORSO_TILT_RATE		10		/* motion rate for variable "tilt" */

#define UPPER_LEG_RATE	3			/* motion rate for variable "left_hip" and "right_hip" */
#define LOW_LEG_RATE	3			/* motion rate for variable "left_knee" and "right_knee" */
#define ANKLE_RATE		3			/* motion rate for variable "left_ankle" and "right_ankle" */

#define SHOULDER_RATE	5			/* motion rate for variable "left_shoulder" and "right_shoulder" */
#define ELBOW_RATE		2			/* motion rate for variable "left_elbow" and "right_elbow" */

#define LIGHT_TURN_RATE	10			/* motion rate for variable "lightturn" and "lightturn1" */
#define VIEW_TURN_RATE	10			/* motion rate for variable "turn" and "turn1"*/
/* ----- end of motion rate definitions ----- */

#define M_PI 3.141592654

GLubyte* teximage1, * teximage2, * teximage3;
int w1, w2, w3, h1, h2, h3;
GLUquadricObj* sphere1, * sphere2;


/* ----- start of definitions on motion variables ----- */
/* definitions on rotation angles for different joints */
int right_shoulder = 0, left_shoulder = 0;		/* rotate forward and backward at the left and right shoulder joints */
int right_elbow = 20, left_elbow = 20;			/* rotate at both elbow joints */
int pivot = 0;			                        /* rotate around pivot at waist joint */
int tilt = 10;									/* rotate forward and backward at waist joint */
int right_ankle = 0, left_ankle = 0;			/* rotate at the left and right ankle joints */
int right_knee = -30, left_knee = -30;				/* rotate at the left and right knee joints */
int right_hip = 0, left_hip = 0;				/* rotate forward and backward at the left and right coxa joints */

/* definitions on rotation angles for view and lights */
int turn = 0, turn1 = 0;						/* turn view to left and right, forward and backward */
int lightturn = 0, lightturn1 = 0;				/* turn light to left and right, forward and backward */

float elevation = 0.0, distance = 0.0, frame = 3.0;  /* variable use for animation */
int i;
/* ----- end of motion variables ----- */

/* ----- start of material definitions ----- */
GLfloat mat_specular1[] = { 0.628281, 0.555802, 0.366065, 1.0 };
GLfloat mat_ambient1[] = { 0.24725, 0.1995, 0.0745, 1.0 };
GLfloat mat_diffuse1[] = { 0.75164, 0.60648, 0.22648, 1.0 };
GLfloat mat_shininess1[] = { 128.0 * 0.4 };

GLfloat mat_specular2[] = { 0.508273, 0.508273, 0.508373 };
GLfloat mat_ambient2[] = { 0.19225, 0.19225, 0.19225 };
GLfloat mat_diffuse2[] = { 0.50754, 0.50754, 0.50754 };
GLfloat mat_shininess2[] = { 128.0 * 0.6 };

GLfloat mat_specular3[] = { 0.296648, 0.296648, 0.296648 };
GLfloat mat_ambient3[] = { 0.25, 0.20725, 0.20725 };
GLfloat mat_diffuse3[] = { 1, 0.829, 0.829 };
GLfloat mat_shininess3[] = { 128.0 * 0.088 };

GLfloat mat_specular4[] = { 0.633, 0.727811, 0.633 };
GLfloat mat_ambient4[] = { 0.0215, 0.1745, 0.0215 };
GLfloat mat_diffuse4[] = { 0.07568, 0.61424, 0.07568 };
GLfloat mat_shininess4[] = { 128 * 0.6 };

GLfloat mat_specular5[] = { 0.60, 0.60, 0.50 };
GLfloat mat_ambient5[] = { 0.0, 0.0, 0.0 };
GLfloat mat_diffuse5[] = { 0.5, 0.5, 0.0 };
GLfloat mat_shininess5[] = { 128.0 * 0.25 };

unsigned int texture;

/* end of material definitions */

/* ----- start of function to define materials properties ----- */
void SetMaterial(GLfloat spec[], GLfloat amb[], GLfloat diff[], GLfloat shin[])
{

	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
	glMaterialfv(GL_FRONT, GL_SHININESS, shin);
	glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);
}
/* ----- end of function to define materials properties ----- */

/* -------------- start of drawing torso ---------------- */
void DrawTorso(void)
{
	glNewList(TORSO, GL_COMPILE);

	/* design torso of your puppet here, for example, draw a sphere as torso */


	glEndList();
}
/* -------------- end of drawing torso ---------------- */


/* -------------------- start of drawing hip --------------------- */
void DrawHip(void)
{
	glNewList(HIP, GL_COMPILE);

	/* design hip of your puppet here */


	glEndList();
}
/* -------------------- end of drawing hip --------------------- */


/* -------------------- start of drawing shoulder --------------------- */
void DrawShoulder(void)
{
	glNewList(SHOULDER, GL_COMPILE);

	/* design shoulder of your puppet here */


	glEndList();
}
/* -------------------- end of drawing shoulder --------------------- */


/* -------------------- start of drawing upper arm --------------------- */
void DrawUpperArm(void)
{
	glNewList(UPPER_ARM, GL_COMPILE);

	/* design upper arm of your puppet here */


	glEndList();
}
/* -------------------- end of drawing upper arm --------------------- */


/* -------------------- start of drawing forearm --------------------- */
void DrawForeArm(void)
{
	glNewList(FOREARM, GL_COMPILE);

	/* design forearm of your puppet here */


	glEndList();
}
/* -------------------- end of drawing forearm --------------------- */


/* -------------------- start of drawing upper leg --------------------- */
void DrawUpperLeg(void)
{
	glNewList(UPPER_LEG, GL_COMPILE);

	/* design upper leg of your puppet here */


	glEndList();
}
/* -------------------- end of drawing upper leg --------------------- */


/* -------------------- start of drawing lower leg --------------------- */
void DrawLowerLeg(void)
{
	glNewList(LOWER_LEG, GL_COMPILE);

	/* design lower leg of your puppet here */


	glEndList();
}
/* -------------------- end of drawing lower leg --------------------- */


/* -------------------- start of drawing foot --------------------- */
void DrawFoot(void)
{
	glNewList(FOOT, GL_COMPILE);

	/* design foot of your puppet here */


	glEndList();
}


/* -------------------- start of drawing head --------------------- */
void DrawHead(void)
{
	glNewList(HEAD, GL_COMPILE);

	/* design head of your puppet here */


	glEndList();
}


/* -------------------- start of drawing environment --------------------- */
void DrawEnvironment(void)
{
	int i, j;

	glNewList(ENVIRONMENT, GL_COMPILE);

	SetMaterial(mat_specular4, mat_ambient4, mat_diffuse4, mat_shininess4);
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();

	/* -------------- start of adding texture to the floor --------------- */
	glEnable(GL_TEXTURE_2D);
	/*Adding a texture via the glTexImage2D function, write your code here*/

	glScalef(20.0, 0.5, 30.0);
	glutSolidCube(1.0);
	glDisable(GL_TEXTURE_2D);
	/* --------------- end of adding texture to the floor --------------- */

	glPopMatrix();
	SetMaterial(mat_specular4, mat_ambient3, mat_diffuse2, mat_shininess1);
	glColor3f(0.6, 0.6, 0.6);
	glTranslatef(0.0, 0.0, -10.0);
	for (j = 0; j < 6; j++) {
		for (i = 0; i < 2; i++) {
			if (i)
				glScalef(-1.0, 1.0, 1.0);
			glTranslatef(10.0, 4.0, 0.0);
			glPushMatrix();
			glScalef(4.0, 8.0, 2.0);
			glutSolidCube(1.0);
			glPopMatrix();
			glTranslatef(0.0, -1.0, -3.0);
			glPushMatrix();
			glScalef(4.0, 6.0, 2.0);
			glutSolidCube(1.0);
			glPopMatrix();
			glTranslatef(-10.0, -3.0, 3.0);
		}
		glScalef(-1.0, 1.0, 1.0);
		glTranslatef(0.0, 0.0, 5.0);
	}

	glEndList();
}
/* -------------------- end of drawing environment --------------------- */


void disable(void)
{
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_NORMALIZE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}


/*-----------------LIGHTS STUFF------------------*/
void lighting(void)
{
	/* light position */
   /* you may need to midify 2.0 to larger value according to size of your model */
	GLfloat position[] = { 0.0, 0.0, 2.0, 1.0 };

	/* you need to draw a wire cube or sphere to simulate position of lighting */
	/* use spot lighting  and rotate light*/

	/* write your code here */
	glColor3f(1, 1, 1);
	glRotatef(lightturn1, 1, 0, 0);
	glRotatef(lightturn, 0, 1, 0);
	glTranslated(0, 0, 2);
	glutWireSphere(.1, 10, 5);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

}


/* ----------- start of integration of whole puppet -------------- */
void DrawPuppet(void)
{

	/* construct the puppet part by part here
		Note: use PushMatrix and PopMatrix to construct the hierarchical relationship
			  between defferent parts.
		Note the relationship betweem parts:
			  shoulder and hip are torso's children, upper arm is shoulder's child, and forearm is upper arm's child;
			  upper leg is hip's child, and lower leg is upper leg's child;
		So if we move torso for example, arms and forarms move too.
	 */
	
	 /* Write your code below  */
	
}
/* ----------- end of integration of whole puppet -------------- */


/* ------------- start of display function --------------- */
void display(void)
{
	/* Clear Screen And Depth Buffer  */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glPushMatrix();
	/* camera stuff */
	glRotatef((GLfloat)turn, 0.0, 1.0, 0.0);
	glRotatef((GLfloat)turn1, 1.0, 0.0, 0.0);

	/* light stuff */
	glPushMatrix();
	lighting();
	glPopMatrix();

	/* draw puppet */
	glPushMatrix();
	glTranslatef(0.0, elevation, 0.0);
	DrawPuppet();
	glPopMatrix();

	/* draw environment */
	glPushMatrix();
	if (distance >= 20.136)
		distance = 0.0;
	glTranslatef(0.0, -5.0, -distance);
	glCallList(ENVIRONMENT);
	glTranslatef(0.0, 0.0, 10.0);
	glCallList(ENVIRONMENT);
	glPopMatrix();

	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}
/* ------------- end of display function --------------- */

 //capture the BMP file
GLubyte* TextureLoadBitmap(char* filename, int* w, int* h)		/* I - Bitmap file to load */
{
	BITMAPINFO* info;				/* Bitmap information */
	void* bits;				/* Bitmap pixel bits */
	GLubyte* rgb;				/* Bitmap RGB pixels */

	/*
	 * Try loading the bitmap and converting it to RGB...
	 */

	bits = LoadDIBitmap(filename, &info);
	rgb = ConvertRGB(info, bits);
	if (rgb == NULL)
	{
		free(info);
		free(bits);
	};

	*w = info->bmiHeader.biWidth;
	*h = info->bmiHeader.biHeight;

	/*
	 * Free the bitmap and RGB images, then return 0 (no errors).
	 */

	free(info);
	free(bits);
	return (rgb);

}

void LoadGLTextures() {
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	/*Here is an example of adding a spherical texture, go ahead and add your code here.*/

	//Create a new secondary geometry object
	sphere1 = gluNewQuadric();
	//Enable or disable the generation of texture coordinates
	gluQuadricTexture(sphere1, GL_TRUE);
	//Load texture image via TextureLoadBitmap function
	char f_name[1][20] = { "earth.bmp"};
	teximage1 = TextureLoadBitmap(f_name[0], &w1, &h1);

}


/* ----------- start of initial function ----------- */
void myinit(void)
{
	/* Clear Screen color and Enable Hidden Surface Removal */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	/* other environment setting */
	glShadeModel(GL_SMOOTH);

	// load texture 
	LoadGLTextures();

	// initial puppet structures 
	DrawTorso();
	DrawHip();
	DrawShoulder();
	DrawHead();
	DrawUpperArm();
	DrawForeArm();
	DrawUpperLeg();
	DrawLowerLeg();
	DrawFoot();

	// initial environment 
	DrawEnvironment();
}
/* ----------- end of initial function ----------- */


/* ------------- start of reshape function --------------- */
void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/* you may need to modify the parameters in next sentence according to size of your model */
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	/* you may need to modify following parameters according to coordinates of your model */
	glTranslatef(0.0, 1.2, -5.5);  /* viewing transform  */
}


/* ------------- start of animation function --------------- */
void animation_run(void)
{
	//write your code here
	if (i % 40 == 0)
	{
		int right_shoulder = 0, left_shoulder = 0;		/* rotate forward and backward at the left and right shoulder joints */
		int right_elbow = 20, left_elbow = 20;			/* rotate at both elbow joints */
		int pivot = 0;			                        /* rotate around pivot at waist joint */
		int tilt = 10;									/* rotate forward and backward at waist joint */
		int right_ankle = 0, left_ankle = 0;			/* rotate at the left and right ankle joints */
		int right_knee = -30, left_knee = -30;				/* rotate at the left and right knee joints */
		int right_hip = 0, left_hip = 0;				/* rotate forward and backward at the left and right coxa joints */
	}
	if (i % 40 < 10 || i % 40 >= 30)
	{
		left_shoulder -= SHOULDER_RATE;
		left_elbow -= ELBOW_RATE;
		right_shoulder += SHOULDER_RATE;
		right_elbow += ELBOW_RATE;
		left_hip += UPPER_LEG_RATE;
		left_knee += LOW_LEG_RATE;
		left_ankle += ANKLE_RATE;
		right_hip -= UPPER_LEG_RATE;
		right_knee -= LOW_LEG_RATE;
		right_ankle -= ANKLE_RATE;
	}
	else
	{
		left_shoulder += SHOULDER_RATE;
		right_shoulder -= SHOULDER_RATE;
		left_elbow += ELBOW_RATE;
		right_elbow -= ELBOW_RATE;
		left_hip -= UPPER_LEG_RATE;
		right_hip += UPPER_LEG_RATE;
		left_knee -= LOW_LEG_RATE;
		right_knee += LOW_LEG_RATE;
		left_ankle -= ANKLE_RATE;
		right_ankle += ANKLE_RATE;
	}

	if (i % 2 < 1)
	{
		tilt += TORSO_TILT_RATE;
	}
	else
	{
		tilt -= TORSO_TILT_RATE;
	}
	i++;
	distance += 1.0;

	glutPostRedisplay();
}
/* ------------- end of animation function --------------- */


/* ----------- start of keyboard events handling functions ------------ */
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		/* start arm control functions */
	case 'q':
		/* wirte your code here */

	case 'Q':
		/* wirte your code here */

	case 'w':
		/* wirte your code here */

	case 'W':
		/* wirte your code here */

	case 'e':
		/* wirte your code here */

	case 'E':
		/* wirte your code here */

	case 'r':
		/* wirte your code here */

	case 'R':
		/* wirte your code here */

		/* end of arm control functions */

		/* start of torso control functions */
	case 'y':
		/* wirte your code here */

	case 'Y':
		/* wirte your code here */

	case 'u':
		/* wirte your code here */

	case 'U':
		/* wirte your code here */

		/* end of torso control functions */

		/* start of leg control functions */
	case 'a':
		/* wirte your code here */

	case 'A':
		/* wirte your code here */

	case 's':
		/* wirte your code here */

	case 'S':
		/* wirte your code here */

	case 'd':
		/* wirte your code here */

	case 'D':
		/* wirte your code here */

	case 'f':
		/* wirte your code here */

	case 'F':
		/* wirte your code here */

	case 'g':
		/* wirte your code here */

	case 'G':
		/* wirte your code here */

	case 'h':
		/* wirte your code here */

	case 'H':
		/* wirte your code here */

		/* end of leg control functions */

		/* start of light source position functions */
	case 'o':
		/* wirte your code here */

	case 'p':
		/* wirte your code here */

	case 'k':
		/* wirte your code here */

	case 'l':
		/* wirte your code here */

		/* end of light source position functions */
	default:
		break;
	}
	glutPostRedisplay();

}
/* ----------- end of keyboard events handling functions ------------ */


/* --------- start of special keys implementation --------- */
void special(int key, int x, int y)
{
	int i = 0;

	switch (key) {
		/* start of view position functions */
	case GLUT_KEY_RIGHT:
		turn = (turn - VIEW_TURN_RATE) % 360;
		i++;
		break;
	case GLUT_KEY_LEFT:
		turn = (turn + VIEW_TURN_RATE) % 360;
		i++;
		break;
	case GLUT_KEY_DOWN:
		turn1 = (turn1 - VIEW_TURN_RATE) % 360;
		i++;
		break;
	case GLUT_KEY_UP:
		turn1 = (turn1 + VIEW_TURN_RATE) % 360;
		i++;
		break;
		/* end of view postions functions */
	}
	if (i)
		glutPostRedisplay();
}
/* --------- end of special keys implementation --------- */


/* --------- start of menu implementation ---------- */
void menu_select(int mode)
{
	switch (mode) {
	case 1:
		glutIdleFunc(animation_run);
		break;
	case 2:
		glutIdleFunc(NULL);
		break;
	case 3:
		exit(EXIT_SUCCESS);
	}
}

/* ARGSUSED */
void null_select(int mode)
{
}

void glutMenu(void)
{
	int glut_menu[12];

	/* move the arms -- at the shoulders */
	glut_menu[4] = glutCreateMenu(null_select);
	glutAddMenuEntry("forward       : q,w", 0);
	glutAddMenuEntry("backwards     : Q,W", 0);

	/* move the arms -- at the elbows */
	glut_menu[5] = glutCreateMenu(null_select);
	glutAddMenuEntry("upwards       : e,r", 0);
	glutAddMenuEntry("downwards     : E,R", 0);

	/* move the legs -- at the hips */
	glut_menu[7] = glutCreateMenu(null_select);
	glutAddMenuEntry("forward       : a,s", 0);
	glutAddMenuEntry("backwards     : A,S", 0);

	/* move the legs -- at the knees */
	glut_menu[8] = glutCreateMenu(null_select);
	glutAddMenuEntry("forward       : d,f", 0);
	glutAddMenuEntry("backwards     : D,F", 0);

	/* move the legs -- at the ankles */
	glut_menu[9] = glutCreateMenu(null_select);
	glutAddMenuEntry("toes up       : g,h", 0);
	glutAddMenuEntry("toes down     : G,H", 0);

	/* rotate the scene */
	glut_menu[10] = glutCreateMenu(null_select);
	glutAddMenuEntry("right         : right arrow", 0);
	glutAddMenuEntry("left          : left arrow", 0);
	glutAddMenuEntry("down          : up arrow", 0);
	glutAddMenuEntry("up            : down arrow", 0);

	/* rotate the light source */
	glut_menu[11] = glutCreateMenu(null_select);
	glutAddMenuEntry("right         : o", 0);
	glutAddMenuEntry("left          : p", 0);
	glutAddMenuEntry("up            : k", 0);
	glutAddMenuEntry("down          : l", 0);

	/* move the arms */
	glut_menu[3] = glutCreateMenu(NULL);
	glutAddSubMenu("at the shoulders? ", glut_menu[4]);
	glutAddSubMenu("at the elbows?", glut_menu[5]);

	/* move the legs */
	glut_menu[6] = glutCreateMenu(NULL);
	glutAddSubMenu("at the hip? ", glut_menu[7]);
	glutAddSubMenu("at the knees?", glut_menu[8]);
	glutAddSubMenu("at the ankles? ", glut_menu[9]);

	/* rotate at waist */
	glut_menu[1] = glutCreateMenu(null_select);
	glutAddMenuEntry("turn left    : u", 0);
	glutAddMenuEntry("turn right   : U", 0);

	/* move the torso */
	glut_menu[2] = glutCreateMenu(null_select);
	glutAddMenuEntry("tilt backwards : y", 0);
	glutAddMenuEntry("tilt forwards  : Y", 0);

	glut_menu[0] = glutCreateMenu(NULL);
	glutAddSubMenu("move the arms.. ", glut_menu[3]);
	glutAddSubMenu("move the legs.. ", glut_menu[6]);
	glutAddSubMenu("rotate the waist?", glut_menu[1]);
	glutAddSubMenu("move the torso?", glut_menu[2]);
	glutAddSubMenu("rotate the scene..", glut_menu[10]);
	glutAddSubMenu("rotate the light source..", glut_menu[11]);

	glutCreateMenu(menu_select);

	glutAddMenuEntry("Run!", 1);
	glutAddMenuEntry("Stop Running.", 2);
	glutAddSubMenu("How do I ..", glut_menu[0]);
	glutAddMenuEntry("Bye~", 3);

	glutAttachMenu(GLUT_LEFT_BUTTON);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
/* --------- end of menu implementation ---------- */


int main(int argc, char** argv)
{
	
	/* start of glut windowing and control functions */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("3D puppet");
	myinit();
	glutDisplayFunc(display);
	glutReshapeFunc(myReshape);

	glutKeyboardFunc(keyboard);

	glutSpecialFunc(special);
	glutMenu();
	glutMainLoop();

	return 0;
}