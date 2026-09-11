#include "InternalObj.hpp"




TileGrid::TileGrid(float COS_X, float COS_Y, int TileSize, int TileDensity) 

:  COS_X(COS_X), COS_Y(COS_Y), TileSize(TileSize), TileDensity(TileDensity){

VTL = 0; //Initally : maybe i'll make a variation of this func which controls the position of the viewing upon init	
VTR = (TileDensity - 1);
VBL = ((TileDensity * TileDensity) - (TileDensity - 1));
VBR = ((TileDensity * TileDensity) - 1); //off one cause vector starts at 0


}//TileGrid Construct

void TileGrid::BindMap(MapFile& CurrentMap){

this->AllTiles = CurrentMap.tiles;



this->VisibleTiles = AllTiles;

while(VisibleTiles.size() > (VBR - 1)){
VisibleTiles.pop_back();
				 }

					   }

void TileGrid::AddTexture(Image TileMapTexture, int HIT, int WIT){

TMT NewTex(TileMapTexture, HIT, WIT);

TileMapTextures.at(How_Many_Textures) = NewTex;
How_Many_Textures++;

						    }

void TileGrid::ShiftGrid( int X_Dif, int Y_Dif){
	
COS_X += X_Dif;
COS_Y += Y_Dif;


if(X_Dif != 0){

VTL += X_Dif; VBL += X_Dif;
VTR += X_Dif; VBR += X_Dif;

if(X_Dif > 0){

VisibleTiles.at(TileDensity) = 0; //PlaceHolder for a value in the vec: AllTiles

for(int i = 1; i < ((X_Dif * TileDensity ) - 1); i++){

VisibleTiles.at( (TileDensity * i) ) = 0; //PlaceHolder for a value in the vec: AllTiles	

			            } //Expands Right
	     } //If X_Dif is pos :: Expands Right
else{

VisibleTiles.at(0) = AllTiles.at(VTL);

for(int i = 1; i < X_Dif; i++){

VisibleTiles.at( (i + TileDensity) ) = AllTiles.at(VTL + (i * TileDensity)); //unsure if this is right 	
			      }
    }//If X_Dif is neg ::Expands left
     
	       }//If X_Dif != 0

if(Y_Dif != 0){

VTL += (TileDensity * Y_Dif); VBL += (TileDensity * Y_Dif);
VTR += (TileDensity * Y_Dif); VBR += (TileDensity * Y_Dif);

if(Y_Dif > 0){

for(int i = 0; i < (Y_Dif * TileDensity); i++){

VisibleTiles.at( (VBR - i) ) = 0; // 0 is a temp value :: replace with a value in the vec: AllTiles	
	
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

void TileGrid::Render(GL_Renderer& GLR, ResourceSack& RS, MapFile& CurrentMap){

	int tx = -TileDensity - 1;
	int ty = -TileDensity;
//tx incremented each tile and ty incremented for
//each time tx > TileDensity and then tx = 0;
		    //

	int TexX = 0; //SourceTileX
	int TexY = 0; //SourceTileY
       	int TexNumb = 0;

for(int i : VisibleTiles){
TexX = i;
std::cout << "i: " << i << "\n";
tx++; 
std::cout << "tx: " << tx << "\n";
std::cout << "ty: " << ty << "\n";

std::cout << "HIT: " << TileMapTextures.at(TexNumb).HeightInTiles << "\n";
std::cout << "LIT: " << TileMapTextures.at(TexNumb).WidthInTiles << "\n";

while(TexX > (TileMapTextures.at(TexNumb).HeightInTiles * TileMapTextures.at(TexNumb).WidthInTiles)){
TexNumb++;

TexX -= (TileMapTextures.at(TexNumb - 1).HeightInTiles *
	  TileMapTextures.at(TexNumb - 1).WidthInTiles);						
		     }

while(TexX > TileMapTextures.at(TexNumb).WidthInTiles){
TexY++;

TexX -= TileMapTextures.at(TexNumb).WidthInTiles;
						      }

while(tx > TileDensity ){
ty++; 
tx = -TileDensity - 1; //difficulty to decide what to do from here
 		       }

CurTexRect = RS.FindTexSqr(TileMapTextures.at(TexNumb), TexX, TexY);

CurTile = Quad( tx * 0.1 , ty * 0.1, 0.0f, TileSize, 1 /*TileMapTextures.at(TexNumb).img.GL_ID*/, CurTexRect);
//Not the gl_id; is different thing needed
GLR.Push_Quad(CurTile);

TexX = 0; TexY = 0; TexNumb = 0;

//Testing:
/*
CurTexRect = RS.FindTexSqr("test", 0, 0);
	CurTile = Quad(tx * 0.025, 0, 0.9f, TileSize, 1, CurTexRect);
GLR.Push_Quad(CurTile);
*/
			  }
}



						
