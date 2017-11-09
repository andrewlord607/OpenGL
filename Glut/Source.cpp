#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
//#include <gl\glew.h>
#include <gl/freeglut.h>// glut .h deprecated

//Подключает библиотеки
//#pragma comment (lib ," opengl32 .lib ")
//#pragma comment (lib ," glu32 .lib ")
//#pragma comment (lib ," glut32 .lib ")


//Глобальные статические переменные -
//хранят текущий размер экрана
static int w = 0, h = 0;


//Функция вызываемая перед вхождением в главный цикл
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

//Функция вызываемая каждый кадр -
// для его отрисовки, вычислений и т. д.
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
//Функця вызываемая при изменении размеров окна
void Reshape(int width, int height) {
	w = width; h = height;
}


int main(int argc, char * argv[])
{
	//Инициализировать сам glut
	glutInit(&argc, argv);
	//Установить начальное положение окна
	glutInitWindowPosition(100, 100);
	//Установить начальные размеры окна
	glutInitWindowSize(800, 800);
	//Установить параметры окна - двойная буфферизация
	// и поддержка цвета RGBA
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	//Создать окно с заголовком OpenGL
	glutCreateWindow("OpenGL");

	//Укажем glut функцию, которая будет вызываться каждый кадр
	glutIdleFunc(Update);
	//Укажем glut функцию, которая будет рисовать каждый кадр
	glutDisplayFunc(Update);
	//Укажем glut функцию, которая будет вызываться при
	// изменении размера окна приложения
	glutReshapeFunc(Reshape);
	Init();
	//Войти в главный цикл приложения
	glutMainLoop();
	return 0;

}