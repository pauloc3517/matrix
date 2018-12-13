#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <Vector3.h>
#include "MyMatrix3.h"



using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	// Front Face
	MyVector3 frontFaceOne{ 1.0f,1.0f,-5.0f };
	MyVector3 frontFaceTwo{ -1.0f, 1.0f, -5.0f };
	MyVector3 frontFaceThree{ -1.0f, -1.0f, -5.0f };
	MyVector3 frontFaceFour{ 1.0f, -1.0f, -5.0f };

	// Back Face
	MyVector3 backFaceOne{ 1.0f, 1.0f, -15.0f };
	MyVector3 backFaceTwo{ -1.0f, 1.0f, -15.0f };
	MyVector3 backFaceThree{ -1.0f, -1.0f, -15.0f };
	MyVector3 backFaceFour{ 1.0f, -1.0f, -15.0f };
	
	// Right Face
	MyVector3 rightFaceOne{ 1.0f, 1.0f, -5.0f };
	MyVector3 rightFaceTwo{ 1.0f, 1.0f, -15.0f };
	MyVector3 rightFaceThree{ 1.0f, -1.0f, -5.0f };
	MyVector3 rightFaceFour{ 1.0f, -1.0f, -15.0f };

	// Left Face
	MyVector3 leftFaceOne{ -1.0f, 1.0f, -5.0f };
	MyVector3 leftFaceTwo{ -1.0f, 1.0f, -15.0f };
	MyVector3 leftFaceThree{ -1.0f, -1.0f, -5.0f };
	MyVector3 leftFaceFour{ -1.0f, -1.0f, -15.0f };
	
	// Top Face
	MyVector3 topFaceOne{ -1.0f, 1.0f, -15.0f };
	MyVector3 topFaceTwo{ 1.0f, 1.0f, -15.0f };
	MyVector3 topFaceThree{ 1.0f, 1.0f, -5.0f };
	MyVector3 topFaceFour{ -1.0f, 1.0f, -5.0f };

	// Bottom Face
	MyVector3 bottomFaceOne{ -1.0f, -1.0f, -15.0f };
	MyVector3 bottomFaceTwo{ 1.0f, -1.0f, -15.0f };
	MyVector3 bottomFaceThree{ 1.0f, -1.0f, -5.0f };
	MyVector3 bottomFaceFour{ -1.0f, -1.0f, -5.0f };




	GLuint index;
	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;
};