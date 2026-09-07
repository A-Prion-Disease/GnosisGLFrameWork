
#ifndef INTERNAL_OBJECT_HPP
#define INTERNAL_OBJECT_HPP

#include "Hermetica/OpenGospeL.hpp"



class TileGrid{

int TileSize;
float COS_X, COS_Y; //CameraOffset

int TileDensity; //(How many tiles in a row and col)
int VTL, VTR, VBL, VBR; //Visible top or bottom : left or right

Quad CurTile;     
TextureRect CurTexRect; 

std::array<TMT, 10> TileMapTextures;

int How_Many_Textures = 0;

std::vector<int> VisibleTiles; // Tiles on screen // tiles will be numbered according to type
std::vector<int> AllTiles; // tiles comprising the map

	public:

TileGrid(void){}
TileGrid(float COS_X, float COS_Y, int TileSize, int TileDensity);

void BindMap(MapFile& CurrentMap);

void AddTexture(Image TileMapTexture, int HIT, int WIT);

void ShiftGrid(int X_Dif, int Y_Dif); 

void Render(GL_Renderer& GLR, ResourceSack& RS, MapFile& CurrentMap);

	      };

#endif
