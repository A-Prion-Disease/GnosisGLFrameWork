#ifndef GAME_HPP
#define GAME_HPP

#include "InternalObj.hpp"

//This and the corresponding c++ file will be where the user 
//inputs their own resources and manufactures their systems


class Game{

TileGrid& TG;
GL_Renderer& glr;
ResourceSack& RS;

MapFile TheMap;

void Init(void);
	public:

Game(GL_Renderer& glr, ResourceSack& RS, TileGrid& TG);

void ChangeTileMap(MapFile& NewMap);

void Render(void);
	  };

#endif
