#include "multistack.h"

int TMultistack::StackRelocation(int nst) {
	
	if (pStack[nst]->IsFull())
	{
		SetStackRelocation(pStackMem);
		RelocationCount++;
		return 1;
	}

	return 0;
}

int TMultistack::GetFreeMemSize() {

	return FreeMemSize;
}

void TMultistack::SetStackRelocation(TElem* pStackMem[]) {

	int FreeMemPerStack = (FreeMemSize- StackNum) / StackNum;

	if (FreeMemPerStack > 0)
	{
		int new_pos = 0;
			   
		for (int i = 0; i < StackNum; i++)
		{
			for (int j = 0; j < pStack[i]->DataCount; j++)
			{
				MemBuf[new_pos + j] = pStack[i]->pMem[j];
			}
			pStack[i]->SetMem(&Mem[new_pos], pStack[i]->DataCount + FreeMemPerStack);//Указываем, какую память использует стек
			pStackMem[i] = &Mem[new_pos];

			new_pos += pStack[i]->DataCount + FreeMemPerStack;//Вычисляем начало следующего стека
		}

		for (int i = 0; i < MemLimit; i++)
		{
			Mem[i] = MemBuf[i];
		}

	}

}

TMultistack::TMultistack() {

	int stackSize = MemLimit / StackNum;//Определяем размер каждого стека в мультистеке

	int pos = 0;//Начало стека в общей памяти

	for (int i = 0; i <StackNum; i++)//итерируемся по массиву стеков и создаем стеки
	{
		pStack[i] = new TStack(0);//Создаем стек

		pStack[i]->SetMem(&Mem[pos], stackSize);//Указываем, какую память использует стек
		
		pos += stackSize;//Наращиваем начало (для следующего стека
	}

	RelocationCount = 0;
	FreeMemSize = MemLimit;
}



TMultistack::~TMultistack() {

	for (int i = 0; i < StackNum; i++)
	{
		delete pStack[i];
	}
}


bool TMultistack::IsEmpty(int ns)const {

	return pStack[ns]->IsEmpty();
}

bool TMultistack::IsFull(int ns)const {
	return pStack[ns]->IsFull();
}

void TMultistack::Put(int ns, const TData& Val) {

	StackRelocation(ns);
	pStack[ns]->Put(Val);
	FreeMemSize--;

}

TData TMultistack::Get(int ns) {
	TData data= pStack[ns]->Get();
	FreeMemSize++;
	return data;
	
}

void TMultistack::print() {
	
	for (int i = 0; i < StackNum; i++) {
		pStack[i]->print();
   }
}