#ifndef INPUT_HOTKEY_H
#define INPUT_HOTKEY_H

typedef struct {
    int ctrl_down;
    int alt_down;
    int shift_down;
    int esc_down;
    int is_cheating;
} keyboard;

keyboard *keyboard_get(void);

void hotkey_character(int c);

void hotkey_left(void);
void hotkey_right(void);
void hotkey_up(void);
void hotkey_down(void);
void hotkey_home(void);
void hotkey_end(void);
void hotkey_page_up(void);
void hotkey_page_down(void);
void hotkey_enter(void);

void hotkey_func(int f_number);

void hotkey_ctrl(int is_down);
void hotkey_alt(int is_down);
void hotkey_shift(int is_down);
void hotkey_esc(int is_down);

void hotkey_reset_state(void);

#endif // INPUT_HOTKEY_H
