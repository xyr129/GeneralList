#include<iostream>
using namespace std;

enum Type
{
	HEAD,
	VALUE,
	SUB,
};

struct GeneralListNode
{
	Type _type;
	GeneralListNode* _next;
	union
	{
		char _value;
		GeneralListNode* _subLink;
	};
	

	GeneralListNode(Type type = VALUE, char value = 0)
		:_type(type)
		, _next(NULL)
	{
		if (_type == VALUE)
		{
			_value = value;
		}
		else if (_type == SUB)
		{
			_subLink = NULL;
		}
	}
};

class GeneralList
{
public:
	GeneralList()
		:_head(NULL)
	{}
	GeneralList(char* s)
		:_head(NULL)
	{
		_head = _CreatGeneralList(s);
	}
	GeneralList(const GeneralList& g)
	{
		_head = _Copy(g._head);
	}
	GeneralList& operator=(const GeneralList& g)
	{
		if (this != &g)
		{
			this->_Destory(_head);
			_head = _Copy(g._head);
		}
		return *this;
	}
	//GeneralList& operator=(const GeneralList& g)
	//{
	//	swap(_head,g._head);
	//	return *this;
	//}

	~GeneralList()
	{
		_Destory(_head);
	}
	size_t Size()
	{
		return _Size(_head);
	}
	void Print()
	{
		_Print(_head);
	}
	size_t Depth()
	{
		return _Depth(_head);
	}
protected:
	bool _IsValue(char ch);
	GeneralListNode* _CreatGeneralList(char*& s);
	size_t _Size(GeneralListNode* head);
	void _Print(GeneralListNode* head);
	size_t _Depth(GeneralListNode* head);
	void _Destory(GeneralListNode* head);
	GeneralListNode* _Copy(GeneralListNode* g);
private:

	GeneralListNode* _head;
};