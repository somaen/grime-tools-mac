//
//  LabArchive.m
//  GrimToolsMac
//
//  Created by Einar Johan Trøan Sømåen on 21.08.11.
//  Copyright 2011 NTNU. All rights reserved.
//

#import "LabArchive.h"
#import "LabItem.h"

@implementation LabArchive

@synthesize _curFileName;
@synthesize _labFileName;
@synthesize _curFileType;
@synthesize _curFileExt;
@synthesize _curFileSize;

- (id)init
{
    self = [super init];
    if (self) {
		_myLab = new Grim::Lab();
		typeDict = [NSDictionary dictionaryWithObjectsAndKeys:
					[NSNumber numberWithInt:TEXTURE_SUR],@"sur",
					[NSNumber numberWithInt:TEXTURE_TGA],@"tga", 
					[NSNumber numberWithInt:MODEL_SKEL], @"sklb", 
					[NSNumber numberWithInt:MODEL_ANIM],@"animb", 
					[NSNumber numberWithInt:MODEL_MESH],@"meshb", 
					[NSNumber numberWithInt:TYPE_COSTUME],@"cosb", 
					nil];
		[typeDict retain];
    }
    
    return self;
}

- (bool)isText
{
	return _isText;
}

- (Grim::Block*)getCurData
{
	Grim::Block *block = _myLab->getFileBlock([self._curFileName UTF8String]);
	return block;
}

- (id) getLabItem
{
	LabItem *item = [[LabItem alloc] init];
	return item;
}

- (void)selectByNumber:(int)num
{
	_isText = false;
	self._curFileName = [NSString stringWithUTF8String:_myLab->getEntryNumName(num).c_str()];
	self._curFileSize = _myLab->getEntryNumLen(num);
	self._curFileExt = [NSString stringWithString:@"TODO"];
	
	NSArray *temp = [_curFileName componentsSeparatedByString:@"."];
	self._curFileExt = [temp lastObject];
	NSNumber *index = [typeDict objectForKey: _curFileExt];
	if (index == nil)
		index = [NSNumber numberWithInt:TYPE_UNKNOWN];
	int typeID = [index intValue];
	switch (typeID) {
		case TEXTURE_SUR:
			self._curFileType = @"Surface-texture";
			_isText = true;
			break;
		case TEXTURE_TGA:
			self._curFileType = @"TGA-texture";
			break;
		case MODEL_SKEL:
			self._curFileType = @"Model-skeleton";
			break;
		case MODEL_ANIM:
			self._curFileType = @"Model-animation";
			break;
		case MODEL_MESH:
			self._curFileType = @"Model-mesh";
			break;
		case TYPE_COSTUME:
			self._curFileType = @"Costume";
			break;
		case TYPE_UNKNOWN:
			self._curFileType = @"Unknown";
			break;
		default:
			self._curFileType = @"ERROR!";
			break;
	}
}

- (NSInteger)numEntries
{
	return _myLab->getNumEntries();
}

- (void)loadNewLAB:(NSString*)filename
{
	const char *name = [filename UTF8String];
	self._labFileName = [NSString stringWithUTF8String:name];
	_myLab->open(name);
}

@end
