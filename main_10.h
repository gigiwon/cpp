#pragma once

typedef struct _tagNode
{
	int iData;
	struct _tagNode* pNextNode; // 포인터로 안하고 _tagNode 하면 안됨
}tNode;

typedef struct _tagList
{
	tNode* pHeadNode;	
	int iCount;
}tLinkedList;

// 연결형 리스트 초기화
void InitList(tLinkedList* pList_);

// 연결형 리스트 데이터 추가
void PushBack(tLinkedList* pList_, int _iData);
void PushFront(tLinkedList* pList_, int _iData);

// 연결형 리스트 메모리 해제
void ReleaseList(tLinkedList* pList_);
