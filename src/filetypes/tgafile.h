//
//  tgafile.h
//  GrimToolsMac
//
//  Created by Einar Johan Trøan Sømåen on 22.08.11.
//  Copyright 2011 NTNU. All rights reserved.
//

#ifndef GrimToolsMac_tgafile_h
#define GrimToolsMac_tgafile_h

struct Texture
{
	int width;
	int height;
	int bpp;
	char *data;
};

Texture *TGAtoTexture(const char* data);

#endif
