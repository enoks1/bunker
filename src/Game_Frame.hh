#include "Parameters.hh"

class Game_Frame {
	public:
		float scale = 1;
		Vector2 position = (Vector2){7*(float)WINDOW_WIDTH/16, (float)WINDOW_HEIGTH/4};
		float width = (float)WINDOW_WIDTH - 2*position.x;
		float height = 2*width;
		Game_Frame() {} /// Initialize Game_Frame with default parameters above.
		void Scale(float scale) { /// Scale frame (and optionally add offset).
			if (height*scale < (float)WINDOW_HEIGTH/10 || height*scale > 2*(float)WINDOW_HEIGTH) {
				return;
			}
			position.x += (1.0-scale)*width/2;
			position.y += (1.0-scale)*height/2;
			width *= scale;
			height *= scale;
		}
};
