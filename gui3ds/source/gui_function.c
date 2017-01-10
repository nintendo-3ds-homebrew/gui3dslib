#include "gui3ds.h"

void	gui3ds_draw_button_texture(s_button *button)
{
	sf2d_draw_texture(button->texture_button, button->x1, button->y1);
}

void	gui3ds_draw_button_color(s_button *button)
{
	sf2d_draw_rectangle(button->x1, button->y1, button->width, button->height, button->color);
}

static void	gui3ds_draw_hitbox_button(u16 x1, u16 y1, u16 width, u16 height)
{
	sf2d_draw_rectangle(x1, y1, width, height, RGBA8(255, 0, 0, 50));
}

bool	gui3ds_touch_button_hitbox(s_button *button, touchPosition *touch, u32 kDown)
{
	gui3ds_draw_hitbox_button(button->x1, button->y1, button->width, button->height);
	if (kDown & KEY_TOUCH)
	{
		if (touch->px >= button->x1 && touch->px <= (button->x1 + button->width) &&
			touch->py >= button->y1 && touch->py <= (button->y1 + button->height))
			return (true);
	}
	return (false);
}

bool	gui3ds_touch_button(s_button *button, touchPosition *touch, u32 kDown)
{
	if (kDown & KEY_TOUCH)
	{
		if (touch->px >= button->x1 && touch->px <= (button->x1 + button->width) &&
			touch->py >= button->y1 && touch->py <= (button->y1 + button->height))
			return (true);
	}
	return (false);
}

void	gui3ds_init_button_texture(s_button *button, sf2d_texture *texture_button, u16 x1, u16 y1)
{
	button->texture_button = texture_button;
	button->x1 = x1;
	button->y1 = y1;
	button->width = texture_button->width;
	button->height = texture_button->height;
}

void	gui3ds_init_button_color(u16 x1, u16 y1, u16 width, u16 height, s_button *button, u32 color)
{
	button->color = color;
	button->x1 = x1;
	button->y1 = y1;
	button->width = width;
	button->height = height;
}
