//
//  filestream.cpp
//  GrimToolsMac
//
//  Created by Einar Johan Trøan Sømåen on 21.08.11.
//

#include <iostream>
#include <fstream>
#include "common/stream.h"

namespace Common {

class SeekableFileStream : public SeekableReadStream {
	std::fstream *_fileStream;
	int32 _length;
public:
	virtual int32 pos() const {
		return _fileStream->tellg();
	}
	
	virtual int32 size() const {
		return _length;
	}
	
	virtual bool eos() const {
		return _fileStream->eof();
	}
	
	virtual bool seek(int32 offset, int whence = SEEK_SET) {
		_fileStream->clear();
		switch (whence) {
			case SEEK_SET:
				_fileStream->seekg(offset, std::ios_base::beg);
				break;
			case SEEK_CUR:
				_fileStream->seekg(offset, std::ios_base::cur);
				break;
			case SEEK_END:
				_fileStream->seekg(offset, std::ios_base::end);
				break;
		}
	}
	
	virtual uint32 read(void *dataPtr, uint32 dataSize) {
		_fileStream->read((char *)dataPtr, dataSize);
		if (_fileStream->fail()) {
			return 0;
		}
		return dataSize;
	}
	
	SeekableFileStream(const char *name) {
		_fileStream = new std::fstream();
		_fileStream->open(name, std::fstream::in | std::fstream::binary);
		if (_fileStream->fail()) {
			_length = -1;
		} else {
			_fileStream->seekg(0, std::ios_base::end);
			_length = _fileStream->tellg();
			_fileStream->seekg(0, std::ios_base::beg);
		}
	}
	virtual ~SeekableFileStream() {
		_fileStream->close();
		delete _fileStream;
	}
};

SeekableReadStream *createFileStreamForFileName(const char *name) {
	SeekableFileStream *fs = new SeekableFileStream(name);
	if (fs->size() == -1) {
		delete fs;
		return NULL;
	}
	return fs;
}


}