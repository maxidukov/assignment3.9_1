#include <iostream>
#include <compare>

class Fraction
{
private:
    int numerator_;
    int denominator_;

public:
    Fraction(int numerator, int denominator)
    {
        numerator_ = numerator;
        denominator_ = denominator;
    }
#if __cplusplus >= 202002L
  auto operator<=>(const Fraction& f2) const {
     return (this->numerator_/this->denominator_) <=> (f2.numerator_/f2.denominator_);
  }
  auto operator==(const Fraction& f2) const {
     return (this->numerator_/this->denominator_) == (f2.numerator_/f2.denominator_);
  }
  //auto operator<=>(const Fraction& f2) const = default;
#else
  bool operator==(Fraction f2){
     return (this->numerator_/this->denominator_) == (f2.numerator_/f2.denominator_);
  }
  bool operator!=(Fraction f2){
     return !(*this==f2);
  }
  bool operator>(Fraction f2){
     return (this->numerator_/this->denominator_) > (f2.numerator_/f2.denominator_);
  }
  bool operator<(Fraction f2){
     return f2>*this;
  }
  bool operator>=(Fraction f2){
     return !(*this<f2);
  }
  bool operator<=(Fraction f2){
     return !(*this>f2);
  }
#endif
};

int main()
{
    Fraction f1(4, 3);
    Fraction f2(6, 11);

    std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
    std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
    std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
    std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
    std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
    std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
    return 0;
}
