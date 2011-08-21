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

#include <Cocoa/Cocoa.h>
#include "filetypes/grim/lab.h"
#import "LabArchive.h"
#import "GrimGL.h"

@interface LabTable : NSObject <NSTableViewDelegate, NSTableViewDataSource> {
	LabArchive *labArchive;
	NSString *_labFileName;
	IBOutlet GrimGL *glHandler;
	IBOutlet NSTextView *_textView;
	IBOutlet NSTableView *_tableView;
	IBOutlet NSTextField *_name;
	IBOutlet NSTextField *_labName;
	IBOutlet NSTextField *_size;
	IBOutlet NSTextField *_type;
}
- (void)loadLabFile: (NSString *)filename;
- (NSInteger)numberOfRowsInTableView:(NSTableView *)aTableView;
- (id)tableView:(NSTableView *)aTableView objectValueForTableColumn:(NSTableColumn *)aTableColumn row:(NSInteger)rowIndex;

// Delegate
- (void)tableViewSelectionDidChange:(NSNotification *)aNotification;

// View-stuff
- (void)updateTextFieldsWithIndex:(int)index;
- (IBAction)openLab:(id)sender;
- (IBAction)renderThis:(id)sender;
@end
