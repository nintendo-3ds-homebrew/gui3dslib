#ifndef GUI3DS_H
#define GUI3DS_H

#include <3ds.h>
#include <stdbool.h>
#include <sfil.h>
#include <sf2d.h>
#include <sftd.h>

typedef struct		button
{
	u16				x1; // x position
	u16				y1; // y position
	u16				width; // button width
	u16				height; // button height
	u32				color; // button color
	touchPosition	touch; // touch for bottom screen position x y
	sf2d_texture	*texture_button; // button texture
}					s_button;
/*
** gui_function.c
*/
void	init_button_texture(s_button *button, sf2d_texture *texture_button, u16 x1, u16 y1);
void	init_button_color(u16 x1, u16 y1, u16 width, u16 height, s_button *button, u32 color);

void	draw_button_texture(s_button *button);
void	draw_button_color(s_button *button);

bool	touch_button(s_button *button, touchPosition *touch, u32 kDown);
bool	touch_button_hitbox(s_button *button, touchPosition *touch, u32 kDown);

#endif
