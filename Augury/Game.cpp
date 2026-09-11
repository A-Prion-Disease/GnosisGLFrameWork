#include "Game.hpp"

void Game::Init(void){

glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


Image Gubram("Crux/Gubram.png", true, 0);

RS.MakeTexture("Crux/testimg.png", "test", 0, true);
RS.MakeTexture("Crux/Gubram.png", "Gubram", 0, true);


//tex has max size of 20
//
glr.Tex[0] = RS.FindTexture("Gubram").GL_ID; //Gubram.GL_ID;
glr.Tex[1] = RS.FindTexture("test").GL_ID;

TG = TileGrid(0, 0, 5, 5); 

MapFile TestMap; TestMap.ReadMapFile("Crux/TestMap.txt", MapQuality::test);
TestMap.Width = 10; TestMap.Height = 10;

TG.AddTexture(RS.FindTexture("test"), 3, 3);

TG.BindMap(TestMap);


glr.Init();

				}

Game::Game(GL_Renderer& glr, ResourceSack& RS, TileGrid& TG) : glr(glr), RS(RS), TG(TG){

this->Init();
								    		      }

void Game::ChangeTileMap(MapFile& NewMap){
TG.BindMap(NewMap);
TheMap = NewMap;
					 }

void Game::Render(void){
TG.Render(glr, RS, TheMap);
glr.Render();
		       }
