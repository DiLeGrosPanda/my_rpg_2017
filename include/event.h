/*
** EPITECH PROJECT, 2018
** RPG
** File description:
** event.h
*/

int manage_ath_mouse(sfRenderWindow *, sfEvent, player_t *);
void manage_window_resize(sfRenderWindow *, player_t *,	sfEvent);
void manage_events(sfRenderWindow *, maps_t *maps, player_t *, float);
int menu_click(sfMouseButtonEvent event, button_t **buttons, sfRenderWindow *);
int inventory_event(sfRenderWindow *, button_t **buttons, sfEvent, player_t *);
int event_dialogue(sfEvent, sfRenderWindow *, dialogue_display_t *);
int manage_skill_tree_mouse(sfRenderWindow *, sfEvent, player_t *);
