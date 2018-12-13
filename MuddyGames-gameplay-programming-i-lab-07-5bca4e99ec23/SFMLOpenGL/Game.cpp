#include "Game.h"



bool updatable = false;

MyVector3 v3;



Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	glNewList(index, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(frontFaceOne.getX(), frontFaceOne.getY(), frontFaceOne.getZ());
		glVertex3f(frontFaceTwo.getX(), frontFaceTwo.getY(), frontFaceTwo.getZ());
		glVertex3f(frontFaceThree.getX(), frontFaceThree.getY(), frontFaceThree.getZ());
		glVertex3f(frontFaceFour.getX(), frontFaceFour.getY(), frontFaceFour.getZ());

		MyMatrix3 f1{ frontFaceOne,frontFaceTwo,frontFaceThree };
		MyMatrix3 f2{ frontFaceTwo, frontFaceThree, frontFaceFour };

		//Back Face
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(backFaceOne.getX(), backFaceOne.getY(), backFaceOne.getZ());
		glVertex3f(backFaceTwo.getX(), backFaceTwo.getY(), backFaceTwo.getZ());
		glVertex3f(backFaceThree.getX(), backFaceThree.getY(), backFaceThree.getZ());
		glVertex3f(backFaceFour.getX(), backFaceFour.getY(), backFaceFour.getZ());


		//Right Face
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(rightFaceOne.getX(), rightFaceOne.getY(), rightFaceOne.getZ());
		glVertex3f(rightFaceTwo.getX(), rightFaceTwo.getY(), rightFaceTwo.getZ());
		glVertex3f(rightFaceThree.getX(), rightFaceThree.getY(), rightFaceThree.getZ());
		glVertex3f(rightFaceFour.getX(), rightFaceFour.getY(), rightFaceFour.getZ());


		//left Face
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(leftFaceOne.getX(), leftFaceOne.getY(), leftFaceOne.getZ());
		glVertex3f(leftFaceTwo.getX(), leftFaceTwo.getY(), leftFaceTwo.getZ());
		glVertex3f(leftFaceThree.getX(), leftFaceThree.getY(), leftFaceThree.getZ());
		glVertex3f(leftFaceFour.getX(), leftFaceFour.getY(), leftFaceFour.getZ());


		//top Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(topFaceOne.getX(), topFaceOne.getY(), topFaceOne.getZ());
		glVertex3f(topFaceTwo.getX(), topFaceTwo.getY(), topFaceTwo.getZ());
		glVertex3f(topFaceThree.getX(), topFaceThree.getY(), topFaceThree.getZ());
		glVertex3f(topFaceFour.getX(), topFaceFour.getY(), topFaceFour.getZ());


		//bottom Face
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(bottomFaceOne.getX(), bottomFaceOne.getY(), bottomFaceOne.getZ());
		glVertex3f(bottomFaceTwo.getX(), bottomFaceTwo.getY(), bottomFaceTwo.getZ());
		glVertex3f(bottomFaceThree.getX(), bottomFaceThree.getY(), bottomFaceThree.getZ());
		glVertex3f(bottomFaceFour.getX(), bottomFaceFour.getY(), bottomFaceFour.getZ());

		
		//Complete the faces of the Cube


		
	}
	glEnd();
	glEndList();
}

void Game::update()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		std::cout << "ttttttt" << std::endl;
		MyVector3 add(0.0010f, 0.0010f, 0.0010f);
		bottomFaceOne += add;
		bottomFaceTwo += add;
		bottomFaceThree += add;
		bottomFaceFour += add;

		//top
		topFaceOne += add;
		topFaceTwo += add;
		topFaceThree += add;
		topFaceFour += add;


		leftFaceOne += add;
		leftFaceTwo += add;
		leftFaceThree += add;
		leftFaceFour += add;


		rightFaceOne += add;
		rightFaceTwo += add;
		rightFaceThree += add;
		rightFaceFour += add;


		frontFaceOne += add;
		frontFaceTwo += add;
		frontFaceThree += add;
		frontFaceFour += add;


		backFaceOne += add;
		backFaceTwo += add;
		backFaceThree += add;
		backFaceFour += add;
	}


	// scale	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		std::cout << "Scales" << std::endl;
		float scale = (1.1f);

		bottomFaceOne = MyVector3(bottomFaceOne.getX() * scale, bottomFaceOne.getY() * scale, bottomFaceOne.getZ() * scale);
		bottomFaceTwo = MyVector3(bottomFaceTwo.getX() * scale, bottomFaceTwo.getY() * scale, bottomFaceTwo.getZ() * scale);
		bottomFaceThree = MyVector3(bottomFaceThree.getX() * scale, bottomFaceThree.getY() * scale, bottomFaceThree.getZ() * scale);
		bottomFaceFour = MyVector3(bottomFaceFour.getX() * scale, bottomFaceFour.getY() * scale, bottomFaceFour.getZ() * scale);

		//top
		topFaceOne = MyVector3(topFaceOne.getX() * scale, topFaceOne.getY() * scale, topFaceOne.getZ() * scale);
		topFaceTwo =  MyVector3(topFaceTwo.getX() * scale, topFaceTwo.getY() * scale, topFaceTwo.getZ() * scale);
		topFaceThree = MyVector3(topFaceThree.getX() * scale, topFaceThree.getY() * scale, topFaceThree.getZ() * scale);
		topFaceFour = MyVector3(topFaceFour.getX() * scale, topFaceFour.getY() * scale, bottomFaceFour.getZ() * scale);


		leftFaceOne = MyVector3(leftFaceOne.getX() * scale, leftFaceOne.getY() * scale, leftFaceOne.getZ() * scale);
		leftFaceTwo =  MyVector3(leftFaceTwo.getX() * scale, leftFaceTwo.getY() * scale, leftFaceTwo.getZ() * scale);
		leftFaceThree = MyVector3(leftFaceThree.getX() * scale, leftFaceThree.getY() * scale, leftFaceThree.getZ() * scale);
		leftFaceFour = MyVector3(leftFaceFour.getX() * scale, leftFaceFour.getY() * scale, leftFaceFour.getZ() * scale);


		rightFaceOne = MyVector3(rightFaceOne.getX() * scale, rightFaceOne.getY() * scale, rightFaceOne.getZ() * scale);
		rightFaceTwo =  MyVector3(rightFaceTwo.getX() * scale, rightFaceTwo.getY() * scale, rightFaceTwo.getZ() * scale);
		rightFaceThree = MyVector3(rightFaceThree.getX() * scale, rightFaceThree.getY() * scale, rightFaceThree.getZ() * scale);
		rightFaceFour = MyVector3(rightFaceFour.getX() * scale, rightFaceFour.getY() * scale, rightFaceFour.getZ() * scale);


		frontFaceOne = MyVector3(frontFaceOne.getX() * scale, frontFaceOne.getY() * scale, frontFaceOne.getZ() * scale);
		frontFaceTwo =  MyVector3(frontFaceTwo.getX() * scale, frontFaceTwo.getY() * scale, frontFaceTwo.getZ() * scale);
		frontFaceThree = MyVector3(frontFaceThree.getX() * scale, frontFaceThree.getY() * scale, frontFaceThree.getZ() * scale);
		frontFaceFour = MyVector3(frontFaceFour.getX() * scale, frontFaceFour.getY() * scale, frontFaceFour.getZ() * scale);


		backFaceOne = MyVector3(backFaceOne.getX() * scale, backFaceOne.getY() * scale, backFaceOne.getZ() * scale);
		backFaceTwo =  MyVector3(backFaceTwo.getX() * scale, backFaceTwo.getY() * scale, backFaceTwo.getZ() * scale);
		backFaceThree = MyVector3(backFaceThree.getX() * scale, backFaceThree.getY() * scale, backFaceThree.getZ() * scale);
		backFaceFour = MyVector3(backFaceFour.getX() * scale, backFaceFour.getY() * scale, backFaceFour.getZ() * scale);
	}
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (updatable)
	{
		rotationAngle += 0.005f;


		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}

	// Redraw everything
	initialize();
	
	
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << endl;
	glLoadIdentity();

	

	//glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on Y Axis

	glCallList(1);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}



