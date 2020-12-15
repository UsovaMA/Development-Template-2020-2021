#ifndef __MULTISTACKROOT_H__
#define __MULTISTACKROOT_H__

#include "stack.h"

#define MemLimit 100 
#define StackNum 10 

class TMultiRoot
{
protected:
  TElem Mem[MemLimit]; // ������ ��� ������
  int DefaultStack;    // ����� �������� �����
public:
  TMultiRoot() { DefaultStack = 0; }

  virtual bool IsEmpty(int ns) const = 0;             // �������� ������� ��
  virtual bool IsFull(int ns) const = 0;              // �������� ������������ ��
  virtual void Put(int ns, const TData &Val) = 0;     // �������� � ����
  virtual TData Get(int ns) = 0;                      // ����� �� ����� � ���������

                                                      // ������ ��� ������ � ������� ������
  void SetDefaultStack(int ns) { DefaultStack = ns; }           // ������� ����
  int  IsEmpty(void) const { return IsEmpty(DefaultStack); }    // ���� ?
  int  IsFull(void) const { return IsFull(DefaultStack); }      // ����� ?
  void Put(const TData &Val) { Put(DefaultStack, Val); }        // � ����
  TData Get(void) { return Get(DefaultStack); }                 // �� �����
};

#endif // __MULTISTACKROOT_H__