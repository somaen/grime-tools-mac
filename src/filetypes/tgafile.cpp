//
//  tgafile.cpp
//  GrimToolsMac
//
//  Created by Einar Johan Trøan Sømåen on 22.08.11.
//  Copyright 2011 NTNU. All rights reserved.
//

#include <iostream>
#include "tgafile.h"

typedef unsigned short uint16;
Texture *TGAtoTexture(const char* data)
{
	if (data[2] != 2)
		std::cout << "ERROR, wrong file format" << std::endl;
	Texture *t = new Texture();
	data += 3 + 2 + 2 + 1 + 2 + 2;
	uint16 *ptr = reinterpret_cast<uint16 *>((void*)data);
	t->width = *ptr;
	t->height = *(ptr+1);
	t->bpp = data[4];
	data += 5;
	int len = t->width * t->height * t->bpp/8;
	char *newData = new char[len];
	memcpy(newData, data, len);
	t->data = newData;
	return t;
}