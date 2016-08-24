/*
 |  ----------------------------------------------
 |    mona GAME ENGINE
 |    [ Colors.h ] [ mona\renderer ]
 |    Copyright(c) Marcin Goryca
 |    marcin.goryca@gmail.com
 |    http://marcingoryca.pl
 |  ----------------------------------------------
 */
#ifndef MONA_RENDERER_COLORS_H_
#define MONA_RENDERER_COLORS_H_ 

namespace mona
{
namespace renderer
{
/*
 |  ----------------------------
 |    Red #FF0000 
 |  ----------------------------
 */
const float MONA_RED[] = {1.0f, 0.0f, 0.0f, 1.0f};
#define monaRed 1.0f, 0.0f, 0.0f
#define monaUBred 255, 0, 0

/*
 |  ----------------------------
 |    Green #00FF00 
 |  ----------------------------
 */
const float MONA_GREEN[] = {0.0f, 1.0f, 0.0f, 1.0f};
#define monaGreen 0.0f, 1.0f, 0.0f
#define monaUBgreen 0, 255, 0

/*
 |  ----------------------------
 |    Blue #0000FF 
 |  ----------------------------
 */
const float MONA_BLUE[] = {0.0f, 0.0f, 1.0f, 1.0f};
#define monaBlue 0.0f, 0.0f, 1.0f
#define monaUBblue 0, 0, 255

/*
 |  ----------------------------
 |    Black #000000 
 |  ----------------------------
 */
const float MONA_BLACK[] = {0.0f, 0.0f, 0.0f, 1.0f};
#define monaBlack 0.0f, 0.0f, 0.0f
#define monaUBblack 0, 0, 0

/*
|  ----------------------------
|    White #FFFFFF
|  ----------------------------
*/
const float MONA_WHITE[] = {1.0f, 1.0f, 1.0f, 1.0f};
#define monaWhite 1.0f, 1.0f, 1.0f
#define monaUBwhite 255, 255, 255

/*
 |  ----------------------------
 |    Yellow #FFFF00 
 |  ----------------------------
 */
const float MONA_YELLOW[] = {1.0f, 1.0f, 0.0f, 1.0f};
#define monaYellow 1.0f, 1.0f, 0.0f
#define monaUByellow 255, 255, 0  

/*
 |  ----------------------------
 |    Darkblue #000080 
 |  -----------------------------
 */
const float MONA_DARKBLUE[] = { 0.0f, 0.0f, 0.8f, 1.0f };
#define monaDarkblue 0.0f, 0.0f, 0.8f
#define monaUBdarkblue 0, 0, 128

/*
 |  ------------------------------
 |    Darkgreen #008000 
 |  ------------------------------
 */
const float MONA_DARKGREEN[] = { 0.0f, 0.8f, 0.0f, 1.0f };
#define monaDarkgreen 0.0f, 0.8f, 0.0f
#define monaUBdarkgreen 0, 128, 0

/*
 |  ------------------------------
 |    Darkcyan #008080 
 |  ------------------------------
 */
const float MONA_DARKCYAN[] = { 0.0f, 0.8f, 0.8f, 1.0f };
#define monaDarkcyan 0.0f, 0.8f, 0.8f
#define monaUBdarkcyan 0, 128, 128

/*
 |  ------------------------------
 |    Darkred #800000 
 |  ------------------------------
 */
const float MONA_DARKRED[] = { 0.8f, 0.0f, 0.0f, 1.0f };
#define darkred 0.8f, 0.0f, 0.0f
#define UBdarkred 128, 0, 0

/*
 |  ------------------------------
 |    Darkmagenta #800080 
 |  ------------------------------
 */
const float MONA_DARKMAGENTA[] = { 0.8f, 0.0f, 0.8f, 1.0f };
#define darkmagenta 0.8f, 0.0f, 0.8f
#define UBdarkmagenta 128, 0, 128

/*
 |  ------------------------------
 |    Darkyellow #808000 
 |  ------------------------------
 */
const float MONA_DARKYELLOW[] = { 0.8f, 0.8f, 0.0f, 1.0f };
#define darkyellow 0.8f, 0.8f, 0.0f
#define UBdarkyellow 128, 128, 0

/*
 |  ------------------------------
 |    Lightgrey #606060 
 |  ------------------------------
 */
const float MONA_LIGHTGREY[] = { 0.6f, 0.6f, 0.6f, 1.0f };
#define lightgrey 0.6f, 0.6f, 0.6f
#define UBlightgrey 192, 192, 192

/*
 |  ------------------------------
 |    Darkgrey #808080 
 |  ------------------------------
 */
const float MONA_DARKGREY[] = { 0.8f, 0.8f, 0.8f, 1.0f };
#define darkgrey 0.8f, 0.8f, 0.8f
#define UBdarkgrey 128, 128, 128

/*
 |  ------------------------------
 |    Cyan #00FFFF 
 |  ------------------------------
 */
const float MONA_CYAN[] = { 0.0f, 1.0f, 1.0f, 1.0f };
#define cyan 0.0f, 1.0f, 1.0f
#define UBcyan 0, 255, 255

/*
 |  ------------------------------
 |    Magenta #FF00FF 
 |  ------------------------------
 */
const float MONA_MAGENTA[] = { 1.0f, 0.0f, 1.0f, 1.0f };
#define magenta 1.0f, 0.0f, 1.0f
#define UBmagenta 255, 0, 255

/*
 |  ------------------------------
 |    Moneygreen #609060 
 |  ------------------------------
 */
const float MONA_MONEYGREEN[] = { 0.6f, 0.9f, 0.6f, 1.0f };
#define moneygreen 0.6f, 0.9f, 0.6f
#define UBmoneygreen 192, 220, 192

/*
 |  ------------------------------
 |    Airforceblue #5D8AA8
 |  ------------------------------
 */
const float MONA_AIRFORCEBLUE[] = { 0.36f, 0.54f, 0.66f, 1.0f };
#define airforceblue 0.36f, 0.54f, 0.66f
#define UBairforceblue 93, 138, 168

/*
 |  ------------------------------
 |    Alizarin Crimson #E32636 
 |  ------------------------------
 */
const float MONA_ALIZARINCRIMSON[] = { 0.83f, 0.1f, 0.26f, 1.0f };
#define alizarincrimson 0.83f, 0.1f, 0.26f
#define UBalizarincrimson 227, 38, 54

/*
 |  -------------------------------
 |    Amaranth #E52B50 
 |  -------------------------------
 */
const float MONA_AMARANTH[] = { 0.9f, 0.17f, 0.31f, 1.0f };
#define amaranth 0.9f, 0.17f, 0.31f
#define UBamaranth 229, 43, 80

/*
 |  -----------------------------------
 |    Skyblue #A6CAF0 
 |  -----------------------------------
 */
const float MONA_SKYBLUE[] = { 0.57f, 0.89f, 0.95f, 1.0f };
#define skyblue 0.57f, 0.89f, 0.95f
#define UBskyblue 166, 202, 240

/*
 |  -----------------------------------
 |    Cream #FFFBF0 
 |  -----------------------------------
 */
const float MONA_CREAM[] = { 1.0f, 0.99f, 0.95f, 1.0f };
#define cream 1.0f, 0.99f, 0.95f
#define UBcream 255, 251, 240

/* 
 |  -----------------------------------
 |    MEDIUmonaREY #A0A0A4 
 |  -----------------------------------
 */
const float MONA_MEDIUmonaREY[] = { 0.55f, 0.55f, 0.56f, 1.0f };
#define mediumonarey 0.55f, 0.55f, 0.56f
#define UBmediumonarey 160, 160, 164

/*
 |  -----------------------------------
 |    AMBER #FFBF00 
 |  -----------------------------------
 */
const float MONA_AMBER[] = { 1.0f, 0.75f, 0.0f, 1.0f };
#define amber 1.0f, 0.75f, 0.0f
#define UBamber 255, 191, 0

/*
 |  -----------------------------------
 |    Amethyst #9966CC 
 |  -----------------------------------
 */
const float MONA_AMETHYST[] = { 0.6f, 0.4f, 0.8f, 1.0f };  
#define amethyst 0.6f, 0.4f, 0.8f
#define UBamethyst 153, 102, 204

/*
 |  -----------------------------------
 |    Antique Brass #CD9575 
 |  -----------------------------------
 */
const float MONA_ANTIQUEBRASS[] = { 0.8f, 0.58f, 0.46f, 1.0f };
#define antiquebrass 0.8f, 0.58f, 0.46f
#define UBantiquebrass 205, 149, 117

/*
 |  -----------------------------------
 |    Applegreen #8DB600 
 |  -----------------------------------
 */
const float MONA_APPLEGREEN[] = { 0.55f, 0.71f, 0.0f, 1.0f };
#define applegreen 0.55f, 0.71f, 0.0f
#define UBapplegreen 141, 182, 0

/*
 |  -----------------------------------
 |    Arsenic #3B444B 
 |  -----------------------------------
 */
const float MONA_ARSENIC[] = { 0.23f, 0.27f, 0.29f, 1.0f };
#define arsenic 0.23f, 0.27f, 0.29f
#define UBarsenic 59, 68, 75

/*
 |  -----------------------------------
 |    Arylideyellow #E9D66B 
 |  -----------------------------------
 */
const float MONA_ARYLIDEYELLOW[] = { 0.91f, 0.84f, 0.42f, 1.0f };
#define arylideyellow 0.91f, 0.84f, 0.42f
#define UBarylideyellow 233, 214, 107

/*
 |  -----------------------------------
 |    Atomic Tangerine #FF9966 
 |  -----------------------------------
 */
const float MONA_ATOMICTANGERINE[] = { 1.0f, 0.6f, 0.4f, 1.0f };
#define atomictangerine 1.0f, 0.6f,0.4f
#define UBatomictangerine 255, 153, 102

/*
 |  ------------------------------------
 |    Auburn #6D351A 
 |  ------------------------------------
 */
const float MONA_AUBURN[] = { 0.43f, 0.21f, 0.1f, 1.0f };
#define auburn #0.43f, 0.21f, 0.1f
#define UBauburn 109, 53, 26

/*
 |  ------------------------------------
 |    Babypink #F4C2C2 
 |  ------------------------------------
 */
const float MONA_BABYPINK[] = { 0.96f, 0.76f, 0.76f, 1.0f };
#define babypink 0.96f, 0.76f, 0.76f
#define UBbabypink 244, 194, 194

/*
 |  -----------------------------------
 |    Ballblue #21ABCD 
 |  -----------------------------------
 */
const float MONA_BALLBLUE[] = { 0.13f, 0.67f, 0.8f, 1.0f };
#define ballblue 0.13f, 0.67f, 0.8f
#define UBballblue 33, 171, 205

// Beaver #9F8170 
const float MONA_BEAVER[] = { 0.62f, 0.51f, 0.44f, 1.0f };
#define beaver 0.62f, 0.51f,0.44f
#define UBbeaver 159, 129, 112

// Bistre #3D2B1F 
const float MONA_BISTRE[] = { 0.24f, 0.17f, 0.12f, 1.0f };
#define bistre 0.24f, 0.17f, 0.12f
#define UBbistre 61, 43, 31

// Bittersweet #FE6F5E 
const float MONA_BITTERSWEET[] = { 1.0f, 0.44f, 0.37f, 1.0f };
#define bittersweet 1.0f, 0.44f, 0.37f
#define UBbittersweet 254, 111, 94

// Bleu de France #318CE7 
const float MONA_BLEUDEFRANCE[] = { 0.19f, 0.55f, 0.91f, 1.0f };
#define bleudefrance 0.19f, 0.55f, 0.91f
#define UBbleudefrance 49, 140, 231

// Blizzard Blue #ACE5EE 
const float MONA_BLIZZARDBLUE[] = { 0.67f, 0.9f, 0.93f, 1.0f };
#define blizzardblue 0.67f, 0.9f, 0.93f
#define UBblizzardblue 172, 229, 238

// Blue Munsell #0093AF 
const float MONA_BLUEMUNSELL[] = { 0.0f, 0.5f, 0.69f, 1.0f };
#define bluemunsell 0.0f, 0.5f, 0.69f
#define UBbluemunsell 0, 147, 175

// Bole #79443B 
const float MONA_BOLE[] = { 0.47f, 0.27f, 0.23f, 1.0f };
#define bole 0.47f, 0.27f, 0.23f
#define UBbole 121, 68, 59

// Bulgarian Rose #480607
const float MONA_BULGARIANROSE[] = { 0.28f, 0.02f, 0.03f, 1.0f };
#define bulgarianrose 0.28f, 0.02f, 0.03f
#define UBbulgarianrose 72, 6, 7

// Burgundy #800020 
const float MONA_BURGUNDY[] = { 0.5f, 0.0f, 0.13f, 1.0f };
#define burgundy 0.5f, 0.0f, 0.13f
#define UBburgundy 128, 0, 32

// Cadmium Green #006B3C 
const float MONA_CADMIUmonaREEN[] = { 0.0f, 0.42f, 0.24f, 1.0f };
#define cadmiumonareen 0.0f, 0.42f, 0.24f
#define UBcadmiumonareen 0, 107, 60

// Camel #C19A6B 
const float MONA_CAMEL[] = { 0.76f, 0.6f, 0.42f, 1.0f };
#define camel 0.76f, 0.6f, 0.42f
#define UBcamel 193, 154, 107

// Cardinal #C41E31 
const float MONA_CARDINAL[] = { 0.77f, 0.12f, 0.23f, 1.0f };
#define cardinal 0.77f, 0.12f, 0.23f
#define UBcardinal 196, 30, 49

// Carmine #960018 
const float MONA_CARMINE[] = { 0.59f, 0.0f, 0.09f, 1.0f };
#define carmine 0.59f, 0.0f, 0.0.9f
#define UBcarmine 150, 0, 24

// Ceruleanblue #2A52BE 
const float MONA_CERULEANBLUE[] = { 0.16f, 0.32f, 0.75f, 1.0f };
#define ceruleanblue 0.16f, 0.32f, 0.75f
#define UBceruleanblue 42, 82, 190

// Chamoisee #A0785A 
const float MONA_CHAMOISEE[] = { 0.63f, 0.47f, 0.35f, 1.0f };
#define chamoisee 0.63f, 0.47f, 0.35f
#define UBchamoisee 160, 120, 90

// Charcoal #36454F 
const float MONA_CHARCOAL[] = { 0.21f, 0.27f, 0.31f, 1.0f };
#define charcoal 0.21f, 0.27f, 0.31f
#define UBcharcoal 54, 69,79

// Antiquefuchsia #915C83 
const float MONA_ANTIQUEFUCHSIA[] = { 0.57f, 0.36f, 0.51f, 1.0f };
#define antiquefuchsia 0.57f, 0.36f, 0.51f
#define UBantiquefuchsia 145, 92, 131

// Antiquewhite #FAEBD7 
const float MONA_ANTIQUEWHITE[] = { 0.98f, 0.92f, 0.84f, 1.0f };
#define antiquewhite 0.98f, 0.92f, 0.84f
#define UBantiquewhite 250, 235, 215

// Apricot #FBCEB1 
const float MONA_APRICOT[] = { 0.98f, 0.81f, 0.69f, 1.0f };
#define apricot 0.98f, 0.81f, 0.69f
#define UBapricot 251, 206, 177

// Aquamarine #7FFFD0 
const float MONA_AQUAMARINE[] = { 0.5f, 1.0f, 0.83f, 1.0f };
#define aquamarine 0.5f, 1.0f, 0.83f
#define UBaquamarine 127, 255, 208

// Armygreen #4B5320 
const float MONA_ARMYGREEN[] = { 0.29f, 0.33f, 0.13f, 1.0f };
#define armygreen 0.29f, 0.33f, 0.13f
#define UBarmygreen 75, 83, 32

// Bazaar #98777B 
const float MONA_BAZAAR[] = { 0.6f, 0.47f, 0.48f, 1.0f };
#define bazaar 0.6f, 0.47f, 0.48f
#define UBbazaar 152, 119, 123

// BlueRYB #0247FE 
const float MONA_BLUERYB[] = { 0.01f, 0.28f, 1.0f, 1.0f };
#define blueryb 0.01f, 0.28f, 1.0f
#define UBblueryb 2, 71, 254

// Brandeis Blue #0070FF 
const float MONA_BRANDEISBLUE[] = { 0.0f, 0.44f, 1.0f, 1.0f };
#define brandeisblue 0.0f, 0.44f, 1.0f
#define UBbrandeisblue 0, 112, 255

// Briliant lavender #F4BBFF 
const float MONA_BRILIANTLAVENDER[] = { 0.96f, 0.73f, 1.0f, 1.0f };
#define briliantlavender 0.96f, 0.73f, 1.0f
#define UBbriliantlavender 244, 187, 255

// Brink pink #FB607F 
const float MONA_BRINKPINK[] = { 0.98f, 0.38f, 0.5f, 1.0f };
#define brinkpink 0.98f, 0.38f, 0.5f
#define UBbrinkpink 251, 96, 127

// British racing green #004225 
const float MONA_BRITISHRACINGGREEN[] = { 0.0f, 0.26f, 0.15f, 1.0f };
#define britishracinggreen 0.0f, 0.26f, 0.15f
#define UBbritishracinggreen 0, 66, 37

// Bronze #CD7F32 
const float MONA_BRONZE[] = { 0.8f, 0.5f, 0.2f, 1.0f };
#define bronze 0.8f, 0.5f, 0.2f
#define UBbronze 205, 127, 50

// Brown(web) #A52A2A 
const float MONA_BROWNWEB[] = { 0.65f, 0.16f, 0.16f, 1.0f };
#define brownweb 0.65f, 0.16f, 0.16f
#define UBbrownweb 165, 42, 42

// Buff #F0DC82 
const float MONA_BUFF[] = { 0.94f, 0.86f, 0.51f, 1.0f };
#define buff 0.94f, 0.86f, 0.51f
#define UBbuff 240, 220, 130

// Burlywood #DEB887 
const float MONA_BURLYWOOD[] = { 0.87f, 0.72f, 0.53f, 1.0f };
#define burlywood 0.87f, 0.72f, 0.53f
#define UBburlywood 222, 184, 135

// Burnt orange #CC5500 
const float MONA_BURNTORANGE[] = { 0.8f, 0.33f, 0.0f, 1.0f };
#define burntorange 0.8f, 0.33f, 0.0f
#define UBburntorange 204, 85, 0

// Burnt sienna #E97451 
const float MONA_BURNTSIENNA[] = { 0.91f, 0.45f, 0.32f, 1.0f };
#define burntsienna 0.91f, 0.45f, 0.32f
#define UBburntsienna 233, 116, 81

// Burnt umber #8A3324 
const float MONA_BURNTUMBER[] = { 0.54f, 0.2f, 0.14f, 1.0f };
#define burntumber 0.54f, 0.2f, 0.14f
#define UBburntumber 138, 51, 36

// Byzantine #BD33A4 
const float MONA_BYZANTINE[] = { 0.74f, 0.2f, 0.64f, 1.0f };
#define byzantine 0.74f, 0.2f, 0.64f
#define UBbyzantine 184, 51, 164

// Byzantium #702963 
const float MONA_BYZANTIUM[] = { 0.44f, 0.16f, 0.39f, 1.0f };
#define byzantium 0.44f, 0.16f, 0.39f
#define UBbyzantium 112, 41, 99

// Halayaube #663854 
const float MONA_HALAYAUBE[] = { 0.4f, 0.22f, 0.33f, 1.0f };
#define halayaube 0.4f, 0.22f, 0.33f

// Hookersgreen #007000 
const float MONA_HOOKERSGREEN[] = { 0.0f, 0.44f, 0.0f, 1.0f };
#define hookersgreen 0.0f, 0.44f, 0.0f

// Dandelion #F0E130 
const float MONA_DANDELION[] = { 0.94f, 0.88f, 0.19f, 1.0f };
#define dandelion 0.94f, 0.88f, 0.19f			

// Darkbrown #654321
const float MONA_DARKBROWN[] = { 0.4f, 0.26f, 0.13f, 1.0f };
#define darkbrown 0.4f, 0.26f, 0.13f			

// Darkbyzantium #5D3954
const float MONA_DARKBYZANTIUM[] = { 0.36f, 0.22f, 0.33f, 1.0f };
#define darkbyzantium 0.36f, 0.22f, 0.33f

// Darkcandyapplered #A40000
const float MONA_DARKCANDYAPPLERED[] = { 0.64f, 0.0f, 0.0f, 1.0f };
#define darkcandyapplered 0.64f, 0.0f, 0.0f

// Darkcelurean #08457E
const float MONA_DARKCERULEAN[] = { 0.03f, 0.27f, 0.49f, 1.0f };
#define darkcerulean 0.03f, 0.27f, 0.49f

// Darkchampagne #C2B280
const float MONA_DARKCHAMPAGNE[] = { 0.76f, 0.7f, 0.5f, 1.0f };
#define darkchampagne 0.76f, 0.7f, 0.5f

// Darkchestnut #986960
const float MONA_DARKCHESTNUT[] = { 0.6f, 0.41f, 0.38f, 1.0f };
#define darkchestnut 0.6f, 0.41f, 0.38f

// Darkcoral #CD5B45
const float MONA_DARKCORAL[] = { 0.8f, 0.36f, 0.27f, 1.0f };
#define darkcoral 0.8f, 0.36f, 0.27f

// Darkelectricblue #536878
const float MONA_DARKELECTRICBLUE[] = { 0.33f, 0.41f, 0.47f, 1.0f };
#define darkelectricblue 0.33f, 0.41f, 0.47f

// Darkgoldenrod #B8860B
const float MONA_DARKGOLDENROD[] = { 0.72f, 0.53f, 0.04f, 1.0f };
#define darkgoldenrod 0.72f, 0.53f, 0.04f

// Darkgreen #013220
const float MONA_DARKGREEN2[] = { 0.0f, 0.2f, 0.13f, 1.0f };
#define monaDarkgreen2 0.0f, 0.2f, 0.13f

// Darkjunglegreen #1A2421
const float MONA_DARKJUNGLEGREEN[] = { 0.1f, 0.14f, 0.13f, 1.0f };
#define darkjunglegreen 0.1f, 0.14f, 0.13f

// Darkkhaki #BDB76B
const float MONA_DARKKHAKI[] = { 0.74f, 0.72f, 0.42f, 1.0f };
#define darkkhaki 0.74f, 0.72f, 0.42f

// Darklava #483C32
const float MONA_DARKLAVA[] = { 0.28f, 0.24f, 0.2f, 1.0f };
#define darklava 0.28f, 0.24f, 0.2f

// Darkmidnightblue #003366
const float MONA_DARKMIDNIGHTBLUE[] = { 0.0f, 0.2f, 0.4f, 1.0f };
#define darkmidnightblue 0.0f, 0.2f, 0.4f

// Darkolivegreen #556B2F
const float MONA_DARKOLIVEGREEN[] = { 0.33f, 0.42f, 0.18f, 1.0f };
#define darkolivegreen 0.33f, 0.42f, 0.18f

// Darkorange #FF8C00
const float MONA_DARKORANGE[] = { 1.0f, 0.55f, 0.0f, 1.0f };
#define darkorange 1.0f, 0.55f, 0.0f

// Darkpastelred #C23B22
const float MONA_DARKPASTELRED[] = { 0.76f, 0.23f, 0.13f, 1.0f };
#define darkpastelred 0.76f, 0.23f, 0.13f

// Darkraspberry #872657
const float MONA_DARKRASPBERRY[] = { 0.53f, 0.15f, 0.34f, 1.0f };
#define darkraspberry 0.53f, 0.15f, 0.34f

// Darksalmon #E9967A
const float MONA_DARKSALMON[] = { 0.91f, 0.59f, 0.48f, 1.0f };
#define darksalmon 0.91f, 0.59f, 0.48f

// Darkscarlet #560319
const float MONA_DARKSCARLET[] = { 0.34f, 0.01f, 0.1f, 1.0f };
#define darkscarlet 0.34f, 0.01f, 0.1f

// Darkspringgreen #177245
const float MONA_DARAKSPRINGGREEN[] = { 0.09f, 0.45f, 0.27f, 1.0f };
#define darkspringgreen 0.09f, 0.45f, 0.27f

// Darktan #918151
const float MONA_DARKTAN[] = { 0.57f, 0.51f, 0.32f, 1.0f };
#define darktan 0.57f, 0.51f, 0.32f

// Darktangerine #FFA812
const float MONA_DARKTANGERINE[] = { 1.0f, 0.66f, 0.07f, 1.0f };
#define darktangerine 1.0f, 0.66f, 0.07f

// Darktaupe
const float MONA_DARKTAUPE[] = { 0.28f, 0.24f, 0.2f, 1.0f };
#define darktaupe 0.28f, 0.24f, 0.2f

// Deepcarmine #A9203E
const float MONA_DEEPCARMINE[] = { 0.66f, 0.13f, 0.24f, 1.0f };
#define deepcarmine 0.66f, 0.13f, 0.24f

// Deepcarminepink #EF3038
const float MONA_DEEPCARMINEPINK[] = { 0.94f, 0.19f, 0.22f, 1.0f };
#define deepcarminepink 0.94f, 0.19f, 0.22f

// Deepcarrotorange #E9692C
const float MONA_DEEPCARROTORANGE[] = { 0.91f, 0.41f, 0.17f, 1.0f };
#define deepcarrotorange 0.91f, 0.41f, 0.17f

// Deepchampagne #FAD6A5
const float MONA_DEEPCHAMPAGNE[] = { 0.98f, 0.84f, 0.65f, 1.0f };
#define deepchampagne 0.98f, 0.84f, 0.65f

// Deepchestnut #B94E48
const float MONA_DEEPCHESTNUT[] = { 0.73f, 0.31f, 0.28f, 1.0f };
#define deepchestnut 0.73f, 0.31f, 0.28f

// Denim #1560BD
const float MONA_DENIM[] = { 0.08f, 0.38f, 0.74f, 1.0f };
#define denim 0.08f, 0.38f, 0.74f

// Desert #C19A6B
const float MONA_DESERT[] = { 0.76f, 0.6f, 0.42f, 1.0f };
#define desert 0.76f, 0.6f, 0.42f

// Earthyellow #E1A95F
const float MONA_EARTHYELLOW[] = { 0.88f, 0.66f, 0.37f, 1.0f };
#define earthyellow 0.88f, 0.66f, 0.37f

// Ecru #C2B280
const float MONA_ECRU[] = { 0.76f, 0.7f, 0.5f, 1.0f };
#define ecru 0.76f, 0.7f, 0.5f

// Eggplant #614051
const float MONA_EGGPLANT[] = { 0.38f, 0.25f, 0.32f, 1.0f };
#define eggplant 0.38f, 0.25f, 0.32f

// Eggshell #F0EAD6
const float MONA_EGGSHELL[] = { 0.94f, 0.92f, 0.84f, 1.0f };
#define eggshell 0.94f, 0.92f, 0.84f

// Fallow #C19A6B
const float MONA_FALLOW[] = { 0.76f, 0.6f, 0.42f, 1.0f };
#define fallow 0.76f, 0.6f, 0.42f

// Falured #801818
const float MONA_FALURED[] = { 0.5f, 0.09f, 0.09f, 1.0f };
#define falured 0.5f, 0.09f, 0.09f

// Fandango #B53389
const float MONA_FANDANGO[] = { 0.71f, 0.2f, 0.54f, 1.0f };
#define fandango 0.71f, 0.2f, 0.54f

// Fawn #E5AA70
const float MONA_FAWN[] = { 0.9f, 0.67f, 0.44f, 1.0f };
#define fawn 0.9f, 0.67f, 0.44f

// Ferngreen #4F7942
const float MONA_FERNGREEN[] = { 0.31f, 0.47f, 0.26f, 1.0f };
#define ferngreen 0.31f, 0.47f, 0.26f

// Firebrick #B22222
const float MONA_FIREBRICK[] = { 0.7f, 0.13f, 0.13f, 1.0f };
#define firebrick .07f, 0.13f, 0.13f

// Fireenginered #CE2029
const float MONA_FIREENGINERED[] = { 0.81f, 0.09f, 0.13f, 1.0f };
#define fireenginered 0.81f, 0.09f, 0.13f

// Flame #E25822
const float MONA_FLAME[] = { 0.89f, 0.35f, 0.13f, 1.0f };
#define flame 0.89f, 0.35f, 0.13f

// Flax #EEDC82
const float MONA_FLAX[] = { 0.93f, 0.86f, 0.51f, 1.0f };
#define flax 0.93f, 0.86f, 0.51f

// Fluorescentyellow
const float MONA_FLUORESCENTYELLOW[] = { 0.8f, 1.0f, 0.0f, 1.0f };
#define fluorescentyellow 0.8f, 1.0f, 0.0f

// Frenchbeige #A67B5B
const float MONA_FRENCHBEIGE[] = { 0.65f, 0.48f, 0.36f, 1.0f };
#define frenchbeige 0.65f, 0.48f, 0.36f

// Frenchblue #0072BB
const float MONA_FRENCHBLUE[] = { 0.0f, 0.45f, 0.73f, 1.0f };
#define frenchblue 0.0f, 0.45f, 0.73f

// Fuzzywuzzy #CC6666
const float MONA_FUZZYWUZZY[] = { 0.8f, 0.4f, 0.4f, 1.0f };
#define fuzzywuzzy 0.8f, 0.4f, 0.4f

// Gamboge #E49B0F
const float MONA_GAMBOGE[] = { 0.89f, 0.61f, 0.06f, 1.0f };
#define gamboge 0.89f, 0.61f, 0.06f	

// Goldmetallic #D4AF37
const float MONA_GOLDMETALLIC[] = { 0.83f, 0.69f, 0.22f, 1.0f };
#define goldmetallic 0.83f, 0.69f, 0.22f

// Goldenpoppy #FCC200
const float MONA_GOLDENPOPPY[] = { 0.99f, 0.76f, 0.0f, 1.0f };
#define goldenpoppy 0.99f, 0.76f, 0.0f

// Greenryb #66B032
const float MONA_GREENRYB[] = { 0.4f, 0.69f, 0.2f, 1.0f };
#define greenryb 0.4f, 0.69f, 0.2f

// Greenyellow #ADFF2F
const float MONA_GREENYELLOW[] = { 0.68f, 1.0f, 0.18f, 1.0f };
#define greenyellow 0.68f, 1.0f, 0.18f

// Hanblue #446CCF
const float MONA_HANBLUE[] = { 0.27f, 0.42f, 0.81f, 1.0f };
#define hanblue 0.27f, 0.42f, 0.81f

// Hansayellow #E9D66B
const float MONA_HANSAYELLOW[] = { 0.91f, 0.84f, 0.42f, 1.0f };
#define hansayellow 0.91f, 0.84f, 0.42f

// Harvardcrimson #C90016
const float MONA_HARVARDCRIMSON[] = { 0.79f, 0.0f, 0.09f, 1.0f };
#define harvardcrimson 0.79f, 0.0f, 0.09f

// Heartgold #808000
const float MONA_HEARTGOLD[] = { 0.5f, 0.5f, 0.0f, 1.0f };
#define heartgold 0.5f, 0.5f, 0.0f

// Huntergreen #355E3B
const float MONA_HUNTERGREEN[] = { 0.21f, 0.37f, 0.23f, 1.0f };
#define huntergreen 0.21f, 0.37f, 0.23f

// Inchworm #B2EC5D
const float MONA_INCHWORM[] = { 0.7f, 0.93f, 0.36f, 1.0f };
#define inchworm 0.7f, 0.93f, 0.36f

// Indianyellow #E3A857
const float MONA_INDIANYELLOW[] = { 0.89f, 0.66f, 0.34f, 1.0f };
#define indianyellow 0.89f, 0.66f, 0.34f

// Indigodye #00416A
const float MONA_INDIGODYE[] = { 0.0f, 0.25f, 0.42f, 1.0f };
#define indigodye 0.0f, 0.25f, 0.42f

// Internationalorange #FF4F00
const float MONA_INTERNATIONALORANGE[] = { 1.0f, 0.31f, 0.0f, 1.0f };
#define internationalorange 1.0f, 0.31f, 0.0f

// Iris #5A4FCF
const float MONA_IRIS[] = { 0.35f, 0.31f, 0.81f, 1.0f };
#define iris 0.35f, 0.31f, 0.81f

// Jasmin #F8DE7E
const float MONA_JASMIN[] = { 0.97f, 0.87f, 0.49f, 1.0f };
#define jasmin 0.97f, 0.87f, 0.49f

// Jonquil #FADA5E
const float MONA_JONQUIL[] = { 0.98f, 0.85f, 0.37f, 1.0f };
#define jonquil 0.98f, 0.85f, 0.37f

// Junebud #BDDA57
const float MONA_JUNEBUD[] = { 0.74f, 0.85f, 0.34f, 1.0f };
#define junebud 0.74f, 0.85f, 0.34f

// Lapislazuli #26619C
const float MONA_LAPISLAZULI[] = { 0.15f, 0.38f, 0.61f, 1.0f };
#define lapislazuli 0.15f, 0.38f, 0.61f

// Lava #CF1020
const float MONA_LAVA[] = { 0.81f, 0.06f, 0.13f, 1.0f };
#define lava 0.81f, 0.06f, 0.13f

// Lemon #FFF7000
const float MONA_LEMON[] = { 1.0f, 0.97f, 0.0f, 1.0f };
#define lemon 1.0f, 0.97f, 0.0f

// Liver #534B4F
const float MONA_LIVER[] = { 0.33f, 0.29f, 0.31f, 1.0f };
#define liver 0.33f, 0.29f, 0.31f

// Lust #E62020
const float MONA_LUST[] = { 0.9f, 0.13f, 0.13f, 1.0f };
#define lust 0.9f, 0.13f, 0.13f

// Mahogany #C04000
const float MONA_MAHOGANY[] = { 0.75f, 0.25f, 0.0f, 1.0f };
#define mahogany 0.75f, 0.25f, 0.0f

// Mangotango #FF8243
const float MONA_MANGOTANGO[] = { 1.0f, 0.51f, 0.26f, 1.0f };
#define mangotango 1.0f, 0.51f, 0.26f

// Naplesyellow #FADA5E
const float MONA_NAPLESYELLOW[] = { 0.98f, 0.85f, 0.37f, 1.0f };
#define naplesyellow 0.98f, 0.85f, 0.37f

// Navajowhite #FFDEAD
const float MONA_NAVAJOWHITE[] = { 1.0f, 0.87f, 0.68f, 1.0f };
#define navajowhite	1.0f, 0.87f, 0.68f

// Neoncarrot #FFA343
const float MONA_NEONCARROT[] = { 1.0f, 0.64f, 0.26f, 1.0f };
#define neoncarrot 1.0f, 0.64f, 0.26f

// Oceanboatblue #0077BE
const float MONA_OCEANBOATBLUE[] = { 0.0f, 0.47f, 0.75f, 1.0f };
#define oceanboatblue 0.0f,0.47f, 0.75f

// Ochre #CC7722
const float MONA_OCHRE[] = { 0.8f, 0.47f, 0.13f, 1.0f };
#define ochre 0.8f, 0.47f, 0.13f

// Olive #808000
const float MONA_OLIVE[] = { 0.5f, 0.5f, 0.0f, 1.0f };
#define olive 0.5f, 0.5f, 0.0f

// Olivine #9AB973
const float MONA_OLIVINE[] = { 0.6f, 0.73f, 0.45f, 1.0f };
#define olivine 0.6f, 0.73f, 0.45f

// Onyx #0F0F0F
const float MONA_ONYX[] = { 0.0f, 0.06f, 0.06f, 1.0f };
#define onyx 0.06f, 0.06f, 0.06f

// Orange #FF7F00
const float MONA_ORANGE[] = { 1.0f, 0.5f, 0.0f, 1.0f };
#define orange 1.0f, 0.5f, 0.0f	

// Orangered #FF4500
const float MONA_ORANGERED[] = { 1.0f, 0.27f, 0.0f, 1.0f };
#define orangered 1.0f, 0.27f, 0.0f

// Otterbrown #654321
const float MONA_OTTERBROWN[] = { 0.4f, 0.26f, 0.13f, 1.0f };
#define otterbrown 0.4f, 0.26f, 0.13f

// Outerspace #414A4C
const float MONA_OUTERSPACE[] = { 0.25f, 0.29f, 0.3f, 1.0f };
#define outerspace 0.25f, 0.29f, 0.3f

// Palatinablue #273BE2
const float MONA_PALATINATEBLUE[] = { 0.15f, 0.23f, 0.89f, 1.0f };
#define palatinateblue 0.15f, 0.23f, 0.89f

// Pear #D1E231
const float MONA_PEAR[] = { 0.82f, 0.89f, 0.19f, 1.0f };
#define pear 0.82f, 0.89f, 0.19f

// Paynesgrey #40404F
const float MONA_PAYNESGREY[] = { 0.25f, 0.25f, 0.28f, 1.0f };
#define paynesgrey 0.25f, 0.25f, 0.28f

// Persianorange #D99058
const float MONA_PERSIANORANGE[] = { 0.85f, 0.56f, 0.35f, 1.0f };
#define persianorange 0.85f, 0.56f, 0.35f

// Portlandorange #FF5A36
const float MONA_PORTLANDORANGE[] = { 1.0f, 0.35f, 0.21f, 1.0f };
#define portlandorange 1.0f, 0.35f, 0.21f

// Prune #701C1C
const float MONA_PRUNE[] = { 0.44f, 0.11f, 0.11f, 1.0f };
#define prune 0.44f, 0.11f, 0.11f

// Pumpkin #FF7518
const float MONA_PUMPKIN[] = { 1.0f, 0.46f, 0.09f, 1.0f };
#define pumpkin 1.0f, 0.46f, 0.09f

// Rossocorsa #D40000
const float MONA_ROSSOCORSA[] = { 0.83f, 0.0f, 0.0f, 1.0f };
#define rossocorsa 0.83f, 0.0f, 0.0f

// Rust #B7410E
const float MONA_RUST[] = { 0.72f, 0.25f, 0.05f, 1.0f };
#define rust 0.72f, 0.25f, 0.05f

// Russet #80461B
const float MONA_RUSSET[] = { 0.5f, 0.27f, 0.11f, 1.0f };
#define russet 0.5f, 0.27f, 0.11f

// Saddlebrown #8B4513
const float MONA_SADDLEBROWN[] = { 0.55f, 0.27f, 0.07f, 1.0f };
#define saddlebrown 0.55f, 0.27f, 0.07f

// Saffron #F4C430
const float MONA_SAFFRON[] = { 0.96f, 0.77f, 0.19f, 1.0f };
#define saffron 0.96f, 0.77f, 0.19f

// Sand #C3B380
const float MONA_SAND[] = { 0.76f, 0.7f, 0.5f, 1.0f };
#define sand 0.76f, 0.7f, 0.5f

// Sepia #704214
const float MONA_SEPIA[] = { 0.44f, 0.26f, 0.08f };
#define sepia 0.44f, 0.26f, 0.08f

// Shadow #8A795D
const float MONA_SHADOW[] = { 0.54f, 0.47f, 0.36f, 1.0f };
#define shadow 0.54f, 0.47f, 0.36f

// Sinopia #CB410B
const float MONA_SINOPIA[] = { 0.8f, 0.25f, 0.04f, 1.0f };
#define sinopia 0.8f, 0.25f, 0.04f

// Smokeytopaz #933D41
const float MONA_SMOKEYTOPAZ[] = { 0.58f, 0.25f, 0.03f, 1.0f };
#define smokeytopaz 0.58f, 0.25f, 0.03f

// Tan #D2B48C
const float MONA_TAN[] = { 0.82f, 0.71f, 0.55f, 1.0f };
#define MONA_tan 0.82f, 0.71f, 0.55f

// Violet #8F00FF
const float MONA_VIOLET[] = { 0.56f, 0.01f, 1.0f, 1.0f };
#define violet 0.56f, 0.0f, 1.0f

// Wenge #645452
const float MONA_WENGE[] = { 0.39f, 0.33f, 0.32f, 1.0f };
#define wenge 0.39f, 0.33f, 0.32f

// Wheat #F5DEB3
const float MONA_WHEAT[] = { 0.96f, 0.87f, 0.7f, 1.0f };
#define wheat 0.96f, 0.87f, 0.7f

// Wine #722F37
const float MONA_WINE[] = { 0.45f, 0.18f, 0.22f, 1.0f };
#define wine 0.45f, 0.18f, 0.22f

class Colors
{
public:
    Colors()
        :_red(0.0f),
         _green(0.0f),
         _blue(0.0f),
         _alpha(0.0f)
    {}

    Colors(float red, float green, float blue)
        :_red(red),
         _green(green),
         _blue(blue)
    {}

    Colors(float red, float green, float blue, float alpha)
        :_red(red),
         _green(green),
         _blue(blue),
         _alpha(alpha)
    {}

    Colors(float colors[4])
        :_red(colors[0]),
         _green(colors[1]),
         _blue(colors[2]),
         _alpha(colors[3])
    {}
    
    ~Colors(){}

    void setRed(float red){ _red = red; }
    void setGreen(float green){ _green = green; }
    void setBlue(float blue){ _blue = blue; }
    void setAlpha(float alpha){ _alpha = alpha; }
    
    void setColors(float red, float green, float blue)
    {
        _red = red;
        _green = green;
        _blue = blue;
    }

    void setColors(float red, float green, float blue, float alpha)
    {
        _red = red;
        _green = green;
        _blue = blue;
        _alpha = alpha; 
    }

    float getRed() const {  return _red; }
    float getGreen() const { return _green; }
    float getBlue() const { return _blue; }
    float getAlpha() const { return _alpha; }

private:
    float _red;
    float _green;
    float _blue;
    float _alpha;
};
}
}
#endif