#include "DisplayEngimon.hpp"

DisplayEngimon::Display(const Engimon& E) {
  E.displayEngiInfo();
  /*
  cout << "##### Engimon Info #####" << endl;
  cout << "Name             : " << E.get_name() << " (" << E.get_nature() << ")" << endl;
  cout << "Level            : " << E.get_level() << " (" << E.get_exp() << "/100?)" << endl;
  cout << "Parents name     : " << E.get_parentsName() << endl;
  cout << "Species/Elements : " << E.get_species() << " / " << E.get_elements() << endl;
  cout << "Ability          : " << E.get_ability() << endl;
  */
}