
//{{BLOCK(labTiles)

//======================================================================
//
//	labTiles, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 10 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 640 + 2048 = 3200
//
//	Time-stamp: 2014-04-03, 17:41:17
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LABTILES_H
#define GRIT_LABTILES_H

#define labTilesTilesLen 640
extern const unsigned short labTilesTiles[320];

#define labTilesMapLen 2048
extern const unsigned short labTilesMap[1024];

#define labTilesPalLen 512
extern const unsigned short labTilesPal[256];

#endif // GRIT_LABTILES_H

//}}BLOCK(labTiles)
