
#ifndef INTERNAL_OBJECT_HPP
#define INTERNAL_OBJECT_HPP

#include "Hermetica/OpenGospeL.hpp"


class TileGrid{

float TileSize;
float COS_X, COS_Y; //CameraOffset

int TileDensity; //(How many tiles in a row and col)
int VTL, VTR, VBL, VBR; //Visible top or bottom : left or right


MapFile& CurrentMap;

std::vector<int> VisibleTiles; // Tiles on screen // tiles will be numbered according to type
std::vector<int> AllTiles; // tiles comprising the map

	public:

TileGrid(MapFile& CurrentMap, float COS_X, float COS_Y, float TileSize, int TileDensity);

void ShiftGrid(int X_Dif, int Y_Dif); 

void Render(void);

	      };

#endif
