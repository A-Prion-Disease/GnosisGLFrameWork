#include "Game.hpp"

void Game::Init(GL_Renderer& glr, ResourceSack& RS){

glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


Image Gubram("Crux/Gubram.png", true);

//Image bobram("Crux/test.png", true);

RS.MakeTexture("Crux/test.png", "test", true);
RS.MakeTexture("Crux/Gubram.png", "Gubram", true);


//tex has max size of 20
//
glr.Tex[0] = Gubram.GL_ID;
glr.Tex[1] = RS.FindTexture("test").GL_ID;


MapFile TestMap; TestMap.ReadMapFile("Crux/TestMap.txt", MapQuality::test);

glr.Init();

				}

Game::Game(GL_Renderer& glr, ResourceSack& RS){

	this->Init(glr, RS);

			    		      }
