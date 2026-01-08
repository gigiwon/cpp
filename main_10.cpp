#include <iostream>

#include "LikedList.h"

int main()
{
	tLinkedList list = {};
	InitList(&list);

	//PushBack(&list, 10);
	//PushBack(&list, 20);
	//PushBack(&list, 30);

	PushFront(&list, 10);
	PushFront(&list, 20);
	PushFront(&list, 30);

	tNode* pNode = list.pHeadNode;
	for (int i = 0; i < list.iCount; ++i)
	{
		printf("%d\n", pNode->iData);
		pNode = pNode->pNextNode;
	}

	ReleaseList(&list);

	return 0;
}
