/*******************************************************
 * Homework 2: OpenGL                                  *
 *-----------------------------------------------------*
 * First, you should fill in problem1(), problem2(),   *
 * and problem3() as instructed in the written part of *
 * the problem set.  Then, express your creativity     *
 * with problem4()!                                    *
 *                                                     *
 * Note: you will only need to add/modify code where   *
 * it says "TODO".                                     *
 *                                                     *
 * The left mouse button rotates, the right mouse      *
 * button zooms, and the keyboard controls which       *
 * problem to display.                                 *
 *                                                     *
 * For Linux/OS X:                                     *
 * Install Make, GCC, OpenGL and freeglut.                              *
 * To compile your program, run "make" in the          *
 * command line.  Typing "make clean" will remove all  *
 * computer-generated files.  Run by typing "./hw2"    *2
 *                                                     *
 * For Visual Studio:                                  *
 * You can create a project with this main.cpp, link   *
 * to your OpenGL libs, build and run the executable   *
 * as you normally would.                              *
 *******************************************************/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "Win/include/GL/freeglut.h"

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = {0, 1, 4, 1};
int windowWidth = 640, windowHeight = 480;
double xRot = 0;
double yRot = 0;
int curProblem = 1; // TODO: change this number to try different examples

float specular[] = {1.0, 1.0, 1.0, 1.0};
float shininess[] = {50.0};

void problem1() {
  // TODO: Your code here!
  glPushMatrix(); // translation matrix

  for (int i = 0; i < 360;
       i +=
       45) { // loop rotates the coordinate system by increments of 45 degrees

    glPushMatrix(); // translation matrix

    // calculate the x and y positions based on the current angle i
    float x = sin(i * 3.14f / 180.0f);
    float y = cos(i * 3.14f / 180.0f);

    if (i % 2 != 0)
      glTranslatef(x * 0.75f, y * 0.75f, 0.0f); // for odd
    else
      glTranslatef(x, y, 0.0f); // for even

    glRotatef(180.0f - i, 0.0f, 0.0f, 1.0f); // position in the circle

    glutSolidTeapot(0.1f); // a teapot with a size of 0.1 units

    glPopMatrix(); // transformation matrix
  }

  glPopMatrix(); // transformation matrix
}

void problem2() {
  // TODO: Your code here!
  const int numerRows = 6; // number of rows
  glTranslatef(0, 0.25,
               0); // entire grid slightly up by 0.25 units along the y-axis

  for (int i = 0; i < numerRows; ++i) {
    // The number of teapots increases as we go down the rows
    int numerPots = i + 1;

    for (int j = 0; j < numerPots; ++j) {
      glPushMatrix(); // translation matrix
      // Adjust the position of each teapot based on horizontally and vertically
      glTranslatef((j - numerPots / 2.0f + 0.5f) * 0.3,
                   (i - numerRows / 2.0f + 0.5f) * 0.3, 1);
      glutSolidTeapot(0.1); // a teapot with a size of 0.1 units
      glPopMatrix();        // transformation matrix
    }
  }
}

void problem3() {
  // TODO: Your code here!
  glPushMatrix(); // translation matrix
  {
    glTranslatef(0.0f, 0.75f, -2.0f); // position
    glScalef(1.875f, 1.85f, 1.85f);   // scale
    for (int i = 0; i < 10; i++) {    // loop for the number of rows

      float size = 2.0f - 0.2f * i;     // size increases as we go down
      float height = -1.0f + 0.11f * i; // height increases as we go down

      glPushMatrix(); // translation matrix
      {
        glTranslatef(0.0f, height, 0.0f);
        if (i == 10) // if the row is last
          glScalef(0.0f, 0.1f, 0.1f);
        else
          glScalef(size, 0.1f, size);
        glutSolidCube(1.0f);
      }
      glPopMatrix(); // transformation matrix
    }
  }
  glPopMatrix(); // transformation matrix
}

void problem4() {
  // TODO: Your code here!

  glPushMatrix(); // translation matrix
  {
    // Have to return here for Palm Transformations
    glTranslatef(0.0f, 0.0f, 0.0f);
    glScalef(0.75f, 0.75f, 0.25f);
    glutSolidCube(1.0f);
    // For Thumb Finger Bones
    glPushMatrix(); // translation matrix
    {
      glTranslatef(0.65f, 0.0f, 0.05f);
      glRotatef(30.0f, 0.0f, 0.0f, -1.0f);
      glScalef(0.2f, 0.35f, 0.25f);
      glPushMatrix(); // translation matrix
      { glutSolidCube(1.0f); }
      glPopMatrix();

      glPushMatrix(); // translation matrix
      {
        glTranslatef(0.0f, 1.055f, 0.0f);
        glRotatef(10.0f, 0.0f, 0.0f, 1.0f);

        glBegin(GL_TRIANGLES); // Thump Point Part

        glVertex3f(0.0f, 0.5f, 0.0f);
        glVertex3f(-0.5f, -0.5f, 0.0f);
        glVertex3f(0.5f, -0.5f, 0.0f);
        glEnd();
      }
      glPopMatrix(); // transformation matrix
    }
    glPopMatrix();

    // For 1st Finger Bones

    glPushMatrix();
    {
      // Have to return here for first Finger Transformations
      glTranslatef(0.35f, 0.7f, 0.0f);
      glScalef(0.25f, 0.35f, 0.25f);
      glRotatef(20.0f, 0.0f, 0.0f, -1.0f);
      glPushMatrix();
      { glutSolidCube(1.0f); }
      glPopMatrix();

      glPushMatrix();
      {
        glTranslatef(0.0f, 1.055f, 0.0f);
        glutSolidCube(1.0f);

        glPushMatrix();
        {
          glTranslatef(0.0f, 1.055f, 0.0f);
          glutSolidCube(1.0f);
        }
        glPopMatrix();
      }
      glPopMatrix();
    }
    glPopMatrix();

    // For 2nd Finger Bones
    glPushMatrix();
    {
      // Have to return here for first Finger Transformations
      glTranslatef(0.0f, 0.7f, 0.0f);
      glScalef(0.25f, 0.35f, 0.25f);
      glPushMatrix();
      { glutSolidCube(1.0f); }
      glPopMatrix();

      glPushMatrix();
      {
        glTranslatef(0.0f, 1.055f, 0.0f);
        glutSolidCube(1.0f);

        glPushMatrix();
        {
          glTranslatef(0.0f, 1.055f, 0.0f);
          glutSolidCube(1.0f);
        }
        glPopMatrix();
      }
      glPopMatrix();
    }
    glPopMatrix();

    // For 3rd Finger Bones
    glPushMatrix();
    {
      // Have to return here for first Finger Transformations
      glTranslatef(-0.3f, 0.7f, 0.05f);
      glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
      glScalef(0.25f, 0.35f, 0.25f);
      glPushMatrix();
      { glutSolidCube(1.0f); }
      glPopMatrix();

      glPushMatrix();
      {
        glTranslatef(0.0f, 1.055f, 0.0f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        glutSolidCube(1.0f);

        glPushMatrix();
        {
          glTranslatef(0.0f, 1.055f, 0.0f);
          glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
          glutSolidCube(1.0f);
        }
        glPopMatrix();
      }
      glPopMatrix();
    }
    glPopMatrix();

    // For 4th Finger Bones
    glPushMatrix();
    {
      // Have to return here for first Finger Transformations
      glTranslatef(-0.55f, 0.7f, 0.05f);
      glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
      glScalef(0.2f, 0.35f, 0.25f);
      glPushMatrix();
      { glutSolidCube(1.0f); }
      glPopMatrix();

      glPushMatrix();
      {
        glTranslatef(0.0f, 1.055f, 0.0f);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        glutSolidCube(1.0f);

        glPushMatrix();
        {
          glTranslatef(0.0f, 1.055f, 0.0f);
          glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
          glutSolidCube(1.0f);
        }
        glPopMatrix();
      }
      glPopMatrix();
    }
    glPopMatrix();
  }
  glPopMatrix();
}

void display() {
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glDisable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);
  glBegin(GL_LINES);
  glColor3f(1, 0, 0);
  glVertex3f(0, 0, 0);
  glVertex3f(1, 0, 0); // x axis
  glColor3f(0, 1, 0);
  glVertex3f(0, 0, 0);
  glVertex3f(0, 1, 0); // y axis
  glColor3f(0, 0, 1);
  glVertex3f(0, 0, 0);
  glVertex3f(0, 0, 1); // z axis
  glEnd(/*GL_LINES*/);

  glEnable(GL_LIGHTING);
  glShadeModel(GL_SMOOTH);
  glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
  glEnable(GL_LIGHT0);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glViewport(0, 0, windowWidth, windowHeight);

  float ratio = (float)windowWidth / (float)windowHeight;
  gluPerspective(50, ratio, 1, 1000);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

  glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

  glRotatef(xRot, 1, 0, 0);
  glRotatef(yRot, 0, 1, 0);

  if (curProblem == 1)
    problem1();
  if (curProblem == 2)
    problem2();
  if (curProblem == 3)
    problem3();
  if (curProblem == 4)
    problem4();

  glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
  if (button == GLUT_LEFT_BUTTON)
    leftDown = (state == GLUT_DOWN);
  else if (button == GLUT_RIGHT_BUTTON)
    rightDown = (state == GLUT_DOWN);

  lastPos[0] = x;
  lastPos[1] = y;
}

void mouseMoved(int x, int y) {
  if (leftDown) {
    xRot += (y - lastPos[1]) * .1;
    yRot += (x - lastPos[0]) * .1;
  }
  if (rightDown) {
    for (int i = 0; i < 3; i++)
      cameraPos[i] *= pow(1.1, (y - lastPos[1]) * .1);
  }

  lastPos[0] = x;
  lastPos[1] = y;
  glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
  curProblem = key - '0';
  if (key == 'q' || key == 'Q' || key == 27) {
    exit(0);
  }
  glutPostRedisplay();
}

void reshape(int width, int height) {
  windowWidth = width;
  windowHeight = height;
  glutPostRedisplay();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(windowWidth, windowHeight);
  glutCreateWindow("HW2");

  glutDisplayFunc(display);
  glutMotionFunc(mouseMoved);
  glutMouseFunc(mouse);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);

  glutMainLoop();

  return 0;
}
// Source:
// https://math.hws.edu/bridgeman/courses/324/s06/doc/opengl.html
// https://www.geeksforgeeks.org/basic-transformations-opengl/