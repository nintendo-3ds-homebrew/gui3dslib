#include <3ds.h>
#include <stdbool.h>
#include <sfil.h>
#include <sf2d.h>
#include <sftd.h>
#include <gui3ds.h>

int	main()
{
	sf2d_init();

	sf2d_texture	*tex_button = sfil_load_PNG_file("3ds/3DSident/assets/button.png", SF2D_PLACE_RAM);
	s_button		button_exit;
	s_button		button;
	touchPosition	touch;
	u32				kDown;

	init_button_texture(&button_exit, tex_button, 90, 190);
	init_button_color(90, 20, 50, 20, &button, RGBA8(0, 255, 100, 255));

	while (aptMainLoop())
	{
		hidScanInput();
		hidTouchRead(&touch);
		kDown = hidKeysDown();
		sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
			draw_button_texture(&button_exit);
			draw_button_color(&button);
		sf2d_end_frame();
		if (touch_button(&button_exit, &touch, kDown) == true)
			break ;
		if (touch_button(&button, &touch, kDown) == true)
			break ;
		sf2d_swapbuffers();
	}
	sf2d_free_texture(tex_button);
	sf2d_fini();
}
