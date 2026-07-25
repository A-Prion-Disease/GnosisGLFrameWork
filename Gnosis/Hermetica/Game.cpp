#include "Game.hpp"

void Game::Init(GL_Renderer& glr){

glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

Image Gubram("Crux/Gubram.png", true);
Image bobram("Crux/test.png", true);

glr.Tex0 = Gubram.GL_ID;
glr.Tex1 = bobram.GL_ID;

glr.Init();

				}

Game::Game(GL_Renderer& glr){

	this->Init(glr);

			    }
