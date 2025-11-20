#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std;

int currentScenario = 1; // Start with scenario 1

// Scenario 2 globals and functions (prefixed with r)
float _move = 0.0f;
bool rtrainMoving = false;
float rtrainSpeed = 0.06f;

int rship = -750, window = 0, blx = 0, bly = 0, c1 = 0, c2 = 0, rboatX = 950;
float rcloud1X = 200, rcloud2X = 500, rcloud3X = 1200;
bool rshipMoving = false, rboatMoving = false;
bool isNight = false;

const float SCALE_X = 40.0f / 1500.0f;
const float SCALE_Y = 40.0f / 1000.0f;
const float OFFSET_X = -20.0f;
const float OFFSET_Y = -20.0f;

void scaledVertex2f(float x, float y) {
    glVertex2f(x * SCALE_X + OFFSET_X, y * SCALE_Y + OFFSET_Y);
}
//ID_41
//Train
void rcircle(float x, float y, float z) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslatef(x, y, z);
    glScalef(2.0f, 2.0f, 1.0f);

   //wheel whole - medium cool gray
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(130, 138, 140);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.2;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();

    // wheel inner - medium-dark gray
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(90, 92, 97);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.15;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();

    //wheel inner - medium cool gray
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(130, 138, 140);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.05;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
    glEnd();
        glPopMatrix();
}
void rTrainWindow(float x, float y, float z) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y, z);
    //glScalef(17.0f, 17.0f, 1.0f);

    //whole body - off-black
glBegin(GL_POLYGON);
glColor3ub(44, 48, 51); // Base color passed as argument
glVertex2f(-11.26f, -13.55f); // L2
glVertex2f(-9.67f, -13.55f);  // O2
glVertex2f(-9.68f, -14.28f);  // N2
glVertex2f(-11.26f, -14.29f); // M2
glEnd();

// window shades - dark slate gray
glBegin(GL_POLYGON);
glColor3ub(64, 69, 71); // Base color passed as argument
glVertex2f(-11.26f, -14.05f); // P2
glVertex2f(-10.82f, -13.55f); // S2
glVertex2f(-10.69f, -13.55f); // R2
glVertex2f(-11.26f, -14.16f); // Q2
glEnd();

// window shades - dark slate gray
glBegin(GL_POLYGON);
glColor3ub(64, 69, 71); // Base color passed as argument
glVertex2f(-10.25f, -13.55f); // U2
glVertex2f(-10.04f, -13.55f); // V2
glVertex2f(-10.54f, -14.29f); // W2
glVertex2f(-10.86f, -14.29f); // T2
glEnd();

// window shades - dark slate gray
glBegin(GL_POLYGON);
glColor3ub(64, 69, 71); // Base color passed as argument
glVertex2f(-10.2f, -14.29f);  // Z2
glVertex2f(-9.98f, -14.29f);  // A3
glVertex2f(-9.68f, -13.9f);   // B3
glVertex2f(-9.68f, -13.78f);  // C3
glEnd();


        glPopMatrix();
}

void rTrainWindowLittle(float x, float y, float z) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(0.55f, 0.55f, 1.0f);


    //whole body - off-black
glBegin(GL_POLYGON);
glColor3ub(44, 48, 51); // Base color passed as argument
glVertex2f(-11.28f, -13.55f); // L2
glVertex2f(-9.67f, -13.53f);  // O2
glVertex2f(-9.68f, -14.28f);  // N2
glVertex2f(-11.26f, -14.29f); // M2
glEnd();

// window shades - dark slate gray
glBegin(GL_POLYGON);
glColor3ub(64, 69, 71); // Base color passed as argument
glVertex2f(-11.28f, -14.05f); // P2
glVertex2f(-10.82f, -13.53f); // S2
glVertex2f(-10.69f, -13.54f); // R2
glVertex2f(-11.27f, -14.16f); // Q2
glEnd();

// window shades - dark slate gray
glBegin(GL_POLYGON);
glColor3ub(64, 69, 71); // Base color passed as argument
glVertex2f(-10.25f, -13.53f); // U2
glVertex2f(-10.04f, -13.53f); // V2
glVertex2f(-10.54f, -14.29f); // W2
glVertex2f(-10.86f, -14.29f); // T2
glEnd();

// window shades - dark slate gray
glBegin(GL_POLYGON);
glColor3ub(64, 69, 71); // Base color passed as argument
glVertex2f(-10.2f, -14.29f);  // Z2
glVertex2f(-9.98f, -14.29f);  // A3
glVertex2f(-9.68f, -13.9f);   // B3
glVertex2f(-9.68f, -13.78f);  // C3
glEnd();


        glPopMatrix();
}
void rTrainDoor(float x, float y, float z) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(0.68f, 1.0f, 1.0f);

//2ND DOOR Body - light, desaturated blue-gray

glBegin(GL_POLYGON);
glColor3ub(204, 204, 214); // Base color passed as argument
glVertex2f(-5.74f, -14.91f); // U3
glVertex2f(-4.4f, -14.91f);  // V3
glVertex2f(-4.35f, -16.92f); // Z3
glVertex2f(-5.73f, -16.94f); // W3
glEnd();

//2ND DOOR Body outline- dark, muted gray with a very subtle hint of purple or brown

glLineWidth(3);
glBegin(GL_LINE_LOOP);
glColor3ub(69, 69, 76); // Base color passed as argument
glVertex2f(-5.74f, -14.91f); // U3
glVertex2f(-4.35f, -14.91f);  // V3
glVertex2f(-4.35f, -16.92f); // Z3
glVertex2f(-5.73f, -16.92f); // W3
glEnd();

//2ND DOOR MIDDLE - dark, muted gray with a very subtle hint of purple or brown
glLineWidth(3);
glBegin(GL_LINES);
glColor3ub(69, 69, 76);// Base color passed as argument
glVertex2f(-5.0352,-14.90373);  // Q3
glVertex2f(-5.04115,-16.92493);  // R3

glEnd();

//Door window - dark charcoal gray
glBegin(GL_POLYGON);
glColor3ub(51, 56, 61); // Base color passed as argument
glVertex2f(-5.53f, -15.09f);  // C4
glVertex2f(-5.24f, -15.09f); // D4
glVertex2f(-5.24f, -15.99f); // F4
glVertex2f(-5.53f, -15.99f); // E4
glEnd();

//Door window - dark charcoal gray
glBegin(GL_POLYGON);
glColor3ub(51, 56, 61);// Base color passed as argument
glVertex2f(-4.88f, -15.09f); // G4
glVertex2f(-4.61f, -15.09f);   // H4
glVertex2f(-4.61f, -15.99f); // J4
glVertex2f(-4.88f, -15.99f); // I4
glEnd();
        glPopMatrix();
}
void rCompartment(float x, float y, float z) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y, z);
    //glScalef(17.0f, 17.0f, 1.0f);

    //holding together piece in the middle of two compartment
    glBegin(GL_POLYGON);
glColor3ub(64, 69, 71); // Base color passed as argument
glVertex2f(-3.76f, -13.66f);  // S1
glVertex2f(-3.52f, -13.69f);  // T4
glVertex2f(-3.5f, -16.95f);   // Z4
glVertex2f(-3.75f, -16.96f);  // N1
glEnd();
//second compartment wheels
    rcircle(-2.5,-17.7,0);
    rcircle(-1.7,-17.7,0);
    rcircle(-0.9,-17.7,0);
    rcircle(-0.1,-17.7,0);

    rcircle(6.5,-17.7,0);
    rcircle(7.3,-17.7,0);
    rcircle(8.1,-17.7,0);
    rcircle(8.9,-17.7,0);
//Second compartment - bodyv - red
glBegin(GL_POLYGON);
glColor3ub(204, 82, 71);  // Base color passed as argument
glVertex2f(-3.52f, -13.18f); // S4
glVertex2f(-3.5f, -17.47f);  // B5
glVertex2f(9.66f, -17.41f);  // C5
glVertex2f(9.66f, -13.14f);  // K5
glEnd();

//Second compartment upper part - salmon red
glBegin(GL_POLYGON);
glColor3ub(220, 110, 99); // Base color passed as argument
glVertex2f(-3.52f, -13.18f); // S4
glVertex2f(-3.52f, -13.69f); // T4
glVertex2f(9.67f, -13.62f);  // J5
glVertex2f(9.66f, -13.14f);  // K5
glEnd();

//Second compartment grey streak body - medium gray with a slight blue tint
glBegin(GL_POLYGON);
glColor3ub(128, 138, 140);// Base color passed as argument
glVertex2f(9.66437,-14.51572);  // I5
glVertex2f(9.66f, -15.17f);  // F5
glVertex2f(-3.49f, -15.21f); // L5
glVertex2f(-3.51f, -14.57f); // U4
glEnd();

//Second compartment grey streak middle - lavender gray
glBegin(GL_POLYGON);
glColor3ub(204, 204, 214); // Base color passed as argument
glVertex2f(-3.51f, -14.66f); // V4
glVertex2f(-3.5f, -14.77f);  // W4
glVertex2f(9.67f, -14.69f);  // G5
glVertex2f(9.66f, -14.59f);  // H5
glEnd();

//Second compartment second lowest part - brick red
glBegin(GL_POLYGON);
glColor3ub(178, 69, 69); //  brick red
glVertex2f(9.68f, -16.91f);  // E5
glVertex2f(9.68f, -17.19f);  // D5
glVertex2f(-3.5f, -17.24f);  // A5
glVertex2f(-3.5f, -16.95f);  // Z4
glEnd();

//Second compartment lowest part - gray
glBegin(GL_POLYGON);
glColor3ub(51, 51, 51); // Base color passed as argument
glVertex2f(9.68f, -17.19f);  // D5
glVertex2f(9.66f, -17.41f);  // C5
glVertex2f(-3.5f, -17.47f);  // B5
glVertex2f(-3.5f, -17.24f);  // A5
glEnd();

//Second compartment doors
rTrainDoor(1,0,0);
rTrainDoor(12.3,0,0);

//Second compartment windows upper
rTrainWindow(9.5,0,0);
rTrainWindow(11.5,0,0);
rTrainWindow(13.5,0,0);
rTrainWindow(15.5,0,0);
rTrainWindow(17.5,0,0);

//Second compartment windows lower
rTrainWindowLittle(4.4,-8.5,0);
rTrainWindowLittle(5.4,-8.5,0);
rTrainWindow(11.5,-2,0);
rTrainWindow(13.5,-2,0);
rTrainWindow(15.5,-2,0);
rTrainWindowLittle(12.3,-8.5,0);
rTrainWindowLittle(13.3,-8.5,0);


        glPopMatrix();
}

//sId1
void rWholeTrain(float x, float y, float z) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move, 0.0f, 0.0f);
    glTranslatef(x, y, z);
    //glScalef(17.0f, 17.0f, 1.0f);

    rcircle(-15.8,-17.7,0);
    rcircle(-15.0,-17.7,0);
    rcircle(-14.2,-17.7,0);
    rcircle(-13.4,-17.7,0);

    rcircle(-4.5,-17.7,0);
    rcircle(-5.3,-17.7,0);
    rcircle(-6.1,-17.7,0);
    rcircle(-6.9,-17.7,0);


    // Train body - red
glBegin(GL_POLYGON);
glColor3ub(204, 82, 71); // Base color passed as argument
glVertex2f(-16.92f, -17.53f); // F1
glVertex2f(-16.89f, -17.31f); // G1
glVertex2f(-16.91f, -17.01f); // H1
glVertex2f(-16.47f, -15.82f); // I1
glVertex2f(-15.19f, -14.39f); // J1
glVertex2f(-13.41f, -13.24f); // K1
glVertex2f(-3.76f, -13.21f);  // L1
glVertex2f(-3.74f, -17.5f);   // M1
glEnd();

//Lowest part grey
glBegin(GL_POLYGON);
glColor3ub(51, 51, 51); // Base color passed as argument
glVertex2f(-16.89f, -17.53f); // F1
glVertex2f(-16.89f, -17.31f); // G1
glVertex2f(-3.74f, -17.25f);  // O1
glVertex2f(-3.74f, -17.5f);   // M1
glEnd();

//2nd lowest part - brick red
glBegin(GL_POLYGON);
glColor3ub(178, 69, 69); // Base color passed as argument
glVertex2f(-3.74f, -17.25f);  // O1
glVertex2f(-3.75f, -16.96f);  // N1
glVertex2f(-16.91f, -17.01f); // H1
glVertex2f(-16.89f, -17.31f); // G1
glEnd();

//train front window body - off-black
glBegin(GL_POLYGON);
glColor3ub(44, 48, 51); // Base color passed as argument
glVertex2f(-15.19f, -14.39f); // J1
glVertex2f(-14.03f, -14.42f); // P1
glVertex2f(-14.03f, -15.81f); // Q1
glVertex2f(-16.47f, -15.81f); // I1
glEnd();

//train front window shade - dark slate gray
glBegin(GL_POLYGON);
glColor3ub(64, 69, 71); // Base color passed as argument
glVertex2f(-15.06f, -14.38f); // T1
glVertex2f(-14.77f, -14.39f); // U1
glVertex2f(-15.8f, -15.8f);   // W1
glVertex2f(-16.33f, -15.78f); // V1
glEnd();

//train front window shade - dark slate gray
glBegin(GL_POLYGON);
glColor3ub(64, 69, 71); // Base color passed as argument
glVertex2f(-14.33f, -14.4f); // Z1
glVertex2f(-14.12f, -14.4f); // A2
glVertex2f(-14.93f, -15.77f); // C2
glVertex2f(-15.34f, -15.78f); // B2
glEnd();

// train upper shade - salmon pink
glBegin(GL_POLYGON);
glColor3ub(220, 110, 99); // Base color passed as argument
glVertex2f(-13.41f, -13.24f); // K1
glVertex2f(-3.76f, -13.21f);  // L1
glVertex2f(-3.74f, -13.66f);  // S1
glVertex2f(-14.04f, -13.69f); // R1
glEnd();

//grey streak in front - medium gray with a slight blue tint
glBegin(GL_POLYGON);
glColor3ub(128, 138, 140);// Base color passed as argument
glVertex2f(-11.7f, -15.22f);   // D2
glVertex2f(-10.86f, -14.59f);  // E2
glVertex2f(-3.75f, -14.54f);   // F2
glVertex2f(-3.74f, -15.2f);    // G2
glEnd();

//middle light grey streak in front - lavender gray
glBegin(GL_POLYGON);
glColor3ub(204, 204, 214); // Base color passed as argument
glVertex2f(-3.75f, -14.64f);   // H2
glVertex2f(-3.75f, -14.73f);   // I2
glVertex2f(-11.1f, -14.76f);   // J2
glVertex2f(-10.97f, -14.66f);  // K2
glEnd();

//Windows
rTrainWindow(0.3,0.0,0);
rTrainWindow(2.3,0.0,0);
rTrainWindow(4.3,0.0,0);
rTrainWindow(2.3,-2.0,0);
rTrainWindow(0.3,-2.0,0);
rTrainWindowLittle(-0.0,-8.5,0);
rTrainWindowLittle(-1.0,-8.5,0);


//  front door body - salmon pink
glBegin(GL_POLYGON);
glColor3ub(220, 110, 99); // Base color passed as argument
glVertex2f(-13.33f, -14.95f); // E3
glVertex2f(-12.37f, -14.93f); // F3
glVertex2f(-12.36f, -16.78f); // G3
glVertex2f(-13.31f, -16.77f); // H3
glEnd();

//  front door body outline - reddish-brown
glLineWidth(2);
glBegin(GL_LINE_LOOP);
glColor3ub(154, 77, 69); // Base color passed as argument
glVertex2f(-13.33f, -14.95f); // E3
glVertex2f(-12.37f, -14.95f); // F3
glVertex2f(-12.37f, -16.78f); // G3
glVertex2f(-13.33f, -16.78f); // H3
glEnd();


//  front door glass - off black
glBegin(GL_POLYGON);
glColor3ub(44, 48, 51); // Base color passed as argument
glVertex2f(-13.16f, -15.05f); // I3
glVertex2f(-12.52f, -15.04f); // J3
glVertex2f(-12.52f, -15.95f); // L3
glVertex2f(-13.17f, -15.96f); // K3
glEnd();

// front door glass shade - slate gray
glBegin(GL_POLYGON);
glColor3ub(64, 69, 71); // Base color passed as argument
glVertex2f(-12.91f, -15.05f); // M3
glVertex2f(-12.77f, -15.05f); // N3
glVertex2f(-13.17f, -15.51f); // P3
glVertex2f(-13.17f, -15.51f); // O3
glEnd();

//  front door glass shade - slate gray
glBegin(GL_POLYGON);
glColor3ub(64, 69, 71); // Base color passed as argument
glVertex2f(-12.52f, -15.1f);  // Q3
glVertex2f(-12.52f, -15.37f);  // R3
glVertex2f(-12.75f, -15.95f); // T3
glVertex2f(-12.93f, -15.95f); // S3
glEnd();


rTrainDoor(-1.0,0.0,0);


rCompartment(0,0,0);
rCompartment(13.4,0,0);
rCompartment(26.8,0,0);
rCompartment(40.2,0,0);
rCompartment(53.6,0,0);

    glPopMatrix();
}
//ID_42
void rRailTrack(float x, float y, float z) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y, z);
    //glScalef(22.0f, 22.0f, 1.0f);

int numSegments = 40; // Number of rail ties
float xOffset = 1.0f; // Distance between each tie

for (int i = 0; i < numSegments; ++i) {
    float dx = i * xOffset; // Offset for this segment

    // Brown part front - russet
    glBegin(GL_POLYGON);
    glColor3ub(126, 80, 55);
    glVertex2f(-10.3f + dx, -18.28f);   // R5
    glVertex2f(-10.1f + dx, -18.28f);   // S5
    glVertex2f(-10.09f + dx, -18.35f);  // U5
    glVertex2f(-10.3f + dx, -18.35f);   // T5
    glEnd();

    // Brown part front outline - black
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(-10.3f + dx, -18.28f);   // R5
    glVertex2f(-10.1f + dx, -18.28f);   // S5
    glVertex2f(-10.09f + dx, -18.35f);  // U5
    glVertex2f(-10.3f + dx, -18.35f);   // T5
    glEnd();

    // Brown part upper - russet
    glBegin(GL_POLYGON);
    glColor3ub(126, 80, 55);
    glVertex2f(-10.3f + dx, -18.28f);   // R5
    glVertex2f(-9.83f + dx, -17.48f);   // V5
    glVertex2f(-9.66f + dx, -17.48f);   // W5
    glVertex2f(-10.1f + dx, -18.28f);   // S5
    glEnd();

    // Brown part upper outline - black
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(-10.3f + dx, -18.28f);   // R5
    glVertex2f(-9.83f + dx, -17.48f);   // V5
    glVertex2f(-9.66f + dx, -17.48f);   // W5
    glVertex2f(-10.1f + dx, -18.28f);   // S5
    glEnd();

    // Brown part side - russet
    glBegin(GL_POLYGON);
    glColor3ub(126, 80, 55);
    glVertex2f(-10.1f + dx, -18.28f);   // S5
    glVertex2f(-10.09f + dx, -18.35f);  // U5
    glVertex2f(-9.64f + dx, -17.56f);   // Z5
    glVertex2f(-9.66f + dx, -17.48f);   // W5
    glEnd();

    // Brown part side outline - black
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(-10.1f + dx, -18.28f);   // S5
    glVertex2f(-10.09f + dx, -18.35f);  // U5
    glVertex2f(-9.64f + dx, -17.56f);   // Z5
    glVertex2f(-9.66f + dx, -17.48f);   // W5
    glEnd();

    // Black points on two part
    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3ub(0,0,0);
    glVertex2f(-10.18f + dx, -18.24f);  // E6
    glVertex2f(-9.76f + dx, -17.53f);   // D6
    glEnd();
}
// Calculate the start and end x positions for the rails
float railStartX = -10.6f; // Slightly before the first tie
float railEndX   = railStartX + (numSegments - 1) * xOffset + 1.2f; // Slightly after the last tie

// Y positions for the two rails (adjust as needed for your drawing)
float leftRailY1 = -18.00f; // Top edge of left rail
float leftRailY2 = -18.18f; // Bottom edge of left rail

float rightRailY1 = -17.48f; // Top edge of right rail
float rightRailY2 = -17.56f; // Bottom edge of right rail

// LEFT RAIL (grey)
glBegin(GL_POLYGON);
glColor3ub(112, 107, 108);
glVertex2f(railStartX, leftRailY1);
glVertex2f(railEndX,   leftRailY1);
glVertex2f(railEndX,   leftRailY2);
glVertex2f(railStartX, leftRailY2);
glEnd();

// LEFT RAIL OUTLINE (black)
glLineWidth(2);
glBegin(GL_LINE_LOOP);
glColor3ub(0, 0, 0);
glVertex2f(railStartX, leftRailY1);
glVertex2f(railEndX,   leftRailY1);
glVertex2f(railEndX,   leftRailY2);
glVertex2f(railStartX, leftRailY2);
glEnd();

// RIGHT RAIL (grey)
glBegin(GL_POLYGON);
glColor3ub(112, 107, 108);
glVertex2f(railStartX, rightRailY1);
glVertex2f(railEndX,   rightRailY1);
glVertex2f(railEndX,   rightRailY2);
glVertex2f(railStartX, rightRailY2);
glEnd();

// RIGHT RAIL OUTLINE (black)
glLineWidth(2);
glBegin(GL_LINE_LOOP);
glColor3ub(0, 0, 0);
glVertex2f(railStartX, rightRailY1);
glVertex2f(railEndX,   rightRailY1);
glVertex2f(railEndX,   rightRailY2);
glVertex2f(railStartX, rightRailY2);
glEnd();


        glPopMatrix();
}
//Train Moving
void rupdate(int value) {
    if (rtrainMoving) {
        _move -= rtrainSpeed;
    }
    glutPostRedisplay();
    glutTimerFunc(20, rupdate, 0);
}
void drawScaledCircle(float cx, float cy, float r, int segments = 360) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * 3.1416f * float(i) / float(segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        scaledVertex2f(cx + x, cy + y);
    }
    glEnd();
}
//ID_43
//Sky
void rdrawSky()
{
     if (!isNight) {
    glColor3f(0.678f, 0.847f, 0.902f); }
    else {
        glColor3f(0.05f, 0.05f, 0.2f);
    }
    glBegin(GL_QUADS);
    scaledVertex2f(0, 0); scaledVertex2f(1500, 0);
    scaledVertex2f(1500, 1000); scaledVertex2f(0, 1000);
    glEnd();
}
////ID_44,//ID_45(moon)
//Sun
void rdrawSun() {
    if (!isNight) {
        glColor3f(1.0f, 1.0f, 0.6f);
        drawScaledCircle(850, 900, 40);
    } else {
        glColor3f(0.8f, 0.8f, 0.9f);
        drawScaledCircle(850, 900, 30);
    }
}
//ID_46
//Cloud
void rdrawCloud(float cx, float cy, float r) {
    if (!isNight) {
        glColor3f(1.0f, 1.0f, 1.0f);
        drawScaledCircle(cx, cy, r);
        drawScaledCircle(cx + r * 1.2f, cy, r * 0.8f);
        drawScaledCircle(cx - r * 1.2f, cy, r * 0.8f);
        drawScaledCircle(cx, cy + r * 0.8f, r * 0.8f);
        drawScaledCircle(cx, cy - r * 0.8f, r * 0.8f);
   }
}
//ID_47
//Stars
void rdrawStars() {
    if (isNight) {
        glColor3f(1.0f, 1.0f, 1.0f);
        glPointSize(3.0f);
        glBegin(GL_POINTS);
        scaledVertex2f(100, 900);
        scaledVertex2f(200, 850);
        scaledVertex2f(300, 950);
        scaledVertex2f(400, 880);
        scaledVertex2f(500, 920);
        scaledVertex2f(600, 870);
        scaledVertex2f(700, 940);
        scaledVertex2f(800, 890);
        scaledVertex2f(1100, 910);
        scaledVertex2f(1200, 860);
        glEnd();
    }
}
//ID_49
//Castle
void rdrawCastle(float x, float y) {
    glPushMatrix();
    glTranslatef(x * SCALE_X + OFFSET_X, y * SCALE_Y + OFFSET_Y, 0);
    glScalef(SCALE_X, SCALE_Y, 1.0f);

    glColor3f(isNight ? 0.6f : 0.9f, isNight ? 0.6f : 0.9f, isNight ? 0.6f : 0.9f);
    glBegin(GL_QUADS);
    glVertex2f(-150, 0); glVertex2f(150, 0);
    glVertex2f(150, 150); glVertex2f(-150, 150);
    glEnd();

    glColor3f(isNight ? 0.5f : 0.75f, isNight ? 0.5f : 0.75f, isNight ? 0.5f : 0.75f);
    for (int i = -150; i <= 120; i += 30) {
        glBegin(GL_QUADS);
        glVertex2f(i, 150); glVertex2f(i + 20, 150);
        glVertex2f(i + 20, 170); glVertex2f(i, 170);
        glEnd();
    }

    glColor3f(isNight ? 0.55f : 0.85f, isNight ? 0.55f : 0.85f, isNight ? 0.55f : 0.85f);
    glBegin(GL_QUADS);
    glVertex2f(-60, 150); glVertex2f(60, 150);
    glVertex2f(60, 250); glVertex2f(-60, 250);
    glEnd();

    glColor3f(isNight ? 0.5f : 0.7f, isNight ? 0.05f : 0.1f, isNight ? 0.05f : 0.1f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-80, 250);
    glVertex2f(80, 250);
    glVertex2f(0, 350);
    glEnd();

    glColor3f(isNight ? 0.4f : 0.6f, isNight ? 0.2f : 0.4f, isNight ? 0.1f : 0.2f);
    glBegin(GL_POLYGON);
    glVertex2f(-30, 0);
    glVertex2f(30, 0);
    glVertex2f(30, 80);
    glVertex2f(-30, 80);
    glEnd();

    float towerX[] = {-170, -120, 120, 170};
    for (int i = 0; i < 4; i++) {
        float cx = towerX[i];
        glColor3f(isNight ? 0.55f : 0.85f, isNight ? 0.55f : 0.85f, isNight ? 0.55f : 0.85f);
        glBegin(GL_QUADS);
        glVertex2f(cx - 20, 0);
        glVertex2f(cx + 20, 0);
        glVertex2f(cx + 20, 140);
        glVertex2f(cx - 20, 140);
        glEnd();

        glColor3f(isNight ? 0.5f : 0.7f, isNight ? 0.05f : 0.1f, isNight ? 0.05f : 0.1f);
        glBegin(GL_TRIANGLES);
        glVertex2f(cx - 25, 140);
        glVertex2f(cx + 25, 140);
        glVertex2f(cx, 190);
        glEnd();
    }

    // Window color: Use glColor3f(1.0f, 0.9f, 0.7f) for night, white for day
    glColor3f(isNight ? 1.0f : 1.0f, isNight ? 0.9f : 1.0f, isNight ? 0.7f : 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-20, 170);
    glVertex2f(20, 170);
    glVertex2f(20, 220);
    glVertex2f(-20, 220);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-80, 40);
    glVertex2f(-40, 40);
    glVertex2f(-40, 90);
    glVertex2f(-80, 90);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(40, 40);
    glVertex2f(80, 40);
    glVertex2f(80, 90);
    glVertex2f(40, 90);
    glEnd();

    glColor3f(isNight ? 0.7f : 1.0f, isNight ? 0.1f : 0.2f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 380);
    glVertex2f(0, 410);
    glVertex2f(35, 395);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0, 350);
    glVertex2f(0, 380);
    glEnd();

    glPopMatrix();
}

//ID_48
//Mountain

void rdrawMountains() {
    glColor3f(isNight ? 0.1f : 0.2f, isNight ? 0.3f : 0.6f, isNight ? 0.25f : 0.5f);
    glBegin(GL_POLYGON);
    scaledVertex2f(-50, 550); scaledVertex2f(100, 850); scaledVertex2f(250, 550);
    glEnd();

    glColor3f(isNight ? 0.1f : 0.2f, isNight ? 0.25f : 0.5f, isNight ? 0.2f : 0.4f);
    glBegin(GL_POLYGON);
    scaledVertex2f(0, 550); scaledVertex2f(50, 650); scaledVertex2f(100, 750);
    scaledVertex2f(150, 650); scaledVertex2f(200, 550);
    glEnd();

    glColor3f(isNight ? 0.1f : 0.2f, isNight ? 0.3f : 0.6f, isNight ? 0.25f : 0.5f);
    glBegin(GL_POLYGON);
    scaledVertex2f(150, 550); scaledVertex2f(200, 650); scaledVertex2f(320, 770);
    scaledVertex2f(380, 850); scaledVertex2f(500, 650); scaledVertex2f(550, 730);
    scaledVertex2f(650, 650); scaledVertex2f(750, 550);
    glEnd();

    glColor3f(isNight ? 0.15f : 0.3f, isNight ? 0.375f : 0.75f, isNight ? 0.3f : 0.6f);
    glBegin(GL_POLYGON);
    scaledVertex2f(220, 550); scaledVertex2f(260, 600); scaledVertex2f(320, 700);
    scaledVertex2f(400, 770); scaledVertex2f(480, 650); scaledVertex2f(530, 620);
    scaledVertex2f(590, 550);
    glEnd();
}
//ID_417
//Stone And LightHouse

void rdrawStoneLighthouseLand() {
    // Lighthouse Base
    glColor3f(isNight ? 0.3f : 0.6f, isNight ? 0.3f : 0.6f, isNight ? 0.3f : 0.6f);
    glBegin(GL_QUADS);
    scaledVertex2f(1260, 650); scaledVertex2f(1340, 650);
    scaledVertex2f(1340, 670); scaledVertex2f(1260, 670);
    glEnd();

    // Lighthouse Body
    glColor3f(isNight ? 0.6f : 0.9f, isNight ? 0.6f : 0.9f, isNight ? 0.6f : 0.9f);
    glBegin(GL_QUADS);
    scaledVertex2f(1270, 670); scaledVertex2f(1330, 670);
    scaledVertex2f(1330, 750); scaledVertex2f(1270, 750);
    glEnd();

    // Lighthouse Side Extensions
    glBegin(GL_QUADS);
    scaledVertex2f(1270, 750); scaledVertex2f(1275, 750);
    scaledVertex2f(1275, 780); scaledVertex2f(1270, 780);
    glEnd();

    glBegin(GL_QUADS);
    scaledVertex2f(1325, 750); scaledVertex2f(1330, 750);
    scaledVertex2f(1330, 780); scaledVertex2f(1325, 780);
    glEnd();

    // Lighthouse Top
    glColor3f(isNight ? 0.35f : 0.55f, isNight ? 0.17f : 0.27f, isNight ? 0.04f : 0.07f);
    glBegin(GL_QUADS);
    scaledVertex2f(1290, 750); scaledVertex2f(1310, 750);
    scaledVertex2f(1310, 755); scaledVertex2f(1290, 755);
    glEnd();

    // Lighthouse Light Circle
    glPushMatrix();
    glTranslatef(1300 * SCALE_X + OFFSET_X, 762 * SCALE_Y + OFFSET_Y, 0);
    glBegin(GL_POLYGON);
    glColor3f(isNight ? 1.0f : 1.0f, isNight ? 1.0f : 0.9f, isNight ? 0.8f : 0.7f);
    /*if(isNight) glColor3f(1.0f, 0.9f, 0.7f);
            else glColor3f(1.0f, 1.0f, 1.0f);*/

                for(int j=0;j<360;j++){
                    float pi=3.1416;
                    float A=(j*2*pi)/180;
                    float r=0.5;
                    float x = r * cos(A);
                    float y = r * sin(A);
                    glVertex2f(x,y);
                }
                glEnd();
    glPopMatrix();
    // Lighthouse Beam (visible only at night)
    if (isNight) {
        glColor4f(1.0f, 1.0f, 0.8f, 0.3f);
        glBegin(GL_TRIANGLES);
        scaledVertex2f(1300, 762);
        scaledVertex2f(1500, 850);
        scaledVertex2f(1500, 670);
        glEnd();
    }

    // Lighthouse Roof Triangle
    glColor3f(isNight ? 0.15f : 0.25f, isNight ? 0.15f : 0.25f, isNight ? 0.15f : 0.25f);
    glBegin(GL_TRIANGLES);
    scaledVertex2f(1260, 780); scaledVertex2f(1300, 820); scaledVertex2f(1340, 780);
    glEnd();

    //ID_412
    // Stone Base Polygon
    glColor3f(isNight ? 0.1f : 0.2f, isNight ? 0.05f : 0.1f, isNight ? 0.05f : 0.1f);
    glBegin(GL_POLYGON);
    scaledVertex2f(1090, 550); scaledVertex2f(1090, 570);
    scaledVertex2f(1250, 650); scaledVertex2f(1350, 650);
    scaledVertex2f(1500, 570); scaledVertex2f(1500, 550);
    glEnd();

    // Land Sand Layer
    glColor3f(isNight ? 0.64f : 0.94f, isNight ? 0.57f : 0.87f, isNight ? 0.43f : 0.73f);
    glBegin(GL_QUADS);
    scaledVertex2f(0, 450); scaledVertex2f(1500, 450);
    scaledVertex2f(1500, 380); scaledVertex2f(0, 380);
    glEnd();

    // Land Stone Layer
    glColor3f(isNight ? 0.55f : 0.85f, isNight ? 0.25f : 0.45f, isNight ? 0.15f : 0.25f);
    glBegin(GL_QUADS);
    scaledVertex2f(0, 450); scaledVertex2f(1500, 450);
    scaledVertex2f(1500, 470); scaledVertex2f(0, 470);
    glEnd();

    //ID_413
    // Grass Layer
    glColor3f(isNight ? 0.0f : 0.0f, isNight ? 0.373f : 0.573f, isNight ? 0.361f : 0.561f);
    glBegin(GL_QUADS);
    scaledVertex2f(0, 470); scaledVertex2f(1500, 470);
    scaledVertex2f(1500, 550); scaledVertex2f(0, 550);
    glEnd();

    //ID_414
    // Bushes
    int bush = 0;
    for (int i = 0; i < 30; i++) {
        glColor3f(isNight ? 0.180f : 0.380f, isNight ? 0.588f : 0.788f, isNight ? 0.133f : 0.333f);
        glBegin(GL_TRIANGLES);
        scaledVertex2f(bush + 0, 470); scaledVertex2f(bush + 50, 470); scaledVertex2f(bush + 25, 490);
        scaledVertex2f(bush + 0, 475); scaledVertex2f(bush + 50, 475); scaledVertex2f(bush + 25, 495);
        scaledVertex2f(bush + 0, 480); scaledVertex2f(bush + 50, 480); scaledVertex2f(bush + 25, 500);
        scaledVertex2f(bush + 0, 485); scaledVertex2f(bush + 50, 485); scaledVertex2f(bush + 25, 500);
        glEnd();
        bush += 50;
    }
}

//Speedboat and Water
void rdrawWaterAndSpeedboat() {
    //ID_410
    // Draw water
    glBegin(GL_QUADS);
    glColor3f(isNight ? 0.0f : 0.0f, isNight ? 0.3f : 0.5f, isNight ? 0.5f : 0.7f);
    scaledVertex2f(0, 380); scaledVertex2f(1500, 380);
    scaledVertex2f(1500, 0); scaledVertex2f(0, 0);
    glEnd();

    // Push matrix to apply translation for speedboat
    glPushMatrix();
    glTranslatef(rboatX * SCALE_X, 0, 0); // Translate based on boatX

    //ID_415
    // Speedboat body
    glBegin(GL_QUADS);
    glColor3f(isNight ? 0.2f : 0.3f, isNight ? 0.2f : 0.3f, isNight ? 0.2f : 0.3f);
    scaledVertex2f(0, 200); scaledVertex2f(-50, 250);
    scaledVertex2f(250, 250); scaledVertex2f(150, 200);
    glEnd();

    // Upper part
    glBegin(GL_QUADS);
    glColor3f(isNight ? 0.6f : 0.9f, isNight ? 0.6f : 0.9f, isNight ? 0.5f : 0.8f);
    scaledVertex2f(0, 250); scaledVertex2f(100, 250);
    scaledVertex2f(100, 270); scaledVertex2f(0, 270);
    glEnd();

    // Window area
    glBegin(GL_QUADS);
    glColor3f(isNight ? 0.2f : 0.4f, isNight ? 0.4f : 0.6f, isNight ? 0.6f : 0.8f);
    scaledVertex2f(10, 250); scaledVertex2f(90, 250);
    scaledVertex2f(90, 265); scaledVertex2f(10, 265);
    glEnd();

    // Windows
    blx = 0;
    for(int i = 0; i < 6; i++) {
        glBegin(GL_QUADS);
        glColor3f(isNight ? 0.55f : 0.75f, isNight ? 0.55f : 0.75f, isNight ? 0.55f : 0.75f);
        scaledVertex2f(blx + 0, 220); scaledVertex2f(blx + 20, 220);
        scaledVertex2f(blx + 20, 240); scaledVertex2f(blx + 0, 240);
        glEnd();
        blx += 30;
    }

    // Mast
    glBegin(GL_QUADS);
    glColor3f(isNight ? 0.2f : 0.4f, isNight ? 0.3f : 0.5f, isNight ? 0.6f : 0.8f);
    scaledVertex2f(100, 250); scaledVertex2f(105, 250);
    scaledVertex2f(105, 320); scaledVertex2f(100, 320);
    glEnd();

    // Triangle part
    if (isNight) {
        glBegin(GL_TRIANGLES);
        glColor3f(isNight ? 0.55f : 0.75f, isNight ? 0.55f : 0.75f, isNight ? 0.55f : 0.75f);
        scaledVertex2f(105, 320); scaledVertex2f(170, 250); scaledVertex2f(240, 250);
        glEnd();
    }

    glPopMatrix();
}
//ID_416
//Ship
void rdrawShip() {
    glPushMatrix();
    glScalef(SCALE_X, SCALE_Y, 1.0f);
    glTranslatef(0, -500, 0);  // Adjust Y-position downward

    glBegin(GL_POLYGON);
    glColor3f(0.55f, 0.0f, 0.0f);
    glVertex2f(rship+150,100); glVertex2f(rship+530,100); glVertex2f(rship+500,70);
    glVertex2f(rship+170,70); glVertex2f(rship+150,80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(rship+100,180); glVertex2f(rship+100,150);
    glVertex2f(rship+150,100); glVertex2f(rship+530,100);
    glVertex2f(rship+610,180);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.5f);
    glVertex2f(rship+100,180); glVertex2f(rship+100,170);
    glVertex2f(rship+600,170); glVertex2f(rship+610,180);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.6f, 0.8f);
    glVertex2f(rship+150,165); glVertex2f(rship+540,165);
    glVertex2f(rship+540,150); glVertex2f(rship+150,150);
    glEnd();

    window=0;
    glBegin(GL_QUADS);
    for(int i=0;i<20;i++){
        glColor3f(0.678f, 0.847f, 0.902f);
        glVertex2f(rship+window+160,165);
        glVertex2f(rship+window+170,165);
        glVertex2f(rship+window+170,150);
        glVertex2f(rship+window+160,150);
        window+=20;
    }
    glEnd();

    window=0;
    glBegin(GL_QUADS);
    for(int i=0;i<40;i++){
        glColor3f(0.1f, 0.1f, 0.1f);
        glVertex2f(rship+window+155,140);
        glVertex2f(rship+window+160,140);
        glVertex2f(rship+window+160,130);
        glVertex2f(rship+window+155,130);
        window+=10;
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(rship+150,180); glVertex2f(rship+540,180);
    glVertex2f(rship+540,200); glVertex2f(rship+150,200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.5f);
    glVertex2f(rship+150,200); glVertex2f(rship+540,200);
    glVertex2f(rship+540,205); glVertex2f(rship+150,205);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.6f, 0.8f);
    glVertex2f(rship+150,185); glVertex2f(rship+540,185);
    glVertex2f(rship+540,195); glVertex2f(rship+150,195);
    glEnd();

    window=0;
    glBegin(GL_QUADS);
    for(int i=0;i<19;i++){
        glColor3f(0.678f, 0.847f, 0.902f);
        glVertex2f(rship+window+160,185);
        glVertex2f(rship+window+170,185);
        glVertex2f(rship+window+170,195);
        glVertex2f(rship+window+160,195);
        window+=20;
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(rship+150,205); glVertex2f(rship+540,205);
    glVertex2f(rship+530,225); glVertex2f(rship+160,225);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.5f);
    glVertex2f(rship+160,225); glVertex2f(rship+530,225);
    glVertex2f(rship+530,230); glVertex2f(rship+160,230);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.6f, 0.8f);
    glVertex2f(rship+160,210); glVertex2f(rship+530,210);
    glVertex2f(rship+530,220); glVertex2f(rship+160,220);
    glEnd();

    window=0;
    glBegin(GL_QUADS);
    for(int i=0;i<18;i++){
        glColor3f(0.678f, 0.847f, 0.902f);
        glVertex2f(rship+window+170,210);
        glVertex2f(rship+window+180,210);
        glVertex2f(rship+window+180,220);
        glVertex2f(rship+window+170,220);
        window+=20;
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(rship+170,230); glVertex2f(rship+310,230);
    glVertex2f(rship+300,245); glVertex2f(rship+180,245);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.678f, 0.847f, 0.902f);
    glVertex2f(rship+180,232); glVertex2f(rship+300,232);
    glVertex2f(rship+293,243); glVertex2f(rship+187,243);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(rship+400,230); glVertex2f(rship+450,230);
    glVertex2f(rship+450,280); glVertex2f(rship+400,280);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(rship+400,280); glVertex2f(rship+450,280);
    glVertex2f(rship+450,285); glVertex2f(rship+400,285);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(rship+210,245); glVertex2f(rship+210,290);
    glVertex2f(rship+250,290); glVertex2f(rship+280,245);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.5f);
    glVertex2f(rship+210,245); glVertex2f(rship+210,250);
    glVertex2f(rship+278,250); glVertex2f(rship+280,245);
    glEnd();

    glPopMatrix();
}

void rdisplay2() {
    glLoadIdentity();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);
    glColor3f(0.678f, 0.847f, 0.902f);
    scaledVertex2f(0, 0); scaledVertex2f(1500, 0);
    scaledVertex2f(1500, 1000); scaledVertex2f(0, 1000);
    glEnd();

    rdrawSky();//ID_43
    rdrawSun();//ID_44
    rdrawStars();//ID_45
    rdrawMountains();//ID_46
    rdrawCastle(900, 550);//ID_47
    rdrawStoneLighthouseLand();//ID_48
    rdrawWaterAndSpeedboat();//ID_49
    rdrawShip();//ID_410
    rdrawCloud(rcloud1X, 900, 40);//ID_411
    rdrawCloud(rcloud2X, 850, 50);//ID_412
    rdrawCloud(rcloud3X, 880, 45);//ID_413
    rRailTrack(-10,15,0);//ID_42
    rWholeTrain(28,15,0);//ID_41
}
void rupdate1(int value) {
    // Move clouds
    rcloud1X += 0.1f;
    rcloud2X += 0.1f;
    rcloud3X += 0.1f;
    if (rcloud1X > 1600) rcloud1X = -100;
    if (rcloud2X > 1600) rcloud2X = -100;
    if (rcloud3X > 1600) rcloud3X = -100;

    // Auto-move ship and speedboat if their flags are set
    if (rshipMoving) {
        rship += 1;
        if (rship > 1600) rship = -1000;
    }
    if (rboatMoving) {
        rboatX += 3;
        if (rboatX > 1400) rboatX = -100;
    }
    glutPostRedisplay();
    glutTimerFunc(16, rupdate1, 0);
}
// Keyboard Interaction function
void rkeyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'j':
        case 'J':
            isNight = true;
            glutPostRedisplay();
            break;
        case 'k':
        case 'K':
            isNight = false;
            glutPostRedisplay();
            break;
        case 'y':
        case 'Y':
            rboatMoving = !rboatMoving;
            glutPostRedisplay();
            break;
        case 'z':
        case 'Z':
            rshipMoving = !rshipMoving;
            glutPostRedisplay();
            break;
               }
}
//  Mouse Interaction function
void rmouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) { // Only handle mouse button press
        if (button == GLUT_RIGHT_BUTTON) {
            rtrainMoving = false; // Stop the train
        }
        else if (button == GLUT_LEFT_BUTTON) {
            rtrainMoving = true; // Start the train
            rtrainSpeed = 0.12f; // Faster speed
        }
    }
    else if (state == GLUT_UP && button == GLUT_LEFT_BUTTON) {
        rtrainSpeed = 0.06f; // Reset to normal speed on left button release
    }
    glutPostRedisplay();
}

// Scenario 1 globals and functions
bool isDay = true;

/// ================= GLOBAL VARIABLES ===================
float V_moveBus = -400.0f;      // Start much further left from green car
float V_busSpeed =1.0f;
float V_savedBusSpeed = 0.0f;
float V_busTireAngle = 0.0f;
bool V_busPaused = false;

float V_moveCargo = 500.0f;      // Start with proper spacing from right
float V_cargoSpeed = 0.5f;       // Speed
float V_savedCargoSpeed = 0.0f;
float V_cargoTireAngle = 0.0f;
bool V_cargoPaused = false;

/// #############  Circle  #############
void vcircle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++)
    {
        float pi = 3.1416;
        float A  = (i*2*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY);
    }
    glEnd();
}

void vcircleM(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++)
    {
        float pi = 3.1416;
        float A  = (i*2*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY);
    }
    glEnd();
}

void vhalfCircle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 180; i++)
    {
        float pi = 3.1416;
        float A  = (i*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY);
    }
    glEnd();
}

/// #############  Sun  #############
float vmoveSun = 0.0f;
float vsunSpeed =0.3f;
float vsavedSunSpeed = 0.0f;
bool vsunPaused = false;

void vsun()
{
    if(isDay)
    {
        glPushMatrix();
        glTranslatef(vmoveSun, 0, 0);
        glColor3f(1,1,0);
        vcircle(50,650,35);
        glPopMatrix();
    }
}

void vupdateSun(int value)
{
    if(!vsunPaused)
    {
        vmoveSun += vsunSpeed;
        if (vmoveSun > 1050)
        {
            vmoveSun = -200;
        }

        glutPostRedisplay();
    }

    glutTimerFunc(16, vupdateSun, 0);
}

/// ############# Moon #############
float vmoveMoon = 0;
float vmoonSpeed =0.3f;
float vsavedMoonSpeed = 0.0f;
bool vmoonPaused = false;

void vmoon()
{
    if(!isDay)
    {
        glPushMatrix();
        glTranslatef(vmoveMoon, 0, 0);

        glColor3f(1,1,1);
        vcircle(850,650,40);

        glColor3f(0.10f, 0.13f, 0.22f);
        vcircle(860,660,40);
        glPopMatrix();
    }
}

void vupdateMoon(int value)
{
    if(!vmoonPaused)
    {
        vmoveMoon -= vmoonSpeed;
        if (vmoveMoon < -940)
        {
            vmoveMoon = 200;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(16, vupdateMoon, 0);
}

/// #############  SKY  #############
void vsky()
{
    glBegin(GL_QUADS);

    if(isDay)
        glColor3f(0.37f, 0.82f, 0.94f);
    else
        glColor3f(0.10f, 0.13f, 0.22f);

    glVertex2f(0, 200);
    glVertex2f(1000, 200);
    glVertex2f(1000, 700);
    glVertex2f(0, 700);
    glEnd();
}

/// #############  Cloud  #############

float V_moveCloud1 = 0.0f;
float V_cloudSpeed1 =1.0f;
float V_savedCloudSpeed1 = 0.0f;
bool V_cloudPaused1 = false;

float V_moveCloud2 = 0.0f;
float V_cloudSpeed2 =1.0f;
float V_savedCloudSpeed2 = 0.0f;
bool V_cloudPaused2 = false;

float V_moveCloud3 = 0.0f;
float V_cloudSpeed3 =1.0f;
float V_savedCloudSpeed3 = 0.0f;
bool V_cloudPaused3 = false;

float V_moveCloud4 = 0.0f;
float V_cloudSpeed4 =1.0f;
float V_savedCloudSpeed4 = 0.0f;
bool V_cloudPaused4 = false;

void V_cloud1()
{
    glPushMatrix();
    glTranslatef(V_moveCloud1, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    int x = 200, y = 650, r = 20;
    vcircle(x,    y, r);
    vcircle(x-25, y+5, r);
    vcircle(x+25, y+5, r);
    vcircle(x-10, y+20, r-3);
    vcircle(x+10, y+20, r-3);

    glPopMatrix();
}

void V_cloud2()
{
    glPushMatrix();
    glTranslatef(V_moveCloud2, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    vcircle(337,640,18);
    vcircle(365,640,20);
    vcircle(390,640,18);
    vcircle(350,632,20);
    vcircle(375,632,20);
    vcircle(355,648,20);
    vcircle(375,648,20);

    glPopMatrix();
}

void V_cloud3()
{
    glPushMatrix();
    glTranslatef(V_moveCloud3, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    int x = 700, y = 650, r = 20;
    vcircle(x, y-15, r);
    vcircle(x+25, y-10, r);
    vcircle(x-25, y-10, r);
    vcircle(x-50, y, r);
    vcircle(x+50, y, r);
    vcircle(x+30, y+15, r+5);
    vcircle(x, y+25, r+5);
    vcircle(x-30, y+15, r+5);

    glBegin(GL_QUADS);
    glVertex2f(650,630);
    glVertex2f(750,630);
    glVertex2f(750,670);
    glVertex2f(650,670);
    glEnd();

    glPopMatrix();
}

void V_cloud4()
{
    glPushMatrix();
    glTranslatef(V_moveCloud4, 0, 0);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);
    vcircle(830,640,20);
    vcircle(860,638,22);
    vcircle(890,640,20);
    vcircle(845,652,20);
    vcircle(870,655,28);

    glPopMatrix();
}

void V_updateCloud1(int value)
{
    if(isDay)
    {
        if(!V_cloudPaused1)
        {
            V_moveCloud1 -= V_cloudSpeed1+1;
            if (V_moveCloud1 < -250)
            {
                V_moveCloud1 = 860;
            }

            glutPostRedisplay();
        }
    }
    else
    {
        if(!V_cloudPaused1)
        {
            V_moveCloud1 += V_cloudSpeed1+1;
            if (V_moveCloud1 >1000)
            {
                V_moveCloud1 = -250;
            }

            glutPostRedisplay();
        }
    }
    glutTimerFunc(16, V_updateCloud1, 0);
}

void V_updateCloud2(int value)
{
    if(!V_cloudPaused2)
    {
        V_moveCloud2 -= V_cloudSpeed2+.3;
        if (V_moveCloud2 < -450)
        {
            V_moveCloud2 = 740;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(9, V_updateCloud2, 0);
}

void V_updateCloud3(int value)
{
    if(!V_cloudPaused3)
    {
        V_moveCloud3 -= V_cloudSpeed3;
        if (V_moveCloud3 < -800)
        {
            V_moveCloud3 = 420;
        }

        glutPostRedisplay();
    }

    glutTimerFunc(16, V_updateCloud3, 0);
}

void V_updateCloud4(int value)
{
    if(isDay)
    {
        if(!V_cloudPaused4)
        {
            V_moveCloud4 -= V_cloudSpeed4+1;
            if (V_moveCloud4 < -900)
            {
                V_moveCloud4 = 250;
            }

            glutPostRedisplay();
        }
    }
    else
    {
        if(!V_cloudPaused4)
        {
            V_moveCloud4 += V_cloudSpeed4+2;
            if (V_moveCloud4 >250)
            {
                V_moveCloud4 = -940;
            }

            glutPostRedisplay();
        }
    }
    glutTimerFunc(16, V_updateCloud4, 0);
}

///  Garden  ------------------>>>>>
void vgarden()
{
    //Base
    if (isDay)
        glColor3f(0.0f, 0.5f, 0.0f);
    else
        glColor3f(0.1f, 0.3f, 0.1f);

    glBegin(GL_QUADS);
    glVertex2f(0,180);
    glVertex2f(1000,180);
    glVertex2f(1000,200);
    glVertex2f(0,200);
    glEnd();
    /// Triangle Tree
    int shift = 150;

    for(int i = 0; i< 67; i++)
    {
        glBegin(GL_QUADS);
        glColor3f(0.702,0.333,0.224);
        glVertex2f(15 + shift * i,200);
        glVertex2f(25 + shift * i,200);
        glVertex2f(25 + shift * i,220);
        glVertex2f(15 + shift * i,220);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0,0.32,0.004);

        glVertex2f(0  + shift * i,220);
        glVertex2f(40 + shift * i,220);
        glVertex2f(20 + shift * i,230);

        glVertex2f(5 + shift * i,230);
        glVertex2f(35 + shift * i,230);
        glVertex2f(20 + shift * i,240);

        glVertex2f(10  + shift * i,240);
        glVertex2f(30 + shift * i,240);
        glVertex2f(20 + shift * i,250);

        glEnd();

        /// Cloud shape tree
        if (isDay)
            glColor3f(0.0f, 0.5f, 0.0f);
        else
            glColor3f(0.1f, 0.3f, 0.1f);

        for(int i = 0; i<1000; i+=50)
        {
            vhalfCircle(i+20,190,25);
        }
    }
}

/// ---------------->>>>>> Train
float vmoveTrain = 0.0f;
float vtrainSpeed =1.0f;
float vsavedTrainSpeed = 0.0f;
bool vtrainPaused = false;

void vtrain()
{
    glPushMatrix();
    glTranslatef(vmoveTrain, 0, 0);

    if(isDay)
        glColor3f(1, 0, 0);
    else
        glColor3f(1.0f, 0.3f, 0.40f);

    glBegin(GL_POLYGON);
    glVertex2f(300,288);
    glVertex2f(548,288);
    glVertex2f(548,313);
    glVertex2f(319,313);
    glVertex2f(300,302);
    glEnd();

    vcircle(301,295,6);

    // Front window
    if(isDay)
        glColor3f(0,0,0);
    else
        glColor3f(1.0f, 1.0f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(320,312);
    glVertex2f(335,312);
    glVertex2f(320,303);
    glVertex2f(305,303);
    glEnd();

    // dark green polygon
if(isDay)
    glColor3f(0.0f, 0.39f, 0.0f);
else
    glColor3f(0.0f, 0.39f, 0.0f);

glBegin(GL_POLYGON);
glVertex2f(320,291);
glVertex2f(548,291);
glVertex2f(548,311);
glVertex2f(335,311);
glVertex2f(320,300);
glEnd();

vcircle(320,295,4);


    // black polygon
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(328,298);
    glVertex2f(545,298);
    glVertex2f(545,309);
    glVertex2f(340,309);
    glVertex2f(325,300);
    glEnd();

    // black polygon
    if (isDay)
        glColor3f(0.92f, 1.0f, 0.996f);
    else
        glColor3f(1,1,.7);

    glBegin(GL_POLYGON);
    glVertex2f(331,301);
    glVertex2f(542,301);
    glVertex2f(542,306);
    glVertex2f(343,306);
    glVertex2f(328,300);
    glEnd();

    // window black lines

    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 370; x<550; x+=60)
    {
        glVertex2f(x,288);
        glVertex2f(x,313);
    }
    glEnd();
    glPopMatrix();
}

void vupdateTrain(int value)
{
    if(!vtrainPaused)
    {
        vmoveTrain -= vtrainSpeed;
        if (vmoveTrain < -550)
        {
            vmoveTrain = 750;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(16, vupdateTrain, 0);
}

/// ------------->>>>>>  Flyover
void vflyOver()
{
    ///Pillar
    if (isDay)
        glColor3f(0.55f, 0.55f, 0.55f);
    else
        glColor3f(0.30f, 0.30f, 0.30f);

    glBegin(GL_QUADS);
    for(int x = 50; x<1000; x+=100)
    {
        glVertex2f(x,   205);
        glVertex2f(x+15,205);
        glVertex2f(x+15,275);
        glVertex2f(x,   275);
    }
    glEnd();

    /// Pillar upper box
    if (isDay)
        glColor3f(0.55f, 0.55f, 0.55f);
    else
        glColor3f(0.30f, 0.30f, 0.30f);

    glBegin(GL_TRIANGLES);
    for(int x = 40; x<1000; x+=100)
    {
        glVertex2f(x,     275);
        glVertex2f(x+35,  275);
        glVertex2f(x+15,255);
    }
    glEnd();

    if(isDay)
        glColor3f(0.80f, 0.80f, 0.80f);
    else
        glColor3f(.4,.4,.4);

    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(0,   275);
    glVertex2f(1000,275);
    glEnd();

    ///Bridge body
    if (isDay)
        glColor3f(0.55f, 0.55f, 0.55f);
    else
        glColor3f(0.30f, 0.30f, 0.30f);

    glBegin(GL_QUADS);
    glVertex2f(0,   277);
    glVertex2f(1000,277);
    glVertex2f(1000,288);
    glVertex2f(0,   288);
    glEnd();
}

/// ---------------------->>>>>>>>> Road
void vroad()
{
    if (isDay)
        glColor3f(.37f, .37f, .37f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    //Base Gray Color
    glBegin(GL_QUADS);
    glVertex2f(0,   0);
    glVertex2f(1000,0);
    glVertex2f(1000,40);
    glVertex2f(0,   40);
    glEnd();

    //Base white line
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(0,   40);
    glVertex2f(1000,40);
    glEnd();

    //Main Road
    glBegin(GL_QUADS);

    if(isDay)
        glColor3f(0.15f, 0.15f, 0.15f);
    else
        glColor3f(0,0,0);

    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glVertex2f(1000,40);
    glVertex2f(0,   40);
    glEnd();

    //Upper white line of the road
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glEnd();

    //Upper gray color
    if (isDay)
        glColor3f(0.51f, 0.51f, 0.51f);
    else
        glColor3f(0.25f, 0.25f, 0.25f);

    glBegin(GL_QUADS);
    glVertex2f(0,   160);
    glVertex2f(1000,160);
    glVertex2f(1000,173);
    glVertex2f(0,   173);
    glEnd();

    //Road dash line
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glLineWidth(3);
    glBegin(GL_LINES);
    for(int x = 0; x<1000; x+=60)
    {
        glVertex2f(x,   102);
        glVertex2f(x+30,102);
    }
    glEnd();
}

/// Bus ------------->>>>>>>>>>

void vbus()
{
    glPushMatrix();
    glTranslatef(V_moveBus, 0, 0);

    glBegin(GL_QUADS);
    if (isDay)
        glColor3f(1.0f, 0.84f, 0.0f);// Deep pink
    else
        glColor3f(0.8f, 0.05f, 0.45f); // Deep pink (darker for night)

    ///Body
    glVertex2f(400, 130);
    glVertex2f(550, 130);
    glVertex2f(550, 190);
    glVertex2f(400, 190);

    ///Front
    glVertex2f(550, 130);
    glVertex2f(570, 130);
    glVertex2f(570, 160);
    glVertex2f(550, 190);

    glEnd();

    ///  FRONT Light
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(1,1,0);

    glBegin(GL_QUADS);
    glVertex2f(565, 135);
    glVertex2f(570, 135);
    glVertex2f(570, 142);
    glVertex2f(565, 142);

    if(!isDay)
    {
    glColor3f(1,1,.6);
    glVertex2f(570, 135);
    glVertex2f(640, 125);
    glVertex2f(640, 152);
    glVertex2f(570, 142);
    }

    /// REAR LIGHT
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(1,0,0);

    glVertex2f(400, 135);
    glVertex2f(405, 135);
    glVertex2f(405, 142);
    glVertex2f(400, 142);

    glEnd();

    /// Window
    /// REAR WINDOW
    if (isDay)
        glColor3f(0.92f, 1.0f, 0.996f);
    else
        glColor3f(1,1,.6);

    glBegin(GL_QUADS);
    glVertex2f(410, 160);
    glVertex2f(530, 160);
    glVertex2f(530, 180);
    glVertex2f(410, 180);
    glEnd();

    glColor3f(1.0f, 0.08f, 0.58f); // Deep pink for bus lines
    glLineWidth(4);
    glBegin(GL_LINES);
    for(int x = 432; x<530; x+=25){
    glVertex2f(x,160);
    glVertex2f(x,180);
    }
    glEnd();


    /// FRONT WINDOW
    if (isDay)
        glColor3f(0.92f, 1.0f, 0.996f);
    else
        glColor3f(1,1,.6);

    glBegin(GL_QUADS);
    glVertex2f(533, 180);
    glVertex2f(550, 180);
    glVertex2f(565, 150);
    glVertex2f(533, 160);

    glEnd();

    /// While

    /// REAR TIRE
    glColor3f(0,0,0);
    vhalfCircle(425,130,12);

    glPushMatrix();
    glTranslatef(425, 130, 0);
    glRotatef(V_busTireAngle, 0.0, 0.0, 1.0);  // Rotate only the tire
    glTranslatef(-425, -130, 0);

   if (isDay)
    glColor3f(0.8f, 0.8f, 0.8f);
else
    glColor3f(0.5f, 0.5f, 0.5f);

    vcircle(425,130,11);

    if (isDay)
    glColor3f(1.0f, 1.0f, 1.0f);
else
    glColor3f(0.7f, 0.7f, 0.7f);

    vcircle(425,130,5);

    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(414,130);
    glVertex2f(436,130);
    glEnd();

    glPopMatrix();

    /// FRONT TIRE
    glColor3f(0,0,0);
    vhalfCircle(540,130,12);

    glPushMatrix();
    glTranslatef(540, 130, 0);
    glRotatef(V_busTireAngle, 0.0, 0.0, 1.0);  // Rotate only the tire
    glTranslatef(-540, -130, 0);

    if (isDay)
    glColor3f(0.8f, 0.8f, 0.8f);
else
    glColor3f(0.5f, 0.5f, 0.5f);

    vcircle(540,130,11);

    if (isDay)
    glColor3f(1.0f, 1.0f, 1.0f);
else
    glColor3f(0.7f, 0.7f, 0.7f);

    vcircle(540,130,5);

    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(529,130);
    glVertex2f(551,130);
    glEnd();

    glPopMatrix();

    glPopMatrix();
}

void V_updateBus(int value)
{
    if(!V_busPaused)
    {
        V_moveBus += 2; // Same speed as other vehicles
        if (V_moveBus > 700)
        {
            V_moveBus = -750; // Start much further left to avoid green car
        }
        V_busTireAngle -= 1.0f;
        glutPostRedisplay();
    }
    glutTimerFunc(2, V_updateBus, 0);
}


/// CARGO ----------->>>>>>>>>>.


void vcargoTruck()
{
    glPushMatrix();
    glTranslatef(V_moveCargo, -40, 0); // move truck + shift it down (-40 Y) for opposite lane

    glBegin(GL_QUADS);
    if (isDay)
        glColor3f(0.0f, 0.0f, 0.50f);
    else
        glColor3f(0.70f, 0.35f, 0.20f);

    /// Body
    glVertex2f(750, 130);
    glVertex2f(900, 130);
    glVertex2f(900, 190);
    glVertex2f(750, 190);

    /// Front
    glVertex2f(900, 130);
    glVertex2f(920, 130);
    glVertex2f(920, 160);
    glVertex2f(900, 190);

    glEnd();

    /// FRONT Light
    if (isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(1, 1, 0);

    glBegin(GL_QUADS);
    glVertex2f(915, 135);
    glVertex2f(920, 135);
    glVertex2f(920, 142);
    glVertex2f(915, 142);

    if (!isDay)
    {
        glColor3f(1, 1, 0.6);
        glVertex2f(920, 135);
        glVertex2f(990, 125);
        glVertex2f(990, 152);
        glVertex2f(920, 142);
    }

    /// REAR LIGHT
    if (isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(1, 0, 0);

    glVertex2f(750, 135);
    glVertex2f(755, 135);
    glVertex2f(755, 142);
    glVertex2f(750, 142);

    glEnd();

    /// REAR WINDOW
    if (isDay)
        glColor3f(0.92f, 1.0f, 0.996f);
    else
        glColor3f(1, 1, 0.6);

    glBegin(GL_QUADS);
    glVertex2f(760, 160);
    glVertex2f(880, 160);
    glVertex2f(880, 180);
    glVertex2f(760, 180);
    glEnd();

    glColor3f(1.00f, 0.60f, 0.29f);
    glLineWidth(4);
    glBegin(GL_LINES);
    for (int x = 782; x < 880; x += 25)
    {
        glVertex2f(x, 160);
        glVertex2f(x, 180);
    }
    glEnd();

    /// FRONT WINDOW
    if (isDay)
        glColor3f(0.92f, 1.0f, 0.996f);
    else
        glColor3f(1, 1, 0.6);

    glBegin(GL_QUADS);
    glVertex2f(883, 180);
    glVertex2f(900, 180);
    glVertex2f(915, 150);
    glVertex2f(883, 160);
    glEnd();

    /// REAR TIRE
    glColor3f(0, 0, 0);
    vhalfCircle(775, 130, 12);

    glPushMatrix();
    glTranslatef(775, 130, 0);
    glRotatef(V_cargoTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-775, -130, 0);

    if (isDay)
        glColor3f(0.8f, 0.8f, 0.8f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    vcircle(775, 130, 11);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.7f, 0.7f, 0.7f);

    vcircle(775, 130, 5);

    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(764, 130);
    glVertex2f(786, 130);
    glEnd();

    glPopMatrix();

    /// FRONT TIRE
    glColor3f(0, 0, 0);
    vhalfCircle(890, 130, 12);

    glPushMatrix();
    glTranslatef(890, 130, 0);
    glRotatef(V_cargoTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-890, -130, 0);

    if (isDay)
        glColor3f(0.8f, 0.8f, 0.8f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    vcircle(890, 130, 11);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.7f, 0.7f, 0.7f);

    vcircle(890, 130, 5);

    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(879, 130);
    glVertex2f(901, 130);
    glEnd();

    glPopMatrix();

    glPopMatrix();
}


/// CARGO UPDATE FUNCTION

void V_updateCargo(int value){
    if (!V_cargoPaused)
    {
        V_moveCargo += 2;
        if (V_moveCargo > 1000)
        {
            V_moveCargo = -900;
        }
        V_cargoTireAngle += 1.0f;
        glutPostRedisplay();
    }
    glutTimerFunc(16, V_updateCargo, 0);
}


///  Night Cars

///car3
float M_moveCar3_night = 200; // Start with proper spacing
float M_car3_nightSpeed = 1.0f;
float M_savedCar3_nightSpeed = 0.0f;
float M_car3_nightTireAngle = 0.0f;
bool  M_car3_nightPaused = false;

void M_car3_night()
{
     glPushMatrix();
    glTranslatef(M_moveCar3_night, 0, 0);

    glBegin(GL_POLYGON);
    glColor3f(0.451f, 0.576f, 0.702f);  //car body
    glVertex2f(735, 75);   // Lower lane (40-102)
    glVertex2f(750, 88);   // Lower lane
    glVertex2f(800, 88);   // Lower lane
    glVertex2f(805, 68);   // Lower lane
    glVertex2f(805, 48);   // Lower lane
    glVertex2f(700, 48);   // Lower lane
    glVertex2f(710, 73);   // Lower lane
    glVertex2f(770, 68);   // Lower lane
    glEnd();

    // Headlight - only show at night
    if(!isDay)
    {
        glBegin(GL_QUADS);
        glColor3f(1,1,0.0f);  //car light
        glVertex2f(710,68);   // Lower lane
        glVertex2f(715,68);
        glVertex2f(715,63);
        glVertex2f(705,60);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1,1,0.60f);
        glVertex2f(710,68);   // Lower lane
        glVertex2f(650,88);
        glVertex2f(650,48);
        glVertex2f(710,63);
        glEnd();
    }

    glBegin(GL_QUADS);    //window
    if(isDay)
        glColor3f(0.5f, 0.8f, 1.0f);  // Blue glass for day
    else
        glColor3f(1,1,0.6);  // Yellow for night
    glVertex2f(750,83);   // Lower lane
    glVertex2f(765,83);
    glVertex2f(765,71);
    glVertex2f(742,71);
    glEnd();

    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.5f, 0.8f, 1.0f);  // Blue glass for day
    else
        glColor3f(1,1,0.6);  // Yellow for night
    glVertex2f(770,83);   // Lower lane
    glVertex2f(795,83);
    glVertex2f(797,71);
    glVertex2f(770,71);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex2f(805,68);   // Lower lane
    glVertex2f(810,68);
    glVertex2f(810,58);
    glVertex2f(805,58);
    glEnd();

    //wheel - moved to lower lane
    glPushMatrix();
    glTranslatef(720,48, 0);  // Lower lane
    glRotatef(M_car3_nightTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-720,-48, 0);

    glColor3f(0,0,0);
    vcircleM(720,48,7);
    glColor3f(0.3,0.3,0.3);
    vcircleM(720,48,5);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(790,48, 0);  // Lower lane
    glRotatef(M_car3_nightTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-790,-48, 0);

    glColor3f(0,0,0);
    vcircleM(790,48,7);
    glColor3f(0.3,0.3,0.3);
    vcircleM(790,48,5);

     glPopMatrix();

    glPopMatrix();

}

void M_updateCar3_night(int value)
{
    if(!M_car3_nightPaused)
    {
        M_moveCar3_night -= 2;  // Same speed as other vehicles
        if (M_moveCar3_night < -1000)
        {
            M_moveCar3_night = 600; // Start further right for proper spacing
        }

        M_car3_nightTireAngle += 2;  // Same tire rotation speed
        glutPostRedisplay();
    }
    glutTimerFunc(16, M_updateCar3_night, 0);  // Same timer as others
}

///car4_night

float M_moveCar4_night = 100; // Start much further right from pink bus
float M_car4_nightSpeed = 1.0f;
float M_savedCar4_nightSpeed = 0.0f;
float M_car4_nightTireAngle = 0.0f;
bool  M_car4_nightPaused = false;

void M_car4_night(){

    glPushMatrix();
    glTranslatef(M_moveCar4_night, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 0.0f); // Deep green BODY
    glVertex2f(500,160);  // Upper lane (102-160)
    glVertex2f(590,160);  // Upper lane
    glVertex2f(590,120);  // Upper lane
    glVertex2f(500,120);  // Upper lane
    glEnd();

    // Headlight - only at night
    if(!isDay)
    {
        glColor3f(1,1,0);   //light
        vcircleM(667,143,7);  // Upper lane

        glBegin(GL_QUADS);
        glColor3f(1,1,0.87); // light
        glVertex2f(672,145);  // Upper lane
        glVertex2f(740,160);  // Upper lane
        glVertex2f(740,130);  // Upper lane
        glVertex2f(672,140);  // Upper lane
        glEnd();
    }

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.4f, 0.0f); // Deep green front
    glVertex2f(590,120); // Upper lane
    glVertex2f(590,180); // Upper lane extended
    glVertex2f(630,180); // Upper lane extended
    glVertex2f(630,177); // Upper lane extended
    glVertex2f(625,177); // Upper lane extended
    glVertex2f(640,160); // Upper lane
    glVertex2f(670,160); // Upper lane
    glVertex2f(670,120); // Upper lane
    glEnd();

    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.5f, 0.8f, 1.0f);  // Blue glass for day
    else
        glColor3f(1,1,0.5);  // Yellow for night
    glVertex2f(600,170);  // Upper lane window
    glVertex2f(620,170);  // Upper lane window
    glVertex2f(630,160);  // Upper lane window
    glVertex2f(600,160);  // Upper lane window
    glEnd();

    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); //black
    glVertex2f(493, 125);  // Upper lane
    glVertex2f(510, 125);  // Upper lane
    glEnd();

    // Back light - only at night
    if(!isDay)
    {
        glLineWidth(10);
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.10f);
        glVertex2f(500, 145);  // Upper lane back light
        glVertex2f(505, 145);  // Upper lane back light
        glEnd();
    }

    //wheel - moved to upper lane
    glPushMatrix();
    glTranslatef(525,120, 0);  // Upper lane
    glRotatef(M_car4_nightTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-525,-120, 0);

    glColor3f(0.0f, 0.0f, 0.0f);
    vcircleM(525,120,9);
    glColor3f(0.30f, 0.30f, 0.30f);
    vcircleM(525,120,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(600,120, 0);  // Upper lane
    glRotatef(M_car4_nightTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-600,-120, 0);

    glColor3f(0.0f, 0.0f, 0.0f);
    vcircleM(600,120,9);
    glColor3f(0.30f, 0.30f, 0.30f);
    vcircleM(600,120,5);
    glPopMatrix();


glPopMatrix();

}

void M_updateCar4_night(int value)
{
    if(!M_car4_nightPaused)
    {
        M_moveCar4_night += 2;  // Same speed as other vehicles
        if (M_moveCar4_night > 1200)
        {
            M_moveCar4_night = -1200; // Start much further left to avoid pink bus
        }

        M_car4_nightTireAngle += 2;  // Same tire rotation speed

        glutPostRedisplay();
    }
    glutTimerFunc(16, M_updateCar4_night, 0);  // Same timer as others
}

//car1night

float moveCar1_nightM = 0;
float car1_nightMSpeed = 1.0f;
float savedcar1_nightMSpeed = 0.0f;
float car1_nightMTireAngle = 0.0f;
bool car1_nightMPaused = false;

void car1_nightM()
{
    glPushMatrix();
    glTranslatef(moveCar1_nightM, 0, 0);



    // car body
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.1f, 0.1f); // Red
    glVertex2f(150, 155);  // Upper lane (102-160)
    glVertex2f(225, 155);  // Upper lane
    glVertex2f(215, 160);  // Upper lane (top edge)
    glVertex2f(160, 160);  // Upper lane (top edge)
    glEnd();

    // Headlight - only at night
    if(!isDay)
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.87f); // yellow light
        glVertex2f(220, 158);  // Upper lane headlight
        glVertex2f(270, 170);  // Upper lane headlight
        glVertex2f(270, 145);  // Upper lane headlight
        glVertex2f(220, 155);  // Upper lane headlight
        glEnd();
    }

    // Draw the minimized roof
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.0f); // Darker red
    glVertex2f(165, 160);  // Upper lane roof
    glVertex2f(210, 160);  // Upper lane roof
    glVertex2f(205, 170);  // Upper lane roof (extended)
    glVertex2f(170, 170);  // Upper lane roof (extended)
    glEnd();

    // Draw the window
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.5f, 0.8f, 1.0f);  // Blue glass for day
    else
        glColor3f(1,1,0.6);  // Yellow for night
    glVertex2f(170, 160);  // Upper lane window
    glVertex2f(205, 160);  // Upper lane window
    glVertex2f(200, 167);  // Upper lane window
    glVertex2f(175, 167);  // Upper lane window
    glEnd();


    // front wheel - moved to upper lane
    glPushMatrix();
    glTranslatef(165, 155, 0);  // Upper lane
    glRotatef(car1_nightMTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-165, -155, 0);

    glColor3f(0.0f, 0.0f, 0.0f); //black
    vcircleM(165, 155, 6);

    glColor3f(0.3f, 0.3f, 0.3f); // Gray
    vcircleM(165, 155, 4);

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0,0,0); // black line
    glVertex2f(160, 155);  // Upper lane
    glVertex2f(170, 155);  // Upper lane
    glEnd();

    glPopMatrix();

    //  rear wheel - moved to upper lane
    glPushMatrix();
    glTranslatef(210, 155, 0);  // Upper lane
    glRotatef(car1_nightMTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-210, -155, 0);

    glColor3f(0.0f, 0.0f, 0.0f);
    vcircleM(210, 155, 6);

    glColor3f(0.3f, 0.3f, 0.3f);
    vcircleM(210, 155, 4);

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0,0,0); // black line
    glVertex2f(205, 155);  // Upper lane
    glVertex2f(215, 155);  // Upper lane
    glEnd();

    glPopMatrix();


    glPopMatrix();
}

void updateCar1_nightM(int value)
{
    if(!car1_nightMPaused)
    {
        moveCar1_nightM += 2.5;  // Balanced speed
        if (moveCar1_nightM > 1000)
        {
            moveCar1_nightM = -300;
        }

        car1_nightMTireAngle += 2.5;  // Tire rotation speed adjusted

        glutPostRedisplay();
    }
    glutTimerFunc(12, updateCar1_nightM, 0);  // Balanced timer for spacing
}


///   Road Side Wall  #########

void vroadSideWall()
{
    // Plain Dark Grey Wall
    glColor3f(0.3f, 0.3f, 0.3f);   // dark grey color

    glBegin(GL_QUADS);
    glVertex2f(0,   170);
    glVertex2f(1000,170);
    glVertex2f(1000,190);
    glVertex2f(0,   190);
    glEnd();
}

/// 4th Building ----->>>
void vbuilding()

{
//   Last Building
if (isDay)
    glColor3f(0.92f, 0.92f, 0.92f);
else
    glColor3f(0.55f, 0.55f, 0.55f);

// Body
glBegin(GL_QUADS);
glVertex2f(590, 200); // 10 + 580
glVertex2f(680, 200); // 100 + 580
glVertex2f(680, 525); // 100 + 580
glVertex2f(590, 525); // 10 + 580

if (isDay)
    glColor3f(1.0f, 1.0f, 1.0f);
else
    glColor3f(0.6f, 0.6f, 0.6f);

// Top
glVertex2f(586, 525); // 6 + 580
glVertex2f(684, 525); // 104 + 580
glVertex2f(684, 535); // 104 + 580
glVertex2f(586, 535); // 6 + 580
glEnd();

// Windows
glBegin(GL_QUADS);
for (int x = 18; x < 80; x += 27)
{
    for (int y = 500; y > 200; y -= 60)
    {
        if (isDay)
            glColor3f(1, 1, 1);
        else
            glColor3f(0.15f, 0.07f, 0.03f);

        glVertex2f(x + 580 - 2, y + 7); // x-2 + 580
        glVertex2f(x + 580 + 22, y + 7); // x+22 + 580
        glVertex2f(x + 580 + 22, y - 20); // x+22 + 580
        glVertex2f(x + 580 - 2, y - 20); // x-2 + 580

        if (isDay)
            glColor3f(0.52f, 0.78f, 0.96f);
        else
            glColor3f(1.0f, 1.0f, 0.5f);

        glVertex2f(x + 580, y + 5); // x + 580
        glVertex2f(x + 580 + 20, y + 5); // x+20 + 580
        glVertex2f(x + 580 + 20, y - 20); // x+20 + 580
        glVertex2f(x + 580, y - 20); // x + 580
    }
}

// Window white border
if (isDay)
    glColor3f(1.0f, 1.0f, 1.0f);
else
    glColor3f(0.6f, 0.6f, 0.6f);

glBegin(GL_QUADS);
for (int y = 480; y > 200; y -= 60)
{
    glVertex2f(585, y); // 5 + 580
    glVertex2f(685, y); // 105 + 580
    glVertex2f(685, y - 15); // 105 + 580
    glVertex2f(585, y - 15); // 5 + 580
}
glEnd();



    /// 1st Building ---->>>

  // Building (coffee color, one shade for all parts)
if (isDay)
    glColor3f(0.44f, 0.31f, 0.22f);   // coffee (day)
else
    glColor3f(0.30f, 0.20f, 0.13f);   // darker coffee (night)

glBegin(GL_QUADS);

// Left side
glVertex2f(190, 200);
glVertex2f(235, 200);
glVertex2f(235, 480);
glVertex2f(190, 480);

// Right side
glVertex2f(235, 200);
glVertex2f(280, 200);
glVertex2f(280, 480);
glVertex2f(235, 480);

// Top bar
glVertex2f(185, 490);
glVertex2f(285, 490);
glVertex2f(285, 475);
glVertex2f(185, 475);

// Horizontal bars
for(int y = 410; y>200; y-=70)
{
    glVertex2f(185, y);
    glVertex2f(285, y);
    glVertex2f(285, y-10);
    glVertex2f(185, y-10);
}

glEnd();

// --------- Window part as it was ---------
glBegin(GL_QUADS);
if(isDay)
    glColor3f(1,1,1);
else
    glColor3f(0.15f, 0.07f, 0.03f);

for(int x = 198; x < 280; x += 47)
{
    for(int y=454; y>220; y-=70)
    {
        glVertex2f(x,    y);
        glVertex2f(x+26, y);
        glVertex2f(x+26, y-34);
        glVertex2f(x,    y-34);
    }
}
glEnd();

// Blue/yellow window fill
if (isDay)
    glColor3f(0.36f, 0.54f, 0.66f);
else
    glColor3f(1.0f, 1.0f, 0.5f);

for(int x = 202; x < 280; x += 47)
{
    for(int y=450; y>220; y-=70)
    {
        glBegin(GL_QUADS);
        glVertex2f(x,    y);
        glVertex2f(x+18, y);
        glVertex2f(x+18, y-27);
        glVertex2f(x,    y-27);
        glEnd();
    }
}

// Window frames (lines)
if(isDay)
    glColor3f(1,1,1);
else
    glColor3f(0.15f, 0.07f, 0.03f);

glLineWidth(2);
glBegin(GL_LINES);
for(int x = 198; x < 280; x += 47)
    for(int y=454; y>220; y-=70)
    {
        glVertex2f(x+13, y);
        glVertex2f(x+13, y-32);

        glVertex2f(x, y-13);
        glVertex2f(x+26, y-13);

        glVertex2f(x,    y-22);
        glVertex2f(x+26, y-22);
    }
glEnd();


    /// 3rd Building
    if (isDay)
        glColor3f(0.96f, 0.96f, 0.96f);
    else
        glColor3f(0.70f, 0.70f, 0.70f);

    glBegin(GL_QUADS);
    //Main Body
    glVertex2f(420, 200);
    glVertex2f(550, 200);
    glVertex2f(550, 440);
    glVertex2f(420, 440);

    glEnd();

    //Body white bar
   if (isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glBegin(GL_QUADS);
    glVertex2f(415, 420);
    glVertex2f(555, 420);
    glVertex2f(555, 440);
    glVertex2f(415, 440);
    glEnd();


    //blue glass
    if (isDay)
        glColor3f(0.38f, 0.54f, 0.66f);
    else
        glColor3f(0.20f, 0.35f, 0.45f);

    //body
    glBegin(GL_QUADS);
    for(int x = 435; x<550; x+=40)
    {
        glVertex2f(x, 200);
        glVertex2f(x+20, 200);
        glVertex2f(x+20, 400);
        glVertex2f(x, 400);
    }


    /// 2nd Building
if (isDay)
    glColor3f(0.84f, 0.74f, 0.62f);
else
    glColor3f(0.50f, 0.40f, 0.30f);

// Body
glBegin(GL_QUADS);
glVertex2f(300, 200); // 640 - 340
glVertex2f(380, 200); // 720 - 340
glVertex2f(380, 380); // 720 - 340
glVertex2f(300, 380); // 640 - 340

// Window
if (isDay)
    glColor3f(1, 1, 1);
else
    glColor3f(0.15f, 0.07f, 0.03f);

for (int y = 373; y > 200; y -= 30)
{
    glVertex2f(307, y); // 647 - 340
    glVertex2f(373, y); // 713 - 340
    glVertex2f(373, y - 21); // 713 - 340
    glVertex2f(307, y - 21); // 647 - 340
}

if (isDay)
    glColor3f(0.52f, 0.78f, 0.96f);
else
    glColor3f(0.94f, 0.69f, 0.35f);

for (int y = 370; y > 200; y -= 30)
{
    glVertex2f(310, y); // 650 - 340
    glVertex2f(370, y); // 710 - 340
    glVertex2f(370, y - 15); // 710 - 340
    glVertex2f(310, y - 15); // 650 - 340
}
glEnd();

if (isDay)
    glColor3f(1, 1, 1);
else
    glColor3f(0.15f, 0.07f, 0.03f);

// Window lines
glLineWidth(1);
glBegin(GL_LINES);
for (int x = 330; x < 370; x += 20) // 670 - 340, 710 - 340
    for (int y = 370; y > 200; y -= 30)
    {
        glVertex2f(x, y);
        glVertex2f(x, y - 15);
    }
glEnd();

    glEnd();
}

void vspecialKeys(int key, int x, int y)
{
    if(isDay)
    {
        switch (key)
        {
        case GLUT_KEY_UP:
            vtrainSpeed += 0.2f;
            break;
        case GLUT_KEY_DOWN:
            vtrainSpeed -= 0.2f;
            if (vtrainSpeed < 0) vtrainSpeed = 0;
            break;
        }
    }

    if(!isDay)
    {
        switch (key)
        {
        case GLUT_KEY_LEFT:
            vmoonSpeed += 0.2f;
            break;
        case GLUT_KEY_RIGHT:
            vmoonSpeed -= 0.2f;
            if (vmoonSpeed < 0) vmoonSpeed = 0;
            break;
        }
    }
}

void vkeyboard(unsigned char key, int x, int y)
{
    if (key == 'd' || key == 'D')
    {
        isDay = true;
        glutPostRedisplay();
    }

    if(key == 'n' || key == 'N')
    {
        isDay = false;
        glutPostRedisplay();
    }

    if (key == ' ')
    {
        /// Bus Stop and Start
        V_busPaused = !V_busPaused;

        if(V_busPaused)
        {
            V_savedBusSpeed = V_busSpeed;
            V_busSpeed = 0;
        }
        else
        {
            V_busSpeed = V_savedBusSpeed;
        }

        /// Cargo Stop and Start
        V_cargoPaused = !V_cargoPaused;

        if(V_cargoPaused)
        {
            V_savedCargoSpeed = V_cargoSpeed;
            V_cargoSpeed = 0;
        }
        else
        {
            V_cargoSpeed = V_savedCargoSpeed;
        }

        /// Train Stop and Start
        vtrainPaused = !vtrainPaused;

        if (vtrainPaused)
        {
            vsavedTrainSpeed = vtrainSpeed;
            vtrainSpeed = 0;
        }
        else
        {
            vtrainSpeed = vsavedTrainSpeed;
        }

        /// Cloud Stop and Start
        // Cloud 1
        V_cloudPaused1 = !V_cloudPaused1;

        if (V_cloudPaused1)
        {
            V_savedCloudSpeed1 = V_cloudSpeed1;
            V_cloudSpeed1 = 0;
        }
        else
        {
            V_cloudSpeed1 = V_savedCloudSpeed1;
        }

        // Cloud 2
        V_cloudPaused2 = !V_cloudPaused2;

        if (V_cloudPaused2)
        {
            V_savedCloudSpeed2 = V_cloudSpeed2;
            V_cloudSpeed2 = 0;
        }
        else
        {
            V_cloudSpeed2 = V_savedCloudSpeed2;
        }

        // Cloud 3
        V_cloudPaused3 = !V_cloudPaused3;

        if (V_cloudPaused3)
        {
            V_savedCloudSpeed3 = V_cloudSpeed3;
            V_cloudSpeed3 = 0;
        }
        else
        {
            V_cloudSpeed3 = V_savedCloudSpeed3;
        }

        // Cloud 4
        V_cloudPaused4 = !V_cloudPaused4;

        if (V_cloudPaused4)
        {
            V_savedCloudSpeed4 = V_cloudSpeed4;
            V_cloudSpeed4 = 0;
        }
        else
        {
            V_cloudSpeed4 = V_savedCloudSpeed4;
        }

        /// Sun Stop and Start
        vsunPaused = !vsunPaused;

        if (vsunPaused)
        {
            vsavedSunSpeed = vsunSpeed;
            vsunSpeed = 0;
        }
        else
        {
            vsunSpeed = vsavedSunSpeed;
        }

        /// Moon Stop and Start
        vmoonPaused = !vmoonPaused;

        if (vmoonPaused)
        {
            vsavedMoonSpeed = vmoonSpeed;
            vmoonSpeed = 0;
        }
        else
        {
            vmoonSpeed = vsavedMoonSpeed;
        }

        /// Car3 Stop and Start
        M_car3_nightPaused = !M_car3_nightPaused;

        if (M_car3_nightPaused)
        {
            M_savedCar3_nightSpeed = M_car3_nightSpeed;
            M_car3_nightSpeed = 0;
        }
        else
        {
            M_car3_nightSpeed = M_savedCar3_nightSpeed;
        }

        /// Car4 Stop and Start
        M_car4_nightPaused = !M_car4_nightPaused;

        if (M_car4_nightPaused)
        {
            M_savedCar4_nightSpeed = M_car4_nightSpeed;
            M_car4_nightSpeed = 0;
        }
        else
        {
            M_car4_nightSpeed = M_savedCar4_nightSpeed;
        }
    }

    if(key == 27)
        exit(0);
}

void vmouse(int button, int state, int x, int y)
{
    if(isDay)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)   // Pause/resume
        {
            vtrainPaused = !vtrainPaused;
            if (vtrainPaused)
            {
                vsavedTrainSpeed = vtrainSpeed;
                vtrainSpeed = 0;
            }
            else
            {
                vtrainSpeed = vsavedTrainSpeed;
            }
        }
    }
    if(isDay)
    {
        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        {
            vsunPaused = !vsunPaused;
            if (vsunPaused)
            {
                vsavedSunSpeed = vsunSpeed;
                vsunSpeed = 0;
            }
            else
            {
                vsunSpeed = vsavedSunSpeed;
            }
        }
    }
    if(!isDay)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)   // Pause/resume
        {
            vmoonPaused = !vmoonPaused;
            if (vmoonPaused)
            {
                vsavedMoonSpeed = vmoonSpeed;
                vmoonSpeed = 0;
            }
            else
            {
                vmoonSpeed = vsavedMoonSpeed;
            }
        }
    }
    if(!isDay)
    {
        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)   // Pause/resume
        {
            V_cargoPaused = !V_cargoPaused;

            if (V_cargoPaused)
            {
                V_savedCargoSpeed = V_cargoSpeed;
                V_cargoSpeed = 0;
            }
            else
            {
                V_cargoSpeed = V_savedCargoSpeed;
            }
        }
    }
}

void vmainCityScenario()
{
    vsky();
    vmoon();
    vsun();
    V_cloud1();
    V_cloud2();
    V_cloud3();
    V_cloud4();
    vbuilding();
    vtrain();
    vflyOver();
    vgarden();
    vroad();
    vroadSideWall();
    vbus();
    vcargoTruck();

    // Show cars in both day and night for busy road effect
    M_car3_night();
    M_car4_night();
    // car1_nightM(); // Red car removed
}

// ===================== Shimul Scenario (Scenario 3) =====================

bool S_isDay = true;

//  Circle helpers
void circle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++)
    {
        float pi = 3.1416f;
        float A  = (i*2*pi)/180.0f;
        float x = radius * cosf(A);
        float y = radius * sinf(A);
        glVertex2f(x + centerX, y + centerY);
    }
    glEnd();
}

void halfCircle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 180; i++)
    {
        float pi = 3.1416f;
        float A  = (i*pi)/180.0f;
        float x = radius * cosf(A);
        float y = radius * sinf(A);
        glVertex2f(x + centerX, y + centerY);
    }
    glEnd();
}

// sky
void Ssky()
{
    glBegin(GL_QUADS);
    if(S_isDay) glColor3f(0.37f, 0.82f, 0.94f);
    else        glColor3f(0.10f, 0.13f, 0.22f);
    glVertex2i(0,700);
    glVertex2i(1000,700);
    glVertex2i(1000,530);
    glVertex2i(0,530);
    glEnd();
}

void Sbackground()
{
    if(S_isDay) glColor3f(.4f,0.74f,0.13f);
    else        glColor3f(0.15f, 0.35f, 0.08f);

    glBegin(GL_QUADS);
    glVertex2i(0,530);
    glVertex2i(1000,530);
    glVertex2i(1000,200);
    glVertex2i(0,200);
    glEnd();
}

void Shouse()
{
    int n=20;
    glBegin(GL_QUADS); //House top Red
    if (S_isDay) glColor3f(0.58f, 0.29f, 0.0f);
    else         glColor3f(0.25f, 0.12f, 0.02f);
    glVertex2i(50-n,350);
    glVertex2i(160-n,350);
    glVertex2i(185-n,315);
    glVertex2i(75-n,315);
    glEnd();

    glBegin(GL_QUADS); // House Wall
    if (S_isDay) glColor3f(1.0f, 0.83f, 0.63f);
    else         glColor3f(0.50f, 0.41f, 0.30f);
    glVertex2i(75-n,315);
    glVertex2i(175-n,315);
    glVertex2i(175-n,260);
    glVertex2i(75-n,250);
    glEnd();

    glBegin(GL_POLYGON); // House Side Wall
    if (S_isDay) glColor3f(1.0f, 0.72f, 0.40f);
    else         glColor3f(0.45f, 0.30f, 0.15f);
    glVertex2i(50-n,350);
    glVertex2i(75-n,315);
    glVertex2i(75-n,250);
    glVertex2i(35-n,260);
    glVertex2i(35-n,315);
    glEnd();

    glBegin(GL_QUADS); // Top left side
    if (S_isDay) glColor3f(0.58f, 0.29f, 0.0f);
    else         glColor3f(0.25f, 0.12f, 0.02f);
    glVertex2i(55-n,345);
    glVertex2i(35-n,315);
    glVertex2i(25-n,315);
    glVertex2i(50-n,350);
    glEnd();

    glBegin(GL_QUADS); // Side Border
    if (S_isDay) glColor3f(1.0f, 0.0f, 0.0f);
    else         glColor3f(0.5f, 0.0f, 0.0f);
    glVertex2i(75-n,250);
    glVertex2i(75-n,240);
    glVertex2i(25-n,250);
    glVertex2i(35-n,260);
    glEnd();
    glFlush();

    glBegin(GL_QUADS); // Front Border
    if (S_isDay) glColor3f(1.0f, 0.0f, 0.0f);
    else         glColor3f(0.5f, 0.0f, 0.0f);
    glVertex2i(75-n,250);
    glVertex2i(175-n,260);
    glVertex2i(185-n,250);
    glVertex2i(75-n,240);
    glEnd();

    glBegin(GL_QUADS); //House Main door
    if (S_isDay) glColor3f(0.50f, 0.23f, 0.09f);
    else         glColor3f(0.15f, 0.07f, 0.03f);
    glVertex2i(110-n,252);
    glVertex2i(140-n,255);
    glVertex2i(140-n,295);
    glVertex2i(110-n,295);

    if (S_isDay) glColor3f(0.50f, 0.23f, 0.09f);
    else         glColor3f(1.0f, 1.0f, 0.5f);
    glVertex2i(112-n,254);
    glVertex2i(138-n,257);
    glVertex2i(138-n,293);
    glVertex2i(112-n,293);
    glEnd();

    glBegin(GL_QUADS); //House Side Window
    if (S_isDay) glColor3f(0.50f, 0.23f, 0.09f);
    else         glColor3f(0.15f, 0.07f, 0.03f);
    glVertex2i(45-n,270);
    glVertex2i(65-n,270);
    glVertex2i(65-n,300);
    glVertex2i(45-n,300);
    glEnd();

    if (S_isDay) glColor3f(0.50f, 0.23f, 0.09f);
    else         glColor3f(1.0f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2i(47-n,272);
    glVertex2i(63-n,272);
    glVertex2i(63-n,298);
    glVertex2i(47-n,298);
    glEnd();

    // Right houses and roads/gardens
    int x = 140; int y=110;
    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(0.58f, 0.29f, 0.0f); else glColor3f(0.25f, 0.12f, 0.02f);
    glVertex2i(625 + x,350+y); glVertex2i(735 + x,350+y); glVertex2i(760 + x,315+y); glVertex2i(650 + x,315+y);
    glEnd();

    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(1.0f, 0.83f, 0.63f); else glColor3f(0.50f, 0.41f, 0.30f);
    glVertex2i(650 + x,315+y); glVertex2i(750 + x,315+y); glVertex2i(750 + x,260+y); glVertex2i(650 + x,250+y);
    glEnd();

    glBegin(GL_POLYGON);
    if (S_isDay) glColor3f(1.0f, 0.72f, 0.40f); else glColor3f(0.45f, 0.30f, 0.15f);
    glVertex2i(625 + x,350+y); glVertex2i(650 + x,315+y); glVertex2i(650 + x,250+y); glVertex2i(610 + x,260+y); glVertex2i(610 + x,315+y);
    glEnd();

    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(0.58f, 0.29f, 0.0f); else glColor3f(0.25f, 0.12f, 0.02f);
    glVertex2i(630 + x,345+y); glVertex2i(610 + x,315+y); glVertex2i(600 + x,315+y); glVertex2i(625 + x,350+y);
    glEnd();

    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(1.0f, 0.0f, 0.0f); else glColor3f(0.5f, 0.0f, 0.0f);
    glVertex2i(650 + x,250+y); glVertex2i(650 + x,240+y); glVertex2i(600 + x,250+y); glVertex2i(610 + x,260+y);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(1.0f, 0.0f, 0.0f); else glColor3f(0.5f, 0.0f, 0.0f);
    glVertex2i(650 + x,250+y); glVertex2i(750 + x,260+y); glVertex2i(760 + x,250+y); glVertex2i(650 + x,240+y);
    glEnd();

    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(0.50f, 0.23f, 0.09f); else glColor3f(0.15f, 0.007f, 0.03f);
    glVertex2i(685 + x,252+y); glVertex2i(715 + x,255+y); glVertex2i(715 + x,295+y); glVertex2i(685 + x,295+y);
    glEnd();

    if (S_isDay) glColor3f(0.50f, 0.23f, 0.09f); else glColor3f(1.0f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2i(687 + x,254+y); glVertex2i(713 + x,257+y); glVertex2i(713 + x,293+y); glVertex2i(687 + x,293+y);
    glEnd();

    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(0.50f, 0.23f, 0.09f); else glColor3f(0.15f, 0.07f, 0.03f);
    glVertex2i(620 + x,270+y); glVertex2i(640 + x,270+y); glVertex2i(640 + x,300+y); glVertex2i(620 + x,300+y);
    glEnd();

    if (S_isDay) glColor3f(0.50f, 0.23f, 0.09f); else glColor3f(1.0f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2i(622 + x,272+y); glVertex2i(638 + x,272+y); glVertex2i(638 + x,298+y); glVertex2i(622 + x,298+y);
    glEnd();

    // Duplicate right house without offset
    y=100;
    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(0.58f, 0.29f, 0.0f); else glColor3f(0.25f, 0.12f, 0.02f);
    glVertex2i(625,350+y); glVertex2i(735,350+y); glVertex2i(760,315+y); glVertex2i(650,315+y);
    glEnd();

    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(1.0f, 0.83f, 0.63f); else glColor3f(0.50f, 0.41f, 0.30f);
    glVertex2i(650,315+y); glVertex2i(750,315+y); glVertex2i(750,260+y); glVertex2i(650,250+y);
    glEnd();

    glBegin(GL_POLYGON);
    if (S_isDay) glColor3f(1.0f, 0.72f, 0.40f); else glColor3f(0.45f, 0.30f, 0.15f);
    glVertex2i(625,350+y); glVertex2i(650,315+y); glVertex2i(650,250+y); glVertex2i(610,260+y); glVertex2i(610,315+y);
    glEnd();

    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(0.58f, 0.29f, 0.0f); else glColor3f(0.25f, 0.12f, 0.02f);
    glVertex2i(630,345+y); glVertex2i(610,315+y); glVertex2i(600,315+y); glVertex2i(625,350+y);
    glEnd();

    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(1.0f, 0.0f, 0.0f); else glColor3f(0.5f, 0.0f, 0.0f);
    glVertex2i(650,250+y); glVertex2i(650,240+y); glVertex2i(600,250+y); glVertex2i(610,260+y);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(1.0f, 0.0f, 0.0f); else glColor3f(0.5f, 0.0f, 0.0f);
    glVertex2i(650,250+y); glVertex2i(750,260+y); glVertex2i(760,250+y); glVertex2i(650,240+y);
    glEnd();

    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(0.50f, 0.23f, 0.09f); else glColor3f(0.15f, 0.007f, 0.03f);
    glVertex2i(685,252+y); glVertex2i(715,255+y); glVertex2i(715,295+y); glVertex2i(685,295+y);
    glEnd();

    if (S_isDay) glColor3f(0.50f, 0.23f, 0.09f); else glColor3f(1.0f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2i(687,254+y); glVertex2i(713,257+y); glVertex2i(713,293+y); glVertex2i(687,293+y);
    glEnd();

    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(0.50f, 0.23f, 0.09f); else glColor3f(0.15f, 0.07f, 0.03f);
    glVertex2i(620,270+y); glVertex2i(640,270+y); glVertex2i(640,300+y); glVertex2i(620,300+y);
    glEnd();

    if (S_isDay) glColor3f(0.50f, 0.23f, 0.09f); else glColor3f(1.0f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2i(622,272+y); glVertex2i(638,272+y); glVertex2i(638,298+y); glVertex2i(622,298+y);
    glEnd();

    glBegin(GL_QUADS); //left side road
    if (S_isDay) glColor3f(0.27f, 0.28f, 0.29f); else glColor3f(0.10f, 0.12f, 0.14f);
    glVertex2i(0,200); glVertex2i(350,200); glVertex2i(365,125); glVertex2i(0,125);
    glEnd();

    glBegin(GL_QUADS); //left side garden
    if (S_isDay) glColor3f(0.4f, 0.74f, 0.13f); else glColor3f(0.15f, 0.35f, 0.08f);
    glVertex2i(0,125); glVertex2i(365,125); glVertex2i(390,0); glVertex2i(0,0);
    glEnd();

    glBegin(GL_QUADS); //right side road
    if (S_isDay) glColor3f(0.27f, 0.28f, 0.29f); else glColor3f(0.10f, 0.12f, 0.14f);
    glVertex2i(600,200); glVertex2i(1000,200); glVertex2i(1000,125); glVertex2i(610,125);
    glEnd();

    glBegin(GL_QUADS); //right side garden
    if (S_isDay) glColor3f(0.4f, 0.74f, 0.13f); else glColor3f(0.15f, 0.35f, 0.08f);
    glVertex2i(610,125); glVertex2i(1000,125); glVertex2i(1000,0); glVertex2i(640,0);
    glEnd();
}

void Sbridge()
{
    glBegin(GL_QUADS); //bridge
    if (S_isDay) glColor3f(0.50f, 0.50f, 0.50f); else glColor3f(0.20f, 0.20f, 0.20f);
    glVertex2i(350,200); glVertex2i(600,200); glVertex2i(615,125); glVertex2i(365,125);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    if (S_isDay) glColor3f(1.0f, 1.0f, 1.0f); else glColor3f(0.5f, 0.5f, 0.5f);
    for(int x = 365; x<616; x+=50){ glVertex2i(x,125); glVertex2i(x+3,140);}
    for(int x = 350; x<601; x+=50){ glVertex2i(x,200); glVertex2i(x+3,215);}
    glEnd();

    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(1.0f, 1.0f, 1.0f); else glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2i(330,217); glVertex2i(620,217); glVertex2i(620,210); glVertex2i(330,210);
    glEnd();

    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(1.0f, 1.0f, 1.0f); else glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2i(345,147); glVertex2i(630,147); glVertex2i(630,140); glVertex2i(345,140);
    glEnd();
}

// Sun
float SsunSpeed = 2.0f; float savedSsunSpeed = 0.0f; bool SsunPaused = false; float S_moveSun = 0.0f;
void Ssun(){ if(S_isDay){ glPushMatrix(); glTranslatef(S_moveSun, 0, 0); glColor3f(1,1,0); circle(50,650,40); glPopMatrix(); } }
void S_updateSun(int value){ if (!SsunPaused){ S_moveSun += SsunSpeed; if (S_moveSun > 1000) S_moveSun = -200; glutPostRedisplay(); } glutTimerFunc(50, S_updateSun, 0); }

// Moon
float SmoonSpeed = 2.0f; float savedSmoonSpeed = 0.0f; bool SmoonPaused = false; float S_moveMoon = 0.0f;
void Smoon(){ if(!S_isDay){ glPushMatrix(); glTranslatef(S_moveMoon, 0, 0); glColor3f(1,1,1); circle(850,650,40); glColor3f(0.10f, 0.13f, 0.22f); circle(860,660,40); glPopMatrix(); } }
void S_updateMoon(int value){ if (!SmoonPaused){ S_moveMoon -= SmoonSpeed; if (S_moveMoon < -940) S_moveMoon = 200; glutPostRedisplay(); } glutTimerFunc(50, S_updateMoon, 0); }

void Stree(){
    if (S_isDay) glColor3f(0.13f, 0.54f, 0.13f); else glColor3f(0.05f, 0.25f, 0.05f);
    int g=80; int v=33;
    circle(190-g,327+v,18); circle(175-g,327+v,18); circle(205-g,325+v,15); circle(220-g,325+v,18); circle(185.5f-g,342+v,18); circle(212.5f-g,342+v,18); circle(199-g,355+v,15);
    int b=540; int c=130;
    circle(190+b,327+c,18); circle(175+b,327+c,18); circle(205+b,325+c,15); circle(220+b,325+c,18); circle(185.5f+b,342+c,18); circle(212.5f+b,342+c,18); circle(199+b,355+c,15);

    int t=83;
    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(0.58f, 0.29f, 0.0f); else glColor3f(0.25f, 0.12f, 0.02f);
    glVertex2i(465+t,397); glVertex2i(487+t,397); glVertex2i(487+t,345); glVertex2i(465+t,345);
    glEnd();

    glBegin(GL_POLYGON);
    if (S_isDay) glColor3f(0.58f, 0.29f, 0.0f); else glColor3f(0.25f, 0.12f, 0.02f);
    glVertex2i(548,345); glVertex2i(533,327); glVertex2i(559,335); glVertex2i(585,327); glVertex2i(570,345);
    glEnd();

    if (S_isDay) glColor3f(0.13f, 0.54f, 0.13f); else glColor3f(0.05f, 0.25f, 0.05f);
    circle(447+t,402,20); circle(450+t,422,20); circle(458+t,439,17); circle(475+t,443,20); circle(490+t,441,15); circle(505+t,400,20); circle(502+t,420,20); circle(475+t,415,20);

    int k=270; int f=85; int j=345;
    if (S_isDay) glColor3f(0.13f, 0.54f, 0.13f); else glColor3f(0.05f, 0.25f, 0.05f);
    circle(447-k,402-f,20); circle(450-k,422-f,20); circle(458-k,439-f,17); circle(475-k,443-f,20); circle(490-k,441-f,15); circle(505-k,400-f,20); circle(502-k,420-f,20); circle(475-k,415-f,20);

    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(0.58f, 0.29f, 0.0f); else glColor3f(0.25f, 0.12f, 0.02f);
    glVertex2i(465-k,397-f); glVertex2i(487-k,397-f); glVertex2i(487-k,345-f); glVertex2i(465-k,345-f);
    glEnd();

    glBegin(GL_POLYGON);
    if (S_isDay) glColor3f(0.58f, 0.29f, 0.0f); else glColor3f(0.25f, 0.12f, 0.02f);
    glVertex2i(195,260); glVertex2i(180,242); glVertex2i(206,250); glVertex2i(232,242); glVertex2i(217,260);
    glEnd();

    int i=450; int w=55; int a=525;
    if (S_isDay) glColor3f(0.13f, 0.54f, 0.13f); else glColor3f(0.05f, 0.25f, 0.05f);
    circle(447-i,402-w,20); circle(450-i,422-w,20); circle(458-i,439-w,17); circle(475-i,443-w,20); circle(490-i,441-w,15); circle(505-i,400-w,20); circle(502-i,420-w,20); circle(475-i,415-w,20);

    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(0.58f, 0.29f, 0.0f); else glColor3f(0.25f, 0.12f, 0.02f);
    glVertex2i(465-i,397-w); glVertex2i(487-i,397-w); glVertex2i(487-i,345-w); glVertex2i(465-i,345-w);
    glEnd();

    glBegin(GL_POLYGON);
    if (S_isDay) glColor3f(0.58f, 0.29f, 0.0f); else glColor3f(0.25f, 0.12f, 0.02f);
    glVertex2i(15,290); glVertex2i(0,272); glVertex2i(26,280); glVertex2i(52,272); glVertex2i(37,290);
    glEnd();

    int s=430; int u=50; if (S_isDay) glColor3f(0.13f, 0.54f, 0.13f); else glColor3f(0.05f, 0.25f, 0.05f);
    circle(447+s,402+u,20); circle(450+s,422+u,20); circle(458+s,439+u,17); circle(475+s,443+u,20); circle(490+s,441+u,15); circle(505+s,400+u,20); circle(502+s,420+u,20); circle(475+s,415+u,20);

    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(0.58f, 0.29f, 0.0f); else glColor3f(0.25f, 0.12f, 0.02f);
    glVertex2i(465+s,397+u); glVertex2i(487+s,397+u); glVertex2i(487+s,345+u); glVertex2i(465+s,345+u);
    glEnd();

    int h=355; glBegin(GL_POLYGON);
    if (S_isDay) glColor3f(0.58f, 0.29f, 0.0f); else glColor3f(0.25f, 0.12f, 0.02f);
    glVertex2i(540+h,345+u); glVertex2i(525+h,327+u); glVertex2i(551+h,335+u); glVertex2i(577+h,327+u); glVertex2i(562+h,345+u);
    glEnd();
}

void Spala(){
    if (S_isDay) glColor3f(0.98f, 0.88f, 0.02f); else glColor3f(0.49f, 0.44f, 0.01f);
    halfCircle(950,360,55); halfCircle(950,390,40); halfCircle(950,410,30); halfCircle(950,427,20);
    if (S_isDay) glColor3f(1.0f, 1.0f, 0.0f); else glColor3f(0.5f, 0.5f, 0.0f);
    halfCircle(980,360,45); halfCircle(980,375,40); halfCircle(980,395,30); halfCircle(980,412,20);
}

void Sriver(){
    if (S_isDay) glColor3f(0.0f, 0.52f, 0.92f); else glColor3f(0.0f, 0.26f, 0.46f);
    circle(35,-75,610);
    if (S_isDay) glColor3f(0.4f, 0.74f, 0.13f); else glColor3f(0.15f, 0.35f, 0.08f);
    circle(0,0,410);
}

void Sfield(){
    glLineWidth(3); glBegin(GL_LINES);
    if (S_isDay) glColor3f(0.89f, 0.70f, 0.27f); else glColor3f(0.45f, 0.35f, 0.13f);
    int count = 0;
    for(int x = 10; x<380; x+=30)
        for(int y = 115; y>0; y-=30){
            if(count == 0){
                glVertex2f(x, y); glVertex2f(x+10, y-25);
                glVertex2f(x+10, y-25); glVertex2f(x+20, y);
                glVertex2f(x+10, y-25); glVertex2f(x+10, y);
                count++;
            } else {
                glVertex2f(x+10, y); glVertex2f(x+20, y-25);
                glVertex2f(x+20, y-25); glVertex2f(x+30, y);
                glVertex2f(x+20, y-25); glVertex2f(x+20, y);
                count=0;
            }
        }
    glEnd();
}

void Sfootballfield(){
    if (S_isDay) glColor3f(1.0f, 1.0f, 1.0f); else glColor3f(0.5f, 0.5f, 0.5f);
    circle(815,60,20);
    if (S_isDay) glColor3f(0.4f, 0.74f, 0.13f); else glColor3f(0.15f, 0.35f, 0.08f);
    circle(815,60,17);
    if (S_isDay) glColor3f(1.0f, 1.0f, 1.0f); else glColor3f(0.5f, 0.5f, 0.5f);
    circle(815,60,4);

    glLineWidth(3); glBegin(GL_LINES);
    if (S_isDay) glColor3f(1.0f, 1.0f, 1.0f); else glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(670,15); glVertex2f(670,105);
    glVertex2f(670,105); glVertex2f(960,105);
    glVertex2f(960,105); glVertex2f(960,15);
    glVertex2f(960,15); glVertex2f(670,15);
    glVertex2f(815,15); glVertex2f(815,105);
    glVertex2f(670,85); glVertex2f(710,85);
    glVertex2f(710,85); glVertex2f(710,35);
    glVertex2f(710,35); glVertex2f(670,35);
    glVertex2f(960,35); glVertex2f(920,35);
    glVertex2f(920,35); glVertex2f(920,85);
    glVertex2f(920,85); glVertex2f(960,85);
    glEnd();
}

// Clouds
float moveScloud1 = 0.0f, Scloud1Speed = 1.0f; float savedScloud1Speed = 0.0f; bool Scloud1Paused = false;
float moveScloud2 = 0.0f, Scloud2Speed = 1.0f; float savedScloud2Speed = 0.0f; bool Scloud2Paused = false;
float moveScloud3 = 0.0f, Scloud3Speed = 1.0f; float savedScloud3Speed = 0.0f; bool Scloud3Paused = false;

void Scloud1(){ glPushMatrix(); glTranslatef(moveScloud1,0,0); if (S_isDay) glColor3f(1,1,1); else glColor3f(0.5f,0.5f,0.5f); circle(720,660,30); circle(750,650,30); circle(780,660,25); circle(750,660,35); circle(770,665,35); glPopMatrix(); }
void Scloud2(){ glPushMatrix(); glTranslatef(moveScloud2,0,0); if (S_isDay) glColor3f(1,1,1); else glColor3f(0.5f,0.5f,0.5f); circle(550,640,28); circle(580,635,28); circle(610,640,28); circle(565,660,25); circle(595,660,25); glPopMatrix(); }
void Scloud3(){ glPushMatrix(); glTranslatef(moveScloud3,0,0); if (S_isDay) glColor3f(1,1,1); else glColor3f(0.5f,0.5f,0.5f); circle(250,640,28); circle(310,640,28); circle(270,660,25); circle(300,660,25); circle(270,630,25); circle(300,630,25); glPopMatrix(); }

void updateScloud1(int value){ if(S_isDay){ if(!Scloud1Paused){ moveScloud1 += Scloud1Speed; if (moveScloud1 > 1000) moveScloud1 = -800; glutPostRedisplay(); } } else { if(!Scloud1Paused){ moveScloud1 -= (Scloud1Speed+1); if (moveScloud1 < -900) moveScloud1 = 300; glutPostRedisplay(); } } glutTimerFunc(25, updateScloud1, 0); }
void updateScloud2(int value){ moveScloud2 += Scloud2Speed; if (moveScloud2 > 1000) moveScloud2 = -800; glutPostRedisplay(); glutTimerFunc(25, updateScloud2, 0); }
void updateScloud3(int value){ moveScloud3 += Scloud3Speed; if (moveScloud3 > 1000) moveScloud3 = -800; glutPostRedisplay(); glutTimerFunc(25, updateScloud3, 0); }

void Shill(){
    if (S_isDay) glColor3f(0.13f, 0.54f, 0.13f); else glColor3f(0.05f, 0.25f, 0.05f);
    halfCircle(15,530,35); halfCircle(45,530,20); halfCircle(90,530,35); halfCircle(135,530,25); halfCircle(180,530,40); halfCircle(225,530,27); halfCircle(255,530,30); halfCircle(300,530,38);
    halfCircle(315,530,15); halfCircle(345,530,20); halfCircle(390,530,35); halfCircle(435,530,25); halfCircle(480,530,40); halfCircle(525,530,27); halfCircle(555,530,30); halfCircle(600,530,38);
    halfCircle(615,530,15); halfCircle(645,530,20); halfCircle(690,530,35); halfCircle(735,530,25); halfCircle(780,530,40); halfCircle(825,530,27); halfCircle(855,530,30); halfCircle(900,530,38);
    halfCircle(915,530,15); halfCircle(945,530,20); halfCircle(990,530,35);
}

// Cars
float moveScar1 = 0.0f; float Scar1Speed = 1.0f; float savedScar1Speed = 0.0f; bool Scar1Paused = false;
float moveScar2 = 0.0f; float Scar2Speed = 1.0f; float savedScar2Speed = 0.0f; bool Scar2Paused = false;

void Scar1(){
    glPushMatrix(); glTranslatef(moveScar1, 0, 0);
    glBegin(GL_POLYGON);
    if (S_isDay) glColor3f(1.0f, 0.0f, 0.0f); else glColor3f(0.5f, 0.0f, 0.0f);
    glVertex2i(100,165); glVertex2i(100,180); glVertex2i(105,190); glVertex2i(193,190); glVertex2i(205,185); glVertex2i(205,165);
    glBegin(GL_POLYGON);
    if (S_isDay) glColor3f(1.0f, 0.0f, 0.0f); else glColor3f(0.5f, 0.0f, 0.0f);
    glVertex2i(110,185); glVertex2i(121,208); glVertex2i(170,208); glVertex2i(190,185);
    glEnd();
    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(0.27f, 0.28f, 0.29f); else glColor3f(0.15f, 0.07f, 0.03f);
    glVertex2i(123,190); glVertex2i(123,202); glVertex2i(145,202); glVertex2i(145,190);
    glEnd();
    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(0.27f, 0.28f, 0.29f); else glColor3f(1.0f, 1.0f, 0.5f);
    glVertex2i(125,192); glVertex2i(125,200); glVertex2i(143,200); glVertex2i(143,192);
    glEnd();
    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(0.27f, 0.28f, 0.29f); else glColor3f(0.15f, 0.07f, 0.03f);
    glVertex2i(152,191); glVertex2i(152,202); glVertex2i(168,202); glVertex2i(177,191);
    glEnd();
    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(0.27f, 0.28f, 0.29f); else glColor3f(1.0f, 1.0f, 0.5f);
    glVertex2i(154,189); glVertex2i(154,200); glVertex2i(166,200); glVertex2i(175,189);
    glEnd();
    if (S_isDay) glColor3f(0.34f, 0.34f, 0.34f); else glColor3f(0.15f, 0.15f, 0.15f);
    halfCircle(125,165,10);
    glColor3f(0,0,0); circle(125,165,9); if (S_isDay) glColor3f(1,1,1); else glColor3f(0.5f,0.5f,0.5f); circle(125,165,3);
    if (S_isDay) glColor3f(0.34f, 0.34f, 0.34f); else glColor3f(0.15f, 0.15f, 0.15f);
    circle(175,165,10); glColor3f(0,0,0); circle(175,165,9); if (S_isDay) glColor3f(1,1,1); else glColor3f(0.5f,0.5f,0.5f); circle(175,165,3);
    glPopMatrix();
}
void updateScar1(int value){ moveScar1 += Scar1Speed; if (moveScar1 > 1000) moveScar1 = -800; glutPostRedisplay(); glutTimerFunc(10, updateScar1, 0); }

void Scar2(){
    glPushMatrix(); glTranslatef(moveScar2, 0, 0);
    glBegin(GL_POLYGON);
    if (S_isDay) glColor3f(0.0f, 0.52f, 0.92f); else glColor3f(0.0f, 0.26f, 0.46f);
    glVertex2i(700,160); glVertex2i(700,205); glVertex2i(710,215); glVertex2i(800,215); glVertex2i(830,190); glVertex2i(860,188); glVertex2i(863,163); glVertex2i(860,160);
    glEnd();
    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(0.27f, 0.28f, 0.29f); else glColor3f(0.15f, 0.07f, 0.03f);
    glVertex2i(715,205); glVertex2i(755,205); glVertex2i(755,190); glVertex2i(715,190);
    glEnd();
    glBegin(GL_QUADS);
    if (S_isDay) glColor3f(0.27f, 0.28f, 0.29f); else glColor3f(1.0f, 1.0f, 0.5f);
    glVertex2i(717,203); glVertex2i(753,203); glVertex2i(753,192); glVertex2i(717,192);
    glEnd();
    glBegin(GL_POLYGON);
    if (S_isDay) glColor3f(0.27f, 0.28f, 0.29f); else glColor3f(0.15f, 0.07f, 0.03f);
    glVertex2i(775,205); glVertex2i(800,205); glVertex2i(815,190); glVertex2i(775,190);
    glBegin(GL_POLYGON);
    if (S_isDay) glColor3f(0.27f, 0.28f, 0.29f); else glColor3f(1.0f, 1.0f, 0.5f);
    glVertex2i(773,203); glVertex2i(798,203); glVertex2i(813,192); glVertex2i(773,192);
    glEnd();
    glLineWidth(6); glBegin(GL_LINES); glColor3f(0,0,0); glVertex2f(700,162); glVertex2f(863,160); glVertex2f(864,162); glEnd();
    glLineWidth(2); glBegin(GL_LINES); glColor3f(0,0,0); glVertex2f(762,160); glVertex2f(762,210); glEnd();
    if (S_isDay) glColor3f(0.34f, 0.34f, 0.34f); else glColor3f(0.15f, 0.15f, 0.15f);
    halfCircle(727,160,12); circle(825,160,12);
    glColor3f(0,0,0); circle(727,160,10); circle(825,160,10);
    if (S_isDay) glColor3f(1,1,1); else glColor3f(0.5f,0.5f,0.5f);
    circle(727,160,4); circle(825,160,4);
    glPopMatrix();
}
void updateScar2(int value){ moveScar2 += Scar2Speed; if (moveScar2 > 1000) moveScar2 = -800; glutPostRedisplay(); glutTimerFunc(10, updateScar2, 0); }

void AhalfCircle(int centerX, int centerY, int radius)
{
    const double pi = 3.141592653589793;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY);
    for (int i = 60; i <= 240; i++){
        double angle = i * (pi / 180.0); double x = radius * cos(angle); double y = radius * sin(angle);
        glVertex2f((float)x + centerX, (float)y + centerY);
    }
    glEnd();
}

void clockwiseHalfCircle(int centerX, int centerY, int radius)
{
    const double pi = 3.141592653589793;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY);
    for (int i = 60; i >= -120; i--){
        double angle = i * (pi / 180.0); double x = radius * cos(angle); double y = radius * sin(angle);
        glVertex2f((float)x + centerX, (float)y + centerY);
    }
    glEnd();
}

void ShouseRoad()
{
    if (S_isDay) glColor3f(0.97f, 0.74f, 0.19f); else glColor3f(0.49f, 0.37f, 0.10f);
    clockwiseHalfCircle(730,330,150);
    if (S_isDay) glColor3f(0.4f, 0.74f, 0.13f); else glColor3f(0.15f, 0.35f, 0.08f);
    clockwiseHalfCircle(715,340,90);
    if (S_isDay) glColor3f(0.97f, 0.74f, 0.19f); else glColor3f(0.49f, 0.37f, 0.10f);
    clockwiseHalfCircle(610,280,165);
    if (S_isDay) glColor3f(0.4f, 0.74f, 0.13f); else glColor3f(0.15f, 0.35f, 0.08f);
    clockwiseHalfCircle(610,280,90);
}

void S_mouse(int button, int state, int x, int y)
{
    if(S_isDay){ if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){ SsunPaused = !SsunPaused; if (SsunPaused){ savedSsunSpeed = SsunSpeed; SsunSpeed = 0; } else { SsunSpeed = savedSsunSpeed; } } }
    if(S_isDay){ if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){ Scar1Paused = !Scar1Paused; if (Scar1Paused){ savedScar1Speed = Scar1Speed; Scar1Speed = 0; } else { Scar1Speed = savedScar1Speed; } } }
    if(!S_isDay){ if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){ SmoonPaused = !SmoonPaused; if (SmoonPaused){ savedSmoonSpeed = SmoonSpeed; SmoonSpeed = 0; } else { SmoonSpeed = savedSmoonSpeed; } } }
}

void S_keyboard(unsigned char key, int x, int y)
{
    if (key == 'd' || key == 'D'){ S_isDay = true; glutPostRedisplay(); }
    else if(key == 'n' || key == 'N'){ S_isDay = false; glutPostRedisplay(); }
    else if (key == ' '){
        SsunPaused = !SsunPaused; if(SsunPaused){ savedSsunSpeed = SsunSpeed; SsunSpeed = 0; } else { SsunSpeed = savedSsunSpeed; }
        Scloud1Paused = !Scloud1Paused; if(Scloud1Paused){ savedScloud1Speed = Scloud1Speed; Scloud1Speed = 0; } else { Scloud1Speed = savedScloud1Speed; }
        Scloud2Paused = !Scloud2Paused; if(Scloud2Paused){ savedScloud2Speed = Scloud2Speed; Scloud2Speed = 0; } else { Scloud2Speed = savedScloud2Speed; }
        Scloud3Paused = !Scloud3Paused; if(Scloud3Paused){ savedScloud3Speed = Scloud3Speed; Scloud3Speed = 0; } else { Scloud3Speed = savedScloud3Speed; }
        Scar1Paused = !Scar1Paused; if(Scar1Paused){ savedScar1Speed = Scar1Speed; Scar1Speed = 0; } else { Scar1Speed = savedScar1Speed; }
        Scar2Paused = !Scar2Paused; if(Scar2Paused){ savedScar2Speed = Scar2Speed; Scar2Speed = 0; } else { Scar2Speed = savedScar2Speed; }
    } else if(key == 27){ exit(0); }
}

void S_specialKeys(int key, int x, int y)
{
    if(S_isDay){ if(key==GLUT_KEY_UP) Scar1Speed += 0.2f; else if(key==GLUT_KEY_DOWN){ Scar1Speed -= 0.2f; if (Scar1Speed < 0) Scar1Speed = 0; } }
    if(!S_isDay){ if(key==GLUT_KEY_RIGHT) Scar2Speed += 0.2f; else if(key==GLUT_KEY_LEFT){ Scar2Speed -= 0.2f; if (Scar2Speed < 0) Scar2Speed = 0; } }
}

void shimul()
{
    Sbackground(); ShouseRoad(); Sriver(); Ssky(); Ssun(); Smoon(); Stree(); Spala(); Shouse(); Scloud1(); Scloud2(); Scloud3(); Shill(); Sbridge(); Scar1(); Scar2(); Sfield(); Sfootballfield();
}

/// ------------------>>>>>>>  Display
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if(currentScenario == 1){
        glPushMatrix();
        glScalef(0.04f, 0.057f, 1.0f);  // Scale factors
        glTranslatef(-500, -350, 0);    // Center the scene

        vmainCityScenario();
        glPopMatrix();
    } else if(currentScenario == 2) {
        rdisplay2();
    } else if(currentScenario == 3) {
        // Switch projection to 0..1000 x 0..700 for Shimul scenario
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0, 1000, 0, 700);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        shimul();
        // Restore projection
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
    }
    glutSwapBuffers();
}

void merged_keyboard(unsigned char key, int x, int y) {
    if (key == '1') {
        currentScenario = 1;
        glutPostRedisplay();
    } else if (key == '2') {
        currentScenario = 2;
        glutPostRedisplay();
    } else if (key == '3') {
        currentScenario = 3;
        glutPostRedisplay();
    } else if (currentScenario == 1) {
        vkeyboard(key, x, y);
    } else if (currentScenario == 2) {
        rkeyboard(key, x, y);
    } else if (currentScenario == 3) {
        S_keyboard(key, x, y);
    }
}

void merged_mouse(int button, int state, int x, int y) {
    if (currentScenario == 1) {
        vmouse(button, state, x, y);
    } else if (currentScenario == 2) {
        rmouse(button, state, x, y);
    } else if (currentScenario == 3) {
        S_mouse(button, state, x, y);
    }
}

void merged_special(int key, int x, int y) {
    if (currentScenario == 1) {
        vspecialKeys(key, x, y);
    } else if (currentScenario == 3) {
        S_specialKeys(key, x, y);
    }
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20, 20, -20, 20);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    cout<<"Press 1 for Scenario-1 (City)"<<endl;
    cout<<"Press 2 for Scenario-2 (Landscape)"<<endl;
    cout<<"Press 3 for Scenario-3 (Village/Bridge)"<<endl;
    cout<<"Other controls as per original scenarios"<<endl;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Merged Scenarios");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(merged_keyboard);
    glutSpecialFunc(merged_special);
    glutMouseFunc(merged_mouse);

    // Scenario 1 timers
    glutTimerFunc(16, V_updateCloud1, 0);
    glutTimerFunc(16, V_updateCloud2, 0);
    glutTimerFunc(16, V_updateCloud3, 0);
    glutTimerFunc(16, V_updateCloud4, 0);
    glutTimerFunc(2, vupdateSun, 0);
    glutTimerFunc(16, vupdateMoon, 0);
    glutTimerFunc(16, vupdateTrain, 0);
    glutTimerFunc(2, V_updateBus, 0);
    glutTimerFunc(16, V_updateCargo, 0);
    glutTimerFunc(16, M_updateCar3_night, 0);
    glutTimerFunc(16, M_updateCar4_night, 0);
    glutTimerFunc(12, updateCar1_nightM, 0);

    // Scenario 2 timers
    glutTimerFunc(300, rupdate, 0);
    glutTimerFunc(0, rupdate1, 0);

    // Scenario 3 timers (Shimul)
    glutTimerFunc(1, updateScar1, 0);
    glutTimerFunc(1, updateScar2, 0);
    glutTimerFunc(1, updateScloud1, 0);
    glutTimerFunc(1, updateScloud2, 0);
    glutTimerFunc(1, updateScloud3, 0);
    glutTimerFunc(1, S_updateSun, 0);
    glutTimerFunc(16, S_updateMoon, 0);

    glutMainLoop();
    return 0;
}
