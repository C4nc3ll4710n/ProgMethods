#ifndef GENS_H
#define GENS_H

class LCG{
    
public:
    LCG(unsigned int s);
    void seed(unsigned int s);
    unsigned int next_mod(unsigned int m);
    unsigned int next_full();

private:
    unsigned int x;
};

class XorShift{

public:
    XorShift(unsigned int s);
    void seed(unsigned int s);
    unsigned int next();
    unsigned int next_bits();

private:
    unsigned int x;
};

class LagFib{

public:
    LagFib(unsigned int s);
    void seed(unsigned int s);
    unsigned int next();
    unsigned int next_bits();

private:
    unsigned int buf[97];
    int i;
};


#endif //GENS_H