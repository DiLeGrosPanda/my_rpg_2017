/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** file to init the player
*/

#include "my.h"

static void fill_player_spells(player_t *player, char key_binding[SPELL_NBR])
{
	player->spells[0] = (spells_t) {1, 0., 0.3, key_binding[0],
		simple_fireball, NULL, NULL};
	player->spells[1] = (spells_t) {0, 0., 1., key_binding[1],
		multi_dir_fireballs, NULL, NULL};
	player->spells[2] = (spells_t) {0, 0., 1., key_binding[2],
		multi_fireballs, NULL, NULL};
	player->spells[3] = (spells_t) {0, 0., 10., key_binding[3],
		buff_player, NULL, NULL};
	player->spells[4] = (spells_t) {0, 0., 1., key_binding[4],
		use_lightning,
		sfTexture_createFromFile("sprites/light.png", sfFalse),
		sfSprite_create(),
	};
}

static void fill_player_stats(player_t *player)
{
	player->texture = sfTexture_createFromFile(PATH_PLAYER, sfFalse);
	player->life = 6;
	player->golds = 0;
	player->xp = 1.01;
	player->sprite = sfSprite_create();
	player->move = BOT;
	player->movement_speed = 2;
	player->attack_dmg = 1;
	player->fireball_cooldown = 0.5;
	player->shader = sfShader_createFromFile("shader/shader/simple.vert",
	"shader/shader/border.frag");
}

static void fill_player_quests(player_t *player)
{
	player->quests[0] = (quests_t) {.content = "First quest:\nParler "
		"au pnj", .states = {0, 1}, .dialogue = dial1};
	player->quests[1] = (quests_t) {.content = "Second quest:\nKill 5 "
		"monsters", .states = {0, 1}, .dialogue = dial2};
	player->quests[2] = (quests_t) {.content = "third quest: kill'em all !",
		.states = {0, 1}, .dialogue = dial3};
	player->quests[3] = (quests_t) {.content = "No more quests: You won !",
		.states = {0, 1}};
}

static int fill_player_view(sfRenderWindow *window, player_t *player)
{
	sfSprite_setTexture(player->sprite, player->texture, sfFalse);
	sfSprite_setTextureRect(player->sprite, (sfIntRect) {0, 0, 32, 32});
	player->llist_item->first = NULL;
	player->llist_item->last = NULL;
	player->llist_item->sprite = sfSprite_create();
	player->llist_item->none = sfTexture_createFromFile("sprites/none.png",
	NULL);
	player->llist_item->base = sfTexture_createFromFile(
	"sprites/info_item.png", NULL);
	sfSprite_setTexture(player->spells[4].sprite,
	player->spells[4].texture, sfFalse);
	sfSprite_setTextureRect(player->spells[4].sprite,
	(sfIntRect) {0, 0, 50, 220});
	player->view = sfView_copy(sfRenderWindow_getView(window));
	sfView_setCenter(player->view, PLAYER_START_POS);
	sfRenderWindow_setView(window, player->view);
	sfSprite_setPosition(player->sprite, PLAYER_START_POS);
	return (0);
}

int init_player(player_t *player, sfRenderWindow *window,
char key_binding[SPELL_NBR])
{
	*player = (player_t) {
		.llist_item = malloc(sizeof(llist_item_t)),
		.life_max = 6,
		.states = {
			.blendMode = sfBlendAlpha,
			.transform = sfTransform_Identity,
			.texture = NULL,
			.shader = NULL,
		},
		.music = sfMusic_createFromFile("./background_music.ogg"),
	};

	fill_player_stats(player);
	fill_player_spells(player, key_binding);
	fill_player_quests(player);
	sfMusic_setLoop(player->music, sfTrue);
	sfMusic_play(player->music);
	if (!player->texture || !player->sprite || !player->spells[4].texture)
		return (1);
	return (fill_player_view(window, player));
}
