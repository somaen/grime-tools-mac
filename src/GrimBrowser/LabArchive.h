//
//  LabArchive.h
//  GrimToolsMac
//
//  Created by Einar Johan Trøan Sømåen on 21.08.11.
//  Copyright 2011 NTNU. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "filetypes/grim/lab.h"

enum LabFileType {
	TYPE_UNKNOWN = 0,
	TEXTURE_SUR = 1,
	TEXTURE_TGA = 2,
	MODEL_MESH = 3,
	MODEL_SKEL = 4,
	MODEL_ANIM = 5,
	TYPE_COSTUME = 6
};

@interface LabArchive : NSObject
{
	NSDictionary *typeDict;
	NSDictionary *typeNames;
	Grim::Lab *_myLab;
	NSString *_labFileName;
	NSString *_curFileName;
	NSString *_curFileExt;
	NSString *_curFileType;
	int _curFileSize;
	bool _isText;
}
- (void)selectByNumber:(int)num;
- (NSInteger)numEntries;
- (bool)isText;
- (Grim::Block*) getCurData;
- (id) getLabItem;
- (void)loadNewLAB:(NSString*)filename;

@property (readwrite, retain) NSString *_labFileName; 
@property (readwrite, retain) NSString *_curFileName;
@property (readwrite, retain) NSString *_curFileExt;
@property (readwrite, retain) NSString *_curFileType;
@property (readwrite, assign) int _curFileSize;

@end
