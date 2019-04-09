#include "logo.h"

#include "graphics/graphics.h"
#include "graphics/image.h"
#include "graphics/lang_text.h"
#include "graphics/window.h"
#include "sound/music.h"
#include "window/main_menu.h"

static void init(void)
{
    sound_music_play_intro();
}

static void draw_background(void)
{
    graphics_clear_screen();

    graphics_in_dialog();
    image_draw(image_group(GROUP_LOGO), 0, 0);
    lang_text_draw_centered_colored(13, 7, 160, 462, 320, FONT_NORMAL_PLAIN, COLOR_WHITE);
    graphics_reset_dialog();
}

static void handle_mouse(const mouse *m)
{
    if (m->left.went_up || m->right.went_up) {
        window_main_menu_show();
    }
}

void window_logo_show(void)
{
    window_type window = {
        WINDOW_LOGO,
        draw_background,
        0,
        handle_mouse,
        0,
        0
    };
    init();
    window_show(&window);
}
