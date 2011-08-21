/* Grim-Tools-Mac
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 *
 * $URL: $
 * $Id: $
 *
 */

#import "LabTable.h"
#import "LabItem.h"
#include "filetypes/grim/lab.h"

@implementation LabTable

- (id)init
{
    self = [super init];
    if (self) {
		labArchive = [[LabArchive alloc] init];
        // Initialization code here.
    }
    
    return self;
}

- (void) loadLabFile: (NSString *)filename 
{
	[labArchive loadNewLAB:filename];
	[_labName setStringValue: labArchive._labFileName];
	[_tableView reloadData];
}

- (NSInteger)numberOfRowsInTableView:(NSTableView *)aTableView
{
	return [labArchive numEntries];
}

- (id)tableView:(NSTableView *)aTableView objectValueForTableColumn:(NSTableColumn *)aTableColumn row:(NSInteger)rowIndex
{
	[labArchive selectByNumber:rowIndex];
	if ( [[aTableColumn identifier] isEqualToString:@"FILENAME"] ) {
		return labArchive._curFileName;
	} else if ( [[aTableColumn identifier] isEqualToString:@"LENGTH"] ) {
		return [NSString stringWithFormat:@"%d",labArchive._curFileSize];
	} else if ( [[aTableColumn identifier] isEqualToString:@"TYPE"] ){
		return labArchive._curFileType;
	}
}

// Delegate
- (void)tableViewSelectionDidChange:(NSNotification *)aNotification
{
	NSLog(@"SELECTED ROW: %D",[[aNotification object] selectedRow]);
	if ([[aNotification object] selectedRow] > 0)
		[self updateTextFieldsWithIndex:[[aNotification object] selectedRow]];
}

// View
- (void)updateTextFieldsWithIndex:(int)index
{
	[labArchive selectByNumber:index];
	[_labName setStringValue: labArchive._labFileName];
	[_size setStringValue: [NSString stringWithFormat:@"%d",labArchive._curFileSize]];
	[_name setStringValue: labArchive._curFileName];
	if ([labArchive isText]) {
	/*	const char *data = [labArchive getCurData];
		[_textView setString:[NSString stringWithUTF8String:data]];*/
	}
		
}

- (IBAction)openLab:(id)sender
{
	// TODO:Remember to add closing.
	NSOpenPanel *panel = [NSOpenPanel openPanel];
	//NSArray *fileExts = [[NSArray alloc] initWithObjects: @"m4b",@"lab",@"M4B",@"LAB"];
	//[panel setAllowedFileTypes:fileExts];
	[panel setAllowsMultipleSelection:NO];
	[panel runModal];
	
	[self loadLabFile:[[[panel URLs] lastObject] path]];
	
}

- (IBAction)renderThis:(id)sender
{
	Grim::Block *block = [labArchive getCurData];
	Texture *t = TGAtoTexture(block->getData());
	delete block;
	[glHandler renderTexture:t];
}

@end
