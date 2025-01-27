#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HEALTH 100
#define AI_HEALTH 100
#define HEAL_AMOUNT 15
#define POWER_ATTACK_DAMAGE 25
#define NORMAL_ATTACK_DAMAGE 10

void display_health(const char *player_name, int health) {
    printf("%s Health: [", player_name);
    for (int i = 0; i < health / 10; i++) {
        printf("#");
    }
    for (int i = 0; i < (MAX_HEALTH - health) / 10; i++) {
        printf("-");
    }
    printf("] %d\n", health);
}

int calculate_damage(int base_damage) {
    int critical_chance = rand() % 100;
    if (critical_chance < 20) {
        printf("Critical hit!\n");
        return base_damage * 2;
    }
    return base_damage;
}

void generate_ai_move(char *ai_action) {
    int random_choice = rand() % 10;
    if (random_choice < 5) {
        strcpy(ai_action, "attack");
    } else if (random_choice < 9) {
        
        strcpy(ai_action, "block");
    } else {
        strcpy(ai_action, "heal");
    }
}

int main() {
    srand(time(0));
    int player1_health = MAX_HEALTH, player2_health = AI_HEALTH;
    char player1_action[15], player2_action[15];
    int ai_mode = 0;

    printf("Welcome to the Enhanced Duel Game!\n");
    printf("Commands: 'attack', 'block', 'heal', 'power-attack'.\n");

    printf("Enter 1 for AI opponent, or 2 for two-player mode: ");
    scanf("%d", &ai_mode);

    while (player1_health > 0 && player2_health > 0) {
        printf("\nPlayer 1, enter your move: ");
        scanf("%s", player1_action);

        if (ai_mode == 1) {
            generate_ai_move(player2_action);
            printf("AI chose: %s\n", player2_action);
        } else {
            printf("Player 2, enter your move: ");
            scanf("%s", player2_action);
        }

        if (strcmp(player1_action, "attack") == 0 && strcmp(player2_action, "block") != 0) {
            int damage = calculate_damage(NORMAL_ATTACK_DAMAGE);
            player2_health -= damage;
            printf("Player 1 attacks! Player 2 loses %d health.\n", damage);
        } 
        if (strcmp(player2_action, "attack") == 0 && strcmp(player1_action, "block") != 0) {
            int damage = calculate_damage(NORMAL_ATTACK_DAMAGE);
            player1_health -= damage;
            printf("Player 2 attacks! Player 1 loses %d health.\n", damage);
        }

        if (strcmp(player1_action, "power-attack") == 0 && strcmp(player2_action, "block") != 0) {
            player2_health -= POWER_ATTACK_DAMAGE;
            printf("Player 1 uses Power Attack! Player 2 loses %d health.\n", POWER_ATTACK_DAMAGE);
        }
        if (strcmp(player2_action, "power-attack") == 0 && strcmp(player1_action, "block") != 0) {
            player1_health -= POWER_ATTACK_DAMAGE;
            printf("Player 2 uses Power Attack! Player 1 loses %d health.\n", POWER_ATTACK_DAMAGE);
        }

        if (strcmp(player1_action, "heal") == 0) {
            player1_health += HEAL_AMOUNT;
            if (player1_health > MAX_HEALTH) player1_health = MAX_HEALTH;
            printf("Player 1 heals for %d health.\n", HEAL_AMOUNT);
        }
        if (strcmp(player2_action, "heal") == 0) {
            player2_health += HEAL_AMOUNT;
            if (player2_health > MAX_HEALTH) player2_health = MAX_HEALTH;
            printf("Player 2 heals for %d health.\n", HEAL_AMOUNT);
        }

        display_health("Player 1", player1_health);
        display_health("Player 2", player2_health);
    }

    if (player1_health <= 0 && player2_health <= 0) {
        printf("\nIt's a draw!\n");
    } else if (player1_health <= 0) {
        printf("\nPlayer 2 wins!\n");
    } else {
        printf("\nPlayer 1 wins!\n");
    }

    return 0;
}