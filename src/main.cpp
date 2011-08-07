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


#include "common/scummsys.h"
#include <iostream>
#include <string>
//#include <GL/glfw.h>

using namespace std;

int main (int argc, const char * argv[]) {
	uint fullscreen = false;
	uint xSize = 640;
	uint ySize = 480;
	uint xPos = 0;
	uint yPos = 0;
	string title = "Grim Tools Mac";
	
	//if (glfwInit() == GL_FALSE)
		return 0;
	if(fullscreen) {
		//glfwOpenWindow(xSize, ySize, 8, 8, 8, 8, 8, 8, GLFW_FULLSCREEN);
		//glfwSetWindowTitle(title.c_str());
		//CGDisplayHideCursor (kCGNullDirectDisplay);
	}
	
	if(!fullscreen) {
		//glfwOpenWindow(xSize, ySize, 8, 8, 8, 8, 8, 8, GLFW_WINDOW);
		//glfwSetWindowPos(xPos, yPos);
	}
    return 0;
}

