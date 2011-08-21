//
//  LabItem.h
//  GrimToolsMac
//
//  Created by Einar Johan Trøan Sømåen on 21.08.11.
//  Copyright 2011 NTNU. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LabItem : NSObject
{
	NSString *filename;
	NSString *fileext;
	NSInteger filesize;
}

- (void)render;

@property (readwrite, retain) NSString *filename;
@property (readwrite, retain) NSString *fileext;
@property (readwrite, assign) NSInteger filesize;
@end
