#include"GeneralList.h"
#include<cassert>


bool GeneralList::_IsValue(char ch)
{
	if (ch >= '0'&&ch <= '9' || ch >= 'a'&&ch <= 'z' || ch >= 'A'&&ch <= 'Z')
	{
		return true;
	}
	return false;
}

GeneralListNode* GeneralList::_CreatGeneralList(char*& s)
{
	assert(*s == '(');
	GeneralListNode* head = new GeneralListNode(HEAD);
	++s; //已经创建了头
	GeneralListNode* cur = head;
	while (*s)
	{
		if (*s == '(')  //子表递归
		{
			//(a,b,(c,d),e)
			GeneralListNode* subNode = new GeneralListNode(SUB); //创建一个子表节点
			cur->_next = subNode;
			cur = cur->_next;
			subNode->_subLink = _CreatGeneralList(s);
		}
		else if (*s == ')')
		{
			++s;
			break;
		}
		else if (_IsValue(*s))
		{
			GeneralListNode* valueNode = new GeneralListNode(VALUE, *s);
			cur->_next = valueNode;
			cur = cur->_next;
			++s;
		}
		else
		{
			++s;
		}
	}
	return head;
}

void GeneralList::_Destory(GeneralListNode* head)
{
	GeneralListNode* cur = head;
	while (cur)
	{
		GeneralListNode* del = cur;
		cur = cur->_next;
		if (del->_type == SUB)
		{
			_Destory(del->_subLink);
		}
		delete del;
	}
}


GeneralListNode* _Copy(GeneralListNode* head)
{
	assert(head);
	GeneralListNode* cur = head->_next;

	GeneralListNode* newHead = new GeneralListNode(HEAD);   //给新表创建head
	GeneralListNode* newCur = newHead;

	while (cur)
	{
		if (cur->_type == VALUE)
		{
			newCur->_next = new GeneralListNode(VALUE, cur->_value);
			newCur = newCur->_next;
		}
		else if (cur->_type == SUB)
		{
			newCur->_next = new GeneralListNode(SUB);
			newCur = newCur->_next;

			newCur->_subLink = _Copy(cur->_subLink);
		}
		cur = cur->_next;
	}
	return newHead;
}


size_t GeneralList:: _Size(GeneralListNode* head)
{
	GeneralListNode* cur = head;
	size_t size = 0;
	while (cur)
	{
		if (cur->_type == VALUE)
		{
			++size;
		}
		else if (cur->_type == SUB)
		{
			_Size(cur->_subLink);
		}
		cur = cur->_next;
	}
	return size;
}

size_t GeneralList::_Depth(GeneralListNode* head)
{
	size_t depth = 1;
	GeneralListNode* cur = head;
	while (cur)
	{
		if (cur->_type == SUB)
		{
			size_t subDepth = _Depth(cur->_subLink);  
			if (subDepth + 1 > depth)
			{
				depth = subDepth + 1;
			}
		}
		cur = cur->_next;
	}
	return depth;
}

void GeneralList::_Print(GeneralListNode* head)
{
	GeneralListNode* cur = head;
	while (cur)
	{
		if (cur->_type == HEAD)
		{
			cout << '(';
		}
		else if (cur->_type == VALUE)
		{
			cout << cur->_value;
			if (cur->_next != NULL)
			{
				cout << ',';
			}
		}
		else    //子表递归
		{
			_Print(cur->_subLink);
			if (cur->_next != NULL)
			{
				cout << ',';
			}
		}
		cur = cur->_next;
	}
	cout << ')';
}

