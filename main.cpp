<<<<<<< HEAD
/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

=======
>>>>>>> aeec4c5a7988bb2b0f8096c183a158427379d060
//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 800;

void GenerateMandelbrot(SDL_Renderer* renderer)
{
	for (int row = 0; row < SCREEN_WIDTH; row++)
	{
		for (int col = 0; col < SCREEN_HEIGHT; col++)
		{
			double c_re = (col - SCREEN_WIDTH / 2.0) * 4.0 / SCREEN_WIDTH;
			double c_im = (row - SCREEN_HEIGHT / 1.25) * 4.0 / SCREEN_WIDTH;
			double x = 0, y = 0;
			int iteration = 0;
			int max = 50;
			
			while (x * x + y * y <= 4 && iteration < max)
			{
				double x_new = x * x - y * y + c_re;
				y = 2 * x * y + c_im;
				x = x_new;
				iteration++;
			}

			//Gradient from Blue to Gold
			int rValues[] = {23,46,69,92,115,138,161,184,207};
			int gValues[] = {20,40,60,80,100,120,140,160,180};
			int bValues[] = {255,233,211,189,167,145,123,101,79};

			if (iteration < max)
			{
				SDL_SetRenderDrawColor(renderer, rValues[(int)(iteration % 8)], gValues[(int)(iteration % 8)], bValues[(int)(iteration % 8)], 255);
				SDL_RenderDrawPoint(renderer, row, col);
			}

			else
			{
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				SDL_RenderDrawPoint(renderer, row, col);
			}
			
			
			
		}

	}
}


int main( int argc, char* args[] )
{

	//When true the application closes	bool quit = false;
	bool quit = false;
	
	//Hook the close button
	SDL_Event event;

	SDL_Window* window;
	
	SDL_Renderer* renderer;
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);

	SDL_RenderClear(renderer);

	GenerateMandelbrot(renderer);

	//Update the renderer
	SDL_RenderPresent(renderer);
	

	//Wait for input before closing.
	while (!quit)
	{
		SDL_WaitEvent(&event);

		if (event.type == SDL_QUIT)
		{
			quit = true;
			break;
		}
	}
}

