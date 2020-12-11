//
// Created by Zhi Wei Gan on 12/11/20.
//

#ifndef RANDOMIZED_SPLAY_TREES_SCIENTIFIC_H
#define RANDOMIZED_SPLAY_TREES_SCIENTIFIC_H


template<typename T>
struct scientificNumberType2
{
    explicit scientificNumberType2(T number, int decimalPlaces) : number(number), decimalPlaces(decimalPlaces) {}

    T number;
    int decimalPlaces;
};

template<typename T>
scientificNumberType2<T> scientificNumber2(T t, int decimalPlaces)
{
    return scientificNumberType2<T>(t, decimalPlaces);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const scientificNumberType2<T>& n)
{
    double numberDouble = n.number;
    int eToThe = 0;
    numberDouble /= 1e7;
    // memorize old state
    std::ios oldState(nullptr);
    oldState.copyfmt(os);

    if (n.number == 0){
        os << "TLE";
    } else{
        os << std::fixed << std::setprecision(n.decimalPlaces) << numberDouble;
    }

    // restore state
    os.copyfmt(oldState);
    return os;
}

template<typename T>
struct scientificNumberType
{
    explicit scientificNumberType(T number, int decimalPlaces) : number(number), decimalPlaces(decimalPlaces) {}

    T number;
    int decimalPlaces;
};

template<typename T>
scientificNumberType<T> scientificNumber(T t, int decimalPlaces)
{
    return scientificNumberType<T>(t, decimalPlaces);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const scientificNumberType<T>& n)
{
    double numberDouble = n.number;
    int eToThe = 0;
    for(; numberDouble > 9; ++eToThe)
    {
        numberDouble /= 10;
    }
    // memorize old state
    std::ios oldState(nullptr);
    oldState.copyfmt(os);

    if (n.number == 0){
        os << "TLE";
    } else{
        os << std::fixed << std::setprecision(n.decimalPlaces) << numberDouble << "e" << eToThe;
    }

    // restore state
    os.copyfmt(oldState);
    return os;
}

#endif //RANDOMIZED_SPLAY_TREES_SCIENTIFIC_H
