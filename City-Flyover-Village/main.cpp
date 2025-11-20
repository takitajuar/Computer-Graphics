#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include<math.h>
using namespace std;

bool scenarioTaki = true;
bool scenarioTajuar = false;
bool scenarioMahir = false;
bool scenarioTTM = false;

/// **************************************************************************************************************************************************
/// ******************************************************** >>> Taki <<< ************************************************************************
/// **************************************************************************************************************************************************
bool isDay = true;

/// #############  Circle  #############
void circle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++)
    {
        float pi = 3.1416;
        float A  = (i*2*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY );
    }
    glEnd();
}

void halfCircle(float centerX, float centerY, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 180; i++)
    {
        float pi = 3.1416;
        float A  = (i*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY );
    }
    glEnd();
}

/// #############  Sun  #############
float moveSun = 0.0f;
float sunSpeed =0.3f;
float savedSunSpeed = 0.0f;
bool sunPaused = false;

void sun()
{
    if(isDay)
    {
        glPushMatrix();
        glTranslatef(moveSun, 0, 0);
        glColor3f(1,1,0);
        circle(50,650,35);
        glPopMatrix();
    }
}

void updateSun(int value)
{
    if(!sunPaused)
    {
        moveSun += sunSpeed;
        if (moveSun > 1050)
        {
            moveSun = -200;
        }

        glutPostRedisplay();
    }

    glutTimerFunc(16, updateSun, 0);
}

/// ############# Moon #############
float moveMoon = 0;
float moonSpeed =0.3f;
float savedMoonSpeed = 0.0f;
bool moonPaused = false;

void moon()
{
    if(!isDay)
    {
        glPushMatrix();
        glTranslatef(moveMoon, 0, 0);

        glColor3f(1,1,1);
        circle(850,650,40);

        glColor3f(0.10f, 0.13f, 0.22f);
        circle(860,660,40);
        glPopMatrix();
    }
}

void updateMoon(int value)
{
    if(!moonPaused)
    {
        moveMoon -= moonSpeed;
        if (moveMoon < -940)
        {
            moveMoon = 200;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(16, updateMoon, 0);
}

/// #############  SKY  #############
void sky()
{
    glBegin(GL_QUADS);

    if(isDay)
        glColor3f(0.37f, 0.82f, 0.94f);
    else
        glColor3f(0.10f, 0.13f, 0.22f);

    glVertex2f(0,   200);
    glVertex2f(1000,200);
    glVertex2f(1000,700);
    glVertex2f(0,   700);
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
    circle(x,    y, r);
    circle(x-25, y+5, r);
    circle(x+25, y+5, r);
    circle(x-10, y+20, r-3);
    circle(x+10, y+20, r-3);

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

    circle(337,640,18);
    circle(365,640,20);
    circle(390,640,18);
    circle(350,632,20);
    circle(375,632,20);
    circle(355,648,20);
    circle(375,648,20);

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
    circle(x, y-15, r);
    circle(x+25, y-10, r);
    circle(x-25, y-10, r);
    circle(x-50, y, r);
    circle(x+50, y, r);
    circle(x+30, y+15, r+5);
    circle(x, y+25, r+5);
    circle(x-30, y+15, r+5);

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
    circle(830,640,20);
    circle(860,638,22);
    circle(890,640,20);
    circle(845,652,20);
    circle(870,655,28);

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

/// ##############################################################  Garden  ###############################################################
void garden()
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
    int shift = 70;

    for(int i = 0; i< 67; i++)
    {
        glBegin(GL_QUADS);
        glColor3f(0.702,0.333,0.224);
        glVertex2f(15 + shift * i,205);
        glVertex2f(25 + shift * i,205);
        glVertex2f(25 + shift * i,220);
        glVertex2f(15 + shift * i,220);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0,0.32,0.004);

        glVertex2f(0  + shift * i,220);
        glVertex2f(40 + shift * i,220);
        glVertex2f(20 + shift * i,230);

        glVertex2f(10  + shift * i,225);
        glVertex2f(30 + shift * i,225);
        glVertex2f(20 + shift * i,235);

        glVertex2f(10  + shift * i,230);
        glVertex2f(30 + shift * i,230);
        glVertex2f(20 + shift * i,240);

        glEnd();

        /// Cloud shape tree
        if (isDay)
            glColor3f(0.0f, 0.5f, 0.0f);
        else
            glColor3f(0.1f, 0.3f, 0.1f);

        for(int i = 0; i<1000; i+=50)
        {
            halfCircle(i+20,190,25);
        }
    }
}

/// ##############################################################  Train  ###############################################################
float moveTrain = 0.0f;
float trainSpeed =1.0f;
float savedTrainSpeed = 0.0f;
bool trainPaused = false;

void train()
{
    glPushMatrix();
    glTranslatef(moveTrain, 0, 0);

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

    circle(301,295,6);

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

    // blue polygon
    if(isDay)
        glColor3f(0.38f, 0.84f, 1.0f);
    else
        glColor3f(0.18f, 0.64f, 0.80f);

    glBegin(GL_POLYGON);
    glVertex2f(320,291);
    glVertex2f(548,291);
    glVertex2f(548,311);
    glVertex2f(335,311);
    glVertex2f(320,300);
    glEnd();

    circle(320,295,4);

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

    //ground deep sky blue
    if(isDay)
        glColor3f(0.02f, 0.61f, 0.93f);
    else
        glColor3f(0.25f, 0.5f, 0.7f);

    glBegin(GL_QUADS);
    glVertex2f(322,288);
    glVertex2f(548,288);
    glVertex2f(548,293);
    glVertex2f(317,293);
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

void updateTrain(int value)
{
    if(!trainPaused)
    {
        moveTrain -= trainSpeed;
        if (moveTrain < -550)
        {
            moveTrain = 750;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(16, updateTrain, 0);
}

/// ##############################################################  Flyover  ###############################################################
void flyOver()
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

/// ##############################################################  Road  ###############################################################
void road()
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

/// ##############################################################  Bus  ###################################################################
float V_moveBus = 0.0f;
float V_busSpeed =1.0f;
float V_savedBusSpeed = 0.0f;
float V_busTireAngle = 0.0f;
bool V_busPaused = false;

void bus()
{
    glPushMatrix();
    glTranslatef(V_moveBus, 0, 0);

    glBegin(GL_QUADS);
    if (isDay)
        glColor3f(1.00f, 0.60f, 0.29f);
    else
        glColor3f(0.70f, 0.35f, 0.20f);

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

    glColor3f(1.00f, 0.60f, 0.29f);
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
    halfCircle(425,130,12);

    glPushMatrix();
    glTranslatef(425, 130, 0);
    glRotatef(V_busTireAngle, 0.0, 0.0, 1.0);  // Rotate only the tire
    glTranslatef(-425, -130, 0);

   if (isDay)
    glColor3f(0.8f, 0.8f, 0.8f);
else
    glColor3f(0.5f, 0.5f, 0.5f);

    circle(425,130,11);

    if (isDay)
    glColor3f(1.0f, 1.0f, 1.0f);
else
    glColor3f(0.7f, 0.7f, 0.7f);

    circle(425,130,5);

    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(414,130);
    glVertex2f(436,130);
    glEnd();

    glPopMatrix();

    /// FRONT TIRE
    glColor3f(0,0,0);
    halfCircle(540,130,12);

    glPushMatrix();
    glTranslatef(540, 130, 0);
    glRotatef(V_busTireAngle, 0.0, 0.0, 1.0);  // Rotate only the tire
    glTranslatef(-540, -130, 0);

    if (isDay)
    glColor3f(0.8f, 0.8f, 0.8f);
else
    glColor3f(0.5f, 0.5f, 0.5f);

    circle(540,130,11);

    if (isDay)
    glColor3f(1.0f, 1.0f, 1.0f);
else
    glColor3f(0.7f, 0.7f, 0.7f);

    circle(540,130,5);

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
        V_moveBus += V_busSpeed+1;
        if (V_moveBus > 700)
        {
            V_moveBus = -550;
        }
        V_busTireAngle -= 1.0f;
        glutPostRedisplay();
    }
    glutTimerFunc(2, V_updateBus, 0);


}
/// ######################################################## Cargo Track ########################################################
float V_moveCargo = 0.0f;
float V_cargoSpeed =1.0f;
float V_savedCargoSpeed = 0.0f;
float V_cargoTireAngle = 0.0f;
bool V_cargoPaused = false;

void cargoTruck()
{
    glPushMatrix();
    glTranslatef(V_moveCargo, 0, 0);

    /// Head and Body joint
    if (isDay)
        glColor3f(0.5f, 0.5f, 0.5f);
    else
        glColor3f(0.3f, 0.3f, 0.3f);

    glBegin(GL_QUADS);
    glVertex2f(760, 73);
    glVertex2f(730, 73);
    glVertex2f(730, 110);
    glVertex2f(760, 83);
    glEnd();

    ///  ********> Body <********
    if (isDay)
        glColor3f(0.51f, 0.86f, 0.92f);
    else
        glColor3f(0.22f, 0.46f, 0.55f);

    glBegin(GL_QUADS);
    glVertex2f(900, 83);
    glVertex2f(750, 83);
    glVertex2f(750, 150);
    glVertex2f(900, 150);
    glEnd();


    /// Head
    if (isDay)
        glColor3f(0.30f, 0.82f, 0.87f);
    else
        glColor3f(0.15f, 0.42f, 0.48f);

    /// upper quad
    glBegin(GL_QUADS);
    glVertex2f(745, 138);
    glVertex2f(715, 138);
    glVertex2f(690, 113);
    glVertex2f(745, 113);

    if (isDay)
        glColor3f(0.69f, 0.92f, 0.95f);
    else
        glColor3f(0.32f, 0.55f, 0.65f);

    glVertex2f(690, 113);
    glVertex2f(693, 111);
    glVertex2f(713, 132);
    glVertex2f(711, 135);

    if (isDay)
        glColor3f(0.30f, 0.82f, 0.87f);
    else
        glColor3f(0.15f, 0.42f, 0.48f);

    /// down quad
    glVertex2f(745, 75);
    glVertex2f(690, 70);
    glVertex2f(690, 113);
    glVertex2f(745, 113);

    glEnd();

    if (isDay)
        glColor3f(0.07f, 0.64f, 0.70f);
    else
        glColor3f(0.04f, 0.38f, 0.50f);

    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2f(740, 133);
    glVertex2f(717, 133);

    glVertex2f(740, 134);
    glVertex2f(740, 87);

    glVertex2f(740, 87);
    glVertex2f(720, 87);

    glVertex2f(720, 87);
    glVertex2f(710, 80);

    glVertex2f(710, 80);
    glVertex2f(693, 83);

    glVertex2f(717, 133);
    glVertex2f(693, 110);

    glVertex2f(693, 110);
    glVertex2f(693, 83);

    glEnd();

    /// window glass
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(718, 130);
    glVertex2f(737, 130);
    glVertex2f(737, 105);
    glVertex2f(697, 100);
    glVertex2f(697, 110);
    glEnd();

    /// inner glass
    if (isDay)
        glColor3f(0.92f, 1.0f, 0.996f);
    else
        glColor3f(0.60f, 0.75f, 0.78f);

    glBegin(GL_POLYGON);
    glVertex2f(720, 128);
    glVertex2f(735, 128);
    glVertex2f(735, 107);
    glVertex2f(699, 102);
    glVertex2f(701, 110);
    glEnd();

    ///******> door holder
    if (isDay)
        glColor3f(0.1f, 0.1f, 0.4f);
    else
        glColor3f(0.05f, 0.05f, 0.25f);

    glBegin(GL_QUADS);
    glVertex2f(735, 102);
    glVertex2f(735, 98);
    glVertex2f(727, 98);
    glVertex2f(727, 102);
    glEnd();

    /// *********>  REAR Light  <***********
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(1,0,0);

    glBegin(GL_QUADS);
    glVertex2f(895, 78);
    glVertex2f(900, 78);
    glVertex2f(900, 90);
    glVertex2f(895, 90);
    glEnd();


    /// *********>  FRONT Light  <***********
    if (isDay)
        glColor3f(1.0f, 1.0f, 0.0f);
    else
        glColor3f(0.8f, 0.8f, 0.2f);

    glBegin(GL_QUADS);
    glVertex2f(689, 82);
    glVertex2f(695, 85);
    glVertex2f(695, 89);
    glVertex2f(689, 89);

    if (isDay)
        glColor3f(1.0f, 0.68f, 0.016f);
    else
        glColor3f(0.8f, 0.5f, 0.01f);

    glVertex2f(689, 94);
    glVertex2f(695, 95);
    glVertex2f(695, 89);
    glVertex2f(689, 89);

    glEnd();

    if(!isDay)
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.68f, 0.016f);
        glVertex2f(689, 94);
        glVertex2f(600, 97);
        glVertex2f(600, 50);
        glVertex2f(689, 84);

        glEnd();
    }

    /// Under The Body Black bar
    if (isDay)
        glColor3f(0.5f, 0.5f, 0.5f);
    else
        glColor3f(0.3f, 0.3f, 0.3f);

    glBegin(GL_QUADS);
    glVertex2f(900, 73);
    glVertex2f(730, 73);
    glVertex2f(725, 83);
    glVertex2f(900, 83);

    glEnd();

    /// Front Black Bumper
    if (isDay)
        glColor3f(0.5f, 0.5f, 0.5f);
    else
        glColor3f(0.3f, 0.3f, 0.3f);

    glBegin(GL_POLYGON);
    glVertex2f(690, 70);
    glVertex2f(730, 70);
    glVertex2f(730, 75);
    glVertex2f(695, 75);
    glVertex2f(695, 85);
    glVertex2f(685, 80);

    glEnd();

    /// ********> body design <********
    if (isDay)
        glColor3f(0.31f, 0.81f, 0.88f);
    else
        glColor3f(0.15f, 0.45f, 0.55f);

    glBegin(GL_QUADS);

    for(int x = 895; x>760; x-=12)
    {
        glVertex2f(x, 88);
        glVertex2f(x-7, 88);
        glVertex2f(x-7, 145);
        glVertex2f(x, 145);
    }
    glEnd();

    /// Body sky blue 3 quads
    if (isDay)
        glColor3f(0.69f, 0.92f, 0.95f);
    else
        glColor3f(0.4f, 0.6f, 0.7f);

    glBegin(GL_QUADS);
    glVertex2f(755, 145);
    glVertex2f(775, 145);
    glVertex2f(810, 88);
    glVertex2f(790, 88);

    glVertex2f(785, 145);
    glVertex2f(825, 145);
    glVertex2f(860, 88);
    glVertex2f(820, 88);

    glVertex2f(835, 145);
    glVertex2f(860, 145);
    glVertex2f(895, 88);
    glVertex2f(870, 88);

    glEnd();

    /// blue design shadow
    /// side shadow
    if (isDay)
        glColor3f(0.05f, 0.64f, 0.69f);
    else
        glColor3f(0.02f, 0.3f, 0.35f);

    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 889; x>750; x-=12)
    {
        glVertex2f(x, 88);
        glVertex2f(x, 145);
    }
    glEnd();

    /// body up-down shadow
    if (isDay)
        glColor3f(0.05f, 0.64f, 0.69f);
    else
        glColor3f(0.02f, 0.28f, 0.32f);

    glLineWidth(1);
    glBegin(GL_LINES);
    for(int x = 895; x>760; x-=12)
    {
        glVertex2f(x, 88);
        glVertex2f(x-7, 88);

        glVertex2f(x, 145);
        glVertex2f(x-7, 145);
    }
    glEnd();

    /// REAR TIRE
    if (isDay)
        glColor3f(0.26f, 0.26f, 0.26f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    halfCircle(865,69,14);

    if (isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.8f, 0.8f, 0.8f);

    halfCircle(865,69,12);

    glPushMatrix();
    glTranslatef(865, 69, 0);
    glRotatef(V_cargoTireAngle, 0.0, 0.0, 1.0);  // Rotate only the tire
    glTranslatef(-865, -69, 0);

    if (isDay)
        glColor3f(0.7f, 0.7f, 0.6f);
    else
        glColor3f(0.4f, 0.4f, 0.35f);

    circle(865,69,12);

    if (isDay)
        glColor3f(0.70f, 0.73f, 0.73f);
    else
        glColor3f(0.45f, 0.48f, 0.48f);

    circle(865,69,8);

    if (isDay)
        glColor3f(0.57f, 0.60f, 0.61f);
    else
        glColor3f(0.3f, 0.32f, 0.33f);

    circle(865,69,7);

    if (isDay)
        glColor3f(0.89f, 0.89f, 0.89f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(865,69,5);

    if (isDay)
        glColor3f(0.60f, 0.60f, 0.60f);
    else
        glColor3f(0.35f, 0.35f, 0.35f);

    circle(865,69,4);

    glPopMatrix();

    /// FRONT TIRE

    if (isDay)
        glColor3f(0.26f, 0.26f, 0.26f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    halfCircle(725,69,14);

    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.8f, 0.8f, 0.8f);

    halfCircle(725,69,12);

    glPushMatrix();
    glTranslatef(725, 69, 0);
    glRotatef(V_cargoTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-725, -69, 0);

    // Front Tire
    if (isDay)
        glColor3f(0.7f, 0.7f, 0.6f);
    else
        glColor3f(0.45f, 0.45f, 0.4f);

    circle(725,69,12);

    if (isDay)
        glColor3f(0.70f, 0.73f, 0.73f);
    else
        glColor3f(0.45f, 0.48f, 0.48f);

    circle(725,69,8);

    if (isDay)
        glColor3f(0.57f, 0.60f, 0.61f);
    else
        glColor3f(0.35f, 0.38f, 0.39f);

    circle(725,69,7);

    if (isDay)
        glColor3f(0.89f, 0.89f, 0.89f);
    else
        glColor3f(0.45f, 0.45f, 0.45f);

    circle(725,69,5);

    if (isDay)
        glColor3f(0.60f, 0.60f, 0.60f);
    else
        glColor3f(0.35f, 0.35f, 0.35f);

    circle(725,69,4);

    if (isDay)
        glColor3f(1,1,1);
    else
        glColor3f(.5,.5,.5);

    glBegin(GL_TRIANGLES);
    glVertex2f(722,70);
    glVertex2f(728,70);
    glVertex2f(725,66);
    glEnd();

    glPopMatrix();
    glPopMatrix();
}

void V_updateCargo(int value)
{
    if(!V_cargoPaused)
    {
        V_moveCargo -= V_cargoSpeed+2;
        if (V_moveCargo < -940)
        {
            V_moveCargo = 450;
        }
        V_cargoTireAngle += 1.0f;
        glutPostRedisplay();
    }
    glutTimerFunc(2, V_updateCargo, 0);


}

/// ##############################################################  Road Side Wall  ###############################################################
void roadSideWall()
{
    if (isDay)
        glColor3f(0.839f, 0.443f, 0.235f);
    else
        glColor3f(0.42f, 0.22f, 0.13f);

    glBegin(GL_QUADS);
    glVertex2f(0,   170);
    glVertex2f(1000,170);
    glVertex2f(1000,190);
    glVertex2f(0,   190);
    glEnd();

    //Breaks Line
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    glLineWidth(1);
    glBegin(GL_LINES);

    glVertex2f(0,   170);
    glVertex2f(1000,170);

    glVertex2f(0,   175);
    glVertex2f(1000,175);

    glVertex2f(0,   180);
    glVertex2f(1000,180);

    glVertex2f(0,   185);
    glVertex2f(1000,185);

    glVertex2f(0,   190);
    glVertex2f(1000,190);

    for(int x = 10; x<1000; x+=20)
    {
        glVertex2f(x,170);
        glVertex2f(x,175);

        glVertex2f(x+10,175);
        glVertex2f(x+10,180);

        glVertex2f(x,180);
        glVertex2f(x,185);

        glVertex2f(x+10,185);
        glVertex2f(x+10,190);
    }

    glEnd();

    //Upper 2 lines
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2f(0,   200);
    glVertex2f(1000,200);

    glVertex2f(0,   205);
    glVertex2f(1000,205);

    for(int i = 0; i< 1000; i+=45)
    {
        glLineWidth(1);
        glVertex2f(i, 190);
        glVertex2f(i, 205);

        glVertex2f(i+5, 190);
        glVertex2f(i+5, 205);
    }
    glEnd();

}

/// ####################################################################### Building ###########################################################
void building()
{
    /// 1st Building
    if(isDay)
        glColor3f(0.92f, 0.92f, 0.92f);
    else
        glColor3f(0.55f, 0.55f, 0.55f);

    // body
    glBegin(GL_QUADS);
    glVertex2f(10,  200);
    glVertex2f(100, 200);
    glVertex2f(100, 525);
    glVertex2f(10,  525);

    if(isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    // Top
    glVertex2f(6,   525);
    glVertex2f(104, 525);
    glVertex2f(104, 535);
    glVertex2f(6,   535);
    glEnd();

    // window
    glBegin(GL_QUADS);
    for(int x = 18; x<80; x+=27 )
    {
        for(int y = 500; y>200; y-=60)
        {
            if(isDay)
                glColor3f(1,1,1);
            else
                glColor3f(0.15f, 0.07f, 0.03f);

            glVertex2f(x-2,  y+7);
            glVertex2f(x+22, y+7);
            glVertex2f(x+22, y-20);
            glVertex2f(x-2,  y-20);

            if(isDay)
                glColor3f(0.52f, 0.78f, 0.96f);
            else
                glColor3f(1.0f, 1.0f, 0.5f);

            glVertex2f(x,  y+5);
            glVertex2f(x+20, y+5);
            glVertex2f(x+20, y-20);
            glVertex2f(x,  y-20);
        }
    }

    // Window white border
    if(isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.6f, 0.6f, 0.6f);

    glBegin(GL_QUADS);
    for(int y = 480; y > 200; y -= 60 )
    {
        glVertex2f(5,   y   );
        glVertex2f(105, y   );
        glVertex2f(105, y-15);
        glVertex2f(5,   y-15);
    }
    glEnd();

    /// $$$$$$$$$$$$$$$$$$ 2nd Building $$$$$$$$$$$$$$
    glBegin(GL_QUADS);

    //body Left half
    if(isDay)
        glColor3f(0.90f, 0.80f, 0.69f);
    else
        glColor3f(0.45f, 0.40f, 0.35f);

    glVertex2f(90,  200);
    glVertex2f(135, 200);
    glVertex2f(135, 400);
    glVertex2f(90,  400);

    //right half
    if(isDay)
        glColor3f(0.83f, 0.73f, 0.63f);
    else
        glColor3f(0.50f, 0.45f, 0.40f);

    glVertex2f(135,  200);
    glVertex2f(180, 200);
    glVertex2f(180, 400);
    glVertex2f(135,  400);

    // Top
    if(isDay)
        glColor3f(0.45f, 0.24f, 0.13f);
    else
        glColor3f(0.25f, 0.15f, 0.10f);

    glVertex2f(90,  400);
    glVertex2f(180, 400);
    glVertex2f(165, 425);
    glVertex2f(105, 425);
    glEnd();

    // Left triangles
    if(isDay)
        glColor3f(0.90f, 0.80f, 0.69f);
    else
        glColor3f(0.45f, 0.40f, 0.35f);
    glBegin(GL_TRIANGLES);
    glVertex2f(135, 400);
    glVertex2f(115, 400);
    glVertex2f(135, 425);
    glEnd();

    // Right triangles
    if(isDay)
        glColor3f(0.83f, 0.73f, 0.63f);
    else
        glColor3f(0.50f, 0.45f, 0.40f);

    glBegin(GL_TRIANGLES);
    glVertex2f(135, 400);
    glVertex2f(155, 400);
    glVertex2f(135, 425);
    glEnd();

    // All border
    if(isDay)
        glColor3f(0.28f, 0.13f, 0.06f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(88, 400);
    glVertex2f(115, 400);

    glVertex2f(115, 398);
    glVertex2f(135, 427);

    glVertex2f(135, 427);
    glVertex2f(155, 400);

    glVertex2f(153, 400);
    glVertex2f(182, 400);

    //body Lines
    glVertex2f(90, 340);
    glVertex2f(180,340);

    glVertex2f(90, 280);
    glVertex2f(180,280);

    glVertex2f(90, 220);
    glVertex2f(180,220);

    glEnd();

    //window
    //Outer quad
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.28f, 0.13f, 0.06f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    for(int x = 100; x<180; x+=45)
    {
        for(int y = 385; y>200; y-=60)
        {
            glVertex2f(x,    y);
            glVertex2f(x+25, y);
            glVertex2f(x+25, y-30);
            glVertex2f(x,    y-30);
        }
    }

    if(isDay)
        glColor3f(0.67f, 0.77f, 0.89f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    //inner quad
    for(int x = 102; x<180; x+=45)
    {
        for(int y = 382; y>200; y-=60)
        {
            glVertex2f(x,    y);
            glVertex2f(x+21, y);
            glVertex2f(x+21, y-25);
            glVertex2f(x,    y-25);
        }
    }
    glEnd();

    // On window border
    if(isDay)
        glColor3f(0.28f, 0.13f, 0.06f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    glLineWidth(1);
    glBegin(GL_LINES);
    for(int x =100; x<180; x+=45)
        for(int y = 372; y>200; y-=60)
        {
            {
                glVertex2f(x,y);
                glVertex2f(x+25,y);

                glVertex2f(x+12.5,y+10);
                glVertex2f(x+12.5,y);
            }
        }

    glEnd();

    /// 3rd Building
    // Left side
    if (isDay)
        glColor3f(0.84f, 0.30f, 0.37f);
    else
        glColor3f(0.50f, 0.15f, 0.20f);

    glBegin(GL_QUADS);
    glVertex2f(190, 200);
    glVertex2f(235, 200);
    glVertex2f(235, 480);
    glVertex2f(190, 480);

    // Right side
    if (isDay)
        glColor3f(0.90f, 0.45f, 0.50f);
    else
        glColor3f(0.60f, 0.25f, 0.30f);

    glVertex2f(235, 200);
    glVertex2f(280, 200);
    glVertex2f(280, 480);
    glVertex2f(235, 480);

    //Top bar
    if (isDay)
        glColor3f(0.50f, 0.15f, 0.20f);
    else
        glColor3f(0.30f, 0.10f, 0.15f);

    glVertex2f(185, 490);
    glVertex2f(285, 490);
    glVertex2f(285, 475);
    glVertex2f(185, 475);

    if (isDay)
        glColor3f(0.50f, 0.15f, 0.20f);
    else
        glColor3f(0.30f, 0.10f, 0.15f);
    ;
    for(int y = 410; y>200; y-=70)
    {
        glVertex2f(185, y);
        glVertex2f(285, y);
        glVertex2f(285, y-10);
        glVertex2f(185, y-10);
    }

    glEnd();

    ///     window
    //   white border
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

    // blue
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

    ///              ***> 4th Building <***
    if (isDay)
        glColor3f(0.36f, 0.54f, 0.66f);
    else
        glColor3f(0.20f, 0.35f, 0.45f);

    glBegin(GL_QUADS);
    glVertex2f(300, 200);
    glVertex2f(400, 200);
    glVertex2f(400, 550);
    glVertex2f(300, 510);

    //Top White
    if (isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glVertex2f(299, 495);
    glVertex2f(401, 540);
    glVertex2f(401, 555);
    glVertex2f(299, 510);

    // Body white quard
    glVertex2f(300, 470);
    glVertex2f(400, 470);
    glVertex2f(400, 455);
    glVertex2f(300, 455);
    glEnd();

    if (isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(320, 200);
    glVertex2f(320, 510);

    glVertex2f(340, 200);
    glVertex2f(340, 520);

    glVertex2f(360, 200);
    glVertex2f(360, 530);

    glVertex2f(380, 200);
    glVertex2f(380, 535);

    if (isDay)
        glColor3f(0.30f, 0.42f, 0.51f);
    else
        glColor3f(0.18f, 0.28f, 0.36f);


    for(int y = 455; y> 200; y-=30)
    {
        glVertex2f(300, y);
        glVertex2f(400, y);
    }
    glVertex2f(312, 500);
    glVertex2f(400, 500);


    glEnd();

    /// 6th Building
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(0.94f, 0.69f, 0.35f);
    else
        glColor3f(0.65f, 0.45f, 0.20f);

    //Body
    glVertex2f(550, 200);
    glVertex2f(640, 200);
    glVertex2f(640, 400);
    glVertex2f(550, 400);

    //top red
    if(isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.6f, 0.0f, 0.0f);

    glVertex2f(550, 415);
    glVertex2f(640, 415);
    glVertex2f(640, 400);
    glVertex2f(550, 400);
    glEnd();

    if(isDay)
        glColor3f(0.94f, 0.69f, 0.35f);
    else
        glColor3f(0.65f, 0.45f, 0.20f);

    for(int x = 555; x<640; x+=13)
        circle(x,400,7);

    //body red lines
    if(isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.6f, 0.0f, 0.0f);

    glLineWidth(4);
    glBegin(GL_LINES);

    glVertex2f(550, 290);
    glVertex2f(640, 290);

    glVertex2f(550, 350);
    glVertex2f(640, 350);

    glVertex2f(550, 230);
    glVertex2f(640, 230);
    glEnd();

    // Window white color
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glBegin(GL_QUADS);
    for(int x = 561; x<640; x+=40 )
    {
        for(int y = 395; y>200; y-=60)
        {

            glVertex2f(x,  y);
            glVertex2f(x+25, y);
            glVertex2f(x+25, y-30);
            glVertex2f(x,  y-30);
        }
    }
    // window blue glass
    if(isDay)
        glColor3f(0.44f, 0.63f, 0.78f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    for(int x = 561; x<640; x+=40 )
    {
        for(int y = 395; y>200; y-=60)
        {
            glVertex2f(x+3,  y-3);
            glVertex2f(x+22, y-3);
            glVertex2f(x+22, y-27);
            glVertex2f(x+3,  y-27);
        }
    }
    glEnd();

    /// Window white line
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 561; x<640; x+=40)
    {
        for(int y = 385; y>200; y-=60)
        {
            glVertex2f(x,  y);
            glVertex2f(x+22, y);

            glVertex2f(x+12, y);
            glVertex2f(x+12, y-20);
        }
    }
    glEnd();

    /// 5th Building
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

    //Upper box
    glVertex2f(440, 440);
    glVertex2f(530, 440);
    glVertex2f(530, 480);
    glVertex2f(440, 480);

    glVertex2f(450, 495);
    glVertex2f(520, 495);
    glVertex2f(520, 505);
    glVertex2f(450, 505);

    glVertex2f(460, 505);
    glVertex2f(510, 505);
    glVertex2f(510, 515);
    glVertex2f(460, 515);

    //Top Bar
    glVertex2f(470, 515);
    glVertex2f(500, 515);
    glVertex2f(500, 525);
    glVertex2f(470, 525);

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

    // border shadow
    if (isDay)
        glColor3f(0.90f, 0.90f, 0.90f);
    else
        glColor3f(0.60f, 0.60f, 0.60f);

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(417, 420);
    glVertex2f(553, 420);
    glEnd();

    //top white
    if (isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glBegin(GL_QUADS);
    glVertex2f(435, 495);
    glVertex2f(535, 495);
    glVertex2f(535, 480);
    glVertex2f(435, 480);
    glEnd();

    // border shadow
    if (isDay)
        glColor3f(0.90f, 0.90f, 0.90f);
    else
        glColor3f(0.60f, 0.60f, 0.60f);

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(437, 479);
    glVertex2f(533, 479);
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

    //top
    for(int x = 450; x<520; x+=20)
    {
        glVertex2f(x,    470);
        glVertex2f(x+11, 470);
        glVertex2f(x+11, 440);
        glVertex2f(x,    440);
    }
    glEnd();

    glColor3f(0.38f, 0.54f, 0.66f);
    glLineWidth(3);
    glBegin(GL_LINES);

    glVertex2f(455, 499);
    glVertex2f(515, 499);

    glVertex2f(465, 509);
    glVertex2f(505, 509);

    glVertex2f(475, 519);
    glVertex2f(495, 519);

    glEnd();

    //Flag
    if(isDay)
        glColor3f(0.00f, 0.42f, 0.31f);
    else
        glColor3f(0.00f, 0.25f, 0.18f);

    glBegin(GL_QUADS);
    glVertex2f(485, 555);
    glVertex2f(510, 555);
    glVertex2f(510, 540);
    glVertex2f(485, 540);
    glEnd();

    if(isDay)
        glColor3f(0.96f, 0.16f, 0.25f);
    else
        glColor3f(0.6f, 0.1f, 0.15f);

    circle(497.5, 547.5, 4);

    // Bamboo
    if(isDay)
        glColor3f(0.83f, 0.65f, 0.42f);
    else
        glColor3f(0.55f, 0.45f, 0.30f);

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(485, 525);
    glVertex2f(485, 555);
    glEnd();



    /// 7th Building
    if (isDay)
        glColor3f(0.84f, 0.74f, 0.62f);
    else
        glColor3f(0.50f, 0.40f, 0.30f);

    //body
    glBegin(GL_QUADS);
    glVertex2f(640, 200);
    glVertex2f(720, 200);
    glVertex2f(720, 380);
    glVertex2f(640, 380);

    //window
    if(isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    for(int y = 373; y>200; y-=30)
    {
        glVertex2f(647, y);
        glVertex2f(713, y);
        glVertex2f(713, y-21);
        glVertex2f(647, y-21);
    }

    if (isDay)
        glColor3f(0.52f, 0.78f, 0.96f);
    else
        glColor3f(0.94f, 0.69f, 0.35f);

    for(int y = 370; y>200; y-=30)
    {
        glVertex2f(650, y);
        glVertex2f(710, y);
        glVertex2f(710, y-15);
        glVertex2f(650, y-15);
    }
    glEnd();

    if(isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    // window lines
    glLineWidth(1);
    glBegin(GL_LINES);
    for(int x = 670; x<710; x+=20)
        for(int y = 370; y>200; y-=30)
        {
            glVertex2f(x, y);
            glVertex2f(x, y-15);
        }
    glEnd();

    /// 8th Building
    if (isDay)
        glColor3f(0.39f, 0.30f, 0.32f);
    else
        glColor3f(0.19f, 0.15f, 0.16f);

    glBegin(GL_QUADS);
    glVertex2f(730, 200);
    glVertex2f(970, 200);
    glVertex2f(970, 430);
    glVertex2f(730, 430);
    glEnd();

    // top bar
    glColor3f(0.28f, 0.13f, 0.06f);
    glBegin(GL_QUADS);
    glVertex2f(725, 440);
    glVertex2f(975, 440);
    glVertex2f(975, 430);
    glVertex2f(725, 430);
    glEnd();

    //Window
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    //4 corner window
    glBegin(GL_QUADS);
    for(int x=759; x<950; x+=150)
        for(int y = 400; y>250; y-=120)
        {
            glVertex2f(x, y);
            glVertex2f(x+32, y);
            glVertex2f(x+32, y-40);
            glVertex2f(x, y-40);
        }
    // middle 2 window
    for(int x=743; x<950; x+=182)
    {
        glVertex2f(x,    340);
        glVertex2f(x+32, 340);
        glVertex2f(x+32, 300);
        glVertex2f(x,    300);
    }
    glEnd();

    //Window
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    //window white circle
    //4 corner
    for(int x = 759; x<940; x+=150)
        for(int y = 360; y>200; y-=120)
            for(int xx = x; xx<x+34; xx+=8)
                circle(xx,y,4);
    for(int x = 743; x<950; x+=182)
        for(int xx = x; xx<x+34; xx+=8)
            circle(xx,300,4);

    if(isDay)
        glColor3f(0.44f, 0.65f, 0.80f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    // blue glass
    for(int x=763; x<950; x+=150)
        for(int y = 397; y>250; y-=120)
        {
            glVertex2f(x,    y);
            glVertex2f(x+24, y);
            glVertex2f(x+24, y-34);
            glVertex2f(x,    y-34);
        }

    for(int x=747; x<950; x+=182)
    {
        glVertex2f(x,    337);
        glVertex2f(x+24, 337);
        glVertex2f(x+24, 303);
        glVertex2f(x,    303);
    }

    glEnd();

    // Lines of windows
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    glLineWidth(3);
    glBegin(GL_LINES);
    for(int x = 775; x<940; x+=150)
        for(int y = 400; y>200; y-=120)
        {
            glVertex2f(x, y);
            glVertex2f(x, y-40);
        }

    // Middle window lines
    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    glLineWidth(3);
    glBegin(GL_LINES);
    for(int x = 759; x<950; x+=182)
    {
        glVertex2f(x, 340);
        glVertex2f(x, 300);
    }

    glEnd();

    /// ***> 9th Building <***
    if (isDay)
        glColor3f(0.51f, 0.73f, 0.75f);
    else
        glColor3f(0.29f, 0.42f, 0.43f);

    glBegin(GL_QUADS);
    glVertex2f(800, 200);
    glVertex2f(850, 200);
    glVertex2f(850, 480);
    glVertex2f(800, 480);

    if (isDay)
        glColor3f(0.47f, 0.67f, 0.69f);
    else
        glColor3f(0.23f, 0.34f, 0.35f);

    glVertex2f(850, 200);
    glVertex2f(900, 200);
    glVertex2f(900, 480);
    glVertex2f(850, 480);

    // Top bar
    if (isDay)
        glColor3f(0.29f, 0.42f, 0.43f);
    else
        glColor3f(0.14f, 0.21f, 0.22f);

    glVertex2f(795, 490);
    glVertex2f(905, 490);
    glVertex2f(905, 475);
    glVertex2f(795, 475);

    if (isDay)
        glColor3f(0.29f, 0.42f, 0.43f);
    else
        glColor3f(0.14f, 0.21f, 0.22f);

    for (int y = 410; y > 200; y -= 70)
    {
        glVertex2f(800, y);
        glVertex2f(900, y);
        glVertex2f(900, y - 10);
        glVertex2f(800, y - 10);
    }

    glEnd();

// Window
    glBegin(GL_QUADS);
    if(isDay)
        glColor3f(1, 1, 1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    for (int x = 810; x < 900; x += 54)
    {
        for (int y = 450; y > 220; y -= 70)
        {
            glVertex2f(x, y);
            glVertex2f(x + 26, y);
            glVertex2f(x + 26, y - 30);
            glVertex2f(x, y - 30);
        }
    }
    glEnd();

    halfCircle(823, 450, 13);
    halfCircle(877, 450, 13);
    halfCircle(823, 380, 13);
    halfCircle(877, 380, 13);
    halfCircle(823, 310, 13);
    halfCircle(877, 310, 13);
    halfCircle(823, 240, 13);
    halfCircle(877, 240, 13);

// Red
    glColor3f(1, 0, 0);
    for (int x = 814; x < 900; x += 54)
    {
        for (int y = 450; y > 220; y -= 70)
        {
            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + 18, y);
            glVertex2f(x + 18, y - 27);
            glVertex2f(x, y - 27);
            glEnd();
        }
    }

    halfCircle(823, 450, 9);
    halfCircle(877, 450, 9);
    halfCircle(823, 380, 9);
    halfCircle(877, 380, 9);
    halfCircle(823, 310, 9);
    halfCircle(877, 310, 9);
    halfCircle(823, 240, 9);
    halfCircle(877, 240, 9);

    if(isDay)
        glColor3f(1,1,1);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glLineWidth(2);
    glBegin(GL_LINES);
    for(int x = 823; x<900; x+=54)
        for(int y = 460; y>200; y-=70)
        {
            glVertex2f(x, y);
            glVertex2f(x, y-40);

            glVertex2f(x-13, y-12);
            glVertex2f(x+13, y-12);

            glVertex2f(x-13, y-25);
            glVertex2f(x+13, y-25);

        }
    glEnd();
}

void specialKeys(int key, int x, int y)
{
    if(isDay)
    {
        switch (key)
        {
        case GLUT_KEY_UP:
            trainSpeed += 0.2f;
            break;
        case GLUT_KEY_DOWN:
            trainSpeed -= 0.2f;
            if (trainSpeed < 0) trainSpeed = 0;
            break;
        }
    }

    if(!isDay)
    {
        switch (key)
        {
        case GLUT_KEY_LEFT:
            moonSpeed += 0.2f;
            break;
        case GLUT_KEY_RIGHT:
            moonSpeed -= 0.2f;
            if (moonSpeed < 0) moonSpeed = 0;
            break;
        }
    }
}

void keyboard(unsigned char key, int x, int y)
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
        trainPaused = !trainPaused;

        if (trainPaused)
        {
            savedTrainSpeed = trainSpeed;
            trainSpeed = 0;
        }
        else
        {
            trainSpeed = savedTrainSpeed;
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
        sunPaused = !sunPaused;

        if (sunPaused)
        {
            savedSunSpeed = sunSpeed;
            sunSpeed = 0;
        }
        else
        {
            sunSpeed = savedSunSpeed;
        }

        /// Moon Stop and Start
        moonPaused = !moonPaused;

        if (moonPaused)
        {
            savedMoonSpeed = moonSpeed;
            moonSpeed = 0;
        }
        else
        {
            moonSpeed = savedMoonSpeed;
        }
    }

    if(key == 'm' || key == 'M')
    {
        scenarioTaki = false;
        scenarioMahir = true;
        scenarioTTM = false;
        scenarioTajuar = false;
    }
    if(key == 'a' || key == 'A')
    {
        scenarioTaki = false;
        scenarioMahir = false;
        scenarioTTM = true;
        scenarioTajuar = false;
    }

    if(key == 's' || key == 'S')
    {
        scenarioTajuar = true;
        scenarioTaki = false;
        scenarioMahir = false;
        scenarioTTM = false;
    }

    if(key == 'v' || key == 'V')
    {
        scenarioTaki = true;
        scenarioMahir = false;
        scenarioTTM = false;
        scenarioTajuar = false;
    }



    if(key == 27)
        exit(0);
}

void mouse(int button, int state, int x, int y)
{
    if(isDay)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)   // Pause/resume
        {
            trainPaused = !trainPaused;
            if (trainPaused)
            {
                savedTrainSpeed = trainSpeed;
                trainSpeed = 0;
            }
            else
            {
                trainSpeed = savedTrainSpeed;
            }
        }
    }
    if(isDay)
    {
        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        {
            sunPaused = !sunPaused;
            if (sunPaused)
            {
                savedSunSpeed = sunSpeed;
                sunSpeed = 0;
            }
            else
            {
                sunSpeed = savedSunSpeed;
            }
        }
    }
    if(!isDay)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)   // Pause/resume
        {
            moonPaused = !moonPaused;
            if (moonPaused)
            {
                savedMoonSpeed = moonSpeed;
                moonSpeed = 0;
            }
            else
            {
                moonSpeed = savedMoonSpeed;
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

void Taki()
{
    sky();
    moon();
    sun();
    V_cloud1();
    V_cloud2();
    V_cloud3();
    V_cloud4();
    building();
    train();
    flyOver();
    garden();
    road();
    roadSideWall();
    bus();
    cargoTruck();
}

/// =======================================================$$$$$$$$$$$$$$$$$$$$$$$$===================================================================


/// **************************************************************************************************************************************************
/// ******************************************************** >>> Mahir <<< ****************************************************************************
/// **************************************************************************************************************************************************

bool isDayM=true;

void circleM(int centerX, int centerY, int radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++)
    {
        float pi = 3.1416;
        float A  = (i*2*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY );
    }
    glEnd();
}

//half circle

void halfCircleM(int centerX, int centerY, int radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 180; i++)
    {
        float pi = 3.1416;
        float A  = (i*pi)/180 ;
        float r  = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + centerX, y + centerY );
    }
    glEnd();
}

///cloud

int moveCloud1M = 0;
void cloud1M()
{
    glPushMatrix();
    glTranslatef(moveCloud1M, 0, 0);

    glColor3f(1.0f, 1.0f, 1.0f);

//cloud-1
    circleM(50,650,15);
    circleM(70,660,15);
    circleM(90,650,15);
    circleM(110,645,15);
    circleM(70,640,15);
    circleM(90,640,15);

    glPopMatrix();

}

void updateCloud1M(int value)
{
    moveCloud1M += 1;
    if (moveCloud1M > 1000)
    {
        moveCloud1M = -300;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateCloud1M, 0);
}


//cloud-2

int moveCloud2M = 0;
void cloud2M()
{
    glPushMatrix();
    glTranslatef(moveCloud2M, 0, 0);

    glColor3f(1.0f, 1.0f, 1.0f);
    circleM(500,650,20);
    circleM(510,670,20);
    circleM(530,640,20);
    circleM(560,645,20);
    circleM(545,670,20);

    glPopMatrix();
}

void updateCloud2M(int value)
{
    moveCloud2M -= 1;
    if (moveCloud2M < -1000)
    {
        moveCloud2M = 500;
    }

    glutPostRedisplay();
    glutTimerFunc(18, updateCloud2M, 0);
}
//cloud-3

int moveCloud3M = 0;
void cloud3M()
{
    glPushMatrix();
    glTranslatef(moveCloud3M, 0, 0);

    glColor3f(1.0f, 1.0f, 1.0f);
    circleM(700,650,20);
    circleM(710,670,20);
    circleM(730,650,15);
    circleM(755,645,15);
    circleM(745,670,20);
    circleM(770,670,15);

    glPopMatrix();

}

void updateCloud3M(int value)
{
    moveCloud3M += 1;
    if (moveCloud3M > 1000)
    {
        moveCloud3M = -700;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateCloud3M, 0);
}


///car1

float moveCar1M = 0;
float car1MSpeed = 1.0f;
float savedcar1MSpeed = 0.0f;
float car1MTireAngle = 0.0f;
bool car1MPaused = false;

void car1M()
{
    glPushMatrix();
    glTranslatef(moveCar1M, 0, 0);


// Square-shaped light
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow light
    glVertex2f(225, 442); // Top-left
    glVertex2f(225.5, 442); // Top-right
    glVertex2f(212, 447); // Bottom-right
    glVertex2f(225.5, 447); // Bottom-left
    glEnd();

    // car body
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.1f, 0.1f); // Red
    glVertex2f(150, 440);
    glVertex2f(225, 440);
    glVertex2f(215, 450);
    glVertex2f(160, 450);
    glEnd();


    // Draw the  roof
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.0f); // Darker red
    glVertex2f(165, 450);
    glVertex2f(210, 450);
    glVertex2f(205, 460);
    glVertex2f(170, 460);
    glEnd();

    // Draw the window
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.8f, 1.0f);
    glVertex2f(170, 450);
    glVertex2f(205, 450);
    glVertex2f(200, 457);
    glVertex2f(175, 457);
    glEnd();

    // front wheel
    glPushMatrix();
    glTranslatef(165, 440, 0);
    glRotatef(car1MTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-165, -440, 0);


    glColor3f(0.0f, 0.0f, 0.0f); //black
    circleM(165, 440, 6);

    glColor3f(0.3f, 0.3f, 0.3f); // Gray
    circleM(165, 440, 4);


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0,0,0); // black line
    glVertex2f(160, 440);
    glVertex2f(170, 440);
    glEnd();

    glPopMatrix();

    //  rear wheel

    glPushMatrix();
    glTranslatef(210, 440, 0);
    glRotatef(car1MTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-210, -440, 0);

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(210, 440, 6);


    glColor3f(0.3f, 0.3f, 0.3f);
    circleM(210, 440, 4);

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0,0,0); // black line
    glVertex2f(205, 440);
    glVertex2f(215, 440);
    glEnd();

    glPopMatrix();


    glPopMatrix();
}

void updateCar1M(int value)
{
    moveCar1M += car1MSpeed;
    if (moveCar1M > 1000)
    {
        moveCar1M = -300;

    }

    car1MTireAngle +=1;


    glutPostRedisplay();
    glutTimerFunc(16, updateCar1M, 0);
}


///truck

float moveTruckM = 0.0f;
float truckMSpeed = 1.0f;
float savedTruckMSpeed = 0.0f;
float truckMTireAngle = 0.0f;
bool truckMPaused = false;

void truckM()
{

    glPushMatrix();
    glTranslatef(moveTruckM, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(0.035f, 0.375f, 0.412f);

// Dark red body

    glVertex2f(450,530);
    glVertex2f(360,530);
    glVertex2f(360,500);
    glVertex2f(450,500);
    glEnd();

    //shade
    for(int i= 360; i<=420; i+=20)
    {
        glBegin(GL_QUADS);
        glColor3f(0.373f, 0.620f, 0.627f);

        glVertex2f(i,530);
        glVertex2f(i+10,530);
        glVertex2f(i+20,500);
        glVertex2f(i+10,500);
        glEnd();
    }
    glBegin(GL_QUADS);
    glColor3f(0.373f, 0.620f, 0.627f);
    glVertex2f(440,530);
    glVertex2f(450,530);
    glVertex2f(450,500);
    glVertex2f(450,500);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.25f, 0.25f, 0.25f); // Dark ash color
    glVertex2f(453,500);
    glVertex2f(340,500);
    glVertex2f(340,492);
    glVertex2f(453,492);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.008f, 0.188f, 0.125f);
// front body

    glVertex2f(360,525);
    glVertex2f(335,525);
    glVertex2f(330,515);
    glVertex2f(330,492);
    glVertex2f(360,492);
    glVertex2f(360,530);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.8f, 1.0f); // window
    glVertex2f(356,523);
    glVertex2f(337,523);
    glVertex2f(333,515);
    glVertex2f(356,515);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.00f, 1.00f, 1.00f); //light
    glVertex2f(330,510);
    glVertex2f(334,510);
    glVertex2f(334,505);
    glVertex2f(330,503);
    glEnd();

    // Additional shading for the body to add depth


    // front wheel

    glPushMatrix();
    glTranslatef(353, 493, 0);
    glRotatef(car1MTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-353, -493, 0);

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(353, 493, 8);
    glColor3f(0.3f, 0.3f, 0.3f); // Gray
    circleM(353, 493, 5);

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0,0,0); // black line
    glVertex2f(348, 493);
    glVertex2f(360, 493);
    glEnd();

    glPopMatrix();

    //  rear wheel
    glPushMatrix();
    glTranslatef(433, 493, 0);
    glRotatef(car1MTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-433, -493, 0);

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(433, 493, 8);
    glColor3f(0.3f, 0.3f, 0.3f); // Gray
    circleM(433, 493, 5);

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0,0,0); // black line
    glVertex2f(428, 493);
    glVertex2f(438, 493);
    glEnd();

glPopMatrix();

    glPopMatrix();
}

void updateTruckM(int value)
{
    moveTruckM -= 1;
    if (moveTruckM < -500)
    {
        moveTruckM = 800;
    }

    truckMTireAngle +=1;

    glutPostRedisplay();
    glutTimerFunc(8, updateTruckM, 0);
}

///Ambulance

float moveAmbulanceM = 0.0f;
float ambulanceMSpeed = 1.0f;
float savedAmbulanceMSpeed = 0.0f;
float ambulanceMTireAngle = 0.0f;
bool ambulanceMPaused = false;
void ambulanceM()
{
    glPushMatrix();
    glTranslatef(moveAmbulanceM, 0, 0);

    // Draw the ambulance body
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f); // White body

    glVertex2f(200, 440);
    glVertex2f(280, 440);
    glVertex2f(290, 420);
    glVertex2f(300, 410);
    glVertex2f(300, 390);
    glVertex2f(190, 390);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    circleM(271, 447, 4);

    // Upper light
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(267.5, 448);
    glVertex2f(275, 448);
    glVertex2f(275, 440);
    glVertex2f(267.5, 440);
    glEnd();

    // Black parts (black body)
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(185, 400);
    glVertex2f(200, 400);
    glVertex2f(200, 390);
    glVertex2f(185, 390);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(293, 400);
    glVertex2f(305, 400);
    glVertex2f(305, 390);
    glVertex2f(293, 390);
    glEnd();

    // Red line
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(300, 410);
    glVertex2f(190, 410);
    glEnd();

    // Red light
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(190, 420);
    glVertex2f(195, 420);
    glVertex2f(195, 410);
    glVertex2f(190, 410);
    glEnd();

    // Yellow light
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(285, 408);
    glVertex2f(300, 408);
    glVertex2f(300, 405);
    glVertex2f(285, 405);
    glEnd();

    // Windows
    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.85f, 0.90f);
    glVertex2f(260, 435);
    glVertex2f(275, 435);
    glVertex2f(283, 420);
    glVertex2f(260, 420);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.85f, 0.90f);
    glVertex2f(255, 435);
    glVertex2f(230, 435);
    glVertex2f(230, 420);
    glVertex2f(255, 420);
    glEnd();

    // Red cross
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(205, 425);
    glVertex2f(225, 425);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(215, 435);
    glVertex2f(215, 415);
    glEnd();

    // Wheels

    glPushMatrix();
    glTranslatef(220, 390, 0);
    glRotatef(ambulanceMTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-220, -390, 0);

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(220, 390, 10);
    glColor3f(0.3f, 0.3f, 0.3f);
    circleM(220, 390, 6);

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0,0,0); // black line
    glVertex2f(215, 390);
    glVertex2f(230, 390);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(270, 390, 0);
    glRotatef(ambulanceMTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-270, -390, 0);

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(270, 390, 10);
    glColor3f(0.3f, 0.3f, 0.3f);
    circleM(270, 390, 6);

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0,0,0); // black line
    glVertex2f(265, 390);
    glVertex2f(275, 390);
    glEnd();
    glPopMatrix();


     glPopMatrix();

    glPopMatrix();
}

void updateAmbulanceM(int value)
{
    moveAmbulanceM += ambulanceMSpeed;
    if (moveAmbulanceM > 1000)
    {
        moveAmbulanceM = -350;
    }

      ambulanceMTireAngle -= 2;
    glutPostRedisplay();
    glutTimerFunc(10, updateAmbulanceM, 0);
}

///bus

float moveBusM = 0.0f;
float busMSpeed = 1.0f;
float savedBusMSpeed = 0.0f;
float busMTireAngle = 0.0f;
bool busMPaused = false;



void busM()
{
    glPushMatrix();
    glTranslatef(moveBusM, 0, 0);

    glBegin(GL_POLYGON);
    glColor3f(1.00f, 0.00f, 0.00f);  //bus body
    glVertex2f(785,520);
    glVertex2f(920,520);
    glVertex2f(920,480);
    glVertex2f(780,480);
    glVertex2f(780,500);
    glVertex2f(785,520);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.00f, 1.00f, 0.00f);
    glVertex2f(780,485);
    glVertex2f(787,485);
    glVertex2f(787,480);
    glVertex2f(780,480);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.00f, 1.00f, 1.00f);  //bus light
    glVertex2f(780,497);
    glVertex2f(785,497);
    glVertex2f(785,492);
    glVertex2f(780,489);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1.00f, 1.00f, 0.00f);
    glVertex2f(913,485);
    glVertex2f(920,485);
    glVertex2f(920,480);
    glVertex2f(913,480);
    glEnd();

    glBegin(GL_QUADS);
     glColor3f(0.68f, 0.85f, 0.90f);  //door
    glVertex2f(800,515);
    glVertex2f(815,515);
    glVertex2f(815,490);
    glVertex2f(800,490);
    glEnd();

    glBegin(GL_QUADS);
   glColor3f(0.68f, 0.85f, 0.90f); //front window
    glVertex2f(783,515);
    glVertex2f(795,515);
    glVertex2f(795,500);
    glVertex2f(780,500);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.85f, 0.90f);  //rear window
    glVertex2f(820,515);
    glVertex2f(915,515);
    glVertex2f(915,500);
    glVertex2f(820,500);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(820,515);
    glVertex2f(915,515);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(820,500);
    glVertex2f(915,500);
    glEnd();

    for(int i=820; i<=915; i+=16)
    {
        glLineWidth(0.5);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,515);
        glVertex2f(i,500);
        glEnd();

    }

    //wheels

    glPushMatrix();
    glTranslatef(800,480, 0);
    glRotatef(car1MTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-800, -480, 0);

    glColor3f(0.00f, 0.00f, 0.00f);
    circleM(800,480,7);
    glColor3f(0.30f, 0.30f, 0.30f);
    circleM(800,480,5);
     glPopMatrix();

    glPushMatrix();
    glTranslatef(900,480, 0);
    glRotatef(car1MTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-900, -480, 0);

     glColor3f(0.00f, 0.00f, 0.00f);
     circleM(900,480,7);
      glColor3f(0.30f, 0.30f, 0.30f);
    circleM(900,480,5);
     glPopMatrix();

    glPopMatrix();


}

void updateBusM(int value) {
    moveBusM -= 1;
    if (moveBusM <-1000) {
        moveBusM= 350;
    }

    busMTireAngle +=1;
    glutPostRedisplay();
    glutTimerFunc(10, updateBusM, 0);
}



///boats

//boat 1
int moveBoat1M = 0;
void boat1M()
{
    glPushMatrix();
    glTranslatef(moveBoat1M, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(0.00f, 0.00f, 0.00f); // hash
    glVertex2f(900,50);
    glVertex2f(970,50);
    glVertex2f(960,40);
    glVertex2f(910,40);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.00f, 0.10f, 0.60f); // hash
    glVertex2f(910,50);
    glVertex2f(920,60);
    glVertex2f(930,50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.90f, 0.10f, 0.60f); // hash
    glVertex2f(918,60);
    glVertex2f(950,60);
    glVertex2f(958,50);
    glVertex2f(930,50);
    glEnd();

    glPopMatrix();

}

void updateBoat1M(int value)
{
    moveBoat1M -= 1;
    if (moveBoat1M < -1000)
    {
        moveBoat1M = 100;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateBoat1M, 0);
}

//boat 2

int moveBoat2M = 0;
void boat2M()
{
    glPushMatrix();
    glTranslatef(moveBoat2M, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.235f, 0.235f); // lower body
    glVertex2f(200,90);
    glVertex2f(320,90);
    glVertex2f(310,70);
    glVertex2f(210,70);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.235f, 0.235f); // lower body
    glVertex2f(270,90);
    glVertex2f(280,105);
    glVertex2f(328,105);
    glVertex2f(320,90);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.95f, 0.82f, 0.74f); // upper body
    glVertex2f(280,105);
    glVertex2f(270,90);
    glVertex2f(210,90);
    glVertex2f(220,120);
    glVertex2f(300,120);
    glVertex2f(310,105);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.85f, 0.90f); // window
    glVertex2f(230,100);
    glVertex2f(230,110);
    glVertex2f(240,110);
    glVertex2f(240,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.85f, 0.90f); // window
    glVertex2f(240,110);
    glVertex2f(240,100);
    glVertex2f(250,100);
    glVertex2f(250,110);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.85f, 0.90f); // window
    glVertex2f(250,100);
    glVertex2f(250,110);
    glVertex2f(260,110);
    glVertex2f(260,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.85f, 0.90f); // window
    glVertex2f(260,110);
    glVertex2f(260,100);
    glVertex2f(270,100);
    glVertex2f(270,110);
    glEnd();


    glLineWidth(0.5);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(230,110);
    glVertex2f(270,110);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(230,100);
    glVertex2f(270,100);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(230,100);
    glVertex2f(230,110);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(270,100);
    glVertex2f(270,110);
    glEnd();
    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(240,100);
    glVertex2f(240,110);
    glEnd();
    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(250,100);
    glVertex2f(250,110);
    glEnd();
    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(260,100);
    glVertex2f(260,110);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.79f, 0.66f, 0.65f);
    glVertex2f(225,120);
    glVertex2f(230,140);
    glVertex2f(290,140);
    glVertex2f(295,120);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.85f, 0.90f);
    glVertex2f(235,140);
    glVertex2f(235,160);
    glVertex2f(250,160);
    glVertex2f(260,140);

    glEnd();

    glPopMatrix();
}

void updateBoat2M(int value)
{
    moveBoat2M += 1;
    if (moveBoat2M > 1000)
    {
        moveBoat2M = -450;
    }

    glutPostRedisplay();
    glutTimerFunc(10, updateBoat2M, 0);
}
///boat3
int moveBoat3M = 0;
void boat3M()
{
    glPushMatrix();
    glTranslatef(moveBoat3M, 0, 0);
    // Boat Body (Brown)
    glColor3f(0.4f, 0.2f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(450, 300);
    glVertex2f(550, 300);
    glVertex2f(540, 290);
    glVertex2f(460, 290);
    glEnd();

    // Mast (Gray)
    glColor3f(0.3f, 0.3f, 0.3f);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(500, 300);
    glVertex2f(500, 350);
    glEnd();

    // Sail (White)
    glColor3f(0.03f, 0.89f, 0.69f);
    glBegin(GL_TRIANGLES);
    glVertex2f(500, 350);
    glVertex2f(520, 300);
    glVertex2f(500, 300);
    glEnd();

    glPopMatrix();
}
void updateBoat3M(int value)
{
    moveBoat3M += 1;
    if (moveBoat3M > 1000)
    {
        moveBoat3M = -550;
    }

    glutPostRedisplay();
    glutTimerFunc(19, updateBoat3M, 0);

}


///Train///
int moveTrainM = 0;
void trainM()
{

    glPushMatrix();
    glTranslatef(moveTrainM, 0, 0);

    glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(100,239);
    glVertex2f(620,239);

    glEnd();

    for(int i=130; i<=550; i+=94)
    {
        //  rear wheel
        glColor3f(0.0f, 0.0f, 0.0f);
        circleM(i, 232, 8);
        circleM(i+30, 232, 8);

        glColor3f(0.3f, 0.3f, 0.3f);
        circleM(i, 232, 6);
        circleM(i+30, 232, 6);

    }

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(585, 232, 8);
    circleM(610, 232, 8);

    glColor3f(0.3f, 0.3f, 0.3f);
    circleM(585, 232, 6);
    circleM(610, 232, 6);



    for (int i = 100; i <= 500; i += 94)
    {

        // Train body
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.4f, 0.0f);
        glVertex2f(i, 270);
        glVertex2f(i + 90, 270);
        glVertex2f(i + 90, 231);
        glVertex2f(i, 231);
        glEnd();

        glLineWidth(5.0f); // Set line width
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f); // White line
        glVertex2f(i, 247);
        glVertex2f(i+90, 247);
        glEnd();

        glLineWidth(2.0f); // Set line width
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.0f); // White line
        glVertex2f(i, 270);
        glVertex2f(i+90, 270);
        glEnd();

        // Door 1 (left door)
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i + 5, 265);
        glVertex2f(i + 15, 265);
        glVertex2f(i + 15, 235);
        glVertex2f(i + 5, 235);
        glEnd();

        // Door 2 (right door)
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i + 75, 265);
        glVertex2f(i + 85, 265);
        glVertex2f(i + 85, 235);
        glVertex2f(i + 75, 235);
        glEnd();

        // Windows
        for (int j = 23; j <= 59; j += 12)
        {
            glBegin(GL_QUADS);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(i + j, 260);
            glVertex2f(i + j + 8, 260);   //(8 units wide)
            glVertex2f(i + j + 8, 252);
            glVertex2f(i + j, 252);
            glEnd();
        }
    }

//front
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.4f, 0.0f);
    glVertex2f(570,270);
    glVertex2f(620,270);
    glVertex2f(630,265);
    glVertex2f(630,231);
    glVertex2f(570,231);

    glEnd();
//red line
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.00f, 0.0f);
    glVertex2f(570,270);
    glVertex2f(620,270);
    glVertex2f(630,265);
    glVertex2f(570,265);

    glEnd();
//front window
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(630,265);
    glVertex2f(595,265);
    glVertex2f(610,250);
    glVertex2f(630,250);
    glEnd();

//front door
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(585,265);
    glVertex2f(585,238);
    glVertex2f(600,238);
    glVertex2f(600,250);
    glEnd();

    glPopMatrix();

}

void updateTrainM(int value)
{
    moveTrainM += 1;
    if (moveTrainM > 1000)
    {
        moveTrainM = -700;
    }

    glutPostRedisplay();
    glutTimerFunc(5, updateTrainM, 0);
}


//sun
int moveSunM = 0;

void sunM()
{
    glPushMatrix();
    glTranslatef(moveSunM, 0, 0);

    glColor3f(0.97,0.49,0.00);
    circleM(200,650,30);
    glPopMatrix();
}

void updateSunM(int value)
{
    moveSunM += 1;
    if (moveSunM > 1000)
    {
        moveSunM = -300;
    }

    glutPostRedisplay();
    glutTimerFunc(80, updateSunM, 0);
}

///road light

void roadLightM()
{

    glColor3f(1.0f, 1.0f, 1.0f);

    for (int i = 0; i < 1000; i += 200)
    {
        // First vertical line
        glLineWidth(6);
        glBegin(GL_LINES);

        glVertex2f(150 + i, 445);
        glVertex2f(150 + i, 620);
        glEnd();

        // Left diagonal line
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2f(90 + i, 600);
        glVertex2f(150 + i, 610);
        glEnd();

        // Right diagonal line
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2f(210 + i, 620);
        glVertex2f(150 + i, 608);
        glEnd();
    }
//light

    glColor3f(1.0f,1.0f,1.0f);
    circleM(95,598,5);
    glEnd();

   glColor3f(1.0f,1.0f,1.0f);
    circleM(208,615,5);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    circleM(295,598,5);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    circleM(408,615,5);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    circleM(495,598,5);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    circleM(608,615,5);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    circleM(695,598,5);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    circleM(808,615,5);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    circleM(895,598,5);
    glEnd();

    glColor3f(1.0f,1.0f,1.0f);
    circleM(1008,615,5);
    glEnd();


}

void lineM()
{
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(0,350);
    glVertex2f(1000,350);
    glEnd();


}

void riverM()
{
    glBegin(GL_QUADS);
    glColor3f(0.27f, 0.51f, 0.71f);
    glVertex2f(0,349);
    glVertex2f(1000,349);
    glVertex2f(1000,0);
    glVertex2f(0,0);

    glEnd();

}

void line2M()
{
    glLineWidth(10);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,200);
    glVertex2f(1000,200);
    glEnd();
}

void bridgeM()
{

    glBegin(GL_QUADS);
    glColor3f(0.50f, 0.50f, 0.50f); // hash
    glVertex2f(0,280);
    glVertex2f(0,200);             //under
    glVertex2f(1000,200);
    glVertex2f(1000,280);

    glEnd();

///railline path

    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,260);
    glVertex2f(1000,260);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,255);
    glVertex2f(1000,255);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,230);
    glVertex2f(1000,230);

    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,225);
    glVertex2f(1000,225);

    glEnd();

//upper road

    glBegin(GL_QUADS);
    glColor3f(0.50f, 0.50f, 0.50f); // hash
    glVertex2f(0,350);
    glVertex2f(1000,350);
    glVertex2f(1000,500);
    glVertex2f(0,500);

    glEnd();


//lines of road

    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,497);
    glVertex2f(1000,497);
    glEnd();

//upper road middle lines

    glLineWidth(2);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < 1000; i += 120)
    {
        glBegin(GL_LINES);
        glVertex2f(i,473);
        glVertex2f(i + 90,473);
        glEnd();
    }

    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < 1000; i += 160)
    {
        glBegin(GL_QUADS);
        glVertex2f(5 + i, 405);
        glVertex2f(150 + i, 405);
        glVertex2f(145 + i, 400);
        glVertex2f(0 + i, 400);
        glEnd();
    }

    glLineWidth(3);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,450);
    glVertex2f(1000,450);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,445);
    glVertex2f(1000,445);
    glEnd();


    for (int i = 50; i <= 850; i += 400)
    {
        glBegin(GL_QUADS);
        glColor3f(0.00f, 0.50f, 0.50f); // Teal
        glVertex2f(i,195);
        glVertex2f(i + 150,195);
        glVertex2f(i + 105,170);
        glVertex2f(i + 45,170);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.75f, 0.75f, 0.75f); // Black
        glVertex2f(i + 45,170);
        glVertex2f(i + 105,170);
        glVertex2f(i + 95,100);
        glVertex2f(i + 55,100);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.36f, 0.40f, 0.39f); // White
        glVertex2f(i + 30,100);
        glVertex2f(i + 120,100);
        glVertex2f(i + 110,90);
        glVertex2f(i + 40,90);
        glEnd();
    }


}

///raillng

void raillingM()
{
    glLineWidth(4);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,390);
    glVertex2f(1000,390);
    glEnd();

    for(int i= 20; i<=1000; i+=50)
    {
        glLineWidth(4);
        glBegin(GL_LINES);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(i,390);
        glVertex2f(i,350);
        glEnd();

        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(i,390);
        glVertex2f(i+20,350);
        glEnd();
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(i+20,350);
        glVertex2f(i+40,390);
        glEnd();

        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(i+10,390);
        glVertex2f(i+20,370);
        glEnd();

        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(i+20,370);
        glVertex2f(i+30,390);
        glEnd();

        glLineWidth(4);
        glBegin(GL_LINES);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(i+40,390);
        glVertex2f(i+40,350);
        glEnd();

    }
}
//crosses

//big crosses
void bigCrossM()
{

    glLineWidth(20);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0,340);
    glVertex2f(220,205);
    glEnd();

    glLineWidth(20);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(220,205);
    glVertex2f(440,340);
    glEnd();

    glLineWidth(20);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(440,340);
    glVertex2f(660,205);
    glEnd();

    glLineWidth(20);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(660,205);
    glVertex2f(880,340);
    glEnd();

    glLineWidth(20);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(880,340);
    glVertex2f(1050,205);
    glEnd();

}
//small crosses

void smallCrossM()
{
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < 1000; i += 430)
    {
        glBegin(GL_QUADS);

        // First quad
        glVertex2f(100 + i, 350);
        glVertex2f(130 + i, 350);
        glVertex2f(230 + i, 280);
        glVertex2f(210 + i, 280);

        glEnd();

        glBegin(GL_QUADS);

        // Second quad
        glVertex2f(228 + i, 280);
        glVertex2f(250 + i, 280);
        glVertex2f(370 + i, 350);
        glVertex2f(340 + i, 350);

        glEnd();
    }
}



void skyM()
{

    glBegin(GL_QUADS);
    glColor3f(0.529f, 0.81f, 0.98f); // sky
    glVertex2f(0,500);
    glVertex2f(1000,500);
    glVertex2f(1000,700);
    glVertex2f(0,700);

    glEnd();

}





//////////////////////////////////////////////////////////////////////////night//////////////////////////////////////////


int moveCloud1M_night = 0;
void cloud1M_night()
{
    glPushMatrix();
    glTranslatef(moveCloud1M_night, 0, 0);

    glColor3f(0.80f, 0.80f, 0.80f);

//cloud-1
    circleM(50,650,15);
    circleM(70,660,15);
    circleM(90,650,15);
    circleM(110,645,15);
    circleM(70,640,15);
    circleM(90,640,15);

    glPopMatrix();

}

void updateCloud1M_night(int value)
{
    moveCloud1M_night -= 1;
    if (moveCloud1M_night <- 1000)
    {
        moveCloud1M_night = 900;
    }

    glutPostRedisplay();
    glutTimerFunc(25, updateCloud1M_night, 0);
}


//cloud-2

int moveCloud2M_night = 0;
void cloud2M_night()
{
    glPushMatrix();
    glTranslatef(moveCloud2M_night, 0, 0);

    glColor3f(0.80f, 0.80f, 0.80f);
    circleM(500,650,20);
    circleM(510,670,20);
    circleM(530,640,20);
    circleM(560,645,20);
    circleM(545,670,20);

    glPopMatrix();
}

void updateCloud2M_night(int value)
{
    moveCloud2M_night += 1;
    if (moveCloud2M_night >1000)
    {
        moveCloud2M_night = -600;
    }

    glutPostRedisplay();
    glutTimerFunc(20, updateCloud2M_night, 0);
}



///plane

float movePlaneM = 0;
float planeMSpeed = 1.0f;
float savedPlaneMSpeed = 0.0f;
float planeMTireAngle = 0.0f;
bool planeMPaused = false;

void planeM()
{
    glPushMatrix();
    glTranslatef(movePlaneM, 0, 0);

    glColor3f(0,1,1);;
    circleM(459,635,10);
    glColor3f(0.698f, 0.75f, 0.709f);
    circleM(448,640,10);
    circleM(453,635,10);


    glBegin(GL_POLYGON);
    glColor3f(0.698f, 0.75f, 0.709f); // body
    glVertex2f(300, 650);
    glVertex2f(450, 650);
    glVertex2f(455, 635);
    glVertex2f(450, 625);
    glVertex2f(330, 625);
    glVertex2f(300, 640);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0,1,1);
    glVertex2f(330, 633);
    glVertex2f(462, 633);
    glVertex2f(462, 625);
    glVertex2f(330, 625);
    glEnd();

    //upper tail light
    glColor3f(1,0,0);
    circleM(403,665,4);
    circleM(407,655,4);


    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.75f, 0.709f); // upper tail
    glVertex2f(390, 675);
    glVertex2f(400, 670);
    glVertex2f(410, 650);
    glVertex2f(385, 650);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,1,1); // upper border
    glVertex2f(390, 675);
    glVertex2f(396, 670);
    glVertex2f(395, 650);
    glVertex2f(385, 650);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(396,671);
    glVertex2f(395,650);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.75f, 0.709f); //lower tail
    glVertex2f(415, 628);
    glVertex2f(390, 628);
    glVertex2f(370, 590);
    glVertex2f(390, 595);
    glEnd();


    glColor3f(1,0,0);
    circleM(416,615,5);

    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.75f, 0.709f); //lower tail light
    glVertex2f(410, 620);
    glVertex2f(403, 610);
    glVertex2f(415, 610);
    glVertex2f(415, 620);
    glEnd();


    glColor3f(1,0,0);
    circleM(406,603.5f,4);
    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.75f, 0.709f); //lower tail light
    glVertex2f(397,607);
    glVertex2f(387,600);
    glVertex2f(405,600);
    glVertex2f(405, 607);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0,1,1); //lower border
    glVertex2f(390, 628);
    glVertex2f(403, 628);
    glVertex2f(382, 595);
    glVertex2f(370, 590);
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(403, 628);
    glVertex2f(382, 594);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.75f, 0.709f); // upper back
    glVertex2f(310, 648);
    glVertex2f(325, 648);
    glVertex2f(315, 675);
    glVertex2f(305, 670);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,1,1); // upper back border
    glVertex2f(310, 648);
    glVertex2f(318, 648);
    glVertex2f(310, 672);
    glVertex2f(305, 670);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(318, 648);
    glVertex2f(310, 672);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.75f, 0.709f); // lower back
    glVertex2f(315, 635);
    glVertex2f(330, 630);
    glVertex2f(315, 610);
    glVertex2f(307, 616);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,1,1); // lower back border
    glVertex2f(315, 635);
    glVertex2f(320, 630);
    glVertex2f(312, 613);
    glVertex2f(307, 616);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,1,1);
    glVertex2f(330, 625);
    glVertex2f(330,633);
    glVertex2f(300,645);
    glVertex2f(300,640);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(330,633);
    glVertex2f(300,645);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(320, 630);
    glVertex2f(312, 613);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(330,632);
    glVertex2f(462,632);
    glEnd();

    for(int i=330; i<=380; i+=10)
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.50f); // window
        glVertex2f(i, 643);
        glVertex2f(i+8, 643);
        glVertex2f(i+8, 635);
        glVertex2f(i, 635);
        glEnd();

    }
    for(int i=330; i<=380; i+=10)
    {
        // window border
        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,643);
        glVertex2f(i+8,643);
        glEnd();

        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i+8, 643);
        glVertex2f(i+8, 635);
        glEnd();

        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i+8, 635);
        glVertex2f(i, 635);
        glEnd();

        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,643);
        glVertex2f(i, 635);
        glEnd();

    }

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);  //door
    glVertex2f(390, 645);
    glVertex2f(400, 645);
    glVertex2f(400, 630);
    glVertex2f(390, 630);
    glEnd();

    for(int i=404; i<=430; i+=10)
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.50f); // window
        glVertex2f(i, 643);
        glVertex2f(i+8, 643);
        glVertex2f(i+8, 635);
        glVertex2f(i, 635);
        glEnd();
    }

    for(int i=404; i<=430; i+=10)
    {
        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);  //window border
        glVertex2f(i,643);
        glVertex2f(i+8,643);
        glEnd();

        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);  //window border
        glVertex2f(i+8,643);
        glVertex2f(i+8,635);
        glEnd();


        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);  //window border
        glVertex2f(i+8,635);
        glVertex2f(i,635);
        glEnd();

        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);  //window border
        glVertex2f(i,635);
        glVertex2f(i,643);
        glEnd();
    }


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(456, 643);
    glVertex2f(435, 643);
    glVertex2f(435, 635);
    glVertex2f(461, 635);
    glEnd();

    /*glColor3f(0.0f, 0.0f, 0.0f);
       circleM(457,639,4.5f);*/


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(457, 643);
    glVertex2f(435, 643);
    glVertex2f(435, 635);
    glVertex2f(464, 635);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.50f);
    glVertex2f(456, 642);
    glVertex2f(436, 642);
    glVertex2f(436, 636);
    glVertex2f(463, 636);
    glEnd();


    glPopMatrix();
}

void updatePlaneM(int value)
{
    movePlaneM += planeMSpeed;
    if (movePlaneM > 1000)
    {
        movePlaneM = -500;
    }

    glutPostRedisplay();
    glutTimerFunc(16,updatePlaneM, 0);
}


///car3

float M_moveCar3_night = 0;
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
    glVertex2f(735, 507);
    glVertex2f(750,520);
    glVertex2f(800, 520);
    glVertex2f(805, 500);
    glVertex2f(805, 480);
    glVertex2f(700, 480);
    glVertex2f(710, 505);
    glVertex2f(770, 500);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,0.0f);  //car light
    glVertex2f(710,500);
    glVertex2f(715,500);
    glVertex2f(715,495);
    glVertex2f(705,492);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,0.60f);
    glVertex2f(710,500);
    glVertex2f(650,520);
    glVertex2f(650,480);
    glVertex2f(710,495);
    glEnd();


    glBegin(GL_QUADS);    //window
    glColor3f(1,1,0.6);
    glVertex2f(750,515);
    glVertex2f(765,515);
    glVertex2f(765,503);
    glVertex2f(742,503);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,0.6);
    glVertex2f(770,515);
    glVertex2f(795,515);
    glVertex2f(797,503);
    glVertex2f(770,503);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);

    glVertex2f(805,500);
    glVertex2f(810,500);
    glVertex2f(810,490);
    glVertex2f(805,490);
    glEnd();

    //wheel
    glPushMatrix();
    glTranslatef(720,480, 0);
    glRotatef(car1MTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-720,-480, 0);

    glColor3f(0,0,0);
    circleM(720,480,7);
    glColor3f(0.3,0.3,0.3);
    circleM(720,480,5);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(790,480, 0);
    glRotatef(car1MTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-790,-480, 0);

    glColor3f(0,0,0);
    circleM(790,480,7);
    glColor3f(0.3,0.3,0.3);
    circleM(790,480,5);

     glPopMatrix();

    glPopMatrix();

}

void M_updateCar3_night(int value)
{
    M_moveCar3_night -= 1;
    if (M_moveCar3_night <- 1000)
    {
        M_moveCar3_night = 400;
    }

    M_car3_nightTireAngle +=1;
    glutPostRedisplay();
    glutTimerFunc(20,M_updateCar3_night, 0);
}



///car4_night

float M_moveCar4_night = 0;
float M_car4_nightSpeed = 1.0f;
float M_savedCar4_nightSpeed = 0.0f;
float M_car4_nightTireAngle = 0.0f;
bool  M_car4_nightPaused = false;

void M_car4_night(){

    glPushMatrix();
    glTranslatef(M_moveCar4_night, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(0.431, 0.149, 0.055); // BODY
    glVertex2f(500,440);
    glVertex2f(590,440);
    glVertex2f(590,400);
    glVertex2f(500,400);
    //glVertex2f();
    glEnd();

    glColor3f(1,1,0);   //light
    circleM(667,423,7);

    glBegin(GL_QUADS);
    glColor3f(1,1,0.87); // light
    glVertex2f(672,425);
    glVertex2f(740,440);
    glVertex2f(740,410);
    glVertex2f(672,420);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.584, 0.271, 0.208);
    glVertex2f(590,400); //front body
    glVertex2f(590,470);
    glVertex2f(630,470);
    glVertex2f(630,467);
    glVertex2f(625,467);
    glVertex2f(640,440);
    glVertex2f(670,440);
    glVertex2f(670,400);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex2f(600,460);  //window
    glVertex2f(620,460);
    glVertex2f(630,440);
    glVertex2f(600,440);
    glEnd();

    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); //black
    glVertex2f(493, 405);
    glVertex2f(510, 405);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.10f);
    glVertex2f(500, 425);          //back light
    glVertex2f(505, 425);
    glEnd();

    //wheel
    glPushMatrix();
    glTranslatef(525,400, 0);
    glRotatef(M_car4_nightTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-525,-400, 0);

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(525,400,9);
    glColor3f(0.30f, 0.30f, 0.30f);
    circleM(525,400,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(600,400, 0);
    glRotatef(M_car4_nightTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-600,-400, 0);

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(600,400,9);
    glColor3f(0.30f, 0.30f, 0.30f);
    circleM(600,400,5);
    glPopMatrix();


glPopMatrix();

}

void M_updateCar4_night(int value)
{
    M_moveCar4_night += 1;
    if (M_moveCar4_night > 1000)
    {
        M_moveCar4_night = -750;
    }

    M_car4_nightTireAngle +=1;

    glutPostRedisplay();
    glutTimerFunc(6, M_updateCar4_night, 0);
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
    glVertex2f(150, 435);
    glVertex2f(225, 435);
    glVertex2f(215, 445);
    glVertex2f(160, 445);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.87f); // yellow light
    glVertex2f(220, 443);
    glVertex2f(270, 455);
    glVertex2f(270, 430);
    glVertex2f(220, 440);
    glEnd();

    // Draw the minimized roof
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.0f, 0.0f); // Darker red
    glVertex2f(165, 445);
    glVertex2f(210, 445);
    glVertex2f(205, 455);
    glVertex2f(170, 455);
    glEnd();

    // Draw the window
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.8f, 1.0f);
    glVertex2f(170, 445);
    glVertex2f(205, 445);
    glVertex2f(200, 452);
    glVertex2f(175, 452);
    glEnd();


    // front wheel
    glPushMatrix();
    glTranslatef(165, 435, 0);
    glRotatef(car1MTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-165, -435, 0);


    glColor3f(0.0f, 0.0f, 0.0f); //black
    circleM(165, 435, 6);

    glColor3f(0.3f, 0.3f, 0.3f); // Gray
    circleM(165, 435, 4);


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0,0,0); // black line
    glVertex2f(160, 435);
    glVertex2f(170, 435);
    glEnd();

    glPopMatrix();

    //  rear wheel

    glPushMatrix();
    glTranslatef(210, 435, 0);
    glRotatef(car1MTireAngle, 0.0, 0.0, 1.0);
    glTranslatef(-210, -435, 0);

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(210, 435, 6);


    glColor3f(0.3f, 0.3f, 0.3f);
    circleM(210, 435, 4);

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0,0,0); // black line
    glVertex2f(205, 435);
    glVertex2f(215, 435);
    glEnd();

    glPopMatrix();


    glPopMatrix();
}

void updateCar1_nightM(int value)
{
    moveCar1_nightM += 1;
    if (moveCar1_nightM > 1000)
    {
        moveCar1_nightM = -300;
    }

     car1_nightMTireAngle +=1;

    glutPostRedisplay();
    glutTimerFunc(16, updateCar1_nightM, 0);
}


///raillng night

void raillingM_night()
{
    glLineWidth(4);
    glBegin(GL_LINES);

    glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0,390);
    glVertex2f(1000,390);
    glEnd();

    for(int i= 20; i<=1000; i+=50)
    {
        glLineWidth(4);
        glBegin(GL_LINES);

        glColor3f(0.80f, 0.80f, 0.80f);
        glVertex2f(i,390);
        glVertex2f(i,350);
        glEnd();

        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(0.80f, 0.80f, 0.80f);
        glVertex2f(i,390);
        glVertex2f(i+20,350);
        glEnd();
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(0.80f, 0.80f, 0.80f);
        glVertex2f(i+20,350);
        glVertex2f(i+40,390);
        glEnd();

        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(0.80f, 0.80f, 0.80f);
        glVertex2f(i+10,390);
        glVertex2f(i+20,370);
        glEnd();

        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(0.80f, 0.80f, 0.80f);
        glVertex2f(i+20,370);
        glVertex2f(i+30,390);
        glEnd();

        glLineWidth(4);
        glBegin(GL_LINES);

        glColor3f(0.80f, 0.80f, 0.80f);
        glVertex2f(i+40,390);
        glVertex2f(i+40,350);
        glEnd();

    }
}


///boats

//boat 1
int moveBoat1_nightM = 0;
void boat1_nightM()
{
    glPushMatrix();
    glTranslatef(moveBoat1_nightM, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(0.00f, 0.00f, 0.00f);
    glVertex2f(900,50);
    glVertex2f(970,50);
    glVertex2f(960,40);
    glVertex2f(910,40);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.00f, 1.0f, 0.05f);
    glVertex2f(910,50);
    glVertex2f(920,60);
    glVertex2f(930,50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.20f, 0.60f);
    glVertex2f(918,60);
    glVertex2f(950,60);
    glVertex2f(958,50);
    glVertex2f(930,50);
    glEnd();

    glPopMatrix();

}

void updateBoat1_nightM(int value)
{
    moveBoat1_nightM -= 1;
    if (moveBoat1_nightM < -1000)
    {
        moveBoat1_nightM = 100;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateBoat1_nightM, 0);
}

//boat 2

int moveBoat2_nightM = 0;
void boat2_nightM()
{
    glPushMatrix();
    glTranslatef(moveBoat2_nightM, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.235f, 0.235f); // lower body
    glVertex2f(200,90);
    glVertex2f(320,90);
    glVertex2f(310,70);
    glVertex2f(210,70);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.235f, 0.235f); // lower body
    glVertex2f(270,90);
    glVertex2f(280,105);
    glVertex2f(328,105);
    glVertex2f(320,90);
    glEnd();


    glBegin(GL_POLYGON);
   glColor3f(0.75f, 0.65f, 0.58f);  //upper body
    glVertex2f(280,105);
    glVertex2f(270,90);
    glVertex2f(210,90);
    glVertex2f(220,120);
    glVertex2f(300,120);
    glVertex2f(310,105);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,0.5); // window
    glVertex2f(230,100);
    glVertex2f(230,110);
    glVertex2f(240,110);
    glVertex2f(240,100);
    glEnd();

    glBegin(GL_QUADS);
     glColor3f(1,1,0.5); // window
    glVertex2f(240,110);
    glVertex2f(240,100);
    glVertex2f(250,100);
    glVertex2f(250,110);
    glEnd();

    glBegin(GL_QUADS);
     glColor3f(1,1,0.5); // window
    glVertex2f(250,100);
    glVertex2f(250,110);
    glVertex2f(260,110);
    glVertex2f(260,100);
    glEnd();

    glBegin(GL_QUADS);
     glColor3f(1,1,0.5); // window
    glVertex2f(260,110);
    glVertex2f(260,100);
    glVertex2f(270,100);
    glVertex2f(270,110);
    glEnd();


    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(230,110);
    glVertex2f(270,110);
    glEnd();
    glLineWidth(0.5);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(230,100);
    glVertex2f(270,100);
    glEnd();
    glLineWidth(0.5);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(230,100);
    glVertex2f(230,110);
    glEnd();
    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(270,100);
    glVertex2f(270,110);
    glEnd();
    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(240,100);
    glVertex2f(240,110);
    glEnd();
    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(250,100);
    glVertex2f(250,110);
    glEnd();
    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(260,100);
    glVertex2f(260,110);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.63f, 0.53f, 0.52f);
    glVertex2f(225,120);
    glVertex2f(230,140);
    glVertex2f(290,140);
    glVertex2f(295,120);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.54f, 0.68f, 0.72f);
    glVertex2f(235,140);
    glVertex2f(235,160);
    glVertex2f(250,160);
    glVertex2f(260,140);

    glEnd();

    for(int i=215; i<=310; i+=10)
    {
        glColor3f(1.0f, 1.0f, 0.0f);
        circleM(i,80,3);
    }


    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.4f, 0.4f);
    glVertex2f(323,90);
    glVertex2f(390,100);
    glVertex2f(390,76);
    glVertex2f(323,85);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(325,90);
    glVertex2f(380,100);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(323,85);
    glVertex2f(390,76);
    glEnd();

    glPopMatrix();
}

void updateBoat2_nightM(int value)
{
    moveBoat2_nightM += 1;
    if (moveBoat2_nightM > 1000)
    {
        moveBoat2_nightM = -450;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateBoat2_nightM, 0);
}

//moon
int moveMoonM = 0;

void moonM()
{
    glPushMatrix();
    glTranslatef(moveMoonM, 0, 0);

    glColor3f(1.0f,1.0f,1.0f);
    circleM(800,650,30);
    glColor3f(0.21f, 0.27f, 0.3098f);
    circleM(785,660,30);

    glPopMatrix();
}


void updateMoonM(int value)
{
    moveMoonM -= 1;
    if (moveMoonM <- 1000)
    {
        moveMoonM = 300;
    }

    glutPostRedisplay();
    glutTimerFunc(80, updateMoonM, 0);
}

void M_star(){
 glPointSize(2); // Set point size
    glBegin(GL_POINTS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(100,650);
        glVertex2f(300,650);
        glVertex2f(500,640);
        glVertex2f(700,670);
        glVertex2f(400,600);
        glVertex2f(900,650);
        glVertex2f(200,550);


    glEnd();

}

///road light night

void roadLight_nightM()
{

    glColor3f(0.8f, 0.8f, 0.8f);

    for (int i = 0; i < 1000; i += 200)
    {
        // First vertical line
        glLineWidth(6);
        glBegin(GL_LINES);

        glVertex2f(150 + i, 445);
        glVertex2f(150 + i, 620);
        glEnd();

        // Left diagonal line
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2f(90 + i, 600);
        glVertex2f(150 + i, 610);
        glEnd();

        // Right diagonal line
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2f(210 + i, 620);
        glVertex2f(150 + i, 608);
        glEnd();
    }
}

///light

void light_nightM()
{

    glColor3f(1.0f,1.0f,0.0f);
    circleM(95,598,5);
    glEnd();

    glColor3f(1.0f,1.0f,0.0f);
    circleM(208,615,5);
    glEnd();

    glColor3f(1.0f,1.0f,0.0f);
    circleM(295,598,5);
    glEnd();

    glColor3f(1.0f,1.0f,0.0f);
    circleM(408,615,5);
    glEnd();

    glColor3f(1.0f,1.0f,0.0f);
    circleM(495,598,5);
    glEnd();

    glColor3f(1.0f,1.0f,0.0f);
    circleM(608,615,5);
    glEnd();

    glColor3f(1.0f,1.0f,0.0f);
    circleM(695,598,5);
    glEnd();

    glColor3f(1.0f,1.0f,0.0f);
    circleM(808,615,5);
    glEnd();

    glColor3f(1.0f,1.0f,0.0f);
    circleM(895,598,5);
    glEnd();

    glColor3f(1.0f,1.0f,0.0f);
    circleM(1008,615,5);
    glEnd();


}



void line_nightM()
{
    glLineWidth(3);
    glBegin(GL_LINES);

    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(0,350);
    glVertex2f(1000,350);
    glEnd();


}


///train_night


float moveTrainM_night = 0;
float trainM_nightSpeed = 1.0f;
float savedTrainM_nightSpeed = 0.0f;
float trainM_nightTireAngle = 0.0f;
bool trainM_nightPaused = false;

void trainM_night()
{

    glPushMatrix();
    glTranslatef(moveTrainM_night, 0, 0);

    glLineWidth(5);
    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(90,239);
    glVertex2f(560,239);

    glEnd();

    for(int i=130; i<=550; i+=94)
    {
        //  rear wheel
        glColor3f(0.0f, 0.0f, 0.0f);
        circleM(i, 232, 8);
        circleM(i+30, 232, 8);

        glColor3f(0.3f, 0.3f, 0.3f);
        circleM(i, 232, 6);
        circleM(i+30, 232, 6);

    }

//front wheel

    glColor3f(0.0f, 0.0f, 0.0f);
    circleM(50, 232, 8);
    glColor3f(0.3f, 0.3f, 0.3f);
    circleM(50, 232, 6);

     glColor3f(0.0f, 0.0f, 0.0f);
    circleM(80, 232, 8);
    glColor3f(0.3f, 0.3f, 0.3f);
    circleM(80, 232, 6);




    for (int i = 100; i <= 500; i += 94)
    {

        // Train body
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.2f, 0.0f);
        glVertex2f(i, 270);
        glVertex2f(i + 90, 270);
        glVertex2f(i + 90, 231);
        glVertex2f(i, 231);
        glEnd();

        glLineWidth(5.0f); // Set line width
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f); // White line
        glVertex2f(i, 247);
        glVertex2f(i+90, 247);
        glEnd();

        glLineWidth(2.0f); // Set line width
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.0f); // White line
        glVertex2f(i, 270);
        glVertex2f(i+90, 270);
        glEnd();

        // Door 1 (left door)
        glBegin(GL_QUADS);
       glColor3f(1,1,0.5f);
        glVertex2f(i + 5, 265);
        glVertex2f(i + 15, 265);
        glVertex2f(i + 15, 235);
        glVertex2f(i + 5, 235);
        glEnd();

        // Door 2 (right door)
        glBegin(GL_QUADS);
        glColor3f(1,1,0.5f);
        glVertex2f(i + 75, 265);
        glVertex2f(i + 85, 265);
        glVertex2f(i + 85, 235);
        glVertex2f(i + 75, 235);
        glEnd();

        // Windows
        for (int j = 23; j <= 59; j += 12)
        {
            glBegin(GL_QUADS);
           glColor3f(1,1,0.5f);
            glVertex2f(i + j, 260);
            glVertex2f(i + j + 8, 260);   //(8 units wide)
            glVertex2f(i + j + 8, 252);
            glVertex2f(i + j, 252);
            glEnd();
        }
    }

//front
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(95,270);
    glVertex2f(45,270);
    glVertex2f(35,265);
    glVertex2f(35,231);
    glVertex2f(95,231);

    glEnd();
//red line
    glBegin(GL_QUADS);
    glColor3f(0.80f, 0.00f, 0.0f);
    glVertex2f(95,270);
    glVertex2f(45,270);
    glVertex2f(35,265);
    glVertex2f(95,265);

    glEnd();
//front window
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5f);
    glVertex2f(35,265);
    glVertex2f(70,265);
    glVertex2f(55,250);
    glVertex2f(35,250);
    glEnd();

//front door
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5f);
    glVertex2f(75,265);
    glVertex2f(75,238);
    glVertex2f(60,238);
    glVertex2f(60,250);
    glEnd();

    glPopMatrix();

}

void updateTrainM_night(int value)
{
    moveTrainM_night -= trainM_nightSpeed;
    if (moveTrainM_night <- 1000)
    {
        moveTrainM_night = 950;
    }

    glutPostRedisplay();
    glutTimerFunc(5, updateTrainM_night, 0);
}



void river_nightM()
{
    glBegin(GL_QUADS);
    //glColor3f(0.118f, 0.16f, 0.24f);
    glColor3f(0.039f, 0.059f, 0.137f);
    glVertex2f(0,349);
    glVertex2f(1000,349);
    glVertex2f(1000,0);
    glVertex2f(0,0);

    glEnd();

}

void line2_nightM()
{
    glLineWidth(10);
    glBegin(GL_LINES);

    glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0,200);
    glVertex2f(1000,200);
    glEnd();
}

void bridge_nightM()
{

    glBegin(GL_QUADS);
    glColor3f(0.10f, 0.10f, 0.10f); // hash
    glVertex2f(0,280);
    glVertex2f(0,200);             //under
    glVertex2f(1000,200);
    glVertex2f(1000,280);

    glEnd();

//railline path
    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0,260);
    glVertex2f(1000,260);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0,255);
    glVertex2f(1000,255);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0,230);
    glVertex2f(1000,230);

    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);

     glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0,225);
    glVertex2f(1000,225);

    glEnd();

//upper road

    glBegin(GL_QUADS);
    glColor3f(0.10f, 0.10f, 0.10f); // hash
    glVertex2f(0,350);
    glVertex2f(1000,350);
    glVertex2f(1000,500);
    glVertex2f(0,500);

    glEnd();


//lines of road

    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0,497);
    glVertex2f(1000,497);
    glEnd();

//upper road middle lines

    glLineWidth(2);
    glColor3f(0.8f, 0.8f, 0.8f);
    for (int i = 0; i < 1000; i += 120)
    {
        glBegin(GL_LINES);
        glVertex2f(i,473);
        glVertex2f(i + 90,473);
        glEnd();
    }

    glColor3f(0.8f, 0.8f, 0.8f);
    for (int i = 0; i < 1000; i += 160)
    {
        glBegin(GL_QUADS);
        glVertex2f(5 + i, 405);
        glVertex2f(150 + i, 405);
        glVertex2f(145 + i, 400);
        glVertex2f(0 + i, 400);
        glEnd();
    }

    glLineWidth(3);
    glBegin(GL_LINES);

     glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0,450);
    glVertex2f(1000,450);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);

     glColor3f(0.80f, 0.80f, 0.80f);
    glVertex2f(0,445);
    glVertex2f(1000,445);
    glEnd();


//pillers of bridge

    for (int i = 50; i <= 850; i += 400)
    {
        glBegin(GL_QUADS);
        glColor3f(0.00f, 0.20f, 0.20f); // Teal
        glVertex2f(i,195);
        glVertex2f(i + 150,195);
        glVertex2f(i + 105,170);
        glVertex2f(i + 45,170);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.75f, 0.75f, 0.75f); // Black
        glVertex2f(i + 45,170);
        glVertex2f(i + 105,170);
        glVertex2f(i + 95,100);
        glVertex2f(i + 55,100);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.36f, 0.40f, 0.39f); // White
        glVertex2f(i + 30,100);
        glVertex2f(i + 120,100);
        glVertex2f(i + 110,90);
        glVertex2f(i + 40,90);
        glEnd();
    }


}

//crosses

//big crosses
void M_bigCross_night(){

    glLineWidth(20);
    glBegin(GL_LINES);

     glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(0,340);
    glVertex2f(220,205);
    glEnd();

    glLineWidth(20);
    glBegin(GL_LINES);

      glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(220,205);
    glVertex2f(440,340);
    glEnd();

    glLineWidth(20);
    glBegin(GL_LINES);

     glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(440,340);
    glVertex2f(660,205);
    glEnd();

    glLineWidth(20);
    glBegin(GL_LINES);

      glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(660,205);
    glVertex2f(880,340);
    glEnd();

    glLineWidth(20);
    glBegin(GL_LINES);

     glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(880,340);
    glVertex2f(1050,205);
    glEnd();

}
//small crosses

void M_smallCross_night(){

    glColor3f(0.8f, 0.8f, 0.8f);
    for (int i = 0; i < 1000; i += 430)
    {
        glBegin(GL_QUADS);

        // First quad
        glVertex2f(100 + i, 350);
        glVertex2f(130 + i, 350);
        glVertex2f(230 + i, 280);
        glVertex2f(210 + i, 280);

        glEnd();

        glBegin(GL_QUADS);

        // Second quad
        glVertex2f(228 + i, 280);
        glVertex2f(250 + i, 280);
        glVertex2f(370 + i, 350);
        glVertex2f(340 + i, 350);

        glEnd();
    }
    }

void sky_nightM()
{

    glBegin(GL_QUADS);
    glColor3f(0.21f, 0.27f, 0.3098f);
    //glColor3f(0.039f, 0.059f, 0.137f); // sky
    glVertex2f(0,500);
    glVertex2f(1000,500);
    glVertex2f(1000,700);
    glVertex2f(0,700);

    glEnd();

}

/////////   function calling for day/////////

void dayM()
{

    glClear(GL_COLOR_BUFFER_BIT);


    riverM();
    boat3M();
    bridgeM();
    lineM();
    line2M();
    trainM();


    bigCrossM();
    smallCrossM();

    boat1M();
    boat2M();

    skyM();
    sunM();
    truckM();
    busM();
    cloud1M();
    cloud2M();
    cloud3M();
    roadLightM();
    car1M();
    ambulanceM();
    raillingM();




}

/////////   function calling for night /////////

void nightM()
{
    glClear(GL_COLOR_BUFFER_BIT);

    river_nightM();
    bridge_nightM();
    line_nightM();
    line2_nightM();
    boat1_nightM();
    boat2_nightM();
    sky_nightM();
    moonM();
    M_star();
    cloud1M_night();
    cloud2M_night();
    planeM();
    M_car3_night();
    roadLight_nightM();
    car1_nightM();
    light_nightM();
    M_smallCross_night();
    trainM_night();
    M_bigCross_night();
    M_star();
    M_car4_night();
    raillingM_night();

}

void keyboardM(unsigned char key, int x, int y)
{
    if (key == 'd' || key == 'D')
    {
        isDayM = true;
        glutPostRedisplay();
    }

    if(key == 'n' || key == 'N')
    {
        isDayM = false;
        glutPostRedisplay();
    }
    if(key == 'm' || key == 'M')
    {
        scenarioTaki = false;
        scenarioMahir = true;
        scenarioTTM = false;
        scenarioTajuar = false;
    }
    if(key == 'a' || key == 'A')
    {
        scenarioTaki = false;
        scenarioMahir = false;
        scenarioTTM = true;
        scenarioTajuar = false;
    }

    if(key == 's' || key == 'S')
    {
        scenarioTajuar = true;
        scenarioTaki = false;
        scenarioMahir = false;
        scenarioTTM = false;
    }

    if(key == 'v' || key == 'V')
    {
        scenarioTaki = true;
        scenarioMahir = false;
        scenarioTTM = false;
        scenarioTajuar = false;
    }

    if(key == 27)
        exit(0);

}

void specialKeysM(int key, int x, int y)
{
    if (isDayM)  // Check if it's day
    {
        switch (key)
        {
        case GLUT_KEY_UP:
            car1MSpeed += 0.5f;
            break;

        case GLUT_KEY_DOWN:
            car1MSpeed -= 0.5f;
            if (car1MSpeed < 0) car1MSpeed = 0;
            break;

        case GLUT_KEY_RIGHT:
            ambulanceMSpeed += 0.5f;
            break;

        case GLUT_KEY_LEFT:
            ambulanceMSpeed -= 0.5f;
            break;
        }
    }
    else  // If it's night
    {
        switch (key)
        {
        case GLUT_KEY_UP:
            planeMSpeed += 0.6f;
            break;

        case GLUT_KEY_DOWN:
            planeMSpeed -= 0.6f;
            if (planeMSpeed < 0) planeMSpeed = 0;
            break;
        }
    }
}


void M_mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)   // Pause/resume
    {
        car1MPaused = !car1MPaused;
        if (car1MPaused)
        {
            savedcar1MSpeed = car1MSpeed;
            car1MSpeed = 0;
        }
        else
        {
          car1MSpeed =  savedcar1MSpeed;

        }



    }


     if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)   // Pause/resume
    {
        trainM_nightPaused = !trainM_nightPaused;
        if (trainM_nightPaused)
        {
            savedTrainM_nightSpeed = trainM_nightSpeed;
            trainM_nightSpeed = 0;
        }
        else
        {
          trainM_nightSpeed =  savedTrainM_nightSpeed;

        }

    }
}

void Mahir()
{
    // Depending on the time of day, call day or night function
    if (isDayM)
    {
        dayM();  // Call the day setup
    }
    else
    {
        nightM();  // Call the night setup
    }
}
/// =======================================================$$$$$$$$$$$$$$$$$$$$$$$$===================================================================


/// **************************************************************************************************************************************************
/// ******************************************************** >>> TTM <<< ****************************************************************************
/// **************************************************************************************************************************************************

//////////////////////////////////////////////////////////////////////////////////////////////////     BIRD

// Function to draw the bird
float moveBirdA = 0.0f;
float birdSpeedA =1.0f;
float savedBirdSpeedA = 0.0f;
bool birdPausedA = false;

void aBird() {
    glPushMatrix();
    glTranslatef(moveBirdA, 0, 0); // Fixed movement scaling for screen size

// Right wing
glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(705.0f, 560.0f);  // Center-top of the right wing
glVertex2f(720.0f, 570.0f);  // Outer tip of the right wing (moved further out)
glVertex2f(705.0f, 545.0f);  // Bottom of the right wing (moved further down)
glEnd();

// Left wing
glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(695.0f, 560.0f);  // Center-top of the left wing
glVertex2f(680.0f, 570.0f);  // Outer tip of the left wing (moved further out)
glVertex2f(695.0f, 545.0f);  // Bottom of the left wing (moved further down)
glEnd();

// Body
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(695.0f, 550.0f);  // Top-left of the body
glVertex2f(705.0f, 550.0f);  // Top-right of the body
glVertex2f(705.0f, 545.0f);  // Bottom-right of the body
glVertex2f(695.0f, 545.0f);  // Bottom-left of the body
glEnd();

    glPopMatrix();
    glFinish();
}


void updateBirdA(int valuupdateBuse) {
    moveBirdA -= birdSpeedA;               // Move the bird left by decreasing its position by 1 unit
    if (moveBirdA < -1000) {      // If the bird moves beyond the left boundary
        moveBirdA = 300;          // Reset its position to the right side at 300 units
    }

    glutPostRedisplay();         // Request a redraw of the screen to reflect the position change
    glutTimerFunc(10, updateBirdA, 0); // Call the function again after 10 milliseconds
}


//////////////////////////////////////////////////////////////////////////////////////////// tree
void aTree()
 {
    int shift = 100;
    for (int i = 0; i < 12; i++)
    {
        // Tree trunk1
        glBegin(GL_QUADS);
        glColor3f(0.61f, 0.35f, 0.18f);
        glVertex2f(20 + shift * i,  240);
        glVertex2f(40 + shift * i, 240);
        glVertex2f(40 + shift * i, 290);
        glVertex2f(20 + shift * i,  290);
        glEnd();

// Tree foliage layers
        glBegin(GL_TRIANGLES);
        glColor3f(0.04f, 0.36f, 0.12f);
        glVertex2f(5 + shift * i, 280);
        glVertex2f(55 + shift * i, 280);
        glVertex2f(30 + shift * i, 320);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.04f, 0.36f, 0.12f);
        glVertex2f(10 + shift * i, 300);
        glVertex2f(50 + shift * i, 300);
        glVertex2f(30 + shift * i, 340);
        glEnd();


    }
 }
//////////////////////////////////////////////////////////////////////////////////////////////////    SKY

void aSky()
{
    if(isDay)
        glColor3f(.8f,0.89f,1.0f);
    else
        glColor3f(0.0f,0.2f,0.4f);
   glBegin(GL_QUADS);

    glVertex2f(0,    240);
    glVertex2d(1000, 240);
    glVertex2d(1000, 700);
    glVertex2d(0,   700);
    glEnd();
    glFinish();
}


/////////////////////////////////////////////////////////////////////////////////////////////Cloud

float moveCloudA = 0.0f;
float cloudSpeedA = 1.0f;
float savedCloudSpeedA = 0.0f;
bool cloudPausedA = false;

void aDrawCloud() {
    glPushMatrix();
    glTranslatef(moveCloudA, 0, 0);

    // Set cloud color based on time of day
    if (isDay)
        glColor3f(1.0f, 1.0f, 1.0f);  // White for day
    else
        glColor3f(0.0f, 0.3f, 0.4f);  // Darker for night

    // Cloud 1
    glBegin(GL_POLYGON);
    circle(200, 580, 40);
    circle(200 + 30, 550 + 10, 30);
    circle(200 - 30, 550 + 10, 30);
    circle(200 + 55, 540 + 10, 20);
    circle(200 - 55, 540 + 10, 20);
    glEnd();

    // Cloud 1 base
    glBegin(GL_QUADS);
    glVertex2f(255, 530);
    glVertex2f(145, 530);
    glVertex2f(145, 550);
    glVertex2f(255, 550);
    glEnd();

    // Cloud 2
    glBegin(GL_POLYGON);
    circle(700, 650 - 15, 20);
    circle(700 + 25, 650 - 10, 20);
    circle(700 - 25, 650 - 10, 20);
    circle(700 - 50, 650, 20);
    circle(700 + 50, 650, 20);
    circle(700 + 30, 650 + 15, 25);
    circle(700, 650 + 25, 25);
    circle(700 - 30, 650 + 15, 25);
    glEnd();

    glPopMatrix();
}

void updateCloudA(int value) {
    if (!cloudPausedA) {
        moveCloudA -= cloudSpeedA;
        if (moveCloudA < -800) {  // Reset when off-screen
            moveCloudA = 1000;
        }
        glutPostRedisplay();  // Redraw the scene
    }
    glutTimerFunc(30, updateCloudA, 0);
}


///////////////////////////////////////////////////////////////////////////////////////////////   Sun and moon

float moveSunA = 0.0f;
float sunSpeedA =1.0f;
float savedSunSpeedA = 0.0f;
bool  sunPausedA = false;

void aSun()
{
    if(isDay)
        glColor3f(1.0f,1.0f,0.0f);
    else
        glColor3f(1.0f,1.0f,1.0f);

        glPushMatrix();
        glTranslatef(moveSunA,0,0);

        circle(700,650,30);
        glPopMatrix();
}

void updateSunA(int value)
{
    if (!sunPausedA) {
        moveSunA += sunSpeedA;
    if(moveSunA>1000){
        moveSunA = -750;
    }
    glutPostRedisplay();
    }
    glutTimerFunc(80,updateSunA,0);

}

///////////////////////////////////////////////////////////////////////////////////////////////////     ROAD

float moveCarA = 0.0f;
float carSpeedA =1.0f;
float savedCarSpeedA = 0.0f;
bool carPausedA = false;

void aDrawCar() {

    glPushMatrix();
    glTranslatef(moveCarA, 0, 0);

    // Car body
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue car
    glVertex2f(100, 130);  // Bottom-left
    glVertex2f(200, 130);  // Bottom-right
    glVertex2f(200, 150);  // Top-right
    glVertex2f(100, 150);  // Top-left
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue car
    glVertex2f(120, 150);  // Bottom-left
    glVertex2f(170, 150);  // Bottom-right
    glVertex2f(170, 170);  // Top-right
    glVertex2f(120, 170);  // Top-left
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f); // Blue car
    glVertex2f(110, 150);  // Bottom-left
    glVertex2f(120, 150);  // Bottom-right
    glVertex2f(120, 170);  // Top-left
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f); // Blue car
    glVertex2f(190, 150);  // Bottom-left
    glVertex2f(170, 150);  // Bottom-right
    glVertex2f(170, 170);  // Top-left
    glEnd();


    // Wheels
    glColor3f(0.0f, 0.0f, 0.0f); // Black wheels
    circle(130, 130, 10); // Left wheel
    circle(170, 130, 10); // Right wheel

    // Wheel rims
    glColor3f(0.5f, 0.5f, 0.5f); // Gray rims
    circle(130, 130, 6); // Left rim
    circle(170, 130, 6); // Right rim

    if(!isDay)
    {
        glColor3f(1.0f,1.0f,0.4f);
        glBegin(GL_QUADS);
        glVertex2f(200, 140);
        glVertex2d(200, 140);
        glVertex2d(250, 110);
        glVertex2d(250, 150);
        glEnd();
    }

    glPopMatrix();
}


void updateCarA(int value) {
    if (!carPausedA) {
        moveCarA += carSpeedA;
    if (moveCarA > 1000) { // Reset when the car goes off the right side of the screen
        moveCarA = -200; // Reset to the left side
    }
    glutPostRedisplay();
    }
    glutTimerFunc(10, updateCarA, 0); // Call every 10ms

}
///////////////////////////////////////////////////////////////      truck

float moveTruckA = 0.0f;
float truckSpeedA =1.0f;
float savedTruckSpeedA = 0.0f;
bool truckPausedA = false;

void atruck(){

    glPushMatrix();
    glTranslatef(moveTruckA, 0, 0);


glBegin(GL_QUADS);
    glColor3f(1.00f, 0.00f, 0.00f); //body
    glVertex2f(400,230);
    glVertex2f(360,230);
    glVertex2f(360,200);
    glVertex2f(400,200);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.00f, 1.00f, 0.00f);
    glVertex2f(403,200);
    glVertex2f(340,200);
    glVertex2f(340,192);
    glVertex2f(403,192);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.00f, 0.00f, 1.00f); // front body
    glVertex2f(360,225);
    glVertex2f(345,225);
    glVertex2f(340,215);
    glVertex2f(340,192);
    glVertex2f(360,192);
    glVertex2f(360,230);


    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.8f, 1.0f); // window
    glVertex2f(358,223);
    glVertex2f(346,223);
    glVertex2f(342,215);
    glVertex2f(358,215);
    glEnd();


    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.00f, 1.00f, 1.00f); //light
    glVertex2f(340,210);
    glVertex2f(344,210);
    glVertex2f(344,205);
    glVertex2f(340,203);
    glEnd();

     // front wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(353, 193, 8);

    //  rear wheel
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(392, 193, 8);

    //  outlines
    glColor3f(0.3f, 0.3f, 0.3f); // Gray
    circle(353, 193, 5);
    circle(392, 193, 5);

    if(!isDay)
    {
        glColor3f(1.0f,1.0f,0.4f);
        glBegin(GL_QUADS);
        glColor3f(1.00f, 1.00f, 0.00f); //light
        glVertex2f(340,206);
        glVertex2f(340,206);
        glVertex2f(300,180);
        glVertex2f(300,210);
        glEnd();
    }

    glPopMatrix();
}

void updatetruckA(int value)
{
    if(!truckPausedA)
    {
        moveTruckA -= truckSpeedA;
        if (moveTruckA +400  < 0)
        {
            moveTruckA = 1000;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(16, updatetruckA, 0);

}


/////////////////////////////////////////////////////////////////////
float moveBusA = 0.0f;
float busSpeedA =1.0f;
float savedBusSpeedA = 0.0f;
bool busPausedA = false;

void adrawBus() {
    glPushMatrix();
    glTranslatef(moveBusA, 0, 0);
    // Bus body
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow bus
    glVertex2f(600, 130);
    glVertex2f(750, 130);
    glVertex2f(750, 200);
    glVertex2f(600, 200);
    glEnd();

    // Windows
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 1.0f); // Light blue windows
    glVertex2f(610, 150);
    glVertex2f(740, 150);
    glVertex2f(740, 190);
    glVertex2f(610, 190);
    glEnd();

    // Wheels
    glColor3f(0.0f, 0.0f, 0.0f); // Black wheels
    circle(630, 130, 10); // Left wheel
    circle(720, 130, 10); // Right wheel

    // Wheel rims
    glColor3f(0.5f, 0.5f, 0.5f); // Gray rims
    circle(630, 130, 6); // Left rim
    circle(720, 130, 6); // Right rim

    if(!isDay)
    {
        glBegin(GL_QUADS);
        glColor3f(1.00f, 1.00f, 0.00f); //light
        glVertex2f(750,140);
        glVertex2f(750,140);
        glVertex2f(810,110);
        glVertex2f(810,160);
        glEnd();
    }
    glPopMatrix();
}

void updateBusA(int value) {
    if (!busPausedA) {
        moveBusA += busSpeedA;
    if (moveBusA > 1000) { // Reset when the bus goes off the right side of the screen
        moveBusA = -750; // Reset to the left side (adjust based on bus width)
    }
    glutPostRedisplay();
     // Call every 10ms
}
glutTimerFunc(10, updateBusA, 0);
}


void aRoad() {
    // Road surface
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f); // Black road
    glVertex2f(0, 65);
    glVertex2f(1000, 65);
    glVertex2f(1000, 210);
    glVertex2f(0, 210);
    glEnd();

    // Road markings (white lines)
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // White lines
    for (int x = 10; x < 1000; x += 60) {
        glVertex2f(x, 155);
        glVertex2f(x + 30, 155);
    }
    glEnd();

    // Draw vehicles on the road
    atruck();
    aDrawCar(); // Red car
    adrawBus();  // Yellow bus
    glFlush(); // Render now
}

////////////////////////////////////////////////////////////////////////////////////////Road Down

void aRoadDown()
{
   glBegin(GL_QUADS);
   if(isDay)
    glColor3f(.88f, .88f, .88f); // Black road
    else
       glColor3f(0.0f, 0.0f, 0.2f);
    glVertex2f(0, 0);
    glVertex2f(1000, 0);
    glVertex2f(1000, 65);
    glVertex2f(0, 65);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);

    glVertex2f(450, 20);
    glVertex2f(555, 20);
    glVertex2f(555, 35);
    glVertex2f(450, 35);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 1.5f);  // Cyan color for the lines
    glVertex2f(460, 0);
    glVertex2f(460, 20);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 1.5f);  // Cyan color for the lines
    glVertex2f(470, 5);
    glVertex2f(470, 20);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 1.5f);  // Cyan color for the lines
    glVertex2f(540, 0);
    glVertex2f(540, 20);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 1.5f);  // Cyan color for the lines
    glVertex2f(550, 5);
    glVertex2f(550, 20);
    glEnd();
    //////////////////////////////////////////
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 1.5f);  // Cyan color for the lines
    glVertex2f(420, 0);
    glVertex2f(420, 120);
    glEnd();

    glLineWidth(7);
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 1.5f);  // Cyan color for the lines
    glVertex2f(410, 120);
    glVertex2f(450, 120);
    glEnd();
    if(isDay)
    glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(1.0f, 1.0f, 0.0f);

    circle(445,107,8);


}

//////////////////////////////////////////////////////////////////////////////////////////    ROAD UP

void aRoadup()
{
    glBegin(GL_QUADS);
    if(isDay)
    glColor3f(1.0f, 1.0f, 1.0f);
    else
       glColor3f(0.0f, 0.0f, 0.2f);
    glVertex2f(0,    210);
    glVertex2f(1000, 210);
    glVertex2f(1000, 220);
    glVertex2f(0,    220);


    glBegin(GL_QUADS);
    if(isDay)
    glColor3f(.88f, .88f, .88f);
    else
     glColor3f(0.0f, 0.0f, 0.2f);
    glVertex2f(0,    220);
    glVertex2f(1000, 220);
    glVertex2f(1000, 240);
    glVertex2f(0, 240);

    glEnd();
    glFlush();
}


////////////////////////////////////////////////////////////////////////////////////////////////////////Railing


void aDownwRailing() {
    // Set the color for the railing (e.g., gray)
    glColor3f(0.5f, 0.5f, 0.5f);

    // Draw vertical posts
    float postWidth = 5.0f; // Width of each post
    float postHeight = 35.0f; // Height of each post
    float spacing = 20.0f; // Spacing between posts

    for (float x = 0; x <= 1000; x += spacing) {
        // Draw a vertical post
        glBegin(GL_QUADS);
        glVertex2f(x, 80); // Bottom-left
        glVertex2f(x + postWidth, 80); // Bottom-right
        glVertex2f(x + postWidth, 80 + postHeight); // Top-right
        glVertex2f(x, 80 + postHeight); // Top-left
        glEnd();
    }

    // Draw horizontal bars
    float barHeight = 3.0f; // Height of each horizontal bar
    float barY = 80 + postHeight - barHeight; // Y-position of the bars

    // Lower horizontal bar
    glBegin(GL_QUADS);
    glVertex2f(0, barY); // Bottom-left
    glVertex2f(1000, barY); // Bottom-right
    glVertex2f(1000, barY + barHeight); // Top-right
    glVertex2f(0, barY + barHeight); // Top-left
    glEnd();

    // Upper horizontal bar (optional, for a double-bar railing)
    float upperBarY = barY + 5.0f; // Y-position of the upper bar
    glBegin(GL_QUADS);
    glVertex2f(0, upperBarY); // Bottom-left
    glVertex2f(1000, upperBarY); // Bottom-right
    glVertex2f(1000, upperBarY + barHeight); // Top-right
    glVertex2f(0, upperBarY + barHeight); // Top-left
    glEnd();
}


//////////////////////////////////////////////////////////////////////////////////////////////////upRailing

void aUpRailing() {
    // Set the color for the railing (e.g., gray)
    glColor3f(0.5f, 0.5f, 0.5f);

    // Draw vertical posts
    float postWidth = 5.0f; // Width of each post
    float postHeight = 20.0f; // Height of each post
    float spacing = 20.0f; // Spacing between posts

    for (float x = 0; x <= 1000; x += spacing) {
        // Draw a vertical post
        glBegin(GL_QUADS);
        glVertex2f(x, 240); // Bottom-left
        glVertex2f(x + postWidth, 240); // Bottom-right
        glVertex2f(x + postWidth, 240 + postHeight); // Top-right
        glVertex2f(x, 240 + postHeight); // Top-left
        glEnd();
    }

    // Draw horizontal bars
    float barHeight = 3.0f; // Height of each horizontal bar
    float barY = 240 + postHeight - barHeight; // Y-position of the bars

    // Lower horizontal bar
    glBegin(GL_QUADS);
    glVertex2f(0, barY); // Bottom-left
    glVertex2f(1000, barY); // Bottom-right
    glVertex2f(1000, barY + barHeight); // Top-right
    glVertex2f(0, barY + barHeight); // Top-left
    glEnd();

    // Upper horizontal bar (optional, for a double-bar railing)
    float upperBarY = barY + 5.0f; // Y-position of the upper bar
    glBegin(GL_QUADS);
    glVertex2f(0, upperBarY); // Bottom-left
    glVertex2f(1000, upperBarY); // Bottom-right
    glVertex2f(1000, upperBarY + barHeight); // Top-right
    glVertex2f(0, upperBarY + barHeight); // Top-left
    glEnd();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////     BUILDING1

void aBuilding1()
{

    glBegin(GL_QUADS);
    if(isDay)
    glColor3f(.88f, .88f, .88f);
    else
        glColor3f(0.0f, 0.0f, 0.1f);
    glVertex2f(0,   240);
    glVertex2d(220, 240);
    glVertex2d(220, 490);
    glVertex2d(0,   490);
    glEnd();


    glBegin(GL_QUADS);
    if(isDay)
    glColor3f(1.f,1.0f,1.0f);
    else
     glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(20,   260);
    glVertex2d(40, 260);
    glVertex2d(40, 470);
    glVertex2d(20,   470);
    glEnd();


    glBegin(GL_QUADS);
    if(isDay)
    glColor3f(1.0f,1.0f,1.0f);
    else
      glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(60,   260);
    glVertex2d(80, 260);
    glVertex2d(80, 470);
    glVertex2d(60,   470);
    glEnd();

    glBegin(GL_QUADS);
    if(isDay)
    glColor3f(1.f,1.0f,1.0f);
    else
     glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(100,   260);
    glVertex2d(120,   260);
    glVertex2d(120,   470);
    glVertex2d(100,   470);
    glEnd();

    glBegin(GL_QUADS);
    if(isDay)
    glColor3f(1.f,1.0f,1.0f);
    else
       glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(140,   260);
    glVertex2d(160,   260);
    glVertex2d(160,   470);
    glVertex2d(140,   470);
    glEnd();

    glBegin(GL_QUADS);
    if(isDay)
    glColor3f(1.f,1.0f,1.0f);
    else
      glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(180,   260);
    glVertex2d(200,   260);
    glVertex2d(200,   470);
    glVertex2d(180,   470);
    glEnd();
    glFlush();


}

//////////////////////////////////////////////////   BILDING2

void aBuilding2()
{
    // Main building body
    glBegin(GL_QUADS);
    if(isDay)
    glColor3f(0.0f, 1.0f, 1.0f);
    else
       glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(220, 240);
    glVertex2d(310, 240);
    glVertex2d(310, 400);
    glVertex2d(220, 400);
    glEnd();

    // Roof base
    glBegin(GL_QUADS);
    if(isDay)
    glColor3f(0.88f, 0.88f, 0.88f);
    else
      glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(220, 400);
    glVertex2d(310, 400);
    glVertex2d(310, 410);
    glVertex2d(220, 410);
    glEnd();

    // Roof top
    glBegin(GL_QUADS);
    if(isDay)
    glColor3f(1.0f, 0.5f, 0.0f);
    else
       glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(230, 410);
    glVertex2d(300, 410);
    glVertex2d(280, 440);
    glVertex2d(250, 440);
    glEnd();

    // Windows (drawn as smaller quads)
    if(isDay)
    glColor3f(0.2f, 0.2f, 0.2f); // Window color (dark gray)
    else
        glColor3f(1.0f, 1.0f, 0.0f);

    // First row of windows
    glBegin(GL_QUADS);
    glVertex2f(230, 260);
    glVertex2f(250, 260);
    glVertex2f(250, 280);
    glVertex2f(230, 280);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(260, 260);
    glVertex2f(280, 260);
    glVertex2f(280, 280);
    glVertex2f(260, 280);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(290, 260);
    glVertex2f(308, 260);
    glVertex2f(308, 280);
    glVertex2f(290, 280);
    glEnd();

    // Second row of windows
    glBegin(GL_QUADS);
    glVertex2f(230, 300);
    glVertex2f(250, 300);
    glVertex2f(250, 320);
    glVertex2f(230, 320);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(260, 300);
    glVertex2f(280, 300);
    glVertex2f(280, 320);
    glVertex2f(260, 320);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(290, 300);
    glVertex2f(308, 300);
    glVertex2f(308, 320);
    glVertex2f(290, 320);
    glEnd();

    // Third row of windows
    glBegin(GL_QUADS);
    glVertex2f(230, 340);
    glVertex2f(250, 340);
    glVertex2f(250, 360);
    glVertex2f(230, 360);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(260, 340);
    glVertex2f(280, 340);
    glVertex2f(280, 360);
    glVertex2f(260, 360);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(290, 340);
    glVertex2f(308, 340);
    glVertex2f(308, 360);
    glVertex2f(290, 360);
    glEnd();

    // Fourth row of windows
    glBegin(GL_QUADS);
    glVertex2f(230, 380);
    glVertex2f(250, 380);
    glVertex2f(250, 395);
    glVertex2f(230, 395);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(260, 380);
    glVertex2f(280, 380);
    glVertex2f(280, 395);
    glVertex2f(260, 395);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(290, 380);
    glVertex2f(308, 380);
    glVertex2f(308, 395);
    glVertex2f(290, 395);
    glEnd();

    glFlush();
}

/////////////////////////////////////////   BUILDING3

void aBuilding3()
{
   glBegin(GL_POLYGON);
   if(isDay)
    glColor3f(1.f,1.0f,1.0f);
    else
     glColor3f(0.0f,0.0f,0.1f);
    glVertex2d(355,   420);
    glVertex2d(355,   240);
    glVertex2d(310,   240);
    glVertex2d(310,   420);
    glEnd();

    glBegin(GL_QUADS);
    if(isDay)
    glColor3f(1.f,0.5f,0.0f);
    else
        glColor3f(0.0f,0.0f,0.2f);
    glVertex2f(355,   240);
    glVertex2d(375,   240);
    glVertex2d(375,   420);
    glVertex2d(355,   420);
    glEnd();


}

/////////////////////////////////////////////////////    Building4

void aBuilding4()
{
    glBegin(GL_POLYGON);
    if(isDay)
    glColor3f(1.f,1.0f,1.0f);
    else
       glColor3f(0.0f,0.0f,0.1f);
    glVertex2f(390, 240);
    glVertex2f(510, 240);
    glVertex2f(510, 480);
    glVertex2f(390, 480);
    glEnd();

    glBegin(GL_POLYGON);
    if(isDay)
    glColor3f(.88f,.88f,.88f);
    else
        glColor3f(0.0f,0.0f,0.1f);
    glVertex2f(400, 480);
    glVertex2f(500, 480);
    glVertex2f(500, 500);
    glVertex2f(400, 500);
    glEnd();

    glBegin(GL_POLYGON);
    if(isDay)
    glColor3f(0.0f,0.0f,0.0f);
    else
        glColor3f(0.0f,0.0f,0.1f);
    glVertex2f(420, 500);
    glVertex2f(480, 500);
    glVertex2f(480, 520);
    glVertex2f(420, 520);
    glEnd();

    glBegin(GL_POLYGON);
    if(isDay)
    glColor3f(.0f,.0f,.0f);
    else
      glColor3f(0.0f,0.0f,0.1f);
    glVertex2f(430, 500);
    glVertex2f(470, 500);
    glVertex2f(470, 530);
    glVertex2f(430, 530);
    glEnd();


    ////////window

    glBegin(GL_POLYGON);
    if(isDay)
    glColor3f(.88f, .88f, .88f);
    else
      glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(400, 250);
    glVertex2f(500, 250);
    glVertex2f(500, 280);
    glVertex2f(400, 280);
    glEnd();

    glBegin(GL_POLYGON);
    if(isDay)
    glColor3f(.88f, .88f, .88f);
    else
      glColor3f(1.0f, 1.0f, 0.0);
    glVertex2f(400, 300);
    glVertex2f(500, 300);
    glVertex2f(500, 330);
    glVertex2f(400, 330);
    glEnd();

    glBegin(GL_POLYGON);
    if(isDay)
    glColor3f(.88f, .88f, .88f);
    else
      glColor3f(1.0f, 1.0f, 0.0);
    glVertex2f(400, 350);
    glVertex2f(500, 350);
    glVertex2f(500, 380);
    glVertex2f(400, 380);
    glEnd();

    glBegin(GL_POLYGON);
    if(isDay)
    glColor3f(.88f, .88f, .88f);
    else
       glColor3f(1.0f, 1.0f, 0.0);
    glVertex2f(400, 400);
    glVertex2f(500, 400);
    glVertex2f(500, 430);
    glVertex2f(400, 430);
    glEnd();

    glBegin(GL_POLYGON);
    if(isDay)
    glColor3f(.88f, .88f, .88f);
    else
       glColor3f(1.0f, 1.0f, 0.0);
    glVertex2f(400, 450);
    glVertex2f(500, 450);
    glVertex2f(500, 460);
    glVertex2f(400, 460);
    glEnd();
    glFinish();
}


///////////////////////////////////////    BUILDIND5
void aBuilding5()
{
    glBegin(GL_POLYGON);
    if(isDay)
    glColor3f(0.7f, 0.7f, 0.2f);
    else
      glColor3f(0.0f, 0.0f, 0.1f);
    glVertex2f(520, 240);
    glVertex2f(640, 240);
    glVertex2f(640, 460);
    glVertex2f(580, 500);
    glVertex2f(520, 460);
    glEnd();

    // Adding windows
    if(isDay)
    glColor3f(0.5f, 0.5f, 1.0f); // Light blue color
    else
        glColor3f(1.0f, 1.0f, 0.1f); // Light blue color
    // First row
    glBegin(GL_QUADS);
    glVertex2f(540, 260);
    glVertex2f(555, 260);
    glVertex2f(555, 275);
    glVertex2f(540, 275);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(565, 260);
    glVertex2f(580, 260);
    glVertex2f(580, 275);
    glVertex2f(565, 275);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(590, 260);
    glVertex2f(605, 260);
    glVertex2f(605, 275);
    glVertex2f(590, 275);
    glEnd();

    // Second row
    glBegin(GL_QUADS);
    glVertex2f(540, 280);
    glVertex2f(555, 280);
    glVertex2f(555, 295);
    glVertex2f(540, 295);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(565, 280);
    glVertex2f(580, 280);
    glVertex2f(580, 295);
    glVertex2f(565, 295);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(590, 280);
    glVertex2f(605, 280);
    glVertex2f(605, 295);
    glVertex2f(590, 295);
    glEnd();

    // Third row
    glBegin(GL_QUADS);
    glVertex2f(540, 300);
    glVertex2f(555, 300);
    glVertex2f(555, 315);
    glVertex2f(540, 315);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(565, 300);
    glVertex2f(580, 300);
    glVertex2f(580, 315);
    glVertex2f(565, 315);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(590, 300);
    glVertex2f(605, 300);
    glVertex2f(605, 315);
    glVertex2f(590, 315);
    glEnd();

    // Top row moved to the right side
    glBegin(GL_QUADS);
    glVertex2f(590, 420);
    glVertex2f(605, 420);
    glVertex2f(605, 435);
    glVertex2f(590, 435);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(590, 440);
    glVertex2f(605, 440);
    glVertex2f(605, 455);
    glVertex2f(590, 455);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(615, 420);
    glVertex2f(630, 420);
    glVertex2f(630, 435);
    glVertex2f(615, 435);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(615, 440);
    glVertex2f(630, 440);
    glVertex2f(630, 455);
    glVertex2f(615, 455);
    glEnd();

    glFlush();
}

///////////////////////////////////////    BUILDIND6
void aBuilding6() {
    // Building base
    glBegin(GL_QUADS);
    if(isDay)
    glColor3f(0.2f, 0.7f, 0.7f);
    else
      glColor3f(0.0f, 0.0f, 0.1f);
    glVertex2f(650, 240);  // Bottom left
    glVertex2f(770, 240);  // Bottom right
    glVertex2f(770, 400);  // Top right
    glVertex2f(650, 400);  // Top left
    glEnd();

    // Top windows (4 windows)
    if(isDay)
    glColor3f(1.0f, 1.0f, 1.0f);  // White color for windows
    else
      glColor3f(1.0f, 1.0f, 0.1f);

    // Left window
    glBegin(GL_QUADS);
    glVertex2f(655, 370);
    glVertex2f(685, 370);
    glVertex2f(685, 390);
    glVertex2f(655, 390);
    glEnd();

    // Second window
    glBegin(GL_QUADS);
    glVertex2f(695, 370);
    glVertex2f(725, 370);
    glVertex2f(725, 390);
    glVertex2f(695, 390);
    glEnd();

    // Third window
    glBegin(GL_QUADS);
    glVertex2f(735, 370);
    glVertex2f(765, 370);
    glVertex2f(765, 390);
    glVertex2f(735, 390);
    glEnd();

    // Right window
    glBegin(GL_QUADS);
    glVertex2f(655, 340);
    glVertex2f(685, 340);
    glVertex2f(685, 360);
    glVertex2f(655, 360);
    glEnd();

    // Second window
    glBegin(GL_QUADS);
    glVertex2f(695, 340);
    glVertex2f(725, 340);
    glVertex2f(725, 360);
    glVertex2f(695, 360);
    glEnd();

    // Third window
    glBegin(GL_QUADS);
    glVertex2f(735, 340);
    glVertex2f(765, 340);
    glVertex2f(765, 360);
    glVertex2f(735, 360);
    glEnd();

    glFlush();
}

///////////////////////////////////////    BUILDIND7
void aBuilding7() {
    // Main building shape
    glBegin(GL_POLYGON);
    if(isDay)
    glColor3f(0.8f, 0.5f, 0.2f);  // Light brown color
    else
     glColor3f(0.0f, 0.0f, 0.1f);
    glVertex2f(780, 240);
    glVertex2f(900, 240);
    glVertex2f(900, 470);
    glVertex2f(780, 470);
    glEnd();

    // Roof of the building
    glBegin(GL_POLYGON);
    if(isDay)
    glColor3f(0.0f, 0.0f, 0.5f);  // Dark blue roof color
    else
      glColor3f(0.0f, 0.0f, 0.1f);  // Dark blue roof color
    glVertex2f(780, 470);
    glVertex2f(900, 470);
    glVertex2f(840, 540);
    glEnd();

    // Roof lines (with color for lines)
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 1.5f);  // Cyan color for the lines
    glVertex2f(840, 540);
    glVertex2f(840, 590);
    glEnd();

    // Circle at the top (red)
    glColor3f(1.0f, 0.0f, 0.0f);  // Red color
    circle(840, 590, 10);


    if(isDay)
    glColor3f(0.8f, 0.8f, 1.0f);  // Light blue color for the windows
    else
       glColor3f(1.0f, 1.0f, 0.0f);

    // First window on the left side
    glBegin(GL_QUADS);
    glVertex2f(790, 350);  // Bottom-left
    glVertex2f(810, 350);  // Bottom-right
    glVertex2f(810, 370);  // Top-right
    glVertex2f(790, 370);  // Top-left
    glEnd();

    // Second window near the middle
    glBegin(GL_QUADS);
    glVertex2f(830, 350);  // Bottom-left
    glVertex2f(850, 350);  // Bottom-right
    glVertex2f(850, 370);  // Top-right
    glVertex2f(830, 370);  // Top-left
    glEnd();

    // Third window on the right side
    glBegin(GL_QUADS);
    glVertex2f(870, 350);  // Bottom-left
    glVertex2f(890, 350);  // Bottom-right
    glVertex2f(890, 370);  // Top-right
    glVertex2f(870, 370);  // Top-left
    glEnd();

    // Additional window on the left for variety (optional)
    glBegin(GL_QUADS);
    glVertex2f(830, 400);  // Bottom-left
    glVertex2f(850, 400);  // Bottom-right
    glVertex2f(850, 420);  // Top-right
    glVertex2f(830, 420);  // Top-left
    glEnd();

    // Second window near the middle
    glBegin(GL_QUADS);
    glVertex2f(830, 310);  // Bottom-left
    glVertex2f(850, 310);  // Bottom-right
    glVertex2f(850, 330);  // Top-right
    glVertex2f(830, 330);  // Top-left
    glEnd();



    glFlush();  // Flush the OpenGL pipeline to render everything
}

///////////////////////////////////////    BUILDIND8
void aBuilding8()
{
    glBegin(GL_QUADS);
    if(isDay)
    glColor3f(0.2f, 0.7f, 0.7f);
    else
       glColor3f(0.0f, 0.0f, 0.1f);
    glVertex2f(910,     240);
    glVertex2f(1000,    240);
    glVertex2f(1000,    500);
    glVertex2f(910,     500);
    glEnd();

    if(isDay)
    glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(1.0f, 1.0f, 0.0f);


    glBegin(GL_QUADS);


    glVertex2f(915,    250);
    glVertex2f(1000,   250);
    glVertex2f(1000,   280);
    glVertex2f(915,    280);
    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(915,    310);
    glVertex2f(1000,   310);
    glVertex2f(1000,   340);
    glVertex2f(915,    340);
    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(915,    370);
    glVertex2f(1000,   370);
    glVertex2f(1000,   400);
    glVertex2f(915,    400);
    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(915,    430);
    glVertex2f(1000,   430);
    glVertex2f(1000,   470);
    glVertex2f(915,    470);
    glEnd();
    glFlush();
}


void keyboardA(unsigned char key, int x, int y) {

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
    if(key == ' '){
         birdPausedA = !birdPausedA;

        if (birdPausedA)
        {
            savedBirdSpeedA = birdSpeedA;
            birdSpeedA = 0;
        }
        else
        {
            birdSpeedA = savedBirdSpeedA;
        }

        ////////////////////////////////////////////////

        cloudPausedA = !cloudPausedA;

        if (cloudPausedA)
        {
            savedCloudSpeedA = cloudSpeedA;
            cloudSpeedA = 0;
        }
        else
        {
            cloudSpeedA = savedCloudSpeedA;
        }

        //////////////////////////////////////////

        sunPausedA = !sunPausedA;

        if (sunPausedA)
        {
            savedSunSpeedA = sunSpeedA;
            sunSpeedA = 0;
        }
        else
        {
            sunSpeedA = savedSunSpeedA;
        }
        //////////////////////////////////////
        carPausedA = !carPausedA;

        if (carPausedA)
        {
            savedCarSpeedA = carSpeedA;
            carSpeedA = 0;
        }
        else
        {
            carSpeedA = savedCarSpeedA;
        }

        //////////////////////////////////////

        truckPausedA = !truckPausedA;

        if (truckPausedA)
        {
            savedTruckSpeedA = truckSpeedA;
            truckSpeedA = 0;
        }
        else
        {
            truckSpeedA = savedTruckSpeedA;
        }

        ////////////////////////////////////

        busPausedA = !busPausedA;

        if (busPausedA)
        {
            savedBusSpeedA = busSpeedA;
            busSpeedA = 0;
        }
        else
        {
            busSpeedA = savedBusSpeedA;
        }
   }

   if(key == 'm' || key == 'M')
    {
        scenarioTaki = false;
        scenarioMahir = true;
        scenarioTTM = false;
        scenarioTajuar = false;
    }
    if(key == 'a' || key == 'A')
    {
        scenarioTaki = false;
        scenarioMahir = false;
        scenarioTTM = true;
        scenarioTajuar = false;
    }

    if(key == 's' || key == 'S')
    {
        scenarioTajuar = true;
        scenarioTaki = false;
        scenarioMahir = false;
        scenarioTTM = false;
    }

    if(key == 'v' || key == 'V')
    {
        scenarioTaki = true;
        scenarioMahir = false;
        scenarioTTM = false;
        scenarioTajuar = false;
    }

    if(key == 27)
        exit(0);

}

void specialKeysA(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        truckSpeedA += 0.2f;
        break;
    case GLUT_KEY_DOWN:
        truckSpeedA -= 0.2f;
        if (truckSpeedA < 0) truckSpeedA = 0;
        break;

    case GLUT_KEY_RIGHT:
            cloudSpeedA += 0.2f;  // Increase speed
            break;
    case GLUT_KEY_LEFT:
            cloudSpeedA -= 0.2f;  // Decrease speed
            if (cloudSpeedA < 0) cloudSpeedA = 0;  // Prevent negative speed
            break;
    }
}


void mouseA(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)   // Pause/resume
    {
        busPausedA = !busPausedA;
        if (busPausedA)
        {
            savedBusSpeedA = busSpeedA;
            busSpeedA = 0;
        }
        else
        {
            busSpeedA = savedBusSpeedA;
        }
    }
}

void TTM()
{
    aSky();
    aSun();
    aDrawCloud();
    aBird();
    aRoadup();
    aBuilding1();
    aBuilding2();
    aBuilding3();
    aBuilding4();
    aBuilding5();
    aBuilding6();
    aBuilding7();
    aBuilding8();
    aTree();
    aRoad();
    aDownwRailing();
    aUpRailing();
    aRoadDown();
}
/// =========================================================$$$$$$$$$$$$$$$$$$$$$$$$===================================================================


/// **************************************************************************************************************************************************
/// ******************************************************** >>> Tajuar <<< **************************************************************************
/// **************************************************************************************************************************************************


bool S_isDay = true;

////////////sky/////////

void Ssky()
{
    glBegin(GL_QUADS);
    if(S_isDay)
        glColor3f(0.37f, 0.82f, 0.94f);
    else
        glColor3f(0.10f, 0.13f, 0.22f);
    glVertex2i(0,700);
    glVertex2i(1000,700);
    glVertex2i(1000,530);
    glVertex2i(0,530);
    glEnd();
}

void Sbackground()
{
    if(S_isDay)
        glColor3f(.4f,0.74f,0.13f);
    else
        glColor3f(0.15f, 0.35f, 0.08f);

    glBegin(GL_QUADS);/////////background/////////
    glVertex2i(0,530);
    glVertex2i(1000,530);
    glVertex2i(1000,200);
    glVertex2i(0,200);
    glEnd();
}

void Shouse()
{
    ///////////////////  Left House  //////////////////
    int n=20;
    glBegin(GL_QUADS); //House top Red
    if (S_isDay)
        glColor3f(0.58f, 0.29f, 0.0f);
    else
        glColor3f(0.25f, 0.12f, 0.02f);

    glVertex2i(50-n,350);
    glVertex2i(160-n,350);
    glVertex2i(185-n,315);
    glVertex2i(75-n,315);
    glEnd();

    glBegin(GL_QUADS); // House Wall
    if (S_isDay)
        glColor3f(1.0f, 0.83f, 0.63f);
    else
        glColor3f(0.50f, 0.41f, 0.30f);

    glVertex2i(75-n,315);
    glVertex2i(175-n,315);
    glVertex2i(175-n,260);
    glVertex2i(75-n,250);
    glEnd();

    glBegin(GL_POLYGON); // House Side Wall
    if (S_isDay)
        glColor3f(1.0f, 0.72f, 0.40f);
    else
        glColor3f(0.45f, 0.30f, 0.15f);
    glVertex2i(50-n,350);
    glVertex2i(75-n,315);
    glVertex2i(75-n,250);
    glVertex2i(35-n,260);
    glVertex2i(35-n,315);
    glEnd();

    glBegin(GL_QUADS); // Top left side
    if (S_isDay)
        glColor3f(0.58f, 0.29f, 0.0f);
    else
        glColor3f(0.25f, 0.12f, 0.02f);

    glVertex2i(55-n,345);
    glVertex2i(35-n,315);
    glVertex2i(25-n,315);
    glVertex2i(50-n,350);
    glEnd();

    glBegin(GL_QUADS); // Side Border
    if (S_isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.5f, 0.0f, 0.0f);

    glVertex2i(75-n,250);
    glVertex2i(75-n,240);
    glVertex2i(25-n,250);
    glVertex2i(35-n,260);
    glEnd();
    glFlush();

    glBegin(GL_QUADS); // Front Border
    if (S_isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.5f, 0.0f, 0.0f);

    glVertex2i(75-n,250);
    glVertex2i(175-n,260);
    glVertex2i(185-n,250);
    glVertex2i(75-n,240);
    glEnd();

    glBegin(GL_QUADS); //House Main door
    if (S_isDay)
        glColor3f(0.50f, 0.23f, 0.09f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glVertex2i(110-n,252);
    glVertex2i(140-n,255);
    glVertex2i(140-n,295);
    glVertex2i(110-n,295);

    if (S_isDay)
        glColor3f(0.50f, 0.23f, 0.09f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    glVertex2i(112-n,254);
    glVertex2i(138-n,257);
    glVertex2i(138-n,293);
    glVertex2i(112-n,293);

    glEnd();

    glBegin(GL_QUADS); //House Side Window
    if (S_isDay)
        glColor3f(0.50f, 0.23f, 0.09f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glVertex2i(45-n,270);
    glVertex2i(65-n,270);
    glVertex2i(65-n,300);
    glVertex2i(45-n,300);
    glEnd();

    if (S_isDay)
        glColor3f(0.50f, 0.23f, 0.09f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    glBegin(GL_QUADS);
    glVertex2i(47-n,272);
    glVertex2i(63-n,272);
    glVertex2i(63-n,298);
    glVertex2i(47-n,298);
    glEnd();

///////////////// Right 2nd HOuse ///////////////

    int x = 140;
    int y=110;
    glBegin(GL_QUADS); //House top Red
    if (S_isDay)
        glColor3f(0.58f, 0.29f, 0.0f);
    else
        glColor3f(0.25f, 0.12f, 0.02f);

    glVertex2i(625 + x,350+y);
    glVertex2i(735 + x,350+y);
    glVertex2i(760 + x,315+y);
    glVertex2i(650 + x,315+y);
    glEnd();

    glBegin(GL_QUADS); // House Wall
    if (S_isDay)
        glColor3f(1.0f, 0.83f, 0.63f);
    else
        glColor3f(0.50f, 0.41f, 0.30f);

    glVertex2i(650 + x,315+y);
    glVertex2i(750 + x,315+y);
    glVertex2i(750 + x,260+y);
    glVertex2i(650 + x,250+y);
    glEnd();

    glBegin(GL_POLYGON); // House Side Wall
    if (S_isDay)
        glColor3f(1.0f, 0.72f, 0.40f);
    else
        glColor3f(0.45f, 0.30f, 0.15f);

    glVertex2i(625 + x,350+y);
    glVertex2i(650 + x,315+y);
    glVertex2i(650 + x,250+y);
    glVertex2i(610 + x,260+y);
    glVertex2i(610 + x,315+y);
    glEnd();

    glBegin(GL_QUADS); // Top left side
    if (S_isDay)
        glColor3f(0.58f, 0.29f, 0.0f);
    else
        glColor3f(0.25f, 0.12f, 0.02f);

    glVertex2i(630 + x,345+y);
    glVertex2i(610 + x,315+y);
    glVertex2i(600 + x,315+y);
    glVertex2i(625 + x,350+y);
    glEnd();

    glBegin(GL_QUADS); // Side Border
    if (S_isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.5f, 0.0f, 0.0f);

    glVertex2i(650 + x,250+y);
    glVertex2i(650 + x,240+y);
    glVertex2i(600 + x,250+y);
    glVertex2i(610 + x,260+y);
    glEnd();
    glFlush();

    glBegin(GL_QUADS); // Front Border
    if (S_isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.5f, 0.0f, 0.0f);

    glVertex2i(650 + x,250+y);
    glVertex2i(750 + x,260+y);
    glVertex2i(760 + x,250+y);
    glVertex2i(650 + x,240+y);
    glEnd();

    glBegin(GL_QUADS); //House Main door
    if (S_isDay)
        glColor3f(0.50f, 0.23f, 0.09f);
    else
        glColor3f(0.15f, 0.007f, 0.03f);

    glVertex2i(685 + x,252+y);
    glVertex2i(715 + x,255+y);
    glVertex2i(715 + x,295+y);
    glVertex2i(685 + x,295+y);
    glEnd();

    if (S_isDay)
        glColor3f(0.50f, 0.23f, 0.09f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2i(687 + x,254+y);
    glVertex2i(713 + x,257+y);
    glVertex2i(713 + x,293+y);
    glVertex2i(687 + x,293+y);
    glEnd();

    glBegin(GL_QUADS); //House Side Window
    if (S_isDay)
        glColor3f(0.50f, 0.23f, 0.09f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glVertex2i(620 + x,270+y);
    glVertex2i(640 + x,270+y);
    glVertex2i(640 + x,300+y);
    glVertex2i(620 + x,300+y);
    glEnd();

    if (S_isDay)
        glColor3f(0.50f, 0.23f, 0.09f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);
    glBegin(GL_QUADS);

    glVertex2i(622 + x,272+y);
    glVertex2i(638 + x,272+y);
    glVertex2i(638 + x,298+y);
    glVertex2i(622 + x,298+y);
    glEnd();
    ///////////////// Right 1st HOuse ///////////////

    y=100;
    glBegin(GL_QUADS); //House top Red
    if (S_isDay)
        glColor3f(0.58f, 0.29f, 0.0f);
    else
        glColor3f(0.25f, 0.12f, 0.02f);

    glVertex2i(625,350+y);
    glVertex2i(735,350+y);
    glVertex2i(760,315+y);
    glVertex2i(650,315+y);
    glEnd();

    glBegin(GL_QUADS); // House Wall
    if (S_isDay)
        glColor3f(1.0f, 0.83f, 0.63f);
    else
        glColor3f(0.50f, 0.41f, 0.30f);

    glVertex2i(650,315+y);
    glVertex2i(750,315+y);
    glVertex2i(750,260+y);
    glVertex2i(650,250+y);
    glEnd();

    glBegin(GL_POLYGON); // House Side Wall
    if (S_isDay)
        glColor3f(1.0f, 0.72f, 0.40f);
    else
        glColor3f(0.45f, 0.30f, 0.15f);

    glVertex2i(625,350+y);
    glVertex2i(650,315+y);
    glVertex2i(650,250+y);
    glVertex2i(610,260+y);
    glVertex2i(610,315+y);
    glEnd();

    glBegin(GL_QUADS); // Top left side
    if (S_isDay)
        glColor3f(0.58f, 0.29f, 0.0f);
    else
        glColor3f(0.25f, 0.12f, 0.02f);

    glVertex2i(630,345+y);
    glVertex2i(610,315+y);
    glVertex2i(600,315+y);
    glVertex2i(625,350+y);
    glEnd();

    glBegin(GL_QUADS); // Side Border
    if (S_isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.5f, 0.0f, 0.0f);

    glVertex2i(650,250+y);
    glVertex2i(650,240+y);
    glVertex2i(600,250+y);
    glVertex2i(610,260+y);
    glEnd();
    glFlush();

    glBegin(GL_QUADS); // Front Border
    if (S_isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.5f, 0.0f, 0.0f);

    glVertex2i(650,250+y);
    glVertex2i(750,260+y);
    glVertex2i(760,250+y);
    glVertex2i(650,240+y);
    glEnd();

    glBegin(GL_QUADS); //House Main door
    if (S_isDay)
        glColor3f(0.50f, 0.23f, 0.09f);
    else
        glColor3f(0.15f, 0.007f, 0.03f);

    glVertex2i(685,252+y);
    glVertex2i(715,255+y);
    glVertex2i(715,295+y);
    glVertex2i(685,295+y);
    glEnd();

    if (S_isDay)
        glColor3f(0.50f, 0.23f, 0.09f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);
    glBegin(GL_QUADS);

    glVertex2i(687,254+y);
    glVertex2i(713,257+y);
    glVertex2i(713,293+y);
    glVertex2i(687,293+y);
    glEnd();

    glBegin(GL_QUADS); //House Side Window
    if (S_isDay)
        glColor3f(0.50f, 0.23f, 0.09f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glVertex2i(620,270+y);
    glVertex2i(640,270+y);
    glVertex2i(640,300+y);
    glVertex2i(620,300+y);
    glEnd();

    if (S_isDay)
        glColor3f(0.50f, 0.23f, 0.09f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);
    glBegin(GL_QUADS);

    glVertex2i(622,272+y);
    glVertex2i(638,272+y);
    glVertex2i(638,298+y);
    glVertex2i(622,298+y);
    glEnd();

    glBegin(GL_QUADS); //left side road
    if (S_isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(0.10f, 0.12f, 0.14f);

    glVertex2i(0,200);
    glVertex2i(350,200);
    glVertex2i(365,125);
    glVertex2i(0,125);
    glEnd();

    glBegin(GL_QUADS); //left side garden

    if (S_isDay)
        glColor3f(0.4f, 0.74f, 0.13f);
    else
        glColor3f(0.15f, 0.35f, 0.08f);

    glVertex2i(0,125);
    glVertex2i(365,125);
    glVertex2i(390,0);
    glVertex2i(0,0);
    glEnd();

    glBegin(GL_QUADS); //right side road
    if (S_isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(0.10f, 0.12f, 0.14f);

    glVertex2i(600,200);
    glVertex2i(1000,200);
    glVertex2i(1000,125);
    glVertex2i(610,125);
    glEnd();

    glBegin(GL_QUADS); //right side garden
    if (S_isDay)
        glColor3f(0.4f, 0.74f, 0.13f);
    else
        glColor3f(0.15f, 0.35f, 0.08f);

    glVertex2i(610,125);
    glVertex2i(1000,125);
    glVertex2i(1000,0);
    glVertex2i(640,0);
    glEnd();

}

/// ############################################# Bridge ###############################################
void Sbridge()
{
    glBegin(GL_QUADS); //bridge
    if (S_isDay)
        glColor3f(0.50f, 0.50f, 0.50f);
    else
        glColor3f(0.20f, 0.20f, 0.20f);

    glVertex2i(350,200);
    glVertex2i(600,200);
    glVertex2i(615,125);
    glVertex2i(365,125);
    glEnd();

    //piller
    glLineWidth(5);
    glBegin(GL_LINES);
    if (S_isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    for(int x = 365; x<616; x+=50)
    {
        glVertex2i(x,125);
        glVertex2i(x+3,140);
    }
    for(int x = 350; x<601; x+=50)
    {
        glVertex2i(x,200);
        glVertex2i(x+3,215);
    }
    glEnd();

    glBegin(GL_QUADS); //bridge
    if (S_isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    glVertex2i(330,217);
    glVertex2i(620,217);
    glVertex2i(620,210);
    glVertex2i(330,210);
    glEnd();

    glBegin(GL_QUADS); //bridge
    if (S_isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    glVertex2i(345,147);
    glVertex2i(630,147);
    glVertex2i(630,140);
    glVertex2i(345,140);
    glEnd();
}

///////////sun//////////
float moveSsun = 0.0f;
float SsunSpeed =2.0f;
float savedSsunSpeed = 0.0f;
bool SsunPaused = false;

float S_moveSun = 0;
void Ssun()
{
    if(S_isDay)
    {
        glPushMatrix();
        glTranslatef(S_moveSun, 0, 0);
        glColor3f(1,1,0);
        circle(50,650,40);
        glPopMatrix();
    }

}
void S_updateSun(int value)
{
    if (!SsunPaused)
    {

        S_moveSun += SsunSpeed ;
        if (S_moveSun > 1000)
        {
            S_moveSun = -200;
        }

        glutPostRedisplay();

    }
    glutTimerFunc(50, S_updateSun, 0);

}
/// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ Moon
float moveSmoon = 0.0f;
float SmoonSpeed =2.0f;
float savedSmoonSpeed = 0.0f;
bool SmoonPaused = false;

float S_moveMoon = 0;
void Smoon()
{
    if(!S_isDay)
    {
        glPushMatrix();
        glTranslatef(S_moveMoon, 0, 0);

        glColor3f(1,1,1);
        circle(850,650,40);

        glColor3f(0.10f, 0.13f, 0.22f);
        circle(860,660,40);
        glPopMatrix();
    }

}
void S_updateMoon(int value)
{
    if (!SmoonPaused)
    {

        S_moveMoon -= SmoonSpeed;
        if (S_moveMoon < -940)
        {
            S_moveMoon = 200;
        }

        glutPostRedisplay();

    }
    glutTimerFunc(50, S_updateMoon, 0);
}

/// ##################################################### Tree ########################
void Stree()

{
    if (S_isDay)
        glColor3f(0.13f, 0.54f, 0.13f);
    else
        glColor3f(0.05f, 0.25f, 0.05f);


//sub  tree////////////////////////////////

    int g=80;
    int v=33;

    circle(190-g,327+v,18);
    circle(175-g,327+v,18);
    circle(205-g,325+v,15);
    circle(220-g,325+v,18);
    circle(185.5-g,342+v,18);
    circle(212.5-g,342+v,18);
    circle(199-g,355+v,15);

    int b=540;
    int c=130;
    circle(190+b,327+c,18);
    circle(175+b,327+c,18);
    circle(205+b,325+c,15);
    circle(220+b,325+c,18);
    circle(185.5+b,342+c,18);
    circle(212.5+b,342+c,18);
    circle(199+b,355+c,15);

    /////right side tree//////////

    int t=83;
    glBegin(GL_QUADS); // right tree body
    if (S_isDay)
        glColor3f(0.58f, 0.29f, 0.0f);
    else
        glColor3f(0.25f, 0.12f, 0.02f);

    glVertex2i(465+t,397);
    glVertex2i(487+t,397);
    glVertex2i(487+t,345);
    glVertex2i(465+t,345);
    glEnd();

    glBegin(GL_POLYGON); // bodyr nicha
    if (S_isDay)
        glColor3f(0.58f, 0.29f, 0.0f);
    else
        glColor3f(0.25f, 0.12f, 0.02f);

    glVertex2i(540+8,345);
    glVertex2i(525+8,327);
    glVertex2i(551+8,335);
    glVertex2i(577+8,327);
    glVertex2i(562+8,345);
    glEnd();

    if (S_isDay)
        glColor3f(0.13f, 0.54f, 0.13f);
    else
        glColor3f(0.05f, 0.25f, 0.05f);

    circle(447+t,402,20);
    circle(450+t,422,20);
    circle(458+t,439,17);
    circle(475+t,443,20);
    circle(490+t,441,15);
    circle(505+t,400,20);
    circle(502+t,420,20);
    circle(475+t,415,20);


    // //left tree/////////////////////////////

    int k=270;
    int f=85;
    int j=345;

    if (S_isDay)
        glColor3f(0.13f, 0.54f, 0.13f);
    else
        glColor3f(0.05f, 0.25f, 0.05f);

    circle(447-k,402-f,20);
    circle(450-k,422-f,20);
    circle(458-k,439-f,17);
    circle(475-k,443-f,20);
    circle(490-k,441-f,15);
    circle(505-k,400-f,20);
    circle(502-k,420-f,20);
    circle(475-k,415-f,20);


    glBegin(GL_QUADS); // right tree body
    if (S_isDay)
        glColor3f(0.58f, 0.29f, 0.0f);
    else
        glColor3f(0.25f, 0.12f, 0.02f);

    glVertex2i(465-k,397-f);
    glVertex2i(487-k,397-f);
    glVertex2i(487-k,345-f);
    glVertex2i(465-k,345-f);
    glEnd();

    glBegin(GL_POLYGON); // bodyr nicha
    if (S_isDay)
        glColor3f(0.58f, 0.29f, 0.0f);
    else
        glColor3f(0.25f, 0.12f, 0.02f);

    glVertex2i(540-j,345-f);
    glVertex2i(525-j,327-f);
    glVertex2i(551-j,335-f);
    glVertex2i(577-j,327-f);
    glVertex2i(562-j,345-f);
    glEnd();

    /////////akdom left tree//////

    int i=450;
    int w=55;
    int a=525;



    if (S_isDay)
        glColor3f(0.13f, 0.54f, 0.13f);
    else
        glColor3f(0.05f, 0.25f, 0.05f);

    circle(447-i,402-w,20);
    circle(450-i,422-w,20);
    circle(458-i,439-w,17);
    circle(475-i,443-w,20);
    circle(490-i,441-w,15);
    circle(505-i,400-w,20);
    circle(502-i,420-w,20);
    circle(475-i,415-w,20);


    glBegin(GL_QUADS); // right tree body
    if (S_isDay)
        glColor3f(0.58f, 0.29f, 0.0f);
    else
        glColor3f(0.25f, 0.12f, 0.02f);

    glVertex2i(465-i,397-w);
    glVertex2i(487-i,397-w);
    glVertex2i(487-i,345-w);
    glVertex2i(465-i,345-w);
    glEnd();

    glBegin(GL_POLYGON); // bodyr nicha
    if (S_isDay)
        glColor3f(0.58f, 0.29f, 0.0f);
    else
        glColor3f(0.25f, 0.12f, 0.02f);

    glVertex2i(540-a,345-w);
    glVertex2i(525-a,327-w);
    glVertex2i(551-a,335-w);
    glVertex2i(577-a,327-w);
    glVertex2i(562-a,345-w);
    glEnd();




/////////////////last right side tree/////////////////////
    int s=430;
    int u=50;

    if (S_isDay)
        glColor3f(0.13f, 0.54f, 0.13f);
    else
        glColor3f(0.05f, 0.25f, 0.05f);

    circle(447+s,402+u,20);
    circle(450+s,422+u,20);
    circle(458+s,439+u,17);
    circle(475+s,443+u,20);
    circle(490+s,441+u,15);
    circle(505+s,400+u,20);
    circle(502+s,420+u,20);
    circle(475+s,415+u,20);


    glBegin(GL_QUADS); // right tree body
    if (S_isDay)
        glColor3f(0.58f, 0.29f, 0.0f);
    else
        glColor3f(0.25f, 0.12f, 0.02f);

    glVertex2i(465+s,397+u);
    glVertex2i(487+s,397+u);
    glVertex2i(487+s,345+u);
    glVertex2i(465+s,345+u);
    glEnd();

    int h=355;
    glBegin(GL_POLYGON); // bodyr nicha
    if (S_isDay)
        glColor3f(0.58f, 0.29f, 0.0f);
    else
        glColor3f(0.25f, 0.12f, 0.02f);

    glVertex2i(540+h,345+u);
    glVertex2i(525+h,327+u);
    glVertex2i(551+h,335+u);
    glVertex2i(577+h,327+u);
    glVertex2i(562+h,345+u);
    glEnd();

}

void Spala()
{

    if (S_isDay)
        glColor3f(0.98f, 0.88f, 0.02f);
    else
        glColor3f(0.49f, 0.44f, 0.01f);

    halfCircle(950,360,55);
    halfCircle(950,390,40);
    halfCircle(950,410,30);
    halfCircle(950,427,20);

    if (S_isDay)
        glColor3f(1.0f, 1.0f, 0.0f);
    else
        glColor3f(0.5f, 0.5f, 0.0f);

    halfCircle(980,360,45);
    halfCircle(980,375,40);
    halfCircle(980,395,30);
    halfCircle(980,412,20);

}
///###river###
void Sriver()
{
    if (S_isDay)
        glColor3f(0.0f, 0.52f, 0.92f);
    else
        glColor3f(0.0f, 0.26f, 0.46f);

    circle(35,-75,610);


    if (S_isDay)
        glColor3f(0.4f, 0.74f, 0.13f);
    else
        glColor3f(0.15f, 0.35f, 0.08f);

    circle(0,0,410);

}

void Sfield()
{
    glLineWidth(3);
    glBegin(GL_LINES);
    if (S_isDay)
        glColor3f(0.89f, 0.70f, 0.27f);
    else
        glColor3f(0.45f, 0.35f, 0.13f);



    int count = 0;
    for(int x = 10; x<380; x+=30)
        for(int y = 115; y>0; y-=30)
        {
            if(count == 0)
            {
                glVertex2f(x,   y);
                glVertex2f(x+10, y-25);

                glVertex2f(x+10, y-25);
                glVertex2f(x+20, y);

                glVertex2f(x+10, y-25);
                glVertex2f(x+10, y);

                count++;
            }
            else
            {
                glVertex2f(x+10,   y);
                glVertex2f(x+20, y-25);

                glVertex2f(x+20, y-25);
                glVertex2f(x+30, y);

                glVertex2f(x+20, y-25);
                glVertex2f(x+20, y);

                count=0;
            }

        }

    glEnd();
}

void Sfootballfield()
{
    if (S_isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(815,60,20);

    if (S_isDay)
        glColor3f(0.4f, 0.74f, 0.13f);
    else
        glColor3f(0.15f, 0.35f, 0.08f);

    circle(815,60,17);

    if (S_isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(815,60,4);

    glLineWidth(3);
    glBegin(GL_LINES);
    if (S_isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);


    glVertex2f(670,15);
    glVertex2f(670,105);

    glVertex2f(670,105);
    glVertex2f(960,105);

    glVertex2f(960,105);
    glVertex2f(960,15);

    glVertex2f(960,15);
    glVertex2f(670,15);

    glVertex2f(815,15);
    glVertex2f(815,105);

    glVertex2f(670,85);
    glVertex2f(710,85);

    glVertex2f(710,85);
    glVertex2f(710,35);

    glVertex2f(710,35);
    glVertex2f(670,35);


    glVertex2f(960,35);
    glVertex2f(920,35);

    glVertex2f(920,35);
    glVertex2f(920,85);


    glVertex2f(920,85);
    glVertex2f(960,85);


    glEnd();

}

float moveScloud1 = 0.0f;
float Scloud1Speed =1.0f;
float savedScloud1Speed = 0.0f;
bool Scloud1Paused = false;


float moveScloud2 = 0.0f;
float Scloud2Speed =1.0f;
float savedScloud2Speed = 0.0f;
bool Scloud2Paused = false;


float moveScloud3 = 0.0f;
float Scloud3Speed =1.0f;
float savedScloud3Speed = 0.0f;
bool Scloud3Paused = false;

void Scloud1() //cloud 1////////////
{

    glPushMatrix();
    glTranslatef(moveScloud1,0,0);

    if (S_isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(720,660,30);
    circle(750,650,30);
    circle(780,660,25);
    circle(750,660,35);
    circle(770,665,35);

    glPopMatrix();
}
void Scloud2()
{
    glPushMatrix();
    glTranslatef(moveScloud2,0,0);

    if (S_isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);
    if (S_isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(550,640,28);
    circle(580,635,28);
    circle(610,640,28);
    circle(565,660,25);
    circle(595,660,25);

    glPopMatrix();

}

void Scloud3()
{
    glPushMatrix();
    glTranslatef(moveScloud3,0,0);

    if (S_isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(250,640,28);
    //circle(280,630,28);
    circle(310,640,28);
    circle(270,660,25);
    circle(300,660,25);
    circle(270,630,25);
    circle(300,630,25);

    glPopMatrix();

}

void updateScloud1(int value)
{
    if(S_isDay)

    {
        if(!Scloud1Paused)
        {

            moveScloud1 += Scloud1Speed;
            if (moveScloud1 > 1000)
            {
                moveScloud1 = -800;
            }

            glutPostRedisplay();
        }
    }
    else
    {
        if(!Scloud1Paused)
        {

            moveScloud1 -= Scloud1Speed+1;
            if (moveScloud1 < -900)
            {
                moveScloud1 = 300;
            }

            glutPostRedisplay();
        }
    }

    glutTimerFunc(25, updateScloud1, 0);
}

void updateScloud2(int value)
{
    moveScloud2 += Scloud2Speed;
    if (moveScloud2 > 1000)
    {
        moveScloud2 = -800;
    }

    glutPostRedisplay();
    glutTimerFunc(25, updateScloud2, 0);
}

void updateScloud3(int value)
{
    moveScloud3 += Scloud3Speed;
    if (moveScloud3 > 1000)
    {
        moveScloud3 = -800;
    }

    glutPostRedisplay();
    glutTimerFunc(25, updateScloud3, 0);
}

//////////////////////////Hill///////////////////////////

void Shill() //HILL
{
    if (S_isDay)
        glColor3f(0.13f, 0.54f, 0.13f);
    else
        glColor3f(0.05f, 0.25f, 0.05f);

    halfCircle(15,530,35);
    halfCircle(45,530,20);
    halfCircle(90,530,35);
    halfCircle(135,530,25);
    halfCircle(180,530,40);
    halfCircle(225,530,27);
    halfCircle(255,530,30);
    halfCircle(300,530,38);

    halfCircle(315,530,15);
    halfCircle(345,530,20);
    halfCircle(390,530,35);
    halfCircle(435,530,25);
    halfCircle(480,530,40);
    halfCircle(525,530,27);
    halfCircle(555,530,30);
    halfCircle(600,530,38);

    halfCircle(615,530,15);
    halfCircle(645,530,20);
    halfCircle(690,530,35);
    halfCircle(735,530,25);
    halfCircle(780,530,40);
    halfCircle(825,530,27);
    halfCircle(855,530,30);
    halfCircle(900,530,38);

    halfCircle(915,530,15);
    halfCircle(945,530,20);
    halfCircle(990,530,35);

}

/// 1st car ////////////////////

float moveScar1 = 0.0f;
float Scar1Speed =1.0f;
float savedScar1Speed = 0.0f;
bool Scar1Paused = false;

float moveScar2 = 0.0f;
float Scar2Speed =1.0f;
float savedScar2Speed = 0.0f;
bool Scar2Paused = false;

void Scar1()
{
    glPushMatrix();
    glTranslatef(moveScar1, 0, 0);

    glBegin(GL_POLYGON); //1st car//////////////////
    //glColor3f(1.f, 1.f, 1.f);
    if (S_isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.5f, 0.0f, 0.0f);

    glVertex2i(100,165);
    glVertex2i(100,180);
    glVertex2i(105,190);
    glVertex2i(193,190);
    glVertex2i(205,185);
    glVertex2i(205,165);


    glBegin(GL_POLYGON); //1st car//////////////////
    if (S_isDay)
        glColor3f(1.0f, 0.0f, 0.0f);
    else
        glColor3f(0.5f, 0.0f, 0.0f);

    glVertex2i(110,185);
    glVertex2i(121,208);
    glVertex2i(170,208);
    glVertex2i(190,185);

    glEnd();


    glBegin(GL_QUADS);//////////glass///////
    if (S_isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);
    glVertex2i(123,190);
    glVertex2i(123,202);
    glVertex2i(145,202);
    glVertex2i(145,190);
    glEnd();


    glBegin(GL_QUADS);/////////////////
    if (S_isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);
    glVertex2i(125,192);
    glVertex2i(125,200);
    glVertex2i(143,200);
    glVertex2i(143,192);
    glEnd();


    glBegin(GL_QUADS);//////////glass///////
    if (S_isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glVertex2i(152,191);
    glVertex2i(152,202);
    glVertex2i(168,202);
    glVertex2i(177,191);
    glEnd();


    glBegin(GL_QUADS);/////////////////
    if (S_isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    glVertex2i(154,189);
    glVertex2i(154,200);
    glVertex2i(166,200);
    glVertex2i(175,189);
    glEnd();


//first car chakka/////////////////////////
    if (S_isDay)
        glColor3f(0.34f, 0.34f, 0.34f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    halfCircle(125,165,10);


    if (S_isDay)
        glColor3f(0.0f, 0.0f, 0.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);

    circle(125,165,9);

    if (S_isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(125,165,3);

    if (S_isDay)
        glColor3f(0.34f, 0.34f, 0.34f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    circle(175,165,10);


    if (S_isDay)
        glColor3f(0.0f, 0.0f, 0.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);

    circle(175,165,9);

    if (S_isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(175,165,3);

    glPopMatrix();
}
void updateScar1(int value)
{
    moveScar1 += Scar1Speed;
    if (moveScar1 > 1000)
    {
        moveScar1 = -800;
    }

    glutPostRedisplay();
    glutTimerFunc(10, updateScar1, 0);
}

/////////////////CAR 2//////////////////////////////

void Scar2()
{
    glPushMatrix();
    glTranslatef(moveScar2, 0, 0);


    glBegin(GL_POLYGON);
    if (S_isDay)
        glColor3f(0.0f, 0.52f, 0.92f);
    else
        glColor3f(0.0f, 0.26f, 0.46f);

    glVertex2i(700,160);
    glVertex2i(700,205);
    glVertex2i(710,215);
    glVertex2i(800,215);
    glVertex2i(830,190);
    glVertex2i(860,188);
    glVertex2i(863,163);
    glVertex2i(860,160);
    glEnd();


    glBegin(GL_QUADS);//////////glass///////
    if (S_isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glVertex2i(715,205);
    glVertex2i(755,205);
    glVertex2i(755,190);
    glVertex2i(715,190);
    glEnd();

    glBegin(GL_QUADS);/////////////////////////////////////////
    if (S_isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    glVertex2i(717,203);
    glVertex2i(753,203);
    glVertex2i(753,192);
    glVertex2i(717,192);
    glEnd();


    glBegin(GL_POLYGON); ///////glass////////////
    if (S_isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(0.15f, 0.07f, 0.03f);

    glVertex2i(775,205);
    glVertex2i(800,205);
    //glVertex2i(805,200);
    glVertex2i(815,190);
    glVertex2i(775,190);


    glBegin(GL_POLYGON); ///////////////////
    if (S_isDay)
        glColor3f(0.27f, 0.28f, 0.29f);
    else
        glColor3f(1.0f, 1.0f, 0.5f);

    glVertex2i(773,203);
    glVertex2i(798,203);
    //glVertex2i(805,200);
    glVertex2i(813,192);
    glVertex2i(773,192);


    glEnd();

    ///////////*****bodyr nicha/////////////

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);

    glVertex2f(700,162);
    //glVertex2f(700,157);
    glVertex2f(863,160);
    glVertex2f(864,162);

    glEnd();


    ///////////bodyr dag///////////////////////

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);

    glVertex2f(762,160);
    glVertex2f(762,210);
    //glVertex2f(863,160);
    //glVertex2f(864,162);

    glEnd();

////////////////////2nd car chakka///////////


    if (S_isDay)
        glColor3f(0.34f, 0.34f, 0.34f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    halfCircle(727,160,12);

    if (S_isDay)
        glColor3f(0.34f, 0.34f, 0.34f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    circle(825,160,12);

    if (S_isDay)
        glColor3f(0.0f, 0.0f, 0.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);

    circle(727,160,10);

    if (S_isDay)
        glColor3f(0.0f, 0.0f, 0.0f);
    else
        glColor3f(0.0f, 0.0f, 0.0f);

    circle(825,160,10);

    if (S_isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(727,160,4);

    if (S_isDay)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.5f, 0.5f, 0.5f);

    circle(825,160,4);

    glPopMatrix();

}

void updateScar2(int value)
{
    moveScar2 += Scar2Speed;
    if (moveScar2 > 1000)
    {
        moveScar2 = -800;
    }

    glutPostRedisplay();
    glutTimerFunc(10, updateScar2, 0);
}

void AhalfCircle(int centerX, int centerY, int radius)
{
    const double pi = M_PI;  // Use predefined pi
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY);  // Center of the half-circle

    for (int i = 60; i <= 240; i++) // Loop from 60° to 240°
    {
        double angle = i * (pi / 180.0);  // Convert degrees to radians
        double x = radius * cos(angle);
        double y = radius * sin(angle);
        glVertex2f(x + centerX, y + centerY);
    }

    glEnd();
}

void clockwiseHalfCircle(int centerX, int centerY, int radius)
{
    const double pi = M_PI;  // Use predefined pi
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY);  // Center of the half-circle

    for (int i = 60; i >= -120; i--) // Loop from 60° to -120° (Clockwise)
    {
        double angle = i * (pi / 180.0);  // Convert degrees to radians
        double x = radius * cos(angle);
        double y = radius * sin(angle);
        glVertex2f(x + centerX, y + centerY);
    }

    glEnd();
}

void ShouseRoad()
{
    if (S_isDay)
        glColor3f(0.97f, 0.74f, 0.19f);
    else
        glColor3f(0.49f, 0.37f, 0.10f);

    clockwiseHalfCircle(730,330,150);

    if (S_isDay)
        glColor3f(0.4f, 0.74f, 0.13f);
    else
        glColor3f(0.15f, 0.35f, 0.08f);

    clockwiseHalfCircle(715,340,90);

    if (S_isDay)
        glColor3f(0.97f, 0.74f, 0.19f);
    else
        glColor3f(0.49f, 0.37f, 0.10f);

    clockwiseHalfCircle(610,280,165);

    if (S_isDay)
        glColor3f(0.4f, 0.74f, 0.13f);
    else
        glColor3f(0.15f, 0.35f, 0.08f);

    clockwiseHalfCircle(610,280,90);

}

void S_mouse(int button, int state, int x, int y)
{
    if(S_isDay)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)   // Pause/resume
        {
            SsunPaused = !SsunPaused;
            if (SsunPaused)
            {
                savedSsunSpeed = SsunSpeed;
                SsunSpeed = 0;
            }
            else
            {
                SsunSpeed = savedSsunSpeed;
            }
        }
    }
    if(S_isDay)
    {
        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)   // Pause/resume
        {
            Scar1Paused = !Scar1Paused;
            if (Scar1Paused)
            {
                savedScar1Speed = Scar1Speed;
                Scar1Speed = 0;
            }
            else
            {
                Scar1Speed = savedScar1Speed;
            }
        }
    }
    if(!S_isDay)
    {
        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        {
            SmoonPaused = !SmoonPaused;
            if (SmoonPaused)
            {
                savedSmoonSpeed = SmoonSpeed;
                SmoonSpeed = 0;
            }
            else
            {
                SmoonSpeed = savedSmoonSpeed;
            }
        }
    }
}

void S_keyboard(unsigned char key, int x, int y)
{
    if (key == 'd' || key == 'D')
    {
        S_isDay = true;
        glutPostRedisplay();
    }
    else if(key == 'n' || key == 'N')
    {
        S_isDay = false;
        glutPostRedisplay();
    }



    if (key == ' ')
    {
        SsunPaused = !SsunPaused;

        if(SsunPaused)
        {
            savedSsunSpeed = SsunSpeed;
            SsunSpeed = 0;
        }
        else
        {
            SsunSpeed = savedSsunSpeed;
        }

        Scloud1Paused = !Scloud1Paused;

        if(Scloud1Paused)
        {
            savedScloud1Speed = Scloud1Speed;
            Scloud1Speed = 0;
        }
        else
        {
            Scloud1Speed = savedScloud1Speed;
        }

        Scloud2Paused = !Scloud2Paused;

        if(Scloud2Paused)
        {
            savedScloud2Speed = Scloud2Speed;
            Scloud2Speed = 0;
        }
        else
        {
            Scloud2Speed = savedScloud2Speed;
        }


        Scloud3Paused = !Scloud3Paused;

        if(Scloud3Paused)
        {
            savedScloud3Speed = Scloud3Speed;
            Scloud3Speed = 0;
        }
        else
        {
            Scloud3Speed = savedScloud3Speed;
        }

        Scar1Paused = !Scar1Paused;

        if(Scar1Paused)
        {
            savedScar1Speed = Scar1Speed;
            Scar1Speed = 0;
        }
        else
        {
            Scar1Speed = savedScar1Speed;
        }

        Scar2Paused = !Scar2Paused;

        if(Scar2Paused)
        {
            savedScar2Speed = Scar2Speed;
            Scar2Speed = 0;
        }
        else
        {
            Scar2Speed = savedScar2Speed;
        }
    }

    if(key == 'm' || key == 'M')
    {
        scenarioTaki = false;
        scenarioMahir = true;
        scenarioTTM = false;
        scenarioTajuar = false;
    }
    if(key == 'a' || key == 'A')
    {
        scenarioTaki = false;
        scenarioMahir = false;
        scenarioTTM = true;
        scenarioTajuar = false;
    }

    if(key == 's' || key == 'S')
    {
        scenarioTajuar = true;
        scenarioTaki = false;
        scenarioMahir = false;
        scenarioTTM = false;
    }

    if(key == 'v' || key == 'V')
    {
        scenarioTaki = true;
        scenarioMahir = false;
        scenarioTTM = false;
        scenarioTajuar = false;
    }

    if(key == 27)
    {
        exit(0);
    }

}
void S_specialKeys(int key, int x, int y)
{
    if(S_isDay)
    {
        switch (key)
    {
    case GLUT_KEY_UP:
        Scar1Speed += 0.2f;
        break;
    case GLUT_KEY_DOWN:
        Scar1Speed -= 0.2f;
        if (Scar1Speed < 0) Scar1Speed = 0;
        break;
    }
    }


    if(!S_isDay)
    {
        switch (key)
    {
    case GLUT_KEY_RIGHT:
        Scar2Speed += 0.2f;
        break;
    case GLUT_KEY_LEFT:
        Scar2Speed -= 0.2f;
        if (Scar2Speed < 0) Scar2Speed = 0;
        break;
    }
    }
}

void Tajuar()
{
    Sbackground();
    ShouseRoad();
    Sriver();
    Ssky();
    Ssun();
    Smoon();
    Stree();
    Spala();
    Shouse();
    Scloud1();
    Scloud2();
    Scloud3();
    Shill();
    Sbridge();
    Scar1();
    Scar2();
    Sfield();
    Sfootballfield();
}
/// =========================================================$$$$$$$$$$$$$$$$$$$$$$$$===================================================================



void selectKeyboard(unsigned char key, int x, int y) {
    if (scenarioTaki)
    {
        keyboard(key, x, y);
    }

    if(scenarioMahir)
    {
        keyboardM(key, x, y);
    }

    if(scenarioTTM)
    {
        keyboardA(key, x, y);
    }

    if (scenarioTajuar)
    {
        S_keyboard(key, x, y);
    }
}

void selectSpecialKeys(int key, int x, int y)
{
    if (scenarioTaki)
    {
        specialKeys(key, x, y);
    }

    if(scenarioMahir)
    {
        specialKeysM(key, x, y);
    }

    if(scenarioTTM)
    {
        specialKeysA(key, x, y);
    }

    if (scenarioTajuar)
    {
        S_specialKeys(key, x, y);
    }
}

void selectMouse(int button, int state, int x, int y)
{
    if (scenarioTaki)
    {
        mouse(button, state, x, y);
    }

    if(scenarioMahir)
    {
        M_mouse(button, state, x, y);
    }

    if(scenarioTTM)
    {
        mouseA(button, state, x, y);
    }

    if (scenarioTajuar)
    {
        S_mouse(button, state, x, y);
    }
}

/// ##############################################################  Display  ###############################################################
void display()
{
    if(scenarioTaki) Taki();
    if(scenarioMahir) Mahir();
    if(scenarioTTM) TTM();
    if(scenarioTajuar) Tajuar();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    cout<<"Press D or d for Day"<<endl;
    cout<<"Press N or n for Night"<<endl;
    cout<<"Press space key to stop everything"<<endl;
    /*cout<<"Press X or x for Next Scenario"<<endl;
    cout<<"Or"<<endl;*/
    cout<<"Press v or V for Main City scenario"<<endl;
    cout<<"Press m or M for Bridge scenario"<<endl;
    cout<<"Press a or A for Sub-City scenario"<<endl;
    cout<<"Press s or S for village scenario"<<endl<<endl;

    cout<<"********** >>>Main City Functionality<<< **********"<<endl;
    cout<<"Press key_up and key_down for Train speed update at day"<<endl;
    cout<<"Press key_left and key_right for Moon speed update at night"<<endl;
    cout<<"Press mouse_left_button to stop and start The Train at day"<<endl;
    cout<<"Press mouse_right_button to stop and start The Sun at day"<<endl;
    cout<<"Press mouse_left_button to stop and start The Moon at night"<<endl;
    cout<<"Press mouse_right_button to stop and start The Cargo Truck at night"<<endl<<endl;


    cout<<"********** >>>Bridge Functionality<<< **********"<<endl;
    cout<<"Press key_up and key_down for Car1 and plane speed update"<<endl;
    cout<<"Press key_left and key_right for Ambulance speed update"<<endl;
    cout<<"Press mouse_left_button to stop car1"<<endl;
    cout<<"Press mouse_right_button to stop the train of night"<<endl<<endl;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000,700);
    glClearColor(0, 0, 0, 1);
    glutInitWindowPosition(200, 50);
    glutCreateWindow("City To Village Traveling");
    gluOrtho2D(0, 1000, 0, 700);
    glutDisplayFunc(display);

    /// Taki
    glutTimerFunc(16, V_updateCloud1, 0);
    glutTimerFunc(16, V_updateCloud2, 0);
    glutTimerFunc(16, V_updateCloud3, 0);
    glutTimerFunc(16, V_updateCloud4, 0);

    glutTimerFunc(2, updateSun, 0);
    glutTimerFunc(16, updateMoon, 0);
    glutTimerFunc(16, updateTrain, 0);
    glutTimerFunc(2, V_updateBus, 0);
    glutTimerFunc(16, V_updateCargo, 0);

    /// Mahir
    glutTimerFunc(16, updateBoat1M, 0);
    glutTimerFunc(10, updateBoat2M, 0);
    glutTimerFunc(16, updateCar1M, 0);
    glutTimerFunc(16, updateSunM, 0);
    glutTimerFunc(8, updateTruckM, 0);
    glutTimerFunc(10, updateTrainM, 0);
    glutTimerFunc(10, updateAmbulanceM, 0);
    glutTimerFunc(16, updateCloud1M, 0);
    glutTimerFunc(16, updateCloud2M, 0);
    glutTimerFunc(16, updateCloud3M, 0);
    glutTimerFunc(19, updateBoat3M, 0);
    glutTimerFunc(16, updatePlaneM, 0);
    glutTimerFunc(10, updateBusM, 0);

    glutTimerFunc(16, updateBoat1_nightM, 0);
    glutTimerFunc(10, updateBoat2_nightM, 0);
    glutTimerFunc(16, updateCar1_nightM, 0);
    glutTimerFunc(16, updateMoonM, 0);
    glutTimerFunc(5, updateTrainM_night, 0);
    glutTimerFunc(20,M_updateCar3_night, 0);
    glutTimerFunc(16, M_updateCar4_night, 0);
    glutTimerFunc(16, updateCloud1M_night, 0);
    glutTimerFunc(18, updateCloud2M_night, 0);

    /// Tajuar
    glutTimerFunc(1, updateScar1, 0);
    glutTimerFunc(1, updateScar2, 0);
    glutTimerFunc(1, updateScloud1, 0);
    glutTimerFunc(1, updateScloud2, 0);
    glutTimerFunc(1, updateScloud3, 0);
    glutTimerFunc(1, S_updateSun, 0);
    glutTimerFunc(16, S_updateMoon, 0);

    /// TTM
    glutTimerFunc(16, updateBirdA, 0);
    glutTimerFunc(20, updateCarA, 0);
    glutTimerFunc(16, updatetruckA,0);
    glutTimerFunc(17, updateBusA, 0);
    glutTimerFunc(16, updateSunA, 0);
    glutTimerFunc(10, updateCloudA,0);

    glutKeyboardFunc(selectKeyboard);
    glutSpecialFunc(selectSpecialKeys);
    glutMouseFunc(selectMouse);

    glutMainLoop();

    return 0;
}
