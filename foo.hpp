#ifndef FOO_HPP_
#define FOO_HPP_

#include <FOO_EXPORT.h>

class Boo;

class FOO_EXPORT Foo {
 public:
  void call(Boo&);
};

#endif // FOO_HPP_
