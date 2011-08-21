//
//  GrimGL.h
//  GrimToolsMac
//
//  Created by Einar Johan Trøan Sømåen on 22.08.11.
//  Copyright 2011 NTNU. All rights reserved.
//

#import <AppKit/AppKit.h>
#import <OpenGL/OpenGL.h>
#include "filetypes/tgafile.h"

@interface GrimGL : NSOpenGLView
{
	unsigned int texID;
}
-(void) drawRect: (NSRect) bounds;
-(void) drawSelectedItems;
-(void) renderTexture:(Texture *) t;
@end
