
//{{BLOCK(WinScreen)

//======================================================================
//
//	WinScreen, 256x160@8, 
//	+ palette 256 entries, not compressed
//	+ 43 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x20 
//	Total size: 512 + 2752 + 1280 = 4544
//
//	Time-stamp: 2014-04-07, 22:18:41
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_WINSCREEN_H
#define GRIT_WINSCREEN_H

#define WinScreenTilesLen 2752
extern const unsigned short WinScreenTiles[1376];

#define WinScreenMapLen 1280
extern const unsigned short WinScreenMap[640];

#define WinScreenPalLen 512
extern const unsigned short WinScreenPal[256];

#endif // GRIT_WINSCREEN_H

//}}BLOCK(WinScreen)
