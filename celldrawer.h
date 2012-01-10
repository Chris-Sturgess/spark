// celldrawer.h
// is responsible for drawing a visual representation of a cell
#include "cell.h"

namespace visuals
{
	class celldrawer
	{
	public:
		// draws a cell to a render target
		void renderCell( cell&, sf::RenderTarget& );
	};
}