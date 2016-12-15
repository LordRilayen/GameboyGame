
//{{BLOCK(StartScreen)

//======================================================================
//
//	StartScreen, 256x160@8, 
//	+ palette 256 entries, not compressed
//	+ 60 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x20 
//	Total size: 512 + 3840 + 1280 = 5632
//
//	Time-stamp: 2014-04-07, 22:11:47
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_STARTSCREEN_H
#define GRIT_STARTSCREEN_H

#define StartScreenTilesLen 3840
extern const unsigned short StartScreenTiles[1920];

#define StartScreenMapLen 1280
extern const unsigned short StartScreenMap[640];

#define StartScreenPalLen 512
extern const unsigned short StartScreenPal[256];

#endif // GRIT_STARTSCREEN_H

//}}BLOCK(StartScreen)
