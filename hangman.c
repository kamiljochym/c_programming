
/* ________ */
/* |      | */
/* O      | */
/* --|--    | */
/* |      | */
/* / \    /_\ */

#include <stdio.h>
#include <string.h>

#define ALIVE 1
#define DEAD 0

int get_char_in_word(int c, int length, char word[], char *revealed_word,
                     int *correct_letters, int *lives) {
  int wrong_letter = 0;
  for (int i = 0; i < length; ++i) {
    if (c == word[i]) {
      /* printf("Letter is in word"); */
      revealed_word[i] = c;
      *correct_letters += 1;
      wrong_letter += 1;
    } else {
      /* printf("letter not in word"); */
    }
  }
  if (wrong_letter == 0) {
    *lives -= 1;
  }
  return 0;
}

int check_win(char *word, char *revealed_word, int length_of_word) {
  for (int i = 0; i < length_of_word; ++i) {
    if (word[i] != revealed_word[i]) {
      return ALIVE;
    }
  }
  printf("YOU WIN!\n");
  return DEAD;
}

int fill_array(char *revealed_word, int length) {
  for (int i = 0; i < length; ++i) {
    revealed_word[i] = '_';
  }
  return 0;
}

int main(void) {

  char hangman_states[][100] = {
      "   _____  \n   |   |  \n   o   |  \n  /|\\  |  \n  / \\  |  \n",
      "   _____  \n       |  \n   o   |  \n  /|\\  |  \n  / \\  |  \n",
      "   _____  \n       |  \n   o   |  \n  /|\\  |  \n  /    |  \n",
      "   _____  \n       |  \n   o   |  \n  /|\\  |  \n       |  \n",
      "   _____  \n       |  \n   o   |  \n  /|   |  \n       |  \n",
      "   _____  \n       |  \n   o   |  \n   |   |  \n       |  \n",
      "   _____  \n       |  \n   o   |  \n       |  \n       |  \n",
      "   _____  \n       |  \n       |  \n       |  \n       |  \n",

  };

  int c;
  int game_state;
  game_state = ALIVE;

  int length_of_word;
  int correct_letters = 0;
  char word[30];
  char revealed_word[30];
  int lives = 8;

  // user inputs word to be guessed
  printf("Enter word to be guessed: \n");
  scanf("%s", word);
  length_of_word = strlen(word);
  // fill revealed_word with underscores
  fill_array(revealed_word, length_of_word);

  printf("%s\n", revealed_word);
  printf("Guess letter: ");
  while (game_state == ALIVE) {

    c = getchar();

    // handle enter presses
    if (c == '\n') {
      continue;
    }

    get_char_in_word(c, length_of_word, word, revealed_word, &correct_letters,
                     &lives);

    game_state = check_win(word, revealed_word, length_of_word);

    // ctrl+d sends EOF and terminates the programs
    if (c == EOF) {
      game_state = DEAD;
      break;
    }

    if (lives < 8) {
      printf("%s", hangman_states[lives]);
    }
    if (lives == 0) {
      game_state = DEAD;
      printf("YOU LOSE!");
      break;
    }
    printf("%s, %d \n", revealed_word, lives);
    printf("Guess letter: ");
  }
}

/*                   "   _____  \n", */
/*                   "       |  \n", */
/*                   "   o   |  \n", */
/*                   "  /|\  |  \n", */
/*                   "  / \  |  \n", */
/*                   "   _____  \n", */
/*                   "       |  \n", */
/*                   "   o   |  \n", */
/*                   "  /|\  |  \n", */
/*                   "  /    |  \n", */

/*                   "   _____  \n", */
/*                   "       |  \n", */
/*                   "   o   |  \n", */
/*                   "  /|\  |  \n", */
/*                   "       |  \n", */

/*                   "   _____  \n", */
/*                   "       |  \n", */
/*                   "   o   |  \n", */
/*                   "  /|   |  \n", */
/*                   "       |  \n", */

/*                   "   _____  \n", */
/*                   "       |  \n", */
/*                   "   o   |  \n", */
/*                   "   |   |  \n", */
/*                   "       |  \n", */
/*                   "   _____  \n", */
/*                   "       |  \n", */
/*                   "   o   |  \n", */
/*                   "       |  \n", */
/*                   "       |  \n", */

/*                   "   _____  \n", */
/*                   "       |  \n", */
/*                   "       |  \n", */
/*                   "       |  \n", */
/*                   "       |  \n", */
