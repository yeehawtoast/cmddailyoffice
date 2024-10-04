#include "art.h"
#include <stdio.h>
#include <string.h>

// funtion declarations
void optionRead();
void prayRosary();
void waitForEnter();

char *ourFather =
    "Our Father, who art in heaven \nhallowed be thy name. \nThy kingdom "
    "come, thy will be done, \non earth as it is in heaven. \nGive us this "
    "day our daily bread \nand forgive us our trespasses \nas we forgive "
    "those who trespass against us; \nand lead us not into temptation, \nbut "
    "deliver us from evil. \nAmen.\n";

char *hailMary = "Hail Mary, Full of Grace, The Lord is with thee.\n"
                 "Blessed art thou among women\nand blessed is the fruit of "
                 "thy womb, Jesus \nHoly Mary, Mother of God, pray for "
                 "us sinners, \nnow, and at the hour of our death. \n";

char *gloryBe = "Glory Be to the Father, \nand to the Son, \nand to the "
                "Holy Spirit. \nas it was in the beginning, is now, \nand "
                "ever shall be, \nworld without end. Amen.\n";

char *apostlesCreed =
    "I believe in God, the Father Almighty, \nCreator of Heaven and earth \n"
    "and in Jesus Christ, \nHis only Son Our Lord, \nWho was conceived by the "
    "Holy Spirit, \nborn of the Virgin Mary,\nsuffered under Pontius Pilate, "
    "\nwas crucified, died, and was buried.\nHe descended into Hell \nand on "
    "the third day He rose again from the dead. \nHe ascended into Heaven "
    "\nand sitteth at the right hand of God, the Father almighty \nfrom "
    "thence He shall come to judge the living and the dead. \nI believe "
    "in the Holy Spirit, \nthe holy Catholic Church, \nthe communion of "
    "saints, \nthe forgiveness of sins, \nthe resurrection of the body and "
    "life everlasting.\n";
char *fatimaPrayer = "O my Jesus, forgive us our sins, \nsave us from the fire "
                     "of hell, \nlead all souls to heaven, \nespecially those "
                     "who are in most need of Thy mercy.";
char *hailHolyQueen =
    "Hail, holy Queen, mother of mercy, our life, our sweetness, and our "
    "hope. \nTo thee do we cry, poor banished children of Eve. \nTo thee "
    "do we send up our sighs mourning and weeping in this valley of tears. "
    "\nTurn then, most gracious advocate, thine eyes of mercy toward us, \n"
    "and after this our exile show us the blessed fruit of thy womb, Jesus. "
    "\n O clement, O loving, O sweet Virgin Mary.";

int main() {
  char selectnum;
  print_theotokos_icon();
  printf("Pray the Rosary \n");
  optionRead();
  do {
    selectnum = getchar();

    if (selectnum == '\n') {
      continue;
    }

    int counter = 0;
    while (getchar() != '\n' && counter < 100) {
      counter++; // Ensure we don't get stuck in an infinite loop
    }

    switch (selectnum) {
    case '1':
      printf("Pray Rosary \n");
      prayRosary();
      break;
    case '2':
      printf("Pray Divine Mercy Chaplet \n");
      break;
    case '3':
      printf("Pray other Prayers \n");
      break;
    default:
      printf("Please enter a valid number \n");
      break;
    }
  } while (selectnum != '1' && selectnum != '2' && selectnum != '3');
  printf("thank you for using this app!\n");
  return 0;
}

void optionRead() {
  printf("Please select an option: \n");
  printf("1. Pray the Rosary for Today \n");
  printf("2. Pray the Divine Mercy Chaplet \n");
  printf("3. Pray other prayers \n");
  printf("Type 1,2 or 3 and Hit Enter to continue:\n");
}

void prayRosary() {
  printf("\n\n\n\n###The Apostles Creed###\n\n%s \n\n", apostlesCreed);
  printf("Hit Enter for the next bead:\n\n\n\n");
  waitForEnter(); // Wait for user input

  printf("\n\n\n\n###Our Father Prayer###\n\n%s \n\n", ourFather);
  printf("Hit Enter for the next bead:\n");
  waitForEnter();

  printf("\n\n\n\n###Hail Mary for Faith###\n\n%s \n\n", hailMary);
  printf("Hit Enter for the next bead:\n");
  waitForEnter();

  printf("\n\n\n\n###Hail Mary for Hope###\n\n%s \n\n", hailMary);
  printf("Hit Enter for the next bead:\n");
  waitForEnter();

  printf("\n\n\n\n###Hail Mary for Charity###\n\n%s \n\n", hailMary);
  printf("Hit Enter for the next bead:\n");
  waitForEnter();

  printf("\n\n\n\n###Glory Be###\n\n%s \n\n", gloryBe);
  printf("Hit Enter for the next bead:\n");
  waitForEnter();

  for (int j = 1; j <= 5; j++) {
    for (int x = 1; x <= j; x++) {
      printf(" [X]");
    }
    printf("\nDecade %d\n\n\n", j);
    printf("%s\n", ourFather);
    printf("Hit ENTER for the next bead:\n\n\n");
    waitForEnter();
    for (int i = 1; i <= 10; i++) {
      for (int x = 1; x <= i; x++) {
        printf(" [X]");
      }
      printf("\n\n####Bead %d####\n\n", i);
      printf("%s\n", hailMary);
      printf("Hit ENTER for the next bead:\n\n\n");
      waitForEnter();
    }
    printf("\n\n\n\n ####Glory Be###\n\n%s\n", gloryBe);
    printf("Hit ENTER for the next bead:\n\n\n");
    waitForEnter();

    printf("\n\n\n\n###Fatima Prayer###\n\n%s\n", fatimaPrayer);
    printf("Hit ENTER for the next bead:\n\n\n");
    waitForEnter();
  }

  printf("\n\n\n###Hail, Holy Queen###\n\n\n%s\n\n", hailHolyQueen);
  printf("V: Pray for us, O Holy Mother of God.\n\n");
  printf("R: That we may be made worthy of the promises of Christ.\n\n");
  printf(
      "In the Name of the Father, and of the Son, and of the Holy Spirit.\n\n");
  printf("Hit ENTER to end the session:");
  waitForEnter();
}
void waitForEnter() {
  char buffer[100]; // Large enough to handle accidental extra input
  while (1) {
    fgets(buffer, sizeof(buffer), stdin); // Read input
    // Check if the input is just a newline (user pressed only Enter)
    if (strcmp(buffer, "\n") == 0) {
      break; // Exit the loop if only Enter was pressed
    } else {
      printf("Please press only Enter to continue.\n");
    }
  }
}
