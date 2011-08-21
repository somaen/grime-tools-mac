/* Residual - A 3D game interpreter
 *
 * Residual is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 *
 */

#ifndef GRIM_H
#define GRIM_H

namespace Grim {

class Bitmap;
	
enum GrimGameType {
	GType_GRIM,
	GType_MONKEY4
};
	
enum ADGameFlags {
	ADGF_NO_FLAGS = 0,
	ADGF_UNSTABLE = (1 << 21),    	// flag to designate not yet officially-supported games that are not fit for public testing
	ADGF_TESTING = (1 << 22),    	// flag to designate not yet officially-supported games that are fit for public testing
	ADGF_PIRATED = (1 << 23), ///< flag to designate well known pirated versions with cracks
	ADGF_ADDENGLISH = (1 << 24), ///< always add English as language option
	ADGF_MACRESFORK = (1 << 25), ///< the md5 for this entry will be calculated from the resource fork
	ADGF_USEEXTRAASTITLE = (1 << 26), ///< Extra field value will be used as main game title, not gameid
	ADGF_DROPLANGUAGE = (1 << 28), ///< don't add language to gameid
	ADGF_CD = (1 << 29),    	///< add "-cd" to gameid
	ADGF_DEMO = (1 << 30)   	///< add "-demo" to gameid
};
	
class Grim {
	GrimGameType _gameType;
public:
	GrimGameType getGameType() { return GType_MONKEY4; }
	bool getIsDemo() { return false; }
	void killBitmap(Bitmap *b) {}
	void registerBitmap(Bitmap *b) {}
};

extern Grim* g_grim;
	
} // end of namespace Grim

#endif
