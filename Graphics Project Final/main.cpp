#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <mmsystem.h>
#include <stdlib.h>
#include <string.h>
#pragma comment(lib, "winmm.lib")
#define PI 3.14159265358979323846f

enum { SC_COVER=0, SC_CODE2=1, SC_CODE3=2, SC_CODE4=3, SC_CODE5=4, SC_CODE5B=5 };
int CURRENT_SCENE = SC_COVER;

void Cover_start() {}
void Cover_stop() {}
void Cover_display();
void Cover_onKey(unsigned char, int, int) {}

void NS2_start(); void NS2_stop(); void NS2_display(); void NS2_onKey(unsigned char,int,int);
void NS3_start(); void NS3_stop(); void NS3_display(); void NS3_onKey(unsigned char,int,int);
void NS4_start(); void NS4_stop(); void NS4_display(); void NS4_onKey(unsigned char,int,int);
void NS5_start(); void NS5_stop(); void NS5_display(); void NS5_onKey(unsigned char,int,int);
void NS6_start(); void NS6_stop(); void NS6_display(); void NS6_onKey(unsigned char,int,int);


inline void StopAllSounds(){ PlaySound(NULL,NULL,0); }

void SwitchScene(int sc){
    // stop old
    switch(CURRENT_SCENE){
        case SC_COVER: Cover_stop(); break;
        case SC_CODE2: NS2_stop(); break;
        case SC_CODE3: NS3_stop(); break;
        case SC_CODE4: NS4_stop(); break;
        case SC_CODE5: NS5_stop(); break;
        case SC_CODE5B: NS6_stop(); break;
    }
    StopAllSounds();
    CURRENT_SCENE = sc;
    // start new
    switch(CURRENT_SCENE){
        case SC_COVER: Cover_start(); break;
        case SC_CODE2: NS2_start(); break;
        case SC_CODE3: NS3_start(); break;
        case SC_CODE4: NS4_start(); break;
        case SC_CODE5: NS5_start(); break;
        case SC_CODE5B: NS6_start(); break;
    }
    glutPostRedisplay();
}

void drawText(float x,float y,float z, void* f, const char* s){
    glRasterPos3f(x,y,z);
    for(const char* c=s; *c; ++c) glutBitmapCharacter(f, *c);
}

void MasterDisplay(){
    switch(CURRENT_SCENE){
        case SC_COVER: Cover_display(); break;
        case SC_CODE2: NS2_display(); break;
        case SC_CODE3: NS3_display(); break;
        case SC_CODE4: NS4_display(); break;
        case SC_CODE5: NS5_display(); break;
        case SC_CODE5B: NS6_display(); break;

    }
    glFlush();
}

void MasterKey(unsigned char key, int x, int y){
    if(key==27){ StopAllSounds(); exit(0); }
    if(key=='0') { SwitchScene(SC_COVER); return; }
    if(key=='1') { SwitchScene(SC_CODE2); return; }
    if(key=='2') { SwitchScene(SC_CODE3); return; }
    if(key=='3') { SwitchScene(SC_CODE4); return; }
    if(key=='4') { SwitchScene(SC_CODE5); return; }
    if(key=='5') { SwitchScene(SC_CODE5B); return; }

    switch(CURRENT_SCENE){
        case SC_COVER: Cover_onKey(key,x,y); break;
        case SC_CODE2: NS2_onKey(key,x,y); break;
        case SC_CODE3: NS3_onKey(key,x,y); break;
        case SC_CODE4: NS4_onKey(key,x,y); break;
        case SC_CODE5: NS5_onKey(key,x,y); break;
    }
}

//Code Start Cover Page
void Cover_display(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f,0.0f,0.5f);
    drawText(-0.60f, 0.90f, 0, GLUT_BITMAP_TIMES_ROMAN_24,
        "AMERICAN INTERNATIONAL UNIVERSITY-BANGLADESH (AIUB)");
    glColor3f(0,0,0);
    drawText(-0.29f, 0.82f, 0, GLUT_BITMAP_HELVETICA_18, "COURSE NAME: COMPUTER GRAPHICS");
    drawText(-0.15f, 0.75f, 0, GLUT_BITMAP_HELVETICA_18, "GRAPHICS PROJECT");
    drawText(-0.14f, 0.68f, 0, GLUT_BITMAP_HELVETICA_18, "SUMMER 2024-2025");
    drawText(-0.08f, 0.61f, 0, GLUT_BITMAP_HELVETICA_18, "SECTION: G");
    drawText(-0.07f, 0.52f, 0, GLUT_BITMAP_HELVETICA_18, "Project Title");
    drawText(-0.31f, 0.44f, 0, GLUT_BITMAP_TIMES_ROMAN_24, "Tourist Spot Of Bangladesh (Museum)");
    drawText(-0.07f, 0.34f, 0, GLUT_BITMAP_HELVETICA_18, "Supervised By");
    drawText(-0.18f, 0.26f, 0, GLUT_BITMAP_TIMES_ROMAN_24, "MAHFUJUR RAHMAN");
    drawText(-0.15f, 0.01f, 0, GLUT_BITMAP_HELVETICA_18, "Submitted By:");

    // simple table
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.9f,-0.05f); glVertex2f(0.9f,-0.05f);
        glVertex2f(0.9f,-0.95f);  glVertex2f(-0.9f,-0.95f);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(-0.7f,-0.05f); glVertex2f(-0.7f,-0.95f);
        glVertex2f(-0.2f,-0.05f); glVertex2f(-0.2f,-0.95f);
        glVertex2f( 0.4f,-0.05f); glVertex2f( 0.4f,-0.95f);
    glEnd();
    float ys[] = {-0.20f,-0.35f,-0.50f,-0.65f,-0.80f,-0.95f};
    for(int i=0;i<6;i++){ glBegin(GL_LINES); glVertex2f(-0.9f,ys[i]); glVertex2f(0.9f,ys[i]); glEnd(); }
    drawText(-0.85f,-0.10f,0,GLUT_BITMAP_HELVETICA_18,"Sl No.");
    drawText(-0.65f,-0.10f,0,GLUT_BITMAP_HELVETICA_18,"Name");
    drawText(-0.15f,-0.10f,0,GLUT_BITMAP_HELVETICA_18,"ID");
    drawText( 0.45f,-0.10f,0,GLUT_BITMAP_HELVETICA_18,"Contribution");
    drawText(-0.85f,-0.25f,0,GLUT_BITMAP_HELVETICA_18,"1");
    drawText(-0.65f,-0.25f,0,GLUT_BITMAP_HELVETICA_18,"MD. FUAD ABDULLAH");
    drawText(-0.15f,-0.25f,0,GLUT_BITMAP_HELVETICA_18,"23-50542-1");
    drawText( 0.45f,-0.25f,0,GLUT_BITMAP_HELVETICA_18,"1st Window");
    drawText(-0.85f,-0.40f,0,GLUT_BITMAP_HELVETICA_18,"2");
    drawText(-0.65f,-0.40f,0,GLUT_BITMAP_HELVETICA_18,"MASHFIKA TABASSUM TISHA");
    drawText(-0.15f,-0.40f,0,GLUT_BITMAP_HELVETICA_18,"23-50533-1");
    drawText( 0.45f,-0.40f,0,GLUT_BITMAP_HELVETICA_18,"2nd Window");
    drawText(-0.85f,-0.55f,0,GLUT_BITMAP_HELVETICA_18,"3");
    drawText(-0.65f,-0.55f,0,GLUT_BITMAP_HELVETICA_18,"MISBAHUN HUMAIRA AKHI");
    drawText(-0.15f,-0.55f,0,GLUT_BITMAP_HELVETICA_18,"23-50554-1");
    drawText( 0.45f,-0.55f,0,GLUT_BITMAP_HELVETICA_18,"3rd Window");
    drawText(-0.85f,-0.70f,0,GLUT_BITMAP_HELVETICA_18,"4");
    drawText(-0.65f,-0.70f,0,GLUT_BITMAP_HELVETICA_18,"SAYMON HASSAN");
    drawText(-0.15f,-0.70f,0,GLUT_BITMAP_HELVETICA_18,"23-50519-1");
    drawText( 0.45f,-0.70f,0,GLUT_BITMAP_HELVETICA_18,"4th Window");
    drawText(-0.85f,-0.85f,0,GLUT_BITMAP_HELVETICA_18,"5");
    drawText(-0.65f,-0.85f,0,GLUT_BITMAP_HELVETICA_18,"SAIMOON KABIR JIHAN");
    drawText(-0.15f,-0.85f,0,GLUT_BITMAP_HELVETICA_18,"22-49686-3");
    drawText( 0.45f,-0.85f,0,GLUT_BITMAP_HELVETICA_18,"5th Window");

}






//Code Start Fuad

namespace NS2 {
#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <math.h>
#define PI 3.14159265358979323846
#include <mmsystem.h> // PlaySound

bool carPaused = false;
bool busPaused = false;

void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c;
    glRasterPos3f(x,y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}
//RoofTop Curve
void drawRoofCap(float startX, float startY, float endX, float endY, int segments) {
    float dx = endX - startX;
    float dy = endY - startY;
    float length = sqrtf(dx*dx + dy*dy);
    float radius = length * 0.5f;
    float angleDeg = atan2f(dy, dx) * 180.0f / PI;

    glPushMatrix();
    glTranslatef((startX + endX) * 0.5f, (startY + endY) * 0.5f, 0.0f); // midpoint
    glRotatef(angleDeg, 0.0f, 0.0f, 1.0f);

    // fill
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f);                // circle center
        for (int i = 0; i <= segments; ++i) {
            float t = PI - (PI * i) / segments;
            glVertex2f(radius * cosf(t), radius * sinf(t));
        }
    glEnd();

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_LINE_STRIP);
        for (int i = 0; i <= segments; ++i) {
            float t = PI - (PI * i) / segments;
            glVertex2f(radius * cosf(t), radius * sinf(t));
        }
    glEnd();

    glPopMatrix();
}


//Clouds
void drawCircle(float cx, float cy, float r, int seg){
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for(int i=0;i<=seg;i++){
        float a = 2.0f*PI*i/seg;
        glVertex2f(cx + r*cosf(a), cy + r*sinf(a));
    }
    glEnd();
}

void drawCloudA(float x, float y, float s, int seg){
    glColor3f(1.0f, 1.0f, 1.0f);
    // top bubbles
    drawCircle(x-0.22f*s, y+0.01f*s, 0.12f*s, seg);
    drawCircle(x-0.06f*s, y+0.06f*s, 0.15f*s, seg);
    drawCircle(x+0.12f*s, y+0.06f*s, 0.14f*s, seg);
    drawCircle(x+0.27f*s, y+0.01f*s, 0.11f*s, seg);
    // bottom puffs
    drawCircle(x-0.10f*s, y-0.07f*s, 0.09f*s, seg);
    drawCircle(x+0.08f*s, y-0.07f*s, 0.09f*s, seg);
    // flat-ish bottom fill
    glBegin(GL_QUADS);
    glVertex2f(x-0.24f*s, y-0.10f*s);
    glVertex2f(x+0.30f*s, y-0.10f*s);
    glVertex2f(x+0.30f*s, y-0.02f*s);
    glVertex2f(x-0.24f*s, y-0.02f*s);
    glEnd();
}

void drawCloudB(float x, float y, float s, int seg){
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x-0.26f*s, y+0.02f*s, 0.12f*s, seg);
    drawCircle(x-0.08f*s, y+0.07f*s, 0.14f*s, seg);
    drawCircle(x+0.12f*s, y+0.07f*s, 0.14f*s, seg);
    drawCircle(x+0.30f*s, y+0.02f*s, 0.10f*s, seg);
    drawCircle(x+0.40f*s, y+0.03f*s, 0.06f*s, seg);
    drawCircle(x-0.10f*s, y-0.06f*s, 0.09f*s, seg);
    drawCircle(x+0.08f*s, y-0.06f*s, 0.09f*s, seg);
    glBegin(GL_QUADS);
    glVertex2f(x-0.28f*s, y-0.10f*s);
    glVertex2f(x+0.38f*s, y-0.10f*s);
    glVertex2f(x+0.38f*s, y-0.02f*s);
    glVertex2f(x-0.28f*s, y-0.02f*s);
    glEnd();
}

// --- Animation state ---
float busX = -1.20f;
float carX =  1.20f;
float busSpeed = 0.0062f;
float carSpeed = 0.0060f;
float carScale = 0.75f;
const float BUS_MIN = -1.00f;   // leftmost
const float BUS_MAX = -0.57f;   // rightmost
const float CAR_MIN =  0.43f;   // leftmost
const float CAR_MAX =  1.01f;   // rightmost
const float CAR_CX  =  0.72f;

bool isNight = false;

static bool __active = false;

void update(int){
    if(!__active) return;
    //Bus Left to Right
    if (!busPaused) {
        busX += busSpeed;
        if ((busX + BUS_MAX) >= 1.0f) {
            busX = -1.0f - BUS_MIN;
        }
    }
    //Car Right to Left
    if (!carPaused) {
        carX -= carSpeed;
        float carScaledMin = CAR_CX + carScale * (CAR_MIN - CAR_CX);
        float carScaledMax = CAR_CX + carScale * (CAR_MAX - CAR_CX);
        if ((carX + carScaledMin) <= -1.0f) {
            carX = 1.0f - carScaledMax;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 'd': case 'D':
            isNight = false;
            PlaySound(NULL, NULL, 0);
            break;
        case 'n': case 'N':
            isNight = true;
            PlaySound(TEXT("night.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
            break;
        case 'c': case 'C': carPaused = !carPaused; break;
        case 'b': case 'B': busPaused = !busPaused; break;
    }
    glutPostRedisplay();
}

void drawStars() {
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.90f, 0.90f); glVertex2f(-0.70f, 0.82f);
    glVertex2f(-0.55f, 0.95f); glVertex2f(-0.35f, 0.88f);
    glVertex2f(-0.15f, 0.92f); glVertex2f( 0.05f, 0.85f);
    glVertex2f( 0.22f, 0.95f); glVertex2f( 0.40f, 0.88f);
    glVertex2f( 0.62f, 0.93f); glVertex2f( 0.80f, 0.86f);
    glEnd();
}


void display() {

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    float skyR   = isNight ? 0.05f : 0.53f;
    float skyG   = isNight ? 0.08f : 0.81f;
    float skyB   = isNight ? 0.18f : 0.98f;
    float grassR = 0.0f;
    float grassG = isNight ? 0.35f : 0.60f;
    float grassB = 0.0f;
    float roadR  = isNight ? 0.20f : 0.30f;
    float roadG  = isNight ? 0.20f : 0.30f;
    float roadB  = isNight ? 0.20f : 0.30f;

//Road
    glColor3f(roadR, roadG, roadB);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.675f);
    glVertex2f(1.0f, -0.675f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    // Road divider
    glColor3f(1.0f, 1.0f, 1.0f);

    // 1st divider
    glBegin(GL_QUADS);
    glVertex2f(-0.8f, -0.80f);
    glVertex2f(-0.65f, -0.80f);
    glVertex2f(-0.65f, -0.85f);
    glVertex2f(-0.8f, -0.85f);
    glEnd();

    // 2nd divider
    glBegin(GL_QUADS);
    glVertex2f(-0.45f, -0.80f);
    glVertex2f(-0.30f, -0.80f);
    glVertex2f(-0.30f, -0.85f);
    glVertex2f(-0.45f, -0.85f);
    glEnd();

    // 3rd divider
    glBegin(GL_QUADS);
    glVertex2f(-0.1f, -0.80f);
    glVertex2f( 0.05f, -0.80f);
    glVertex2f( 0.05f, -0.85f);
    glVertex2f(-0.1f, -0.85f);
    glEnd();

    // 4th divider
    glBegin(GL_QUADS);
    glVertex2f(0.25f, -0.80f);
    glVertex2f(0.40f, -0.80f);
    glVertex2f(0.40f, -0.85f);
    glVertex2f(0.25f, -0.85f);
    glEnd();

    // 5th divider
    glBegin(GL_QUADS);
    glVertex2f(0.60f, -0.80f);
    glVertex2f(0.75f, -0.80f);
    glVertex2f(0.75f, -0.85f);
    glVertex2f(0.60f, -0.85f);
    glEnd();


    // Sky
    glColor3f(skyR, skyG, skyB);

    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.675f);
    glVertex2f(1.0f, -0.675f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
    if (isNight) {
    glColor3f(1.0f, 1.0f, 1.0f);   // white stars
    glPointSize(2.0f);             // star size

    glBegin(GL_POINTS);
    glVertex2f(-0.9f, 0.9f);
    glVertex2f(-0.7f, 0.85f);
    glVertex2f(-0.5f, 0.95f);
    glVertex2f(-0.3f, 0.80f);
    glVertex2f(-0.1f, 0.92f);

    glVertex2f( 0.1f, 0.88f);
    glVertex2f( 0.3f, 0.95f);
    glVertex2f( 0.5f, 0.90f);
    glVertex2f( 0.7f, 0.85f);
    glVertex2f( 0.9f, 0.93f);

    glVertex2f(-0.8f, 0.7f);
    glVertex2f(-0.6f, 0.75f);
    glVertex2f(-0.4f, 0.72f);
    glVertex2f(-0.2f, 0.78f);
    glVertex2f( 0.0f, 0.73f);

    glVertex2f( 0.2f, 0.76f);
    glVertex2f( 0.4f, 0.72f);
    glVertex2f( 0.6f, 0.74f);
    glVertex2f( 0.8f, 0.77f);
    glVertex2f( 0.95f,0.71f);
    glEnd();
    }

    if (isNight) drawStars();

    //Grass
    glColor3f(grassR, grassG, grassB);

    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(1.0f, -0.675f);
    glVertex2f(-1.0f, -0.675f);
    glEnd();



    //Building
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
    glVertex2f(0.1f, -0.5f);
    glVertex2f(0.1f, 0.625f);
    glVertex2f(0.52f, 0.625f);
    glVertex2f(0.52f, -0.5f);
    glEnd();

    //Cut Building Roof
    glColor3f(skyR, skyG, skyB);
    glBegin(GL_QUADS);
    glVertex2f(0.16f, 0.625f);
    glVertex2f(0.22f, 0.55f);
    glVertex2f(0.4f, 0.55f);
    glVertex2f(0.46f, 0.625f);
    glEnd();

    //1st Empty
    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(0.14f, -0.2f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.2f, -0.5f);
    glVertex2f(0.14f,-0.5f);
    glEnd();

     //2nd Empty
    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(0.22f, -0.2f);
    glVertex2f(0.28f, -0.2f);
    glVertex2f(0.28f, -0.5f);
    glVertex2f(0.22f,-0.5f);
    glEnd();

     //3rd Empty
    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(0.3f, -0.2f);
    glVertex2f(0.36f, -0.2f);
    glVertex2f(0.36f, -0.5f);
    glVertex2f(0.3f,-0.5f);
    glEnd();

     //4th Empty
    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(0.38f, -0.2f);
    glVertex2f(0.44f, -0.2f);
    glVertex2f(0.44f, -0.5f);
    glVertex2f(0.38f,-0.5f);
    glEnd();


    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.1f, 0.475f);
    glVertex2f(-0.1f, 0.55f);
    glVertex2f(-0.1f, -0.5f);
    glVertex2f(0.1f,-0.5f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.1f, 0.475f);
    glVertex2f(0.1f, -0.5f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.1f, 0.55f);
    glVertex2f(-0.74f, 0.375f);
    glVertex2f(-0.74f, -0.5f);
    glVertex2f(-0.1f,-0.5f);
    glEnd();


    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.1f, 0.55f);
    glVertex2f(-0.1f,-0.5f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.08f, -0.05f);
    glVertex2f(0.08f,-0.025f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.08f, -0.05f);
    glVertex2f(-0.08f,-0.5f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.08f, -0.025f);
    glVertex2f(0.08f,-0.5f);
    glEnd();


    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(-0.08f, -0.15f);
    glVertex2f(0.08f, -0.15f);
    glVertex2f(0.08f, -0.2f);
    glVertex2f(-0.08f,-0.2f);
    glEnd();


    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.26f, 0.5f);
    glVertex2f(-0.26f,-0.5f);
    glEnd();


    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.42f, 0.46f);
    glVertex2f(-0.42f,-0.5f);
    glEnd();


    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.58f, 0.422f);
    glVertex2f(-0.58f,-0.5f);
    glEnd();


    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.08f, -0.25f);
    glVertex2f(0.06f,-0.25f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.06f,-0.25f);
    glVertex2f(0.06f,-0.5f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f,-0.25f);
    glVertex2f(0.0f,-0.5f);
    glEnd();


    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(-0.26f, 0.125f);
    glVertex2f(-0.1f, 0.125f);
    glVertex2f(-0.1f, 0.05f);
    glVertex2f(-0.26f,0.05f);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(-0.42f, 0.125f);
    glVertex2f(-0.28f, 0.125f);
    glVertex2f(-0.28f, 0.05f);
    glVertex2f(-0.42f,0.05f);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(-0.58f, 0.125f);
    glVertex2f(-0.44f, 0.125f);
    glVertex2f(-0.44f, 0.05f);
    glVertex2f(-0.58f,0.05f);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(-0.74f, 0.125f);
    glVertex2f(-0.6f, 0.125f);
    glVertex2f(-0.6f, 0.05f);
    glVertex2f(-0.74f,0.05f);
    glEnd();


    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.1f,-0.075f);
    glVertex2f(-0.74f,-0.075f);
    glEnd();


    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.12f,-0.075f);
    glVertex2f(-0.12f,-0.5f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.74f,-0.075f);
    glVertex2f(-0.74f,-0.5f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.74f,-0.075f);
    glVertex2f(-0.74f,-0.5f);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(-0.74f, -0.15f);
    glVertex2f(-0.6f, -0.15f);
    glVertex2f(-0.6f, -0.2f);
    glVertex2f(-0.74f,-0.2f);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(-0.58f, -0.15f);
    glVertex2f(-0.44f, -0.15f);
    glVertex2f(-0.44f, -0.2f);
    glVertex2f(-0.58f,-0.2f);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(-0.42f, -0.15f);
    glVertex2f(-0.28f, -0.15f);
    glVertex2f(-0.28f, -0.2f);
    glVertex2f(-0.42f,-0.2f);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(-0.26f, -0.15f);
    glVertex2f(-0.12f, -0.15f);
    glVertex2f(-0.12f, -0.2f);
    glVertex2f(-0.26f,-0.2f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(0.5f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.5f, -0.2f);
    glVertex2f(-0.18f, -0.2f);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(-0.7f,-0.3f);
    glEnd();


    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(0.5f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(-0.18f, -0.2f);
    glVertex2f(-0.18f, -0.3f);
    glVertex2f(-0.3f,-0.4f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(0.5f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.7f,-0.3f);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(-0.3f, -0.4f);
    glVertex2f(-0.7f,-0.4f);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(-0.14f, -0.25f);
    glVertex2f(-0.14f, -0.5f);
    glVertex2f(-0.18f, -0.5f);
    glVertex2f(-0.18f,-0.25f);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(-0.2f, -0.3f);
    glVertex2f(-0.18f, -0.3f);
    glVertex2f(-0.18f, -0.5f);
    glVertex2f(-0.2f,-0.5f);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(-0.68f, -0.5f);
    glVertex2f(-0.62f, -0.5f);
    glVertex2f(-0.62f, -0.4f);
    glVertex2f(-0.68f,-0.4f);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(-0.54f, -0.5f);
    glVertex2f(-0.44f, -0.5f);
    glVertex2f(-0.44f, -0.4f);
    glVertex2f(-0.54f,-0.4f);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(-0.42f, -0.5f);
    glVertex2f(-0.34f, -0.5f);
    glVertex2f(-0.34f, -0.4f);
    glVertex2f(-0.42f,-0.4f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.56f,-0.5f);
    glVertex2f(0.64f, -0.5f);
    glVertex2f(0.64f, 0.725f);
    glVertex2f(0.56f,0.625f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.56f,0.55f);
    glVertex2f(0.56f, -0.5f);
    glVertex2f(0.52f, -0.5f);
    glVertex2f(0.52f,0.55f);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(0.56f,0.525f);
    glVertex2f(0.56f, 0.4f);
    glVertex2f(0.52f, 0.4f);
    glVertex2f(0.52f,0.525f);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(0.56f,0.35f);
    glVertex2f(0.56f, 0.225f);
    glVertex2f(0.52f, 0.225f);
    glVertex2f(0.52f,0.35f);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(0.56f,0.175f);
    glVertex2f(0.56f, 0.05f);
    glVertex2f(0.52f, 0.05f);
    glVertex2f(0.52f,0.175f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.7f,0.6f);
    glVertex2f(0.7f, -0.5f);
    glVertex2f(0.64f, -0.5f);
    glVertex2f(0.64f,0.575f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.64f,0.575f);
    glVertex2f(0.64f, -0.5f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.7f,0.6f);
    glVertex2f(0.9f, 0.25f);
    glVertex2f(0.9f, -0.5f);
    glVertex2f(0.7f,-0.5f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.7f,0.6f);
    glVertex2f(0.7f, -0.5f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.52f,0.55f);
    glVertex2f(0.52f,-0.5f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.56f,0.55f);
    glVertex2f(0.56f,-0.5f);
    glEnd();

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(0.64f,-0.025f);
    glVertex2f(0.68f, -0.025f);
    glVertex2f(0.68f, -0.5f);
    glVertex2f(0.64f,-0.5f);
    glEnd();

    //Main Road to Building Road
    glColor3f(0.80f, 0.80f, 0.80f);
    glBegin(GL_QUADS);
    glVertex2f(-0.54f, -0.50f);
    glVertex2f(-0.44f, -0.50f);
    glVertex2f(-0.40f, -0.675f);
    glVertex2f(-0.58f, -0.675f);

    glEnd();

    glColor3f(0.55f, 0.55f, 0.55f);
    glLineWidth(1.5f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.54f, -0.50f);
    glVertex2f(-0.44f, -0.50f);
    glVertex2f(-0.40f, -0.675f);
    glVertex2f(-0.58f, -0.675f);
    glEnd();


    //Tree

    //1st Tree
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
    glVertex2f(-0.795f, -0.675f);
    glVertex2f(-0.745f, -0.675f);
    glVertex2f(-0.745f, -0.500f);
    glVertex2f(-0.795f, -0.500f);
    glEnd();

    glColor3f(0.00f, 0.50f, 0.00f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.85f, -0.500f);
    glVertex2f(-0.69f, -0.500f);
    glVertex2f(-0.77f, -0.320f);
    glEnd();

    glColor3f(0.00f, 0.60f, 0.00f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.84f, -0.430f);
    glVertex2f(-0.70f, -0.430f);
    glVertex2f(-0.77f, -0.230f);
    glEnd();

    glColor3f(0.00f, 0.70f, 0.00f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.83f, -0.360f);
    glVertex2f(-0.71f, -0.360f);
    glVertex2f(-0.77f, -0.120f);
    glEnd();

    //2nd Tree
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
    glVertex2f(-0.90f, -0.675f);
    glVertex2f(-0.86f, -0.675f);
    glVertex2f(-0.86f, -0.100f);
    glVertex2f(-0.90f, -0.100f);
    glEnd();

    glColor3f(0.00f, 0.50f, 0.00f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.01f, -0.100f);
    glVertex2f(-0.75f, -0.100f);
    glVertex2f(-0.88f,  0.090f);
    glEnd();

    glColor3f(0.00f, 0.60f, 0.00f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.98f,  0.010f);
    glVertex2f(-0.78f,  0.010f);
    glVertex2f(-0.88f,  0.210f);
    glEnd();

    glColor3f(0.00f, 0.70f, 0.00f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.95f,  0.120f);
    glVertex2f(-0.81f,  0.120f);
    glVertex2f(-0.88f,  0.330f);
    glEnd();


    //3rd Tree
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
    glVertex2f(0.90f, -0.675f);
    glVertex2f(0.94f, -0.675f);
    glVertex2f(0.94f, -0.510f);
    glVertex2f(0.90f, -0.510f);
    glEnd();

    glColor3f(0.00f, 0.50f, 0.00f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.85f, -0.510f);
    glVertex2f(0.99f, -0.510f);
    glVertex2f(0.92f, -0.340f);
    glEnd();

    glColor3f(0.00f, 0.60f, 0.00f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.86f, -0.440f);
    glVertex2f(0.98f, -0.440f);
    glVertex2f(0.92f, -0.250f);
    glEnd();

    glColor3f(0.00f, 0.70f, 0.00f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.87f, -0.370f);
    glVertex2f(0.97f, -0.370f);
    glVertex2f(0.92f, -0.140f);
    glEnd();

    //WALL & GATE
    // Left wall (up to gate)
    glColor3f(0.70f, 0.70f, 0.70f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.675f);
    glVertex2f(-0.58f, -0.675f);
    glVertex2f(-0.58f, -0.615f);
    glVertex2f(-1.0f, -0.615f);
    glEnd();

    // Right wall (after gate)
    glBegin(GL_QUADS);
    glVertex2f(-0.40f, -0.675f);
    glVertex2f( 1.0f, -0.675f);
    glVertex2f( 1.0f, -0.615f);
    glVertex2f(-0.40f, -0.615f);
    glEnd();

    // Wall top caps
    glColor3f(0.45f, 0.45f, 0.45f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.615f);
    glVertex2f(-0.58f, -0.615f);
    glVertex2f(-0.58f, -0.600f);
    glVertex2f(-1.0f, -0.600f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-0.40f, -0.615f);
    glVertex2f( 1.0f, -0.615f);
    glVertex2f( 1.0f, -0.600f);
    glVertex2f(-0.40f, -0.600f);
    glEnd();

    //wall decorate
    //Left
    glColor3f(0.35f, 0.35f, 0.35f);

    glBegin(GL_LINES); glVertex2f(-0.98f, -0.675f); glVertex2f(-0.98f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f(-0.90f, -0.675f); glVertex2f(-0.90f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f(-0.82f, -0.675f); glVertex2f(-0.82f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f(-0.74f, -0.675f); glVertex2f(-0.74f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f(-0.66f, -0.675f); glVertex2f(-0.66f, -0.600f); glEnd();

    //Right
    glBegin(GL_LINES); glVertex2f(-0.38f, -0.675f); glVertex2f(-0.38f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f(-0.30f, -0.675f); glVertex2f(-0.30f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f(-0.22f, -0.675f); glVertex2f(-0.22f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f(-0.14f, -0.675f); glVertex2f(-0.14f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f(-0.06f, -0.675f); glVertex2f(-0.06f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f( 0.02f, -0.675f); glVertex2f( 0.02f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f( 0.10f, -0.675f); glVertex2f( 0.10f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f( 0.18f, -0.675f); glVertex2f( 0.18f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f( 0.26f, -0.675f); glVertex2f( 0.26f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f( 0.34f, -0.675f); glVertex2f( 0.34f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f( 0.42f, -0.675f); glVertex2f( 0.42f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f( 0.50f, -0.675f); glVertex2f( 0.50f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f( 0.58f, -0.675f); glVertex2f( 0.58f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f( 0.66f, -0.675f); glVertex2f( 0.66f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f( 0.74f, -0.675f); glVertex2f( 0.74f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f( 0.82f, -0.675f); glVertex2f( 0.82f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f( 0.90f, -0.675f); glVertex2f( 0.90f, -0.600f); glEnd();
    glBegin(GL_LINES); glVertex2f( 0.98f, -0.675f); glVertex2f( 0.98f, -0.600f); glEnd();


    //GATE
    glColor3f(0.15f, 0.15f, 0.15f); // dark iron color

    // Left pillar
    glBegin(GL_QUADS);
    glVertex2f(-0.58f, -0.675f);
    glVertex2f(-0.56f, -0.675f);
    glVertex2f(-0.56f, -0.50f);
    glVertex2f(-0.58f, -0.50f);
    glEnd();

    // Right pillar
    glBegin(GL_QUADS);
    glVertex2f(-0.42f, -0.675f);
    glVertex2f(-0.40f, -0.675f);
    glVertex2f(-0.40f, -0.50f);
    glVertex2f(-0.42f, -0.50f);
    glEnd();

    //Gate Design
    //Vertical bars
    glBegin(GL_LINES);
    glVertex2f(-0.56f, -0.675f);
    glVertex2f(-0.56f, -0.50f);
    glVertex2f(-0.54f, -0.675f);
    glVertex2f(-0.54f, -0.50f);
    glVertex2f(-0.52f, -0.675f);
    glVertex2f(-0.52f, -0.50f);
    glVertex2f(-0.50f, -0.675f);
    glVertex2f(-0.50f, -0.50f);
    glVertex2f(-0.48f, -0.675f);
    glVertex2f(-0.48f, -0.50f);
    glVertex2f(-0.46f, -0.675f);
    glVertex2f(-0.46f, -0.50f);
    glVertex2f(-0.44f, -0.675f);
    glVertex2f(-0.44f, -0.50f);
    glVertex2f(-0.42f, -0.675f);
    glVertex2f(-0.42f, -0.50f);
    glEnd();

    //Horizontal bars
    glBegin(GL_LINES);
    glVertex2f(-0.56f, -0.65f);
    glVertex2f(-0.42f, -0.65f);
    glVertex2f(-0.56f, -0.60f);
    glVertex2f(-0.42f, -0.60f);
    glVertex2f(-0.56f, -0.55f);
    glVertex2f(-0.42f, -0.55f);
    glEnd();






    //Car
    // ===== Car (moves right -> left) =====
    glPushMatrix();
    glTranslatef(carX, 0.0f, 0.0f);   // animate

    const float CAR_CX = 0.72f;
    const float CAR_CY = -0.87f;
    glTranslatef(CAR_CX, CAR_CY, 0.0f);
    glScalef(carScale, carScale, 1.0f);
    glTranslatef(-CAR_CX, -CAR_CY, 0.0f);

    // Black top quad
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.59f, -0.775f);
    glVertex2f(0.85f, -0.775f);
    glVertex2f(0.93f, -0.850f);
    glVertex2f(0.51f, -0.850f);
    glEnd();

    // Red body
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.43f, -0.850f);
    glVertex2f(1.01f, -0.850f);
    glVertex2f(1.01f, -0.950f);
    glVertex2f(0.43f, -0.950f);
    glEnd();

    // Wheels
    {
    GLfloat x1 = 0.57f, y1 = -0.95f;
    GLfloat x2 = 0.89f, y2 = -0.95f;
    GLfloat radius = 0.05f; int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x1, y1);
        for (int i=0;i<=triangleAmount;i++)
            glVertex2f(x1 + radius*cos(i*twicePi/triangleAmount),
                       y1 + radius*sin(i*twicePi/triangleAmount));
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x2, y2);
        for (int i=0;i<=triangleAmount;i++)
            glVertex2f(x2 + radius*cos(i*twicePi/triangleAmount),
                       y2 + radius*sin(i*twicePi/triangleAmount));
    glEnd();
    }
    glPopMatrix();


    //Bus
   // ===== Bus (moves left -> right) =====
    glPushMatrix();
    glTranslatef(busX, 0.0f, 0.0f);   // animate

    // Main body (red)
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1.00f, -0.80f);
    glVertex2f(-0.70f, -0.80f);
    glVertex2f(-0.70f, -0.60f);
    glVertex2f(-1.00f, -0.60f);
    glEnd();

    // Roof
    glBegin(GL_QUADS);
    glVertex2f(-1.00f, -0.60f);
    glVertex2f(-0.70f, -0.60f);
    glVertex2f(-0.70f, -0.57f);
    glVertex2f(-1.00f, -0.57f);
    glEnd();

    // Windows
    glColor3f(0.6f, 0.85f, 1.0f);
    // window 1
    glBegin(GL_QUADS);
    glVertex2f(-0.98f, -0.60f);
    glVertex2f(-0.93f, -0.60f);
    glVertex2f(-0.93f, -0.65f);
    glVertex2f(-0.98f, -0.65f);
    glEnd();

    // window 2
    glBegin(GL_QUADS);
    glVertex2f(-0.92f, -0.60f);
    glVertex2f(-0.87f, -0.60f);
    glVertex2f(-0.87f, -0.65f);
    glVertex2f(-0.92f, -0.65f);
    glEnd();

    // window 3
    glBegin(GL_QUADS);
    glVertex2f(-0.86f, -0.60f);
    glVertex2f(-0.81f, -0.60f);
    glVertex2f(-0.81f, -0.65f);
    glVertex2f(-0.86f, -0.65f);
    glEnd();

    // window 4
    glBegin(GL_QUADS);
    glVertex2f(-0.80f, -0.60f);
    glVertex2f(-0.75f, -0.60f);
    glVertex2f(-0.75f, -0.65f);
    glVertex2f(-0.80f, -0.65f);
    glEnd();

    // Half Door (blue)
    glColor3f(0.3f, 0.6f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.74f, -0.60f);
    glVertex2f(-0.70f, -0.60f);
    glVertex2f(-0.70f, -0.70f);
    glVertex2f(-0.74f, -0.70f);
    glEnd();

    // Wheels (smaller)
    glColor3f(0.0f, 0.0f, 0.0f);
    float r = 0.035f; int segments = 40;

    // Back wheel
    float cx1 = -0.95f, cy1 = -0.80f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx1, cy1);
    for (int i = 0; i <= segments; i++) {
    float a = 2 * PI * i / segments;
    glVertex2f(cx1 + r * cosf(a), cy1 + r * sinf(a));
    }
    glEnd();

    // Front wheel
    float cx2 = -0.77f, cy2 = -0.80f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx2, cy2);
    for (int i = 0; i <= segments; i++) {
    float a = 2 * PI * i / segments;
    glVertex2f(cx2 + r * cosf(a), cy2 + r * sinf(a));
    }
    glEnd();

    glPopMatrix();


    //RoofTop Curve
    int seg = 80;

    drawRoofCap(-0.74f, 0.375f, -0.58f, 0.417f, seg); // 1st curve
    drawRoofCap(-0.58f, 0.417f, -0.42f, 0.460f, seg); // 2nd curve
    drawRoofCap(-0.42f, 0.460f, -0.26f, 0.500f, seg); // 3rd curve
    drawRoofCap(-0.26f, 0.500f, -0.10f, 0.550f, seg); // 4th curve

    drawRoofCap(0.7f, 0.6f, 0.78f, 0.460f, seg); // 1st curve
    drawRoofCap(0.78f, 0.460f, 0.82f, 0.375f, seg); // 2nd curve
    drawRoofCap(0.82f, 0.375f, 0.86f, 0.3f, seg); // 3rd curve
    drawRoofCap(0.86f, 0.3f, 0.9f, 0.25f, seg); // 4th curve

    //Cloud
    int cloudSeg = 56;
    // Left side Cloud
    drawCloudA(-0.68f, 0.84f, 0.40f, cloudSeg);
    drawCloudA(-0.33f, 0.84f, 0.50f, cloudSeg);
    // Right side Cloud
    drawCloudA( 0.78f, 0.85f, 0.52f, cloudSeg);


    //Flag
    // Pole (rectangle)
    glColor3f(0.40f, 0.25f, 0.10f);
    glBegin(GL_QUADS);
    glVertex2f(-0.425f, -0.50f);
    glVertex2f(-0.415f, -0.50f);
    glVertex2f(-0.415f,  0.05f);
    glVertex2f(-0.425f,  0.05f);
    glEnd();

    //Flag Green Rectangle
    glColor3f(0.0f, 0.45f, 0.15f);
    glBegin(GL_QUADS);
    glVertex2f(-0.415f,  0.020f);
    glVertex2f(-0.255f,  0.020f);
    glVertex2f(-0.255f, -0.140f);
    glVertex2f(-0.415f, -0.140f);
    glEnd();


    //Flag Red Circle
    glColor3f(0.82f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);

    //Center
    glVertex2f(-0.335f, -0.060f);

    // Approx circle rim
    glVertex2f(-0.295f, -0.060f);
    glVertex2f(-0.2980f, -0.0370f);
    glVertex2f(-0.3067f, -0.0176f);
    glVertex2f(-0.3197f, -0.0046f);
    glVertex2f(-0.335f,  0.0000f);
    glVertex2f(-0.3503f, -0.0046f);
    glVertex2f(-0.3633f, -0.0176f);
    glVertex2f(-0.3720f, -0.0370f);
    glVertex2f(-0.375f, -0.060f);
    glVertex2f(-0.3720f, -0.0830f);
    glVertex2f(-0.3633f, -0.1024f);
    glVertex2f(-0.3503f, -0.1154f);
    glVertex2f(-0.335f, -0.120f);
    glVertex2f(-0.3197f, -0.1154f);
    glVertex2f(-0.3067f, -0.1024f);
    glVertex2f(-0.2980f, -0.0830f);
    glVertex2f(-0.295f, -0.060f);
    glEnd();


    //Text
    glColor3f(0.0f, 0.0f, 0.0f); // black
    renderBitmapString(0.24f, 0.26f, 0.0f, GLUT_BITMAP_HELVETICA_18, (char*)"Bangladesh");
    renderBitmapString(0.20f, 0.20f, 0.0f, GLUT_BITMAP_HELVETICA_18, (char*)"National Museum");






    glFlush();

}
}

// glue
void NS2_start(){ NS2::__active=true; glutTimerFunc(16, NS2::update, 0); }
void NS2_stop(){ NS2::__active=false; PlaySound(NULL,NULL,0); }
void NS2_display(){ NS2::display(); }
void NS2_onKey(unsigned char k,int x,int y){ NS2::handleKeypress(k,x,y); }



//Start Code TISHA
namespace NS3 {
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <mmsystem.h>
#define PI 3.14159265358979323846
#define MAX_RAIN 500

float rain_x[MAX_RAIN];
float rain_y[MAX_RAIN];
bool isRaining = false;

void initRain() {
    for (int i = 0; i < MAX_RAIN; i++) {
        rain_x[i] = (rand() % 200 - 100) / 100.0f;
        rain_y[i] = (rand() % 200) / 100.0f;
    }
}
void startRainSound() { PlaySound(TEXT("rain.wav"), NULL, SND_ASYNC | SND_LOOP); }
void stopRainSound() { PlaySound(NULL, 0, 0); }

void drawRain() {
    glColor3f(0.6f, 0.6f, 0.9f);
    glBegin(GL_LINES);
    for (int i = 0; i < MAX_RAIN; i++) {
        glVertex2f(rain_x[i], rain_y[i]);
        glVertex2f(rain_x[i], rain_y[i] - 0.05f);
    }
    glEnd();
}
void updateRain() {
    if (isRaining) {
        for (int i = 0; i < MAX_RAIN; i++) {
            rain_y[i] -= 0.02f;
            if (rain_y[i] < -1.0f) {
                rain_y[i] = 1.0f + (rand() % 100) / 100.0f;
                rain_x[i] = (rand() % 200 - 100) / 100.0f;
            }
        }
    }
    glutPostRedisplay();
}

void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

//Cloud helpers
void drawCircle(float cx, float cy, float r, int seg){
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for(int i=0;i<=seg;i++){
        float a = 2.0f*PI*i/seg;
        glVertex2f(cx + r*cosf(a), cy + r*sinf(a));
    }
    glEnd();
}
void drawCloudA(float x, float y, float s, int seg){
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x-0.22f*s, y+0.01f*s, 0.12f*s, seg);
    drawCircle(x-0.06f*s, y+0.06f*s, 0.15f*s, seg);
    drawCircle(x+0.12f*s, y+0.06f*s, 0.14f*s, seg);
    drawCircle(x+0.27f*s, y+0.01f*s, 0.11f*s, seg);
    drawCircle(x-0.10f*s, y-0.06f*s, 0.09f*s, seg);
    drawCircle(x+0.08f*s, y-0.06f*s, 0.09f*s, seg);
    glBegin(GL_QUADS);
        glVertex2f(x-0.24f*s, y-0.10f*s);
        glVertex2f(x+0.30f*s, y-0.10f*s);
        glVertex2f(x+0.30f*s, y-0.02f*s);
        glVertex2f(x-0.24f*s, y-0.02f*s);
    glEnd();
}
void drawCloudB(float x, float y, float s, int seg){
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x-0.26f*s, y+0.02f*s, 0.12f*s, seg);
    drawCircle(x-0.08f*s, y+0.07f*s, 0.14f*s, seg);
    drawCircle(x+0.12f*s, y+0.07f*s, 0.14f*s, seg);
    drawCircle(x+0.30f*s, y+0.02f*s, 0.10f*s, seg);
    drawCircle(x+0.40f*s, y+0.03f*s, 0.06f*s, seg);
    drawCircle(x-0.10f*s, y-0.06f*s, 0.09f*s, seg);
    drawCircle(x+0.08f*s, y-0.06f*s, 0.09f*s, seg);
    glBegin(GL_QUADS);
        glVertex2f(x-0.28f*s, y-0.10f*s);
        glVertex2f(x+0.38f*s, y-0.10f*s);
        glVertex2f(x+0.38f*s, y-0.02f*s);
        glVertex2f(x-0.28f*s, y-0.02f*s);
    glEnd();
}

//Boat animation
float boatX = 1.2f;
const float BOAT_SPEED = 0.003f;
const float LEFT_LIMIT  = -1.4f;
const float RIGHT_RESET =  1.2f;

void updateBoat(int value) {
    boatX -= BOAT_SPEED;
    if (boatX < LEFT_LIMIT) {
        boatX = RIGHT_RESET;
    }
    glutPostRedisplay();
    glutTimerFunc(15, updateBoat, 0);
}

// Day/Night state
bool isNight = false;
void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'r' || key == 'R') {
        isRaining = !isRaining;
        if (isRaining) startRainSound();
        else           stopRainSound();
        glutPostRedisplay();
    }
    if (key == 'n' || key == 'N') { isNight = true; }
    if (key == 'd' || key == 'D') { isNight = false; }
    if (key == 27) exit(0);
}

void display() {

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);




        //Canel

    glColor3f(isNight ? 0.06f : 0.247f,  // R
          isNight ? 0.20f : 0.624f,  // G
          isNight ? 0.35f : 0.820f); // B

        glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.25f);
        glVertex2f(1.0f, -0.25f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
        glEnd();

      //Boat
     //Boat (right->left animation)
glPushMatrix();
glTranslatef(boatX, 0.0f, 0.0f);

// Boat body
glColor3f(0.3f, 0.3f, 0.3f);
glBegin(GL_QUADS);
    glVertex2f(0.4f, -0.65f);
    glVertex2f(0.8f, -0.65f);
    glVertex2f(0.7f, -0.775f);
    glVertex2f(0.5f, -0.775f);
glEnd();

// Sail
glColor3f(0.0f, 0.3f, 0.3f);
glBegin(GL_TRIANGLES);
    glVertex2f(0.6f, -0.5f);
    glVertex2f(0.7f, -0.65f);
    glVertex2f(0.5f, -0.65f);
glEnd();

glPopMatrix();


     //Field

   glColor3f(isNight ? 0.02f : 0.0f,
          isNight ? 0.25f : 0.8f,
          isNight ? 0.05f : 0.3f);

        glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.0f);
        glVertex2f(1.0f, 0.0f);
        glVertex2f(1.0f, -0.25f);
        glVertex2f(-1.0f, -0.25f);
        glEnd();

        //Sky

   glColor3f(isNight ? 0.02f : 0.53f,
          isNight ? 0.05f : 0.81f,
          isNight ? 0.12f : 0.98f);

        glBegin(GL_QUADS);
        glVertex2f(-1.0f, 1.0f);
        glVertex2f(1.0f, 1.0f);
        glVertex2f(1.0f, 0.0f);
        glVertex2f(-1.0f, 0.0f);
        glEnd();

     //Cloud
    int cloudSeg = 56;
    // Left side Cloud
    drawCloudA(-0.68f, 0.84f, 0.40f, cloudSeg);
    drawCloudA(-0.33f, 0.84f, 0.50f, cloudSeg);
    // Right side Cloud
    drawCloudA( 0.78f, 0.85f, 0.52f, cloudSeg);







        //Building 1
       glColor3f(1.0f, 0.992f, 0.815f);
        glBegin(GL_QUADS);
        glVertex2f(-0.3f, 0.625f);
        glVertex2f(0.3f, 0.625f);
        glVertex2f(0.3f, 0.0f);
        glVertex2f(-0.3f, 0.0f);
        glEnd();

       glColor3f(1.0f, 0.992f, 0.815f);
        glBegin(GL_QUADS);
        glVertex2f(0.3f, 0.625f);
        glVertex2f(0.5f, 0.55f);
        glVertex2f(0.53f, 0.0f);
        glVertex2f(0.3f, 0.0f);
        glEnd();

          glColor3f(0.796f, 0.255f, 0.329f);
        glBegin(GL_QUADS);
        glVertex2f(-0.3f, 0.25f);
        glVertex2f(-0.5f, 0.2f);
        glVertex2f(0.36f, 0.2f);
        glVertex2f(0.36f, 0.25f);
        glEnd();

         glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.36f, 0.6f);
        glVertex2f(0.36f, 0.0f);
         glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.3f, 0.625f);
        glVertex2f(0.3f, 0.0f);
         glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.3f, 0.575f);
        glVertex2f(0.3f, 0.575f);
         glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.3f, 0.575f);
        glVertex2f(0.36f, 0.55f);
         glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.36f, 0.55f);
        glVertex2f(0.5f, 0.5f);
         glEnd();

      //DownDoor1
   glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(-0.26f, 0.15f);
        glVertex2f(-0.22f, 0.15f);
        glVertex2f(-0.22f, 0.0f);
        glVertex2f(-0.26f, 0.0f);
        glEnd();

         //DownDoor2
          glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(-0.2f, 0.15f);
        glVertex2f(-0.16, 0.15f);
        glVertex2f(-0.16f, 0.0f);
        glVertex2f(-0.2f, 0.0f);
        glEnd();

         //DownDoor3
         glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(-0.1f, 0.15f);
        glVertex2f(-0.04f, 0.15f);
        glVertex2f(-0.04f, 0.0f);
        glVertex2f(-0.1f, 0.0f);
        glEnd();

         //DownDoor4
         glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(-0.02f, 0.15f);
        glVertex2f(0.04f, 0.15f);
        glVertex2f(0.04f, 0.0f);
        glVertex2f(-0.02f, 0.0f);
        glEnd();

         //DownDoor5
          glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(0.06f, 0.15f);
        glVertex2f(0.12f, 0.15f);
        glVertex2f(0.12f, 0.0f);
        glVertex2f(0.06f, 0.0f);
        glEnd();

         //DownDoor6
          glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(0.16f, 0.15f);
        glVertex2f(0.2f, 0.15f);
        glVertex2f(0.2f, 0.0f);
        glVertex2f(0.16f, 0.0f);
        glEnd();

         //DownDoor7
         glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(0.22f, 0.15f);
        glVertex2f(0.26f, 0.15f);
        glVertex2f(0.26f, 0.0f);
        glVertex2f(0.22f, 0.0f);
        glEnd();


         //UpDoor1
   glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(-0.26f, 0.425f);
        glVertex2f(-0.22f, 0.425f);
        glVertex2f(-0.22f, 0.25f);
        glVertex2f(-0.26f, 0.25f);
        glEnd();

         //UpDoor2
          glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(-0.2f, 0.425f);
        glVertex2f(-0.16, 0.425f);
        glVertex2f(-0.16f, 0.25f);
        glVertex2f(-0.2f, 0.25f);
        glEnd();

         //UpDoor3
         glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(-0.1f, 0.475f);
        glVertex2f(-0.04f, 0.475f);
        glVertex2f(-0.04f, 0.25f);
        glVertex2f(-0.1f, 0.25f);
        glEnd();

         //UpDoor4
         glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(-0.02f, 0.475f);
        glVertex2f(0.04f, 0.475f);
        glVertex2f(0.04f, 0.25f);
        glVertex2f(-0.02f, 0.25f);
        glEnd();

         //UpDoor5
          glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(0.06f, 0.475f);
        glVertex2f(0.12f, 0.475f);
        glVertex2f(0.12f, 0.25f);
        glVertex2f(0.06f, 0.25f);
        glEnd();

         //UpDoor6
          glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(0.16f, 0.425f);
        glVertex2f(0.2f, 0.425f);
        glVertex2f(0.2f, 0.25f);
        glVertex2f(0.16f, 0.25f);
        glEnd();

         //UpDoor7
         glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(0.22f, 0.425f);
        glVertex2f(0.26f, 0.425f);
        glVertex2f(0.26f, 0.25f);
        glVertex2f(0.22f, 0.25f);
        glEnd();

        //DownLine1
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.28f, 0.0f);
        glVertex2f(-0.28f, 0.2f);
         glEnd();

         //DownLine2
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.14f, 0.0f);
        glVertex2f(-0.14f, 0.2f);
         glEnd();

         //DownLine3
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.12f, 0.0f);
        glVertex2f(-0.12f, 0.2f);
         glEnd();

         //DownLine4
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.14f, 0.0f);
        glVertex2f(0.14f, 0.2f);
         glEnd();

         //DownLine5
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.28f, 0.0f);
        glVertex2f(0.28f, 0.2f);
         glEnd();

         //UpLine1
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.28f, 0.25f);
        glVertex2f(-0.28f, 0.5f);
         glEnd();

       //UpLine2
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.14f, 0.25f);
        glVertex2f(-0.14f, 0.575f);
         glEnd();

      //UpLine3
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.28f, 0.5f);
        glVertex2f(-0.14f, 0.5f);
         glEnd();

      //UpLine4
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.12f, 0.25f);
        glVertex2f(-0.12f, 0.575f);
         glEnd();

         //UpLine5
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.14f, 0.5f);
        glVertex2f(-0.12f, 0.525f);
         glEnd();

         //UpLine6
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.12f, 0.525f);
        glVertex2f(0.14f, 0.525f);
         glEnd();

         //UpLine7
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.14f, 0.25f);
        glVertex2f(0.14f, 0.525f);
         glEnd();

         //UpLine8
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.14f, 0.5f);
        glVertex2f(0.28f, 0.5f);
         glEnd();

         //UpLine9
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.28f, 0.25f);
        glVertex2f(0.28f, 0.5f);
         glEnd();

         //LeftGrill 1
         glColor3f(0.596f, 0.396f, 0.200f);
        glBegin(GL_LINES);
        glVertex2f(-0.26f, 0.325f);
        glVertex2f(-0.22f, 0.325f);
         glEnd();


         //LeftGrill 1
         glColor3f(0.596f, 0.396f, 0.200f);
        glBegin(GL_LINES);
        glVertex2f(-0.24f, 0.25f);
        glVertex2f(-0.24f, 0.325f);
         glEnd();


      //LeftGrill 2
         glColor3f(0.596f, 0.396f, 0.200f);
        glBegin(GL_LINES);
        glVertex2f(-0.2f, 0.325f);
        glVertex2f(-0.16f, 0.325f);
         glEnd();


         //LeftGrill 2
         glColor3f(0.596f, 0.396f, 0.200f);
        glBegin(GL_LINES);
        glVertex2f(-0.18f, 0.25f);
        glVertex2f(-0.18f, 0.325f);
         glEnd();

         //MiddleGrill 1
         glColor3f(0.596f, 0.396f, 0.200f);
        glBegin(GL_LINES);
        glVertex2f(-0.1f, 0.325f);
        glVertex2f(-0.04f, 0.325f);
         glEnd();


         //MiddleGrill 1
         glColor3f(0.596f, 0.396f, 0.200f);
        glBegin(GL_LINES);
        glVertex2f(-0.08f, 0.25f);
        glVertex2f(-0.08f, 0.325f);
         glEnd();

          //MiddleGrill 1
         glColor3f(0.596f, 0.396f, 0.200f);
        glBegin(GL_LINES);
        glVertex2f(-0.06f, 0.25f);
        glVertex2f(-0.06f, 0.325f);
         glEnd();

          //MiddleGrill 2
         glColor3f(0.596f, 0.396f, 0.200f);
        glBegin(GL_LINES);
        glVertex2f(-0.02f, 0.325f);
        glVertex2f(0.04f, 0.325f);
         glEnd();


         //MiddleGrill 2
         glColor3f(0.596f, 0.396f, 0.200f);
        glBegin(GL_LINES);
        glVertex2f(0.0f, 0.25f);
        glVertex2f(0.0f, 0.325f);
         glEnd();

          //MiddleGrill 2
         glColor3f(0.596f, 0.396f, 0.200f);
        glBegin(GL_LINES);
        glVertex2f(0.02f, 0.25f);
        glVertex2f(0.02f, 0.325f);
         glEnd();

           //MiddleGrill 3
         glColor3f(0.596f, 0.396f, 0.200f);
        glBegin(GL_LINES);
        glVertex2f(0.06f, 0.325f);
        glVertex2f(0.12f, 0.325f);
         glEnd();


         //MiddleGrill 3
         glColor3f(0.596f, 0.396f, 0.200f);
        glBegin(GL_LINES);
        glVertex2f(0.08f, 0.25f);
        glVertex2f(0.08f, 0.325f);
         glEnd();

          //MiddleGrill 3
         glColor3f(0.596f, 0.396f, 0.200f);
        glBegin(GL_LINES);
        glVertex2f(0.1f, 0.25f);
        glVertex2f(0.1f, 0.325f);
         glEnd();

          //rightGrill 1
         glColor3f(0.596f, 0.396f, 0.200f);
        glBegin(GL_LINES);
        glVertex2f(0.16f, 0.325f);
        glVertex2f(0.2f, 0.325f);
         glEnd();


         //rightGrill 1
         glColor3f(0.596f, 0.396f, 0.200f);
        glBegin(GL_LINES);
        glVertex2f(0.18f, 0.25f);
        glVertex2f(0.18f, 0.325f);
         glEnd();

          //rightGrill 2
         glColor3f(0.596f, 0.396f, 0.200f);
        glBegin(GL_LINES);
        glVertex2f(0.22f, 0.325f);
        glVertex2f(0.26f, 0.325f);
         glEnd();


         //rightGrill 2
         glColor3f(0.596f, 0.396f, 0.200f);
        glBegin(GL_LINES);
        glVertex2f(0.24f, 0.25f);
        glVertex2f(0.24f, 0.325f);
         glEnd();

         //BuildingUpperPartDesign

         //MostLeftCrown1
          glColor3f(1.0f, 0.992f, 0.815f);
        glBegin(GL_QUADS);
        glVertex2f(-0.30f, 0.675f);
        glVertex2f(-0.28f, 0.675f);
        glVertex2f(-0.28f, 0.625f);
        glVertex2f(-0.30f, 0.625f);
        glEnd();

      glColor3f(1.0f, 0.992f, 0.815f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.29f, 0.72f);
        glVertex2f(-0.26f, 0.675f);
        glVertex2f(-0.32f, 0.675f);
        glEnd();

         //LeftCrown2
          glColor3f(1.0f, 0.992f, 0.815f);
        glBegin(GL_QUADS);
        glVertex2f(-0.14f, 0.65f);
        glVertex2f(-0.12f, 0.65f);
        glVertex2f(-0.12f, 0.625f);
        glVertex2f(-0.14f, 0.625f);
        glEnd();

      glColor3f(1.0f, 0.992f, 0.815f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.13f, 0.7f);
        glVertex2f(-0.11f, 0.65f);
        glVertex2f(-0.15f, 0.65f);
        glEnd();

     //MiddleBigCrown

       glColor3f(1.0f, 0.992f, 0.815f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.0f, 0.75f);
        glVertex2f(0.12f, 0.625f);
        glVertex2f(-0.12f, 0.625f);
        glEnd();

         //MostRightCrown1
          glColor3f(1.0f, 0.992f, 0.815f);
        glBegin(GL_QUADS);
        glVertex2f(0.28f, 0.675f);
        glVertex2f(0.30f, 0.675f);
        glVertex2f(0.30f, 0.625f);
        glVertex2f(0.28f, 0.625f);
        glEnd();

      glColor3f(1.0f, 0.992f, 0.815f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.29f, 0.72f);
        glVertex2f(0.32f, 0.675f);
        glVertex2f(0.26f, 0.675f);
        glEnd();

         //RightCrown2
          glColor3f(1.0f, 0.992f, 0.815f);
        glBegin(GL_QUADS);
        glVertex2f(0.14f, 0.65f);
        glVertex2f(0.12f, 0.65f);
        glVertex2f(0.12f, 0.625f);
        glVertex2f(0.14f, 0.625f);
        glEnd();

      glColor3f(1.0f, 0.992f, 0.815f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.13f, 0.7f);
        glVertex2f(0.11f, 0.65f);
        glVertex2f(0.15f, 0.65f);
        glEnd();



         //left Building1

      glColor3f(0.698f, 0.133f, 0.133f);
        glBegin(GL_QUADS);
        glVertex2f(-0.44f, 0.425f);
        glVertex2f(-0.3f, 0.425f);
        glVertex2f(-0.3f, 0.0f);
        glVertex2f(-0.44f, 0.0f);
        glEnd();

         glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.3f, 0.625f);
        glVertex2f(-0.3f, 0.0);
         glEnd();

     //left Building2
     glColor3f(0.698f, 0.133f, 0.133f);
        glBegin(GL_QUADS);
        glVertex2f(-0.6f, 0.55f);
        glVertex2f(-0.44f, 0.55f);
        glVertex2f(-0.44f, 0.0f);
        glVertex2f(-0.6f, 0.0f);
        glEnd();

         glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.44f, 0.55f);
        glVertex2f(-0.44f, 0.0);
         glEnd();

      //left Building3
         glColor3f(0.698f, 0.133f, 0.133f);
        glBegin(GL_QUADS);
        glVertex2f(-0.8f, 0.525f);
        glVertex2f(-0.6f, 0.55f);
        glVertex2f(-0.6f, 0.0f);
        glVertex2f(-0.8f, 0.0f);
        glEnd();

        //window1
         glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.78f, 0.425f);
        glVertex2f(-0.72f, 0.425f);
        glVertex2f(-0.72f, 0.25f);
        glVertex2f(-0.78f, 0.25f);
        glEnd();

       // window2
         glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.68f, 0.425f);
        glVertex2f(-0.62f, 0.425f);
        glVertex2f(-0.62f, 0.25f);
        glVertex2f(-0.68f, 0.25f);
        glEnd();

        //window3
         glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.68f, 0.175f);
        glVertex2f(-0.62f, 0.175f);
        glVertex2f(-0.62f, 0.025f);
        glVertex2f(-0.68f, 0.025f);
        glEnd();

       //window4
         glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.78f, 0.175f);
        glVertex2f(-0.72f, 0.175f);
        glVertex2f(-0.72f, 0.025f);
        glVertex2f(-0.78f, 0.025f);
        glEnd();

        //lines
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.6f, 0.55f);
       glVertex2f(-0.6f, 0.0f);
         glEnd();


    //left Building4
        glColor3f(0.698f, 0.133f, 0.133f);
        glBegin(GL_QUADS);
        glVertex2f(-1.0f, 0.525f);
        glVertex2f(-0.8f, 0.525f);
        glVertex2f(-0.8f, 0.0f);
        glVertex2f(-1.0f, 0.0f);
        glEnd();

         glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.8f, 0.525f);
       glVertex2f(-0.8f, 0.0f);
         glEnd();

          glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-1.0f, 0.475f);
       glVertex2f(-0.8f, 0.475f);
         glEnd();

          glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.8f, 0.475f);
       glVertex2f(-0.6f, 0.5f);
         glEnd();

          glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.6f, 0.5f);
       glVertex2f(-0.44f, 0.5f);
         glEnd();



        //window1
         glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.98f, 0.425f);
        glVertex2f(-0.92f, 0.425f);
        glVertex2f(-0.92f, 0.25f);
        glVertex2f(-0.98f, 0.25f);
        glEnd();

        //window2
         glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.88f, 0.425f);
        glVertex2f(-0.82f, 0.425f);
        glVertex2f(-0.82f, 0.25f);
        glVertex2f(-0.88f, 0.25f);
        glEnd();


       //window3
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.88f, 0.175f);
        glVertex2f(-0.82f, 0.175f);
        glVertex2f(-0.82f, 0.025f);
        glVertex2f(-0.88f, 0.025f);
        glEnd();

        //window4
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.98f, 0.175f);
        glVertex2f(-0.92f, 0.175f);
        glVertex2f(-0.92f, 0.025f);
        glVertex2f(-0.98f, 0.025f);
        glEnd();



        //BigTree

         glColor3f(0.55f, 0.27f, 0.07f);
        glBegin(GL_QUADS);
        glVertex2f(-0.50f, 0.175f);
        glVertex2f(-0.46f, 0.175f);
        glVertex2f(-0.46f, 0.0f);
        glVertex2f(-0.50f, 0.0f);
        glEnd();

      glColor3f(0.0f, 0.8f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.48f, 0.325f);
        glVertex2f(-0.56f, 0.175f);
        glVertex2f(-0.40f, 0.175f);
        glEnd();

     glColor3f(0.0f, 0.8f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.48f, 0.425f);
        glVertex2f(-0.38f, 0.225f);
        glVertex2f(-0.58f, 0.225f);
        glEnd();

   glColor3f(0.0f, 0.8f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.48f, 0.5f);
        glVertex2f(-0.36f, 0.275f);
        glVertex2f(-0.60f, 0.275f);
        glEnd();


     //RightSmallBuilding

    glColor3f(0.698f, 0.133f, 0.133f);
        glBegin(GL_QUADS);
        glVertex2f(0.4f, 0.225f);
        glVertex2f(0.8f, 0.225f);
        glVertex2f(0.8f, 0.0f);
        glVertex2f(0.4f, 0.0f);
        glEnd();

        //Window1
         glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(0.48f, 0.15f);
        glVertex2f(0.56f, 0.15f);
        glVertex2f(0.56f, 0.05f);
        glVertex2f(0.48f, 0.05f);
        glEnd();

        //Window2
         glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(0.66f, 0.15f);
        glVertex2f(0.74f, 0.15f);
        glVertex2f(0.74f, 0.05f);
        glVertex2f(0.66f, 0.05f);
        glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.4f, 0.225f);
        glVertex2f(0.8f, 0.225);
         glEnd();

    glColor3f(1.98f, 0.81f, 0.02f);
        glBegin(GL_QUADS);
        glVertex2f(0.5f, 0.25f);
        glVertex2f(0.8f, 0.25f);
        glVertex2f(0.8f, 0.225f);
        glVertex2f(0.4f, 0.225f);
        glEnd();



         glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.4f, 0.225f);
        glVertex2f(0.5f, 0.25);
         glEnd();

    //RightBuilding1

     glColor3f(0.698f, 0.133f, 0.133f);
        glBegin(GL_QUADS);
        glVertex2f(0.5f, 0.55f);
        glVertex2f(0.88f, 0.55f);
        glVertex2f(0.88f, 0.25f);
        glVertex2f(0.5f, 0.25f);
        glEnd();


        //Window1
         glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(0.5f, 0.4f);
        glVertex2f(0.56f, 0.4f);
        glVertex2f(0.56f, 0.25f);
        glVertex2f(0.5f, 0.25f);
        glEnd();


        //Lines
     glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.5f, 0.25f);
        glVertex2f(0.8f, 0.25);
         glEnd();

     glColor3f(1.98f, 0.81f, 0.02f);
        glBegin(GL_QUADS);
        glVertex2f(0.88f, 0.55f);
        glVertex2f(1.0f, 0.50f);
        glVertex2f(1.0f, 0.375f);
        glVertex2f(0.88f, 0.375f);
        glEnd();


    glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.88f, 0.55f);
        glVertex2f(0.88f, 0.375f);
         glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.88f, 0.5f);
         glEnd();

         //RightBuilding2

       glColor3f(1.0f, 0.992f, 0.815f);
        glBegin(GL_QUADS);
        glVertex2f(0.8f, 0.375f);
        glVertex2f(1.0f, 0.375f);
        glVertex2f(1.0f, 0.0f);
        glVertex2f(0.8f, 0.0f);
        glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.8f, 0.375f);
        glVertex2f(0.8f, 0.0f);
         glEnd();

          glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.8f, 0.375f);
        glVertex2f(1.0f, 0.375f);
         glEnd();


  //SmallTree

    glColor3f(0.55f, 0.27f, 0.07f);
        glBegin(GL_QUADS);
        glVertex2f(0.89f, 0.15f);
        glVertex2f(0.91f, 0.15f);
        glVertex2f(0.91f, 0.0f);
        glVertex2f(0.89f, 0.0f);
        glEnd();

    glColor3f(0.0f, 0.8f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.90f, 0.275f);
        glVertex2f(0.96f, 0.15f);
        glVertex2f(0.84f, 0.15f);
        glEnd();

  glColor3f(0.0f, 0.8f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.90f, 0.35f);
        glVertex2f(0.98f, 0.2f);
        glVertex2f(0.82f, 0.2f);
        glEnd();

    //Stair
    //step1

     glColor3f(1.98f, 0.81f, 0.02f);
        glBegin(GL_QUADS);
        glVertex2f(-0.3f, -0.1f);
        glVertex2f(0.09f, -0.1f);
        glVertex2f(0.0f, -0.175f);
        glVertex2f(-0.38f, -0.175f);
        glEnd();


         //step2

     glColor3f(1.98f, 0.81f, 0.02f);
        glBegin(GL_QUADS);
        glVertex2f(-0.38f, -0.175f);
        glVertex2f(0.0f, -0.175f);
        glVertex2f(0.0f,- 0.225f);
        glVertex2f(-0.38f, -0.225f);
        glEnd();

         //step3

     glColor3f(1.98f, 0.81f, 0.02f);
        glBegin(GL_QUADS);
        glVertex2f(-0.38f, -0.225f);
        glVertex2f(0.0f, -0.225f);
        glVertex2f(-0.06f, -0.275f);
        glVertex2f(-0.46f, -0.275f);
        glEnd();


   //line s1
    glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.38f, -0.175f);
        glVertex2f(0.0f, -0.175f);
         glEnd();


   //line s2
    glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.38f, -0.225f);
        glVertex2f(0.0f, -0.225f);
         glEnd();


    //step4

     glColor3f(1.98f, 0.81f, 0.02f);
        glBegin(GL_QUADS);
        glVertex2f(-0.46f, -0.275f);
        glVertex2f(-0.06f, -0.275f);
        glVertex2f(-0.06f, -0.325f);
        glVertex2f(-0.46f, -0.325f);
        glEnd();


    //step5

     glColor3f(1.98f, 0.81f, 0.02f);
        glBegin(GL_QUADS);
        glVertex2f(-0.46f,-0.325f);
        glVertex2f(-0.06f,-0.325f);
        glVertex2f(-0.10f, -0.375f);
        glVertex2f(-0.5f,-0.375f);
        glEnd();

         //step6

     glColor3f(1.98f, 0.81f, 0.02f);
        glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.375f);
        glVertex2f(-0.1f, -0.375f);
        glVertex2f(-0.1f, -0.425f);
        glVertex2f(-0.5f,-0.425f);
        glEnd();

      //line s3
    glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.46f, -0.275f);
        glVertex2f(-0.06f, -0.275f);
         glEnd();

            //line s4
    glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.46f, -0.325f);
        glVertex2f(-0.06f, -0.325f);
         glEnd();

            //line s5
    glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
       glVertex2f(-0.5f, -0.375f);
        glVertex2f(-0.1f, -0.375f);
         glEnd();

        //line s6
    glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.5f, -0.425f);
        glVertex2f(-0.1f, -0.425f);
         glEnd();


   //stair side1

    glColor3f(1.98f, 0.81f, 0.02f);
        glBegin(GL_QUADS);
        glVertex2f(0.0f, -0.175f);
        glVertex2f(0.09f, -0.1f);
        glVertex2f(0.09f, -0.25f);
        glVertex2f(0.0f, -0.325f);
        glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);

        glVertex2f(0.09f, -0.1f);
        glVertex2f(0.0f, -0.175f);
         glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.0f, -0.175f);
        glVertex2f(0.0f, -0.225f);
         glEnd();


     //stair side2

    glColor3f(1.98f, 0.81f, 0.02f);
        glBegin(GL_QUADS);
        glVertex2f(-0.06f, -0.275f);
        glVertex2f(0.0f, -0.225f);
        glVertex2f(0.0f, -0.325f);
        glVertex2f(-0.06f, -0.4f);
        glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.06f, -0.275f);
        glVertex2f(0.0f, -0.225f);
         glEnd();

   glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.06f, -0.275f);
        glVertex2f(-0.06f, -0.325f);
         glEnd();

   //stair side 3

    glColor3f(1.98f, 0.81f, 0.02f);
        glBegin(GL_QUADS);
        glVertex2f(-0.1f, -0.375f);
        glVertex2f(-0.06f, -0.325f);
        glVertex2f(-0.06f, -0.4f);
        glVertex2f(-0.1f, -0.425f);
        glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
         glVertex2f(-0.1f, -0.375f);
        glVertex2f(-0.06f, -0.325f);
         glEnd();

   glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.1f, -0.375f);
        glVertex2f(-0.1f, -0.425f);
         glEnd();




    // Rain
    if (isRaining) {
        drawRain();
    }

    glFlush();
}
}

// glue
void NS3_start(){
    NS3::initRain();
    glutIdleFunc(NS3::updateRain);
    glutTimerFunc(0, NS3::updateBoat, 0);
}
void NS3_stop(){
    glutIdleFunc(NULL);
    PlaySound(NULL,NULL,0);
}
void NS3_display(){ NS3::display(); }
void NS3_onKey(unsigned char k,int x,int y){ NS3::handleKeypress(k,x,y); }



//Start Akhi Code
namespace NS4 {
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <mmsystem.h>
#define PI 3.14159265358979323846

float cloudX = 0.0f;
float truckX = 0.0f;
float animationSpeed = 0.0005f;

void update(int value) {
    cloudX += animationSpeed;
    if (cloudX > 1.2f) cloudX = -1.2f;

    truckX -= animationSpeed * 2.5f;

    if (truckX < -2.0f) truckX = 1.8f;
    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c; glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}
void drawCircle(float cx, float cy, float r, int seg){
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for(int i=0;i<=seg;i++){
        float a = 2.0f*PI*i/seg;
        glVertex2f(cx + r*cosf(a), cy + r*sinf(a));
    }
    glEnd();
}
void drawCloudA(float x, float y, float s, int seg){
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x-0.22f*s, y+0.01f*s, 0.12f*s, seg);
    drawCircle(x-0.06f*s, y+0.06f*s, 0.15f*s, seg);
    drawCircle(x+0.12f*s, y+0.06f*s, 0.14f*s, seg);
    drawCircle(x+0.27f*s, y+0.01f*s, 0.11f*s, seg);
    drawCircle(x-0.10f*s, y-0.07f*s, 0.09f*s, seg);
    drawCircle(x+0.08f*s, y-0.07f*s, 0.09f*s, seg);
    glBegin(GL_QUADS);
        glVertex2f(x-0.24f*s, y-0.10f*s);
        glVertex2f(x+0.30f*s, y-0.10f*s);
        glVertex2f(x+0.30f*s, y-0.02f*s);
        glVertex2f(x-0.24f*s, y-0.02f*s);
    glEnd();
}
void drawCloudB(float x, float y, float s, int seg){
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x-0.26f*s, y+0.02f*s, 0.12f*s, seg);
    drawCircle(x-0.08f*s, y+0.07f*s, 0.14f*s, seg);
    drawCircle(x+0.12f*s, y+0.07f*s, 0.14f*s, seg);
    drawCircle(x+0.30f*s, y+0.02f*s, 0.10f*s, seg);
    drawCircle(x+0.40f*s, y+0.03f*s, 0.06f*s, seg);
    drawCircle(x-0.10f*s, y-0.06f*s, 0.09f*s, seg);
    drawCircle(x+0.08f*s, y-0.06f*s, 0.09f*s, seg);
    glBegin(GL_QUADS);
        glVertex2f(x-0.28f*s, y-0.10f*s);
        glVertex2f(x+0.38f*s, y-0.10f*s);
        glVertex2f(x+0.38f*s, y-0.02f*s);
        glVertex2f(x-0.28f*s, y-0.02f*s);
    glEnd();
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Road

glColor3f(0.30f, 0.30f, 0.30f);
glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.675f);
    glVertex2f( 1.0f, -0.675f);
    glVertex2f( 1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
glEnd();

    // Road divider
    glColor3f(1.0f, 1.0f, 1.0f);

    // 1st divider
    glBegin(GL_QUADS);
        glVertex2f(-0.8f, -0.80f);
        glVertex2f(-0.65f, -0.80f);
        glVertex2f(-0.65f, -0.85f);
        glVertex2f(-0.8f, -0.85f);
    glEnd();

    // 2nd divider
    glBegin(GL_QUADS);
        glVertex2f(-0.45f, -0.80f);
        glVertex2f(-0.30f, -0.80f);
        glVertex2f(-0.30f, -0.85f);
        glVertex2f(-0.45f, -0.85f);
    glEnd();

    // 3rd divider
    glBegin(GL_QUADS);
        glVertex2f(-0.1f, -0.80f);
        glVertex2f( 0.05f, -0.80f);
        glVertex2f( 0.05f, -0.85f);
        glVertex2f(-0.1f, -0.85f);
    glEnd();

    // 4th divider
    glBegin(GL_QUADS);
        glVertex2f(0.25f, -0.80f);
        glVertex2f(0.40f, -0.80f);
        glVertex2f(0.40f, -0.85f);
        glVertex2f(0.25f, -0.85f);
    glEnd();

    // 5th divider
    glBegin(GL_QUADS);
        glVertex2f(0.60f, -0.80f);
        glVertex2f(0.75f, -0.80f);
        glVertex2f(0.75f, -0.85f);
        glVertex2f(0.60f, -0.85f);
    glEnd();

     // Field (ground strip)
glColor3f(0.71f, 0.40f, 0.11f);
glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.25f);
    glVertex2f( 1.0f, -0.25f);
    glVertex2f( 1.0f, -0.675f);
    glVertex2f(-1.0f, -0.675f);
glEnd();


        // Sky


glColor3f(0.53f, 0.81f, 0.98f);   // Day: skyblue
glBegin(GL_QUADS);
    glVertex2f(-1.0f,  1.0f);
    glVertex2f( 1.0f,  1.0f);
    glVertex2f( 1.0f, -0.25f);
    glVertex2f(-1.0f, -0.25f);
glEnd();


       int cloudSeg = 56;
    // Left side Cloud
    drawCloudA(cloudX - 0.68f, 0.84f, 0.40f, cloudSeg);
    drawCloudA(cloudX - 0.33f, 0.84f, 0.50f, cloudSeg);
    // Right side Cloud
    drawCloudA(cloudX + 0.78f, 0.85f, 0.52f, cloudSeg);


      //big building
        glColor3f(1.0f, 0.992f, 0.815f);
        glBegin(GL_QUADS);
        glVertex2f(0.2f, 1.0f);
        glVertex2f(0.8f, 1.0f);
        glVertex2f(0.8f, -0.25f);
        glVertex2f(0.2f, -0.25f);
        glEnd();

        //short building
        glColor3f(1.0f, 0.992f, 0.815f);
        glBegin(GL_QUADS);
        glVertex2f(-0.2f, 0.675f);
        glVertex2f(0.1f, 0.675f);
        glVertex2f(0.1f, -0.25f);
        glVertex2f(-0.2f, -0.25f);
        glEnd();

        glColor3f(1.0f, 0.992f, 0.815f);
        glBegin(GL_QUADS);
        glVertex2f(-1.0f, 0.25f);
        glVertex2f(-0.2f, 0.675f);
        glVertex2f(-0.2f, -0.25f);
        glVertex2f(-1.0f, -0.25f);
        glEnd();

       //window corner
       glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-1.0f, 0.125f);
        glVertex2f(-0.2f, 0.5f);
        glVertex2f(-0.2f, 0.375f);
        glVertex2f(-1.0f, 0.00f);
        glEnd();

        //window
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.98f, 0.1f);
        glVertex2f(-0.82f, 0.175f);
        glVertex2f(-0.82f, 0.1125f);
        glVertex2f(-0.98f, 0.0375f);
        glEnd();

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.76f, 0.2f);
        glVertex2f(-0.62f, 0.275f);
        glVertex2f(-0.62f, 0.2125f);
        glVertex2f(-0.76f, 0.1375f);
        glEnd();

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.56f, 0.3f);
        glVertex2f(-0.42f, 0.375f);
        glVertex2f(-0.42f, 0.3125f);
        glVertex2f(-0.56f, 0.2375f);
        glEnd();

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(-0.36f, 0.4f);
        glVertex2f(-0.22f, 0.4625f);
        glVertex2f(-0.22f, 0.3875f);
        glVertex2f(-0.36f, 0.325f);
        glEnd();

        //building line

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.2f,0.675f);
        glVertex2f(-0.2f,-0.25f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.2f,0.675f);
        glVertex2f(0.1f,0.675f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.1f,-0.25f);
        glVertex2f(0.1f,0.675f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.2f,0.675f);
        glVertex2f(-1.0f,0.25f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.2f,1.0f);
        glVertex2f(0.2f,-0.25f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.2f,0.9975f);
        glVertex2f(0.8f,0.9975f);
        glEnd();

       glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.8f,-0.25f);
        glVertex2f(0.8f,1.0f);
        glEnd();


    //tree
    glColor3f(0.40f, 0.26f, 0.13f);
        glBegin(GL_QUADS);
        glVertex2f(-0.88f,-0.4f);
        glVertex2f(-0.84f,-0.4f);
        glVertex2f(-0.84f,-0.675f);
        glVertex2f(-0.88f,-0.675f);
        glEnd();


    glColor3f(0.40f, 0.26f, 0.13f);
        glBegin(GL_QUADS);
        glVertex2f(-0.44f,-0.4f);
        glVertex2f(-0.4f,-0.4f);
        glVertex2f(-0.4f,-0.675f);
        glVertex2f(-0.44f,-0.675f);
        glEnd();

        glColor3f(0.40f, 0.26f, 0.13f);
        glBegin(GL_QUADS);
        glVertex2f(0.84f,-0.4f);
        glVertex2f(0.88f,-0.4f);
        glVertex2f(0.88f,-0.675f);
        glVertex2f(0.84f,-0.675f);
        glEnd();

        //tree leaf 1
     glColor3f(0.0f, 0.5f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-1.0f,-0.4f);
        glVertex2f(-0.86f,-0.25f);
        glVertex2f(-0.72f,-0.4f);
        glEnd();

        glColor3f(0.0f, 0.5f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.98f,-0.35f);
        glVertex2f(-0.86f,-0.2f);
        glVertex2f(-0.74f,-0.35f);
        glEnd();

        glColor3f(0.0f, 0.5f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.96f,-0.3f);
        glVertex2f(-0.86f,-0.15f);
        glVertex2f(-0.76f,-0.3f);
        glEnd();

        //tree leaf 2
        glColor3f(0.0f, 0.5f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.56f,-0.4f);
        glVertex2f(-0.42f,-0.25f);
        glVertex2f(-0.28f,-0.4f);
        glEnd();

        glColor3f(0.0f, 0.5f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.56f,-0.35f);
        glVertex2f(-0.42f,-0.2f);
        glVertex2f(-0.3f,-0.35f);
        glEnd();

        glColor3f(0.0f, 0.5f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.54f,-0.3f);
        glVertex2f(-0.42f,-0.15f);
        glVertex2f(-0.32f,-0.3f);
        glEnd();

        //leaf 3

         glColor3f(0.0f, 0.5f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.72f,-0.4f);
        glVertex2f(0.86f,-0.25f);
        glVertex2f(1.0f,-0.4f);
        glEnd();

        glColor3f(0.0f, 0.5f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.72f,-0.35f);
        glVertex2f(0.86f,-0.2f);
        glVertex2f(0.98f,-0.35f);
        glEnd();

        glColor3f(0.0f, 0.5f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.74f,-0.3f);
        glVertex2f(0.86f,-0.15f);
        glVertex2f(0.96f,-0.3f);
        glEnd();


      //gate
      glColor3f(0.36f, 0.20f, 0.09f);
        glBegin(GL_QUADS);
        glVertex2f(-0.2f,-0.25f);
        glVertex2f(0.1f,-0.25f);
        glVertex2f(0.1f,-0.675f);
        glVertex2f(-0.2f,-0.675f);
        glEnd();

        //gate line
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.18f,-0.2f);
        glVertex2f(-0.18f,-0.675f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.2f,-0.2f);
        glVertex2f(-0.2f,-0.675f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.16f,-0.2f);
        glVertex2f(-0.16f,-0.675f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.14f,-0.2f);
        glVertex2f(-0.14f,-0.675f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.12f,-0.2f);
        glVertex2f(-0.12f,-0.675f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.1f,-0.2f);
        glVertex2f(-0.1f,-0.675f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.08f,-0.2f);
        glVertex2f(-0.08f,-0.675f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.06f,-0.2f);
        glVertex2f(-0.06f,-0.675f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.04f,-0.2f);
        glVertex2f(-0.04f,-0.675f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.02f,-0.2f);
        glVertex2f(-0.02f,-0.675f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.0f,-0.2f);
        glVertex2f(-0.0f,-0.675f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.02f,-0.2f);
        glVertex2f(0.02f,-0.675f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.04f,-0.2f);
        glVertex2f(0.04f,-0.675f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.06f,-0.2f);
        glVertex2f(0.06f,-0.675f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.08f,-0.2f);
        glVertex2f(0.08f,-0.675f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(0.1f,-0.2f);
        glVertex2f(0.1f,-0.675f);
        glEnd();

       glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(-0.22f,-0.25f);
        glVertex2f(0.12f,-0.25f);
        glEnd();


       glColor3f(0.0f, 0.0f,0.30f);
        glBegin(GL_QUADS);
        glVertex2f(0.3f+truckX,-0.375f);
        glVertex2f(0.7f+truckX,-0.375f);
        glVertex2f(0.7f+truckX,-0.75f);
        glVertex2f(0.3f+truckX,-0.75f);
        glEnd();

        glColor3f(0.0f, 0.0f,0.35f);
        glBegin(GL_QUADS);
        glVertex2f(0.2f+truckX,-0.45f);
        glVertex2f(0.3f+truckX,-0.425f);
        glVertex2f(0.3f+truckX,-0.75f);
        glVertex2f(0.16f+truckX,-0.75f);
        glVertex2f(0.16f+truckX,-0.75f);
        glEnd();

        glColor3f(1.0f, 0.992f, 0.815f);
        glBegin(GL_QUADS);
        glVertex2f(0.21f+truckX,-0.475f);
        glVertex2f(0.28f+truckX,-0.46f);
        glVertex2f(0.28f+truckX,-0.6f);
        glVertex2f(0.19f+truckX,-0.6f);
        glEnd();

        glColor3f(0.70f, 0.75f, 0.71f);
        glBegin(GL_QUADS);
        glVertex2f(0.16f+truckX,-0.75f);
        glVertex2f(0.68f+truckX,-0.75f);
        glVertex2f(0.68f+truckX,-0.825f);
        glVertex2f(0.16f+truckX,-0.825f);
        glEnd();

        //Car 1st Tire with animation
    GLfloat x1 = 0.3f+truckX;

    GLfloat y1 = -0.8f;

    GLfloat radius = 0.06f;

    int triangleAmount = 100;

    GLfloat twicePi = 2.0f * PI;



    glColor3f(0.0f, 0.0f, 0.0f); // black color



    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x1, y1);

    for(int i = 0; i <= triangleAmount; i++) {

        glVertex2f(

            x1 + (radius * cos(i * twicePi / triangleAmount)),
            y1 + (radius * sin(i * twicePi / triangleAmount))

        );

    }

    glEnd();


   //Car 2nd Tire with animation
    GLfloat x2 = 0.57f+truckX;

    GLfloat y2 = -0.8f;



    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x2, y2);

    for(int i = 0; i <= triangleAmount; i++) {

        glVertex2f(

            x2 + (radius * cos(i * twicePi / triangleAmount)),
            y2 + (radius * sin(i * twicePi / triangleAmount))

        );

    }

    glEnd();

    //text

    glColor3f(0.0f, 0.0f, 0.0f);
    renderBitmapString(0.37f, 0.55f, 0.9f, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"National Museum");
    renderBitmapString(0.42f, 0.45f,0.9f,GLUT_BITMAP_TIMES_ROMAN_24, (char*)"of Science");
    renderBitmapString(0.38f, 0.35f, 0.9f, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"and Technology");

    glFlush();
}

void playSound() { PlaySound("horn.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP); }
}

// glue
static bool __ns4_active=false;
void NS4_start(){ __ns4_active=true; glutTimerFunc(10, NS4::update, 0); NS4::playSound(); }
void NS4_stop(){ __ns4_active=false; PlaySound(NULL,NULL,0); }
void NS4_display(){ NS4::display(); }
void NS4_onKey(unsigned char, int, int){}





//Code Start Saymon
namespace NS5 {
#include <windows.h>
#include <GL/glut.h>
#include <math.h>

GLfloat carPos = -1.2f;
GLfloat carSpeed = 0.005f;

void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * i / num_segments;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}
void drawCar() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(carPos - 0.15f, -0.75f);
        glVertex2f(carPos + 0.15f, -0.75f);
        glVertex2f(carPos + 0.15f, -0.6f);
        glVertex2f(carPos - 0.15f, -0.6f);
    glEnd();
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_QUADS);
        glVertex2f(carPos - 0.1f, -0.6f);
        glVertex2f(carPos + 0.1f, -0.6f);
        glVertex2f(carPos + 0.07f, -0.5f);
        glVertex2f(carPos - 0.07f, -0.5f);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(carPos - 0.1f, -0.75f, 0.05f, 20);
    drawCircle(carPos + 0.1f, -0.75f, 0.05f, 20);
}
void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c; glRasterPos3f(x, y, z);
    for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}


void display() {
   glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);  //Road black
        glVertex2f(-1.0f, -0.75f);
        glVertex2f( 1.0f, -0.75f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
    glEnd();


    glColor3f(1.0f, 1.0f, 1.0f);


    glBegin(GL_QUADS); // road line white
        glVertex2f(-0.9f, -0.85f);
        glVertex2f(-0.7f, -0.85f);
        glVertex2f(-0.7f, -0.9f);
        glVertex2f(-0.9f, -0.9f);
    glEnd();


    glBegin(GL_QUADS); // road line white
        glVertex2f(-0.6f, -0.85f);
        glVertex2f(-0.4f, -0.85f);
        glVertex2f(-0.4f, -0.9f);
        glVertex2f(-0.6f, -0.9f);
    glEnd();


    glBegin(GL_QUADS); // road line white
        glVertex2f(-0.3f, -0.85f);
        glVertex2f( -0.1f, -0.85f);
        glVertex2f(-0.1f, -0.9f);
        glVertex2f( -0.3f, -0.9f);
    glEnd();


    glBegin(GL_QUADS); // road line white
        glVertex2f(0.0f, -0.85f);
        glVertex2f(0.2f, -0.85f);
        glVertex2f(0.2f, -0.9f);
        glVertex2f(0.0f, -0.9f);
    glEnd();


    glBegin(GL_QUADS); // road line white
        glVertex2f(0.3f, -0.85f);
        glVertex2f(0.5f, -0.85f);
        glVertex2f(0.5f, -0.9f);
        glVertex2f(0.3f, -0.9f);
    glEnd();

      glBegin(GL_QUADS); // road line white
        glVertex2f(0.6f, -0.85f);
        glVertex2f(0.8f, -0.85f);
        glVertex2f(0.8f, -0.9f);
        glVertex2f(0.6f, -0.9f);
    glEnd();



       glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS); //green grass

        glVertex2f(-1.0f, 0.25f);
        glVertex2f( 0.2f, 0.25f);
        glVertex2f( 0.8f, -0.75f);
        glVertex2f(-1.0f, -0.75f);
    glEnd();

glColor3f(1.0f, 0.992f, 0.815f);
glBegin(GL_QUADS); //building cream
    glVertex2f(-1.0f, 0.875f);
    glVertex2f( 0.2f, 0.875f);
    glVertex2f( 0.2f, 0.25f);
    glVertex2f(-1.0f, 0.25f);


    glBegin(GL_QUADS); //building cream
    glVertex2f(0.2f, 0.875f);
    glVertex2f( 1.0f, 0.6875f);
    glVertex2f( 1.0f, 0.25f);
    glVertex2f(0.2f, 0.25f);

    glEnd();

 glColor3f(0.871f, 0.722f, 0.529f);
    glBegin(GL_QUADS); // soil color field
    glVertex2f(0.2f, 0.25f);
    glVertex2f( 1.0f, 0.25f);
    glVertex2f( 1.0f, -0.75f);
    glVertex2f(0.8f, -0.75f);

    glEnd();


   glColor3f(0.396f, 0.263f, 0.129f);
    glBegin(GL_QUADS); // dark brown tree steam
    glVertex2f(0.4f, 0.075f);
    glVertex2f( 0.44f, 0.075f);
    glVertex2f( 0.44f, -0.075f);
    glVertex2f(0.4f, -0.075f);

    glEnd();


      glBegin(GL_QUADS);
    glVertex2f(0.54f, -0.1f);
    glVertex2f( 0.58f, -0.1f);
    glVertex2f( 0.58f, -0.25f);
    glVertex2f(0.54f, -0.25f);

    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.66f, -0.3f);
    glVertex2f( 0.7f, -0.3f);
    glVertex2f( 0.7f, -0.45f);
    glVertex2f(0.66f, -0.45f);

    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.78f, -0.475f);
    glVertex2f( 0.82f, -0.475f);
    glVertex2f( 0.82f, -0.625f);
    glVertex2f(0.78f, -0.625f);

    glEnd();



   glColor3f(0.0f, 0.392f, 0.0f);
    glBegin(GL_TRIANGLES); // dark green leaves of tree
    glVertex2f(0.36f, 0.075f);
    glVertex2f( 0.42f, 0.175f);
    glVertex2f( 0.48f, 0.075f);
     glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(0.36f, 0.125f);
    glVertex2f( 0.42f, 0.225f);
    glVertex2f( 0.48f, 0.125f);
     glEnd();


     glBegin(GL_TRIANGLES);
    glVertex2f(0.5f, -0.1f);
    glVertex2f( 0.56f, 0.0f);
    glVertex2f( 0.62f, -0.1f);
     glEnd();

     glBegin(GL_TRIANGLES);
    glVertex2f(0.5f, -0.05f);
    glVertex2f( 0.56f, 0.05f);
    glVertex2f( 0.62f, -0.05f);
     glEnd();


     glBegin(GL_TRIANGLES);
    glVertex2f(0.62f, -0.3f);
    glVertex2f( 0.68f, -0.2f);
    glVertex2f( 0.74f, -0.3f);
     glEnd();

     glBegin(GL_TRIANGLES);
    glVertex2f(0.62f, -0.25f);
    glVertex2f( 0.68f, -0.15f);
    glVertex2f( 0.74f, -0.25f);
     glEnd();

     glBegin(GL_TRIANGLES);
    glVertex2f(0.74f, -0.475f);
    glVertex2f( 0.8f, -0.375f);
    glVertex2f( 0.86f, -0.475f);
     glEnd();


     glBegin(GL_TRIANGLES);
    glVertex2f(0.74f, -0.425f);
    glVertex2f( 0.8f, -0.325f);
    glVertex2f( 0.86f, -0.425f);
     glEnd();






glColor3f(0.0f, 0.0f, 0.0f);


glBegin(GL_LINES); // black lines of building
    glVertex2f(-0.9f, 0.875f);
    glVertex2f(-0.9f, 0.25f);

    glVertex2f(-0.8f, 0.875f);
    glVertex2f(-0.8f, 0.25f);

    glVertex2f(-0.7f, 0.875f);
    glVertex2f(-0.7f, 0.25f);

    glVertex2f(-0.6f, 0.875f);
    glVertex2f(-0.6f, 0.25f);

    glVertex2f(-0.5f, 0.875f);
    glVertex2f(-0.5f, 0.25f);

    glVertex2f(-0.4f, 0.875f);
    glVertex2f(-0.4f, 0.25f);

    glVertex2f(-0.3f, 0.875f);
    glVertex2f(-0.3f, 0.25f);

    glVertex2f(-0.2f, 0.875f);
    glVertex2f(-0.2f, 0.25f);

    glVertex2f(-0.1f, 0.875f);
    glVertex2f(-0.1f, 0.25f);

    glVertex2f(0.0f, 0.875f);
    glVertex2f(0.0f, 0.25f);

     glVertex2f(0.1f, 0.875f);
    glVertex2f(0.1f, 0.25f);

    glVertex2f(0.2f, 0.875f);
    glVertex2f(0.2f, 0.25f);

     glVertex2f(0.3f, 0.85f);
    glVertex2f(0.3f, 0.25f);

    glVertex2f(0.4f, 0.825f);
    glVertex2f(0.4f, 0.25f);

     glVertex2f(0.5f, 0.8f);
    glVertex2f(0.5f, 0.25f);

     glVertex2f(0.6f, 0.775f);
    glVertex2f(0.6f, 0.25f);

     glVertex2f(0.7f, 0.75f);
    glVertex2f(0.7f, 0.25f);

     glVertex2f(0.8f, 0.725f);
    glVertex2f(0.8f, 0.25f);

     glVertex2f(0.9f, 0.7f);
    glVertex2f(0.9f, 0.25f);

     glVertex2f(1.0f, 0.6875f);
    glVertex2f(1.0f, 0.25f);


     glVertex2f(-1.0f, 0.625f);
    glVertex2f(-0.9f, 0.625f);

     glVertex2f(-0.8f, 0.625f);
    glVertex2f(-0.7f, 0.625f);

    glVertex2f(-0.6f, 0.625f);
    glVertex2f(-0.5f, 0.625f);

     glVertex2f(-0.4f, 0.625f);
    glVertex2f(-0.3f, 0.625f);

     glVertex2f(-0.2f, 0.625f);
    glVertex2f(-0.1f, 0.625f);


     glVertex2f(0.0f, 0.625f);
    glVertex2f(0.1f, 0.625f);

     glVertex2f(0.2f, 0.625f);
    glVertex2f(0.3f, 0.625f);

    glVertex2f(0.4f, 0.625f);
    glVertex2f(0.5f, 0.625f);

     glVertex2f(0.6f, 0.625f);
    glVertex2f(0.7f, 0.625f);

     glVertex2f(0.8f, 0.625f);
    glVertex2f(0.9f, 0.625f);



     glVertex2f(-1.0f, 0.375f);
    glVertex2f(-0.9f, 0.375f);

     glVertex2f(-0.8f, 0.375f);
    glVertex2f(-0.7f, 0.375f);

    glVertex2f(-0.6f, 0.375f);
    glVertex2f(-0.5f, 0.375f);

     glVertex2f(-0.4f, 0.375f);
    glVertex2f(-0.3f, 0.375f);

     glVertex2f(-0.2f, 0.375f);
    glVertex2f(-0.1f, 0.375f);



     glVertex2f(0.0f, 0.375f);
    glVertex2f(0.1f, 0.375f);

     glVertex2f(0.2f, 0.375f);
    glVertex2f(0.3f, 0.375f);

    glVertex2f(0.4f, 0.375f);
    glVertex2f(0.5f, 0.375f);

     glVertex2f(0.6f, 0.375f);
    glVertex2f(0.7f, 0.375f);

     glVertex2f(0.8f, 0.375f);
    glVertex2f(0.9f, 0.375f);




    glVertex2f(-0.9f, 0.5f);
    glVertex2f(-0.8f, 0.5f);

     glVertex2f(-0.7f, 0.5f);
    glVertex2f(-0.6f, 0.5f);

    glVertex2f(-0.5f, 0.5f);
    glVertex2f(-0.4f, 0.5f);

     glVertex2f(-0.3f, 0.5f);
    glVertex2f(-0.2f, 0.5f);

     glVertex2f(-0.1f, 0.5f);
    glVertex2f(0.0f, 0.5f);





    glVertex2f(0.1f, 0.5f);
    glVertex2f(0.2f, 0.5f);

     glVertex2f(0.3f, 0.5f);
    glVertex2f(0.4f, 0.5f);

    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.6f, 0.5f);

     glVertex2f(0.7f, 0.5f);
    glVertex2f(0.8f, 0.5f);

     glVertex2f(0.9f, 0.5f);
    glVertex2f(1.0f, 0.5f);


    glVertex2f(-1.0f, 0.875f);
    glVertex2f(0.2f, 0.875f);


    glVertex2f(0.2f, 0.875f);
    glVertex2f(1.0f, 0.6875f);

    glVertex2f(-1.0f, 0.25f);
    glVertex2f(1.0f, 0.25f);


glEnd();




    drawCar();

    drawCar();
    glFlush();
}

void update(int value) {
    carPos += carSpeed;
    if (carPos > 1.2f) {
        carPos = -1.2f;
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}
}




//Code Start Saimoon

namespace NS6 {
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <mmsystem.h>
#define PI 3.14159265358979323846

// ---- animation state ----
static GLfloat position = 0.0f;
static GLfloat speed    = 0.1f;
static bool    __active = false;

void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // center
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * (float)i / (float)num_segments;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}
void update(int) {
    if(!__active) return;
    if (position < -1.25f) {
        position = 1.0f;
    }
    position -= speed;
    glutPostRedisplay();
    glutTimerFunc(45, update, 0);
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Sky Blue
    glColor3f(0.53f, 0.81f, 0.98f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0,0.375);
        glVertex2f(-1.0,1.0);
        glVertex2f(1.0,1.0);
        glVertex2f(1.0,0.375);
    glEnd();

    // ================= CLOUDS =================
    glColor3f(1.0f, 1.0f, 1.0f);  // White clouds
    // Cloud 1 (left side)
    drawCircle(-0.85f, 0.85f, 0.08f, 100);
    drawCircle(-0.75f, 0.87f, 0.1f, 100);
    drawCircle(-0.65f, 0.85f, 0.08f, 100);
    // Cloud 2 (right side)
    drawCircle(0.65f, 0.88f, 0.1f, 100);
    drawCircle(0.75f, 0.90f, 0.12f, 100);
    drawCircle(0.85f, 0.88f, 0.1f, 100);
    // Cloud 3 (top middle)
    drawCircle(-0.15f, 0.95f, 0.1f, 100);
    drawCircle(0.0f, 0.97f, 0.12f, 100);
    drawCircle(0.15f, 0.95f, 0.1f, 100);

    // Road
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.675f);
        glVertex2f(1.0f, -0.675f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
    glEnd();

    // Road divider (5 segments)
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS); glVertex2f(-0.8f, -0.80f); glVertex2f(-0.65f, -0.80f); glVertex2f(-0.65f, -0.85f); glVertex2f(-0.8f, -0.85f); glEnd();
    glBegin(GL_QUADS); glVertex2f(-0.45f, -0.80f); glVertex2f(-0.30f, -0.80f); glVertex2f(-0.30f, -0.85f); glVertex2f(-0.45f, -0.85f); glEnd();
    glBegin(GL_QUADS); glVertex2f(-0.1f, -0.80f); glVertex2f( 0.05f, -0.80f); glVertex2f( 0.05f, -0.85f); glVertex2f(-0.1f, -0.85f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.25f, -0.80f); glVertex2f(0.40f, -0.80f); glVertex2f(0.40f, -0.85f); glVertex2f(0.25f, -0.85f); glEnd();
    glBegin(GL_QUADS); glVertex2f(0.60f, -0.80f); glVertex2f(0.75f, -0.80f); glVertex2f(0.75f, -0.85f); glVertex2f(0.60f, -0.85f); glEnd();

    //Museum
    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_QUADS);
      glVertex2f(-0.7,-0.125);
      glVertex2f(-0.7,0.5);
      glVertex2f(0.7,0.5);
      glVertex2f(0.7,-0.125);
    glEnd();

    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
      glVertex2f(-0.6,-0.375);
      glVertex2f(-0.6,-0.125);
      glVertex2f(0.6,-0.125);
      glVertex2f(0.6,-0.375);
    glEnd();

    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
      glVertex2f(-0.4,-0.125);
      glVertex2f(-0.4,0.0);
      glVertex2f(0.4,0.0);
      glVertex2f(0.4,-0.125);
    glEnd();

    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
      glVertex2f(-0.6,-0.375);
      glVertex2f(-0.6,-0.125);
      glVertex2f(0.6,-0.125);
      glVertex2f(0.6,-0.375);
    glEnd();

    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_QUADS);
      glVertex2f(-0.8,-0.5);
      glVertex2f(-0.7,-0.375);
      glVertex2f(0.7,-0.375);
      glVertex2f(0.8,-0.5);
    glEnd();

    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
      glVertex2f(-0.8,-0.625);
      glVertex2f(-0.8,-0.5);
      glVertex2f(0.8,-0.5);
      glVertex2f(0.8,-0.625);
    glEnd();

    glColor3f(0.98f, 0.98f, 0.94f);
    glBegin(GL_LINES); glVertex2f(-0.2,-0.375); glVertex2f(-0.2,0.0); glEnd();
    glBegin(GL_LINES); glVertex2f(-0.4,-0.375); glVertex2f(-0.4,0.0); glEnd();
    glBegin(GL_LINES); glVertex2f(0.0,-0.375); glVertex2f(0.0,0.0); glEnd();
    glBegin(GL_LINES); glVertex2f(0.2,-0.375); glVertex2f(0.2,0.0); glEnd();
    glBegin(GL_LINES); glVertex2f(0.4,-0.375); glVertex2f(0.4,0.0); glEnd();

    //Upper Building


        glColor3f(0.0f, 0.0f, 0.5f);

          glBegin(GL_QUADS);
           glVertex2f(-1.0,0.0);
           glVertex2f(-1.0,0.625);
           glVertex2f(-0.86,0.625);
           glVertex2f(-0.86,0.0);
           glEnd();

           //1st Building's Window

         glColor3f(1.0f, 1.0f, 0.0f);

         glBegin(GL_QUADS);
            glVertex2f(-0.96,0.05);
            glVertex2f(-0.96,0.125);
            glVertex2f(-0.9,0.125);
            glVertex2f(-0.9,0.05);
            glEnd();

        glBegin(GL_QUADS);
            glVertex2f(-0.96,0.175);
            glVertex2f(-0.96,0.275);
            glVertex2f(-0.9,0.275);
            glVertex2f(-0.9,0.175);
            glEnd();


            glBegin(GL_QUADS);
            glVertex2f(-0.96,0.325);
            glVertex2f(-0.96,0.425);
            glVertex2f(-0.9,0.425);
            glVertex2f(-0.9,0.325);
            glEnd();

            glBegin(GL_QUADS);
            glVertex2f(-0.96,0.475);
            glVertex2f(-0.96,0.575);
            glVertex2f(-0.9,0.575);
            glVertex2f(-0.9,0.475);
            glEnd();

            glBegin(GL_LINES);
            glVertex2f(-0.86,0.0);
            glVertex2f(-0.86,0.475);
            glEnd();

        //2nd Building

         glColor3f(0.0f, 0.0f, 0.5f);

           glBegin(GL_QUADS);
            glVertex2f(-0.86,0.0);
            glVertex2f(-0.86,0.475);
            glVertex2f(-0.7,0.475);
            glVertex2f(-0.7,0.0);
            glEnd();
      //2nd Building's Window

         glColor3f(1.0f, 1.0f, 0.0f);

         glBegin(GL_QUADS);
            glVertex2f(-0.82,0.05);
            glVertex2f(-0.82,0.15);
            glVertex2f(-0.74,0.15);
            glVertex2f(-0.74,0.05);
            glEnd();

            glBegin(GL_QUADS);
            glVertex2f(-0.82,0.2);
            glVertex2f(-0.82,0.3);
            glVertex2f(-0.74,0.3);
            glVertex2f(-0.74,0.2);
            glEnd();

            glBegin(GL_QUADS);
            glVertex2f(-0.82,0.35);
            glVertex2f(-0.82,0.45);
            glVertex2f(-0.74,0.45);
            glVertex2f(-0.74,0.35);
            glEnd();

            //3rd Building

         glColor3f(0.0f, 0.0f, 0.5f);

           glBegin(GL_POLYGON);
            glVertex2f(-0.7,0.5);
            glVertex2f(-0.7,0.475);
            glVertex2f(-0.74,0.475);
            glVertex2f(-0.74,0.75);
            glVertex2f(-0.6,0.75);
            glVertex2f(-0.6,0.5);
            glEnd();

            //3rd Building's

            glColor3f(1.0f, 1.0f, 0.0f);

          glBegin(GL_QUADS);
            glVertex2f(-0.7,0.525);
            glVertex2f(-0.7,0.6);
            glVertex2f(-0.64,0.6);
            glVertex2f(-0.64,0.525);
            glEnd();

          glBegin(GL_QUADS);
            glVertex2f(-0.7,0.65);
            glVertex2f(-0.7,0.725);
            glVertex2f(-0.64,0.725);
            glVertex2f(-0.64,0.65);
            glEnd();

         //4th Building

          glColor3f(0.0f, 0.0f, 0.5f);

            glBegin(GL_QUADS);
            glVertex2f(-0.6,0.5);
            glVertex2f(-0.6,0.875);
            glVertex2f(-0.4,0.875);
            glVertex2f(-0.4,0.5);
            glEnd();

            //4th Building's Window

            glColor3f(1.0f, 1.0f, 0.0f);

            glBegin(GL_QUADS);
            glVertex2f(-0.58,0.525);
            glVertex2f(-0.58,0.6);
            glVertex2f(-0.52,0.6);
            glVertex2f(-0.52,0.525);
            glEnd();

            glBegin(GL_QUADS);
            glVertex2f(-0.58,0.65);
            glVertex2f(-0.58,0.725);
            glVertex2f(-0.52,0.725);
            glVertex2f(-0.52,0.65);
            glEnd();

            glBegin(GL_QUADS);
            glVertex2f(-0.58,0.775);
            glVertex2f(-0.58,0.85);
            glVertex2f(-0.52,0.85);
            glVertex2f(-0.52,0.775);
            glEnd();

        //5th Building
          glColor3f(0.0f, 0.0f, 0.5f);

          glBegin(GL_QUADS);
            glVertex2f(-0.4,0.5);
            glVertex2f(-0.4,0.75);
            glVertex2f(-0.2,0.75);
            glVertex2f(-0.2,0.5);
            glEnd();

        //5th Building's Color

          glColor3f(1.0f,1.0f,0.0f);

          glBegin(GL_QUADS);
            glVertex2f(-0.48,0.525);
            glVertex2f(-0.48,0.6);
            glVertex2f(-0.42,0.6);
            glVertex2f(-0.42,0.525);
            glEnd();

             glBegin(GL_QUADS);
            glVertex2f(-0.48,0.65);
            glVertex2f(-0.48,0.725);
            glVertex2f(-0.42,0.725);
            glVertex2f(-0.42,0.65);
            glEnd();

            glBegin(GL_QUADS);
            glVertex2f(-0.48,0.775);
            glVertex2f(-0.48,0.85);
            glVertex2f(-0.42,0.85);
            glVertex2f(-0.42,0.775);
            glEnd();

            //6th Building

         glColor3f(0.0f, 0.0f, 0.5f);

         glBegin(GL_QUADS);
            glVertex2f(-0.2,0.5);
            glVertex2f(-0.2,0.875);
            glVertex2f(0.0,0.875);
            glVertex2f(0.0,0.5);
            glEnd();

            //6th Building's Color

            glColor3f(1.0f,1.0f,0.0f);

         glBegin(GL_QUADS);
            glVertex2f(-0.38,0.525);
            glVertex2f(-0.38,0.6);
            glVertex2f(-0.32,0.6);
            glVertex2f(-0.32,0.525);
            glEnd();

            glBegin(GL_QUADS);
            glVertex2f(-0.38,0.65);
            glVertex2f(-0.38,0.725);
            glVertex2f(-0.32,0.725);
            glVertex2f(-0.32,0.65);
            glEnd();

             //7th Building

         glColor3f(0.0f, 0.0f, 0.5f);

         glBegin(GL_QUADS);
            glVertex2f(0.0,0.5);
            glVertex2f(0.0,0.75);
            glVertex2f(0.2,0.75);
            glVertex2f(0.2,0.5);
            glEnd();

            //7th Building Color

            glColor3f(1.0f,1.0f,0.0f);

            glBegin(GL_QUADS);
              glVertex2f(-0.28,0.525);
              glVertex2f(-0.28,0.6);
              glVertex2f(-0.22,0.6);
              glVertex2f(-0.22,0.525);
              glEnd();

              glBegin(GL_QUADS);
            glVertex2f(-0.28,0.65);
            glVertex2f(-0.28,0.725);
            glVertex2f(-0.22,0.725);
            glVertex2f(-0.22,0.65);
            glEnd();


         //8th Building

         glColor3f(0.0f, 0.0f, 0.5f);

         glBegin(GL_QUADS);
            glVertex2f(0.2,0.5);
            glVertex2f(0.2,0.875);
            glVertex2f(0.4,0.875);
            glVertex2f(0.4,0.5);
            glEnd();

        //8th Building's Color

        glColor3f(1.0f,1.0f,0.0f);

            glBegin(GL_QUADS);
              glVertex2f(-0.18,0.525);
              glVertex2f(-0.18,0.6);
              glVertex2f(-0.12,0.6);
              glVertex2f(-0.12,0.525);
              glEnd();

              glBegin(GL_QUADS);
            glVertex2f(-0.18,0.65);
            glVertex2f(-0.18,0.725);
            glVertex2f(-0.12,0.725);
            glVertex2f(-0.12,0.65);
            glEnd();

             glBegin(GL_QUADS);
              glVertex2f(-0.18,0.775);
              glVertex2f(-0.18,0.85);
              glVertex2f(-0.12,0.85);
              glVertex2f(-0.12,0.775);
              glEnd();

              //9th Buiding's Color

              glColor3f(1.0f,1.0f,0.0f);

              glBegin(GL_QUADS);
              glVertex2f(-0.08,0.525);
              glVertex2f(-0.08,0.6);
              glVertex2f(-0.02,0.6);
              glVertex2f(-0.02,0.525);
              glEnd();

              glBegin(GL_QUADS);
            glVertex2f(-0.08,0.65);
            glVertex2f(-0.08,0.725);
            glVertex2f(-0.02,0.725);
            glVertex2f(-0.02,0.65);
            glEnd();

             glBegin(GL_QUADS);
              glVertex2f(-0.08,0.775);
              glVertex2f(-0.08,0.85);
              glVertex2f(-0.02,0.85);
              glVertex2f(-0.02,0.775);
              glEnd();

              //10th Building Color

              glColor3f(1.0f,1.0f,0.0f);

              glBegin(GL_QUADS);
              glVertex2f(0.02,0.525);
              glVertex2f(0.02,0.6);
              glVertex2f(0.08,0.6);
              glVertex2f(0.08,0.525);
              glEnd();

              glBegin(GL_QUADS);
            glVertex2f(0.02,0.65);
            glVertex2f(0.02,0.725);
            glVertex2f(0.08,0.725);
            glVertex2f(0.08,0.65);
            glEnd();

            //11th Building Color

            glColor3f(1.0f,1.0f,0.0f);

              glBegin(GL_QUADS);
              glVertex2f(0.12,0.525);
              glVertex2f(0.12,0.6);
              glVertex2f(0.18,0.6);
              glVertex2f(0.18,0.525);
              glEnd();

              glBegin(GL_QUADS);
            glVertex2f(0.12,0.65);
            glVertex2f(0.12,0.725);
            glVertex2f(0.18,0.725);
            glVertex2f(0.18,0.65);
            glEnd();

            //12th Building Color

            glColor3f(1.0f,1.0f,0.0f);

              glBegin(GL_QUADS);
              glVertex2f(0.22,0.525);
              glVertex2f(0.22,0.6);
              glVertex2f(0.28,0.6);
              glVertex2f(0.28,0.525);
              glEnd();

              glBegin(GL_QUADS);
            glVertex2f(0.22,0.65);
            glVertex2f(0.22,0.725);
            glVertex2f(0.28,0.725);
            glVertex2f(0.28,0.65);
            glEnd();

            glBegin(GL_QUADS);
              glVertex2f(0.22,0.775);
              glVertex2f(0.22,0.85);
              glVertex2f(0.28,0.85);
              glVertex2f(0.28,0.775);
              glEnd();

              //13th Building

              glColor3f(1.0f,1.0f,0.0f);

              glBegin(GL_QUADS);
              glVertex2f(0.32,0.525);
              glVertex2f(0.32,0.6);
              glVertex2f(0.38,0.6);
              glVertex2f(0.38,0.525);
              glEnd();

              glBegin(GL_QUADS);
            glVertex2f(0.32,0.65);
            glVertex2f(0.32,0.725);
            glVertex2f(0.38,0.725);
            glVertex2f(0.38,0.65);
            glEnd();

            glBegin(GL_QUADS);
              glVertex2f(0.32,0.775);
              glVertex2f(0.32,0.85);
              glVertex2f(0.38,0.85);
              glVertex2f(0.38,0.775);
              glEnd();


        glColor3f(0.0f, 0.0f, 0.5f);

        glBegin(GL_QUADS);
            glVertex2f(0.4,0.5);
            glVertex2f(0.4,0.75);
            glVertex2f(0.6,0.75);
            glVertex2f(0.6,0.5);
            glEnd();

             //14th Building Color

              glColor3f(1.0f,1.0f,0.0f);

              glBegin(GL_QUADS);
              glVertex2f(0.42,0.525);
              glVertex2f(0.42,0.6);
              glVertex2f(0.48,0.6);
              glVertex2f(0.48,0.525);
              glEnd();

              glBegin(GL_QUADS);
            glVertex2f(0.42,0.65);
            glVertex2f(0.42,0.725);
            glVertex2f(0.48,0.725);
            glVertex2f(0.48,0.65);
            glEnd();

            //15th Building Color

            glColor3f(1.0f,1.0f,0.0f);

              glBegin(GL_QUADS);
              glVertex2f(0.52,0.525);
              glVertex2f(0.52,0.6);
              glVertex2f(0.58,0.6);
              glVertex2f(0.58,0.525);
              glEnd();

              glBegin(GL_QUADS);
            glVertex2f(0.52,0.65);
            glVertex2f(0.52,0.725);
            glVertex2f(0.58,0.725);
            glVertex2f(0.58,0.65);
            glEnd();

        glColor3f(0.0f, 0.0f, 0.5f);

        glBegin(GL_POLYGON);
            glVertex2f(0.7,0.5);
            glVertex2f(0.7,0.475);
            glVertex2f(0.8,0.475);
            glVertex2f(0.8,0.875);
            glVertex2f(0.6,0.875);
            glVertex2f(0.6,0.5);
            glEnd();

            //16th Building Color

            glColor3f(1.0f,1.0f,0.0f);

              glBegin(GL_QUADS);
              glVertex2f(0.62,0.525);
              glVertex2f(0.62,0.6);
              glVertex2f(0.68,0.6);
              glVertex2f(0.68,0.525);
              glEnd();

              glBegin(GL_QUADS);
            glVertex2f(0.62,0.65);
            glVertex2f(0.62,0.725);
            glVertex2f(0.68,0.725);
            glVertex2f(0.68,0.65);
            glEnd();

            glBegin(GL_QUADS);
              glVertex2f(0.62,0.775);
              glVertex2f(0.62,0.85);
              glVertex2f(0.68,0.85);
              glVertex2f(0.68,0.775);
              glEnd();

              //17th Building Color

              glColor3f(1.0f,1.0f,0.0f);

              glBegin(GL_QUADS);
              glVertex2f(0.72,0.525);
              glVertex2f(0.72,0.6);
              glVertex2f(0.78,0.6);
              glVertex2f(0.78,0.525);
              glEnd();

              glBegin(GL_QUADS);
            glVertex2f(0.72,0.65);
            glVertex2f(0.72,0.725);
            glVertex2f(0.78,0.725);
            glVertex2f(0.78,0.65);
            glEnd();

            glBegin(GL_QUADS);
              glVertex2f(0.72,0.775);
              glVertex2f(0.72,0.85);
              glVertex2f(0.78,0.85);
              glVertex2f(0.78,0.775);
              glEnd();

            glBegin(GL_LINES);
              glVertex2f(0.7,0.475);
              glVertex2f(0.8,0.475);
              glEnd();


        glColor3f(0.0f, 0.0f, 0.5f);

        glBegin(GL_QUADS);
            glVertex2f(0.7,0.0);
            glVertex2f(0.7,0.475);
            glVertex2f(0.86,0.475);
            glVertex2f(0.86,0.0);
            glEnd();

            //18th Building

            glColor3f(1.0f,1.0f,0.0f);

              glBegin(GL_QUADS);
                glVertex2f(0.74,0.05);
                glVertex2f(0.74,0.15);
                glVertex2f(0.82,0.15);
                glVertex2f(0.82,0.05);
                glEnd();

                 glBegin(GL_QUADS);
                glVertex2f(0.74,0.2);
                glVertex2f(0.74,0.3);
                glVertex2f(0.82,0.3);
                glVertex2f(0.82,0.2);
                glEnd();

                 glBegin(GL_QUADS);
                glVertex2f(0.74,0.35);
                glVertex2f(0.74,0.45);
                glVertex2f(0.82,0.45);
                glVertex2f(0.82,0.35);
                glEnd();

        glColor3f(0.0f, 0.0f, 0.5f);

        glBegin(GL_QUADS);
            glVertex2f(0.86,0.0);
            glVertex2f(0.86,0.625);
            glVertex2f(1.0,0.625);
            glVertex2f(1.0,0.0);
            glEnd();

            //19th Building Color

            glColor3f(1.0f,1.0f,0.0f);

            glBegin(GL_QUADS);
            glVertex2f(0.9,0.025);
            glVertex2f(0.9,0.1);
            glVertex2f(0.96,0.1);
            glVertex2f(0.96,0.025);
            glEnd();

            glBegin(GL_QUADS);
            glVertex2f(0.9,0.125);
            glVertex2f(0.9,0.225);
            glVertex2f(0.96,0.225);
            glVertex2f(0.96,0.125);
            glEnd();

            glBegin(GL_QUADS);
            glVertex2f(0.9,0.25);
            glVertex2f(0.9,0.35);
            glVertex2f(0.96,0.35);
            glVertex2f(0.96,0.25);
            glEnd();

            glBegin(GL_QUADS);
            glVertex2f(0.9,0.375);
            glVertex2f(0.9,0.475);
            glVertex2f(0.96,0.475);
            glVertex2f(0.96,0.375);
            glEnd();

            glBegin(GL_QUADS);
            glVertex2f(0.9,0.5);
            glVertex2f(0.9,0.6);
            glVertex2f(0.96,0.6);
            glVertex2f(0.96,0.5);
            glEnd();

            glBegin(GL_LINES);
            glVertex2f(0.86,0.0);
            glVertex2f(0.86,0.475);
            glEnd();


        //Tree

        glColor3f(0.545f, 0.271f, 0.075f);

        glBegin(GL_QUADS);
            glVertex2f(-0.92,-0.5);
            glVertex2f(-0.92,-0.25);
            glVertex2f(-0.88,-0.25);
            glVertex2f(-0.88,-0.5);
            glEnd();

        glColor3f(0.0f,1.0f,0.0f);

        glBegin(GL_TRIANGLES);
            glVertex2f(-1.0,-0.25);
            glVertex2f(-0.9,-0.125);
            glVertex2f(-0.8,-0.25);
            glEnd();

        glBegin(GL_TRIANGLES);
            glVertex2f(-1.0,-0.225);
            glVertex2f(-0.9,-0.1);
            glVertex2f(-0.8,-0.225);
            glEnd();

        glBegin(GL_TRIANGLES);
            glVertex2f(-1.0,-0.2);
            glVertex2f(-0.9,-0.075);
            glVertex2f(-0.8,-0.2);
            glEnd();

            //2nd Tree

            glColor3f(0.545f, 0.271f, 0.075f);

        glBegin(GL_QUADS);
            glVertex2f(0.92,-0.5);
            glVertex2f(0.92,-0.25);
            glVertex2f(0.88,-0.25);
            glVertex2f(0.88,-0.5);
            glEnd();

        glColor3f(0.0f,1.0f,0.0f);

        glBegin(GL_TRIANGLES);
            glVertex2f(1.0,-0.25);
            glVertex2f(0.9,-0.125);
            glVertex2f(0.8,-0.25);
            glEnd();

        glBegin(GL_TRIANGLES);
            glVertex2f(1.0,-0.225);
            glVertex2f(0.9,-0.1);
            glVertex2f(0.8,-0.225);
            glEnd();

        glBegin(GL_TRIANGLES);
            glVertex2f(1.0,-0.2);
            glVertex2f(0.9,-0.075);
            glVertex2f(0.8,-0.2);
            glEnd();

            glColor3f(0.0f,1.0f,0.0f);

            glBegin(GL_POLYGON);
            glVertex2f(-1.0,-0.675);
            glVertex2f(-1.0,-0.45);
            glVertex2f(-0.92,-0.45);
            glVertex2f(-0.86,-0.45);
            glVertex2f(-0.76,-0.45);
            glVertex2f(-0.8,-0.5);
            glVertex2f(-0.8,-0.625);
            glVertex2f(0.0,-0.625);
            glVertex2f(0.0,-0.675);
            glEnd();

            glBegin(GL_POLYGON);
            glVertex2f(1.0,-0.675);
            glVertex2f(1.0,-0.45);
            glVertex2f(0.92,-0.45);
            glVertex2f(0.86,-0.45);
            glVertex2f(0.76,-0.45);
            glVertex2f(0.8,-0.5);
            glVertex2f(0.8,-0.625);
            glVertex2f(0.0,-0.625);
            glVertex2f(0.0,-0.675);
            glEnd();

            //Text
    glColor3f(0.0f, 0.0f, 0.0f); // black
    renderBitmapString(-0.62f, 0.34f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"Liberation War");
    renderBitmapString(-0.62f, 0.28f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"Museum");

            //Car's Body
            glPushMatrix();

            glTranslatef(position, 0.0f, 0.0f);

            glColor3f(0.3f, 0.6f, 0.9f);

            glBegin(GL_QUADS);
            glVertex2f(0.4,-0.8);
            glVertex2f(0.44,-0.725);
            glVertex2f(0.66,-0.725);
            glVertex2f(0.7,-0.8);
            glEnd();

            glColor3f(1.0f, 1.0f, 0.0f);

            glBegin(GL_QUADS);
            glVertex2f(0.3,-0.9);
            glVertex2f(0.3,-0.8);
            glVertex2f(0.8,-0.8);
            glVertex2f(0.8,-0.9);
            glEnd();

            //Wheels

            glColor3f(0.0f, 0.0f, 0.0f); // Black wheels
            drawCircle(0.40f, -0.90f, 0.05f, 50); // Left wheel
            drawCircle(0.70f, -0.90f, 0.05f, 50); // Right wheel



    glPopMatrix();



    // Text
    glColor3f(0.0f, 0.0f, 0.0f); // black
    renderBitmapString(-0.62f, 0.34f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"Liberation War");
    renderBitmapString(-0.62f, 0.28f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"Museum");

    // Car (animated)
    glPushMatrix();
        glTranslatef(position, 0.0f, 0.0f);

        glColor3f(0.3f, 0.6f, 0.9f);
        glBegin(GL_QUADS);
            glVertex2f(0.4,-0.8);
            glVertex2f(0.44,-0.725);
            glVertex2f(0.66,-0.725);
            glVertex2f(0.7,-0.8);
        glEnd();

        glColor3f(1.0f, 1.0f, 0.0f);
        glBegin(GL_QUADS);
            glVertex2f(0.3,-0.9);
            glVertex2f(0.3,-0.8);
            glVertex2f(0.8,-0.8);
            glVertex2f(0.8,-0.9);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f); // Black wheels
        drawCircle(0.40f, -0.90f, 0.05f, 50); // Left wheel
        drawCircle(0.70f, -0.90f, 0.05f, 50); // Right wheel
    glPopMatrix();

    glFlush();
}

static void startSound(){ PlaySound(TEXT("FastCar.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP); }

}

// glue
void NS6_start(){ NS6::__active=true; NS6::startSound(); glutTimerFunc(0, NS6::update, 0); }
void NS6_stop(){  NS6::__active=false; PlaySound(NULL,NULL,0); }
void NS6_display(){ NS6::display(); }
void NS6_onKey(unsigned char, int, int){}


// glue
static bool __ns5_active=false;
void NS5_start(){ __ns5_active=true; glutTimerFunc(0, NS5::update, 0); }
void NS5_stop(){ __ns5_active=false; }
void NS5_display(){ NS5::display(); }
void NS5_onKey(unsigned char, int, int){}

//Main
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200, 600);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("Graphics Project Final");
    glutDisplayFunc(MasterDisplay);
    glutKeyboardFunc(MasterKey);

    SwitchScene(SC_COVER);

    glutMainLoop();
    return 0;
}
