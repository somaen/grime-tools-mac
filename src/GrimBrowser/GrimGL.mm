//
//  GrimGL.m
//  GrimToolsMac
//
//  Created by Einar Johan Trøan Sømåen on 22.08.11.
//  Copyright 2011 NTNU. All rights reserved.
//

#import "GrimGL.h"
#import <OpenGL/gl.h>

@implementation GrimGL

- (id)init
{
    self = [super init];
    if (self) {
		texID = -1;
        // Initialization code here.
    }
    
    return self;
}

-(void) drawRect: (NSRect) bounds
{
	glClearColor(0, 0, 0.0f, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    [self drawSelectedItems];
    glFlush();
}

-(void) drawSelectedItems
{
	if(texID != 0) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texID);
	}
	//glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.0f,-1.0f,0.0f);
	
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.0f,-1.0f,0.0f);
	
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1.0f,1.0f,0.0f);
	
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.0f,1.0f,0.0f);
	glEnd();
}

-(void) renderTexture:(Texture *) t;
{
	glGenTextures(1, &texID);
	
	GLint format = GL_RGB;
	GLint type = GL_FLOAT;//GL_UNSIGNED_BYTE;
	int bytes = 4;
	
	glBindTexture(GL_TEXTURE_2D, texID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, format, t->width, t->height, 0, format, type, t->data);
	
	delete t;

}

@end
