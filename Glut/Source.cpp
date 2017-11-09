#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
//#include <gl\glew.h>
#include <gl/freeglut.h>// glut .h deprecated

//���������� ����������
//#pragma comment (lib ," opengl32 .lib ")
//#pragma comment (lib ," glu32 .lib ")
//#pragma comment (lib ," glut32 .lib ")


//���������� ����������� ���������� -
//������ ������� ������ ������
static int w = 0, h = 0;


//������� ���������� ����� ���������� � ������� ����
void Init(void) {
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void draw_sphere(void) {
	glColor3d(1, 0, 0);
	glutWireSphere(0.5, 30, 10);

}

void draw_quad(void) {
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();
}

void draw_tri(void) {
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();
}

void draw_tri_c(void) {
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(-0.5f, -0.5f);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.0f, 0.5f);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0.5f, -0.5f);
	glEnd();
}

//������� ���������� ������ ���� -
// ��� ��� ���������, ���������� � �. �.
void Update(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	//Task1
	//draw_sphere();
	//Task2
	//draw_tri();
	//draw_quad();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(-0.5f, -0.5f);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.0f, 0.5f);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0.5f, -0.5f);
	glEnd();

	glutSwapBuffers();
}
//������ ���������� ��� ��������� �������� ����
void Reshape(int width, int height) {
	w = width; h = height;
}


int main(int argc, char * argv[])
{
	//���������������� ��� glut
	glutInit(&argc, argv);
	//���������� ��������� ��������� ����
	glutInitWindowPosition(100, 100);
	//���������� ��������� ������� ����
	glutInitWindowSize(800, 800);
	//���������� ��������� ���� - ������� ������������
	// � ��������� ����� RGBA
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	//������� ���� � ���������� OpenGL
	glutCreateWindow("OpenGL");

	//������ glut �������, ������� ����� ���������� ������ ����
	glutIdleFunc(Update);
	//������ glut �������, ������� ����� �������� ������ ����
	glutDisplayFunc(Update);
	//������ glut �������, ������� ����� ���������� ���
	// ��������� ������� ���� ����������
	glutReshapeFunc(Reshape);
	Init();
	//����� � ������� ���� ����������
	glutMainLoop();
	return 0;

}