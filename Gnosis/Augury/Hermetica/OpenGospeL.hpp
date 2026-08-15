#ifndef OPEN_GOSPEL_HPP
#define OPEN_GOSPEL_HPP
//OpenGL Abstractions (Gave a themed name cause thats how I roll)

#include "TextureSeer.hpp"

#include "FileOracle.hpp"

#include <unordered_map>


struct TextureRect{

int LIT, HIT; // Tex Length & Height in tiles

int XSlot, YSlot;

		    };



//GL_STUFF




struct Shader{

GLuint GL_ID;


Shader(void);

void Compile(const char* VertShader, const char* FragShader);

Shader& Use(void);

void setInt(const char* name, GLint value, bool useShader = false);

	    };


struct Vertex{
glm::vec3 Position;
glm::vec4 Color;
glm::vec2 TextureCords;
GLfloat TextureID;
GLfloat mixRatio;
	     };


struct Quad{

std::array<Vertex, 4> Verts;

Quad(void);

Quad(GLfloat x, GLfloat y, GLfloat z, GLfloat size, GLfloat TexID, GLfloat MixRatio);
Quad(glm::vec3 XYZ, glm::vec3 Col, GLfloat size, GLfloat TexID);

Quad(GLfloat x, GLfloat y, GLfloat z, GLfloat W, GLfloat H, GLfloat TexID, TextureRect& TSQR);
Quad(GLfloat x, GLfloat y, GLfloat z, GLfloat Size, GLfloat TexId, TextureRect& TSQR);
};	


class GL_Renderer{

std::vector<GLfloat> Vertices;

GLuint VAO;
GLuint IBO;
GLuint VBO;

GLuint offset = 0;

static const size_t MaxQuads = 1000;
static const size_t MaxVerts = MaxQuads * 4;
static const size_t MaxIndices = MaxQuads * 6;

GLuint IndicesCount = 0;

	public:

GLuint Tex[20] = {0};

void Init(void);

void Push_Quad(Quad& Q);

void Render(void);

		 };
//ResManager


class ResourceSack{

	public:

ResourceSack(void){} 
		
std::unordered_map<std::string, Shader> Shaders;
std::unordered_map<std::string, Image> Textures;

Shader MakeShader(std::string VertShaderPath, std::string FragShaderPath, std::string ShaderName);

Shader FindShader(std::string ShaderName);

Image MakeTexture(const std::string& ImgPath, std::string TextureName, 
							bool alpha = true );
Image FindTexture(std::string TexName);

TextureRect FindTexSqr(std::string TexAtlas, int x, int y, int tileSize);


		  };




#endif

