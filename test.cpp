void ars()
{
  vector<bool> first, economy;
  CreatePlane(first, economy);
  displayPlaneChart(first, economy);
  int choice;
  int aseat;
  char nextSeat;
  int bseat;
  int bchoice;

    do {
        displayBookingMenu();
        choice = getMenuChoice();
        if (choice !=3)
        {
          aseat = bookseat(first, economy, choice);
          displayPlaneChart(first, economy);
          printBoardingPass(first, economy, choice, aseat);
          cout << endl;
          cout << "Would you like to book another seat? y | n " << endl;
          cout << endl;
          cin >> nextSeat;
          do {
            displayBookingMenu();
            bchoice = getMenuChoice();
            if (bchoice != 3)
            {
              bseat = bookseat(first, economy, bchoice);
              displayPlaneChart(first, economy);
              printBoardingPass(first, economy, bchoice, bseat);
            }
          }
          while (nextSeat = 'y');
        }
      }
      while (choice != 3);
      cout << "Thank you, have a nice day!"<< endl;
      exit(0);

  displayPlaneChart(first, economy);
}
