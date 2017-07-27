#ifndef OSTD_ISSAME_H
#define OSTD_ISSAME_H

namespace ostd {

  template<typename T1, typename T2>
  class IsSame
  {
  public:
    enum {
      Value = false
    };
  };

  template<typename T1>
  class IsSame<T1, T1>
  {
  public:
    enum {
      Value = true
    };
  };

}//namespace ostd


#endif //OSTD_ISSAME_H
