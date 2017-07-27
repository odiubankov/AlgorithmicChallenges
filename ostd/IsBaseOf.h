#ifndef OSTD_ISBASEOF_H
#define OSTD_ISBASEOF_H

namespace ostd {

  template<typename T, typename BaseT>
  class IsBaseOf
  {
    struct Yes { char y; };
    struct No { char n[2]; };

    static Yes f(BaseT*);
    static No f(...);

  public:
    enum {
      Value = sizeof(f(static_cast<T*>(nullptr))) == sizeof(Yes)
    };
  };

}//namespace ostd


#endif //OSTD_ISBASEOF_H
