//
//  filestream.h
//  GrimToolsMac
//
//  Created by Einar Johan Trøan Sømåen on 21.08.11.
//  Copyright 2011 NTNU. All rights reserved.
//

#ifndef GrimToolsMac_filestream_h
#define GrimToolsMac_filestream_h

#include "common/stream.h"

namespace Common {

SeekableReadStream *createFileStreamForFileName(const char*);

}

#endif
