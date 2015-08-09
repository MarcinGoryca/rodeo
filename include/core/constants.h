/*
-----------------------------------
    MG Game Engine
    Copyright(c) Marcin Goryca
    marcin.goryca@gmail.com
    http://marcingoryca.pl
-----------------------------------
*/
#ifndef MG_CORE_CONSTANTS_H_
#define MG_CORE_CONSTANTS_H_

#ifndef MG_COMMON_H_
#include "common.h"
#endif

#ifndef MG_RENDERER_COLORS_H_
#include "renderer\colors.h"
#endif

namespace mg
{
namespace core
{
typedef unsigned char* ucp;
typedef unsigned char uc;
typedef unsigned int ui;
typedef short int si;
typedef const int ci;
typedef unsigned short us;
typedef unsigned long ul;
typedef const char* ccp;
typedef const char* const ccpc;
typedef std::wstring ws;
typedef std::string s;
//-----------------
//    MATH
//-----------------
const float MG_ONE = 1.0f;
const float MG_ZERO = 0.0f;
const float MG_HALF = 0.5f;
const float MG_NEGATIVE_ONE = -1.0f;
const float MG_PI = 3.14159265f;
const float MG_TWOPI = 6.2831852f;
const float MG_HALFPI = 1.5707963f;
const float MG_ONEBYPI = 1.0f / MG_PI;
const float MG_ONEBY2PI = 1.0f / MG_TWOPI;
const ui MG_FULL_CIRCLE = 360;

// DEGREE - Degrees From Radians [180 / PI] 
const float MG_DEGREE = 57.2957f;
const float MG_RADIAN = 0.01745f;



//namespaces

//Default Engine Configuration Values

// Relative\Absolute Path to engine configuration file
const std::wstring CONFIGURATION_INI = L"configuration\\EngineStart.ini";
const std::wstring CONFIGURATION_XML = L"configuration\\engine_start.xml";

// Default window properties string
const std::wstring CONF_DEF_WINDOW_STRING = L"Window";
const std::wstring CONF_DEF_WINDOW_WIDTH_KEY = L"windowWidth";
const std::wstring CONF_DEF_WINDOW_HEIGHT_KEY = L"windowHeight";
const std::wstring CONF_DEF_SCREEN_DEPTH_KEY = L"screenDepth";
const std::wstring CONF_DEF_SCREEN_FREQUENCY_KEY = L"screenFrequency";
const std::wstring CONF_DEF_FULLSCREEN_KEY = L"fullScreen";
const int CONF_DEF_WINDOW_WIDTH = 600;
const int CONF_DEF_WINDOW_HEIGHT = 400;
const int CONF_DEF_WINDOW_DEPTH = 24;
const int CONF_DEF_WINDOW_FREQUENCY = 60;
const int CONF_DEF_FULLSCREEN = 0;

//-----------------------------------
// CONSTANTS 3DS (For 3ds Files)
//-----------------------------------

// Every Header in 3DS is 6 bytes long 
// 2 bytes ID and 4 bytes length

// Header of 3DS file
// This chunk contains length of whole 3ds file 
const int MAIN3DS = 0x4D4D;

// Editor version 
const int VERSION = 0x0002;

// Editor Config 
// Here starts all geometry
const int EDITOR = 0x3D3D; 

// Chunk of objects in 3DS file
// In this chunk there are objects: cameras, lights, meshes 
const int MESH = 0x4000;

// Materials
// Holds information about ambient, diffuse, specular color,\n
// texture information, shininess
// Chunk 0xAFFF itself contains no data 
const int MATERIAL = 0xAFFF;

// Editor config (unneeded) 
const int MESHVERSION = 0x3D3E;

//--------------
//    OBJECT's
//--------------

// Triangular Mesh
// There is real data of 3DS file.\n
// This chunk holds a mesh containing triangles 
const int TRIANGLE_POLYGON_MESH = 0x4100;

// Mesh Vertices
// Contains all information about vertices of a mesh 
const int VERTEX_LIST = 0x4110;

// MeshFaces
// Contains the vertex indexes, so the model is solid 
const int FACE_LIST = 0x4120;

// Face Material Info 
const int FACE_MATERIAL = 0x4130;

// Texture Coordinates
// Holds  u, v coordinates of textures for every vertex 
const int UVMAPPING = 0x4140;

// Local axis 
const int AXIS = 0x4160;

//----------------
//    MATERIAL
//----------------

// Material Name 
const int MATERIAL_NAME = 0xA000;

// Ambient Color
// Contains ambient color of the current material.\n
// Subchank 0x0011 contains information of color in RGB format. 
const int MATERIAL_AMBIENT = 0xA010;

// Diffuse
// same as Ambient Color 
const int MATERIAL_DIFFUSE = 0xA020;

// Specular Color
// same as Ambient Color and Diffuse 
const int MATERIAL_SPECULAR = 0xA030;

// Shininess 
const int MATERIAL_SHININESS = 0xA040;

// Transparency 
const int MATERIAL_TRANSPARENCY = 0xA050;

// Texture Map 
const int MATERIAL_TEXTURE_MAP = 0xA200;

// Texture Map Filename 
const int MATERIAL_TEXTURE_FILENAME = 0xA300;

//--------------------
//    ANIMATION
//--------------------

// Keyframe data 
const int KEYFRAME = 0xB000;

// Mesh anim data 
const int ANIMOBJECT = 0xB002;

// Number of keyframes 
const int FRAMES = 0xB008;

// Object parameters for animation 
const int PARAM = 0xB010;

// Object pivot point 
const int PIVOT = 0xB013;

// Object hierarchy position 
const int HIERARCHY = 0xB030;

// Track position 
const int POSITON = 0xB020;

// Track rotation 
const int ROTATION = 0xB021;

// Track scale 
const int SCALE = 0xB022;

//------------
//    TODO
//------------

const int KFVERSION = 0x0005;
const int COLORF = 0x0010;
const int COLOR24 = 0x0011;
const int LINCOLOR24 = 0x0012;
const int LINCOLORF = 0x0013;
const int INTPERCENTAGE = 0x0030;
const int FLOATPERC = 0x0031;
const int MASTERSCALE = 0x0100;
const int IMAGEFILE = 0x1100;
const int AMBIENTLIGHT = 0x2100;
const int VERTEXFLAGS = 0x4111;

const int MESHCOLORIND = 0x4165;
const int MESHTEXTUREINFO = 0x4170;
//const int HIERARCHY = 0x4F00;
const int MATERIALFALLOFF = 0xA052;
const int MATERIALEMMISIVE = 0xA080;
const int MATERIALSHADER = 0xA100;
const int OBJECTLIGHT = 0x4600;
const int OBJECTCAMERA = 0x4700;
const int ANIMHEADER = 0xB00A;



// ALL IN-ENGINE ASSETS

// Engine Window Icons - DO NOT MODIFY!
const std::wstring ICON_ASSETS_PATH = L"assets\\icons\\rrbi-32.ico";
const std::wstring ICON_SMALL_ASSETS_PATH = L"assets\\icons\\rrbi-16.ico";

// RAW FILES - TERRAIN DATA
//const char* const kMap1_raw = "assets\\heightmaps\\map1.raw";

// AUDIO FILES
//const char* const kMm9_mp3 = "assets\\audio\\mm9.mp3";

// FONT MEDIA PATH
//const char* const fonts_path = "assets\\fonts";

// SHADERS TYPE - VERTEX SHADER, FRAGMENT SHADER
enum ShaderType { MG_VS, MG_FS };

// SHADERS VENDOR - GLSL, CG
enum ShadersVendor { MG_GLSL, MG_CG };

// Maximum amount of objects on the scene
const ui MAX_OBJECTS_ = 100;


enum RendererType 
{
    MG_DX, MG_GL
};
}    // end of core namespace
}    // end of mg namespace
#endif