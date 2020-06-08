#ifndef ATTACK_H
#define ATTACK_H

#include <iostream>
#include <string>


class Attack {
public:
    
    Attack();
    
    void set_name(const std::string &name_in);
    
    void set_strength(const int &strength_in);
    
    std::string get_name() const ;
    
    int get_strength() const ;
    
private:
    int strength;
    std::string name;
    
};

std::ostream & operator<<(std::ostream &os, const Attack&attack);



#endif
