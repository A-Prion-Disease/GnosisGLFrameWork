#include "InternalObj.hpp"


TileGrid::TileGrid(MapFile& CurrentMap, float CenterX, float CenterY, float TileSize, int TileDensity) 
:  CurrentMap(CurrentMap), CenterX(CenterX), CenterY(CenterY), TileSize(TileSize), TileDensity(TileDensity){


VisBotRight = TileDensity * TileDensity;

this->Render();

this->AllTiles = CurrentMap.tiles;


for(int i = 0; i < VisBotRight; i++){

this->VisibleTiles.at(i) = AllTiles.at(i);

				    } //Starts at the topright corner of the Current map

}//TileGrid Construct

void TileGrid::ShiftGrid( int X_Dif, int Y_Dif){
	
CenterX += X_Dif;
CenterY += Y_Dif;


if(X_Dif != 0){

if(X_Dif > 0){

VisibleTiles.at(TileDensity) = 0; //PlaceHolder for a value in the vec: AllTiles

for(int i = 1; i < (X_Dif - 1); i++){

VisibleTiles.at( ((TileDensity * i)) -1 ) = 0; //PlaceHolder for a value in the vec: AllTiles	
			      } //Expands Right
	     } //If X_Dif is pos :: Expands Right
else{

VisibleTiles.at(0) = 0; //PlaceHolder value for a value in the vec: AllTiles

for(int i = 1; i < X_Dif; i++){

VisibleTiles.at( (i + TileDensity) ) = 0; //PlaceHolder for a value in the vec: AllTiles 	
			      }
    }//If X_Dif is neg ::Expands left
     
	       }//If X_Dif != 0

if(Y_Dif != 0){

if(Y_Dif > 0){

for(int i = 0; i < (Y_Dif * TileDensity); i++){

VisibleTiles.at( (VisBotRight - i) ) = 0; // 0 is a temp value :: replace with a value in the vec: AllTiles	
	
					      }//Expands Down
	     }//If Y_Dif is pos : i.e. expands downwards
else{

for(int i = 0; i < (Y_Dif * TileDensity); i++){

VisibleTiles.at(i) = 0; //placeholder value (Seems shockingly a little too simple)

					      }
    }//if Y_Dif is neg : i.e. expands upwards
	      }

if((X_Dif && Y_Dif) == 0){
	std::cout << "No shift happened despite being called: buggy code?" << std::endl;
			 }

					       }

void TileGrid::Render(void){

	int tx, ty; //tx incremented each tile and ty incremented for each time tx > TileDensity and then tx = 0;

	for(int i = 0; i < VisibleTiles.size(); i++){

		switch(VisibleTiles.at(i)){
			case 1:{
			std::cout << "No functionality yet \n";
			//Will eventually render a specific tile type
			break;
			       }
		   	   }
				   }//switch
						     }//forloop
