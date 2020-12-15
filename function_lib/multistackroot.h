#ifndef __MULTISTACKROOT_H__
#define __MULTISTACKROOT_H__

#include "stack.h"

#define MemLimit 100 
#define StackNum 10 

class TMultiRoot
{
protected:
  TElem Mem[MemLimit]; // пам€ть дл€ стеков
  int DefaultStack;    // номер текущего стека
public:
  TMultiRoot() { DefaultStack = 0; }

  virtual bool IsEmpty(int ns) const = 0;             // контроль пустоты —ƒ
  virtual bool IsFull(int ns) const = 0;              // контроль переполнени€ —ƒ
  virtual void Put(int ns, const TData &Val) = 0;     // положить в стек
  virtual TData Get(int ns) = 0;                      // вз€ть из стека с удалением

                                                      // методы дл€ работы с текущим стеком
  void SetDefaultStack(int ns) { DefaultStack = ns; }           // текущий стек
  int  IsEmpty(void) const { return IsEmpty(DefaultStack); }    // пуст ?
  int  IsFull(void) const { return IsFull(DefaultStack); }      // полон ?
  void Put(const TData &Val) { Put(DefaultStack, Val); }        // в стек
  TData Get(void) { return Get(DefaultStack); }                 // из стека
};

#endif // __MULTISTACKROOT_H__