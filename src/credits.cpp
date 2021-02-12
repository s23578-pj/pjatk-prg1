#include <iostream>
#include <unistd.h>
auto credits() -> int {
  system("clear");
  std::cout << "\n\
                                         =============================================== \n\
                                         ===========================  ================== \n\
                                         ===========================  ================== \n\
                                         ===========================  =======  ========= \n\
                                         ==   ===  =   ====   ======  ==  ==    ===   == \n\
                                         =  =  ==    =  ==  =  ===    =======  ===  =  = \n\
                                         =  =====  =======     ==  =  ==  ===  ====  === \n\
                                         =  =====  =======  =====  =  ==  ===  =====  == \n\
                                         =  =  ==  =======  =  ==  =  ==  ===  ===  =  = \n\
                                         ==   ===  ========   ====    ==  ===   ===   == \n\
                                         =============================================== \n\n\n\n";

  std::cout << "                                                       "
               "EXECUTIVE PRODUCER \n";
  std::cout << "                                                  Krzysztof "
               "Szczypior & Jakub Styn \n\n";
  std::cout
      << "                                                       DECORATOR \n";
  std::cout << "                                                  Krzysztof "
               "Szczypior \n\n";
  std::cout << "                                                       MAIN "
               "ORIGINATOR \n";
  std::cout << "                                                  Krzysztof "
               "Szczypior \n\n";
  std::cout
      << "                                                       ASSISTANTS \n";
  std::cout
      << "                                                  Uncle Google \n";
  std::cout << "                                                  patrorjt - "
               "font website \n";
  std::cout
      << "                                                  Stackoverflow \n";
  std::cout << "                                                  Library "
               "Documentation of ncurses.h \n";
  std::cout << "                                                  'Casual "
               "Coder' - YouTuber (tutorial ncurses.h) \n\n";
  std::cout << " \n\
                                    +-+-+-+-+-+-+ +-+-+-+ +-+-+-+-+-+ +-+-+-+ +-+-+-+-+-+-+-+ \n\
                                    |T|H|A|N|K|S| |F|O|R| |U|S|I|N|G| |O|U|R| |P|R|O|J|E|C|T| \n\
                                    +-+-+-+-+-+-+ +-+-+-+ +-+-+-+-+-+ +-+-+-+ +-+-+-+-+-+-+-+ \n";

  sleep(15);
  return 0;
}
