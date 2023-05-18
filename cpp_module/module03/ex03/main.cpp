#include "DiamondTrap.hpp"

int main(){
	DiamondTrap huipark("huipark");


	huipark.printStatus();

  std::cout << "-----Test#2 highFivesGuys()-----" << std::endl;
  huipark.highFivesGuys();
  std::cout << std::endl;

  std::cout << "-----Test#3 attack()-----" << std::endl;
  huipark.attack("huipark");
  std::cout << std::endl;

  std::cout << "-----Test#4 whoAmI()-----" << std::endl;
  huipark.whoAmI();
  std::cout << std::endl;
  huipark.takeDamage(10);

}
